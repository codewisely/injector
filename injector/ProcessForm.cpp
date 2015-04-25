#include "ProcessForm.h"

#include <Windows.h>
#include <Psapi.h>

void printProc(System::Windows::Forms::ListBox^ ptr, DWORD procid) {
	char procname[MAX_PATH] = "<unknown>";
	HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, procid);
	if (hProc != NULL) {
		HINSTANCE hModule;
		DWORD cbNeeded;
		if (EnumProcessModules(hProc, &hModule, sizeof(hModule), &cbNeeded)){
			GetModuleBaseName(hProc, hModule, procname, sizeof(procname) / sizeof(char));
		}

		System::String^ conv_procname = gcnew System::String(procname);
		conv_procname == "<unknown>" ? 0 : ptr->Items->Add(conv_procname);

		CloseHandle(hProc);
	}
}

void UpdateList(System::Windows::Forms::ListBox^ ptr) {
	DWORD aProcesses[1024], cbNeeded, cProcesses;

	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
		return;

	cProcesses = cbNeeded / sizeof(DWORD);

	for (unsigned int i = 0; i < cProcesses; i++) {
		if (aProcesses[i] != 0) printProc(ptr, aProcesses[i]);
	}
}