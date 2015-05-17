#include <cstdio>
#include <Windows.h>
#include <TlHelp32.h>

#pragma region Some Typedefs (to avoid unnecessary detection)
#define _getaddr(lib, func) GetProcAddress(GetModuleHandle(lib), func);

typedef HINSTANCE(__stdcall *__LoadLibraryA)(char*);
__LoadLibraryA _loadlib = (__LoadLibraryA)_getaddr("kernel32.dll", "LoadLibraryA");

typedef HANDLE(__stdcall *__OpenProcess)(DWORD, bool, DWORD);
__OpenProcess _openprocess = (__OpenProcess)_getaddr("kernel32.dll", "OpenProcess");

typedef HANDLE(__stdcall *__VirtualAllocEx)(HANDLE, LPVOID, SIZE_T, DWORD, DWORD);
__VirtualAllocEx _valloc = (__VirtualAllocEx)_getaddr("kernel32.dll", "VirtualAllocEx");

typedef BOOL(__stdcall *__WriteProcessMemory)(HANDLE, LPVOID, LPCVOID, SIZE_T, SIZE_T*);
__WriteProcessMemory _writemem = (__WriteProcessMemory)_getaddr("kernel32.dll", "WriteProcessMemory");

typedef HANDLE(__stdcall *__CreateRemoteThread)(HANDLE, LPSECURITY_ATTRIBUTES, SIZE_T, LPTHREAD_START_ROUTINE, LPVOID, DWORD, LPDWORD);
__CreateRemoteThread _remotethread = (__CreateRemoteThread)_getaddr("kernel32.dll", "CreateRemoteThread");

typedef BOOL(__stdcall *__CloseHandle)(HANDLE);
__CloseHandle _closehandle = (__CloseHandle)_getaddr("kernel32.dll", "CloseHandle");

#undef _getaddr
#pragma endregion

using namespace System::Runtime::InteropServices;

DWORD FindProcId(char* procname){
	PROCESSENTRY32 entry = { sizeof(entry) };
	HANDLE hSnapshot;
	DWORD pid;

	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (Process32First(hSnapshot, &entry))	{
		do {
			if (!strcmp(entry.szExeFile, procname))	{

				pid = entry.th32ProcessID;
				_closehandle(hSnapshot);
				return pid;

			}
		} while (Process32Next(hSnapshot, &entry));
	}

	return 0;
}

bool Inject(System::String^ _procname, System::String^ _dllpath) {

	char* procname = (char*)Marshal::StringToHGlobalAnsi(_procname).ToPointer();
	char* dllpath = (char*)Marshal::StringToHGlobalAnsi(_dllpath).ToPointer();

	DWORD procid = FindProcId(procname);

	HANDLE hProc = _openprocess(PROCESS_ALL_ACCESS, false, procid);

	if (!hProc) {
		MessageBoxA(0, "Process doesn't exist!", "ERROR", MB_OK | MB_ICONERROR | MB_TASKMODAL);
		return false;
	}

	LPVOID paramAddr = _valloc(hProc, 0, strlen(dllpath) + 1, MEM_COMMIT, PAGE_READWRITE);
	bool written = _writemem(hProc, paramAddr, dllpath, strlen(dllpath) + 1, 0);
	_remotethread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)_loadlib, paramAddr, 0, 0);
	_closehandle(hProc);

	Marshal::FreeHGlobal(System::IntPtr(dllpath));
	Marshal::FreeHGlobal(System::IntPtr(procname));
	return written;
}
