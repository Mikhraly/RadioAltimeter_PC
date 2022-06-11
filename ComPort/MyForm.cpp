#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ComPort::MyForm form;
	Application::Run(% form);
}




System::Void ComPort::MyForm::buttonOpenPort_Click(System::Object^ sender, System::EventArgs^ e) {
	
	return System::Void();
}
