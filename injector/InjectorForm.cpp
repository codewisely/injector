#include <Windows.h>
#include "InjectorForm.h"
using namespace injector;

[STAThreadAttribute]
int __stdcall WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew InjectorForm());
}
