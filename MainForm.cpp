#include "MainForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(array<System::String^> ^args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ImageryProcess::MainForm form;
	Application::Run(%form);
}
