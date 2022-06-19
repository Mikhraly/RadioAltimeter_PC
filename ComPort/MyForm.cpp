#include "MyForm.h"
#include "Port.h"

using namespace System;
using namespace System::Windows::Forms;

bool dataUpdated = false;

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ComPort::MyForm form;
	Application::Run(% form);
}



System::Void ComPort::MyForm::buttonOpenPort_Click(System::Object^ sender, System::EventArgs^ e) {

	mySerialPort->Open();
	Thread^ outThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::outThread));
	outThread->Start();

}

System::Void ComPort::MyForm::buttonClosePort_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->Close();
}

void ComPort::MyForm::outThread() {
	array<unsigned char>^ buffer = { 0x7E, 0xAA, 0xFF };

	while (true) {
		if (!dataUpdated) {
			this->mySerialPort->Write(buffer, 0, 3);
			Thread::Sleep(0);
		}
	}
}

System::Void ComPort::MyForm::com1_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}


