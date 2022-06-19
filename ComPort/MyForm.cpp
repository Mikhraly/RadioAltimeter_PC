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



/// <summary>
/// Поток передачи данных в COM-порт
/// </summary>
void ComPort::MyForm::outThread() {
	array<unsigned char>^ buffer = { 0x7E, 0xAA, 0xFF };

	while (true) {
		if (!dataUpdated) {
			this->mySerialPort->Write(buffer, 0, 3);
			Thread::Sleep(0);
		}
	}
}



/// <summary>
/// Выбор порта
/// </summary>

System::Void ComPort::MyForm::com1_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->PortName = L"COM1";
	this->portNameStatusLabel->Text = L"COM1";
}

System::Void ComPort::MyForm::com2_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->PortName = L"COM2";
	this->portNameStatusLabel->Text = L"COM2";
}

System::Void ComPort::MyForm::com3_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->PortName = L"COM3";
	this->portNameStatusLabel->Text = L"COM3";
}

System::Void ComPort::MyForm::com4_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->PortName = L"COM4";
	this->portNameStatusLabel->Text = L"COM4";
}

System::Void ComPort::MyForm::com5_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->PortName = L"COM5";
	this->portNameStatusLabel->Text = L"COM5";
}

/// <summary>
/// Выбор скорости передачи
/// </summary>

System::Void ComPort::MyForm::speed1200_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 1200;
	this->portSpeedStatusLabel->Text = L"1200";
}

System::Void ComPort::MyForm::speed2400_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 2400;
	this->portSpeedStatusLabel->Text = L"2400";
}

System::Void ComPort::MyForm::speed4800_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 4800;
	this->portSpeedStatusLabel->Text = L"4800";
}

System::Void ComPort::MyForm::speed9600_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 9600;
	this->portSpeedStatusLabel->Text = L"9600";
}

System::Void ComPort::MyForm::speed19200_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 19200;
	this->portSpeedStatusLabel->Text = L"19200";
}

System::Void ComPort::MyForm::speed38400_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 38400;
	this->portSpeedStatusLabel->Text = L"38400";
}

System::Void ComPort::MyForm::speed57600_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 57600;
	this->portSpeedStatusLabel->Text = L"57600";
}

System::Void ComPort::MyForm::speed115200_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 115200;
	this->portSpeedStatusLabel->Text = L"115200";
}

/// <summary>
/// Подключить
/// </summary>

System::Void ComPort::MyForm::portConnectToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->Open();
	
	if (mySerialPort->IsOpen) {
		this->isConnectStatusLabel->Text = L"Подключено";
		this->statusStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(
			static_cast<System::Byte>(83)),
			static_cast<System::Int32>(static_cast<System::Byte>(177)),
			static_cast<System::Int32>(static_cast<System::Byte>(84)));

	Thread^ outThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::outThread));
	outThread->Start();
	}
}


