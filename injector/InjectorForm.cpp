#include "InjectorForm.h"
#include <Windows.h>
using namespace injector;

[STAThreadAttribute]
int __stdcall WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	//InjectorForm^ newInjectorForm = gcnew InjectorForm;
	//Application::Run(newInjectorForm);

	Application::Run(gcnew InjectorForm());
}