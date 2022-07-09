#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;


RadioAltimeter altimeter;

struct Data {
	unsigned char testByte;
	int word;
} data = {0};

struct Flag {
	bool outCircleWorks;
	bool inCircleWorks;
	bool isAltimeterFree;
	bool isDataFree;
	bool isWordChanged;
} flag = {false, false, true, true, false};


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
	array<unsigned char>^ outMessage = { 0x7E, 0xAA, 0xFF };

	unsigned char testByte = 0xAA;

	while (flag.outCircleWorks) {
		if (flag.isWordChanged) {
			flag.isWordChanged = false;
			outMessage[1] = data.testByte;
		}

		this->mySerialPort->Write(outMessage, 0, 3);
		Thread::Sleep(10);
	}
}

void ComPort::MyForm::inThread() {
	array<unsigned char>^ inMessage = { 0, 0, 0 };

	while (flag.inCircleWorks) {
		//this->mySerialPort->Read();

		//this->mutex.WaitOne();
		// to do something important
		//this->mutex.ReleaseMutex();
	}
}



System::Void ComPort::MyForm::com1ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->PortName = L"COM1";
	this->portNameStatusLabel->Text = L"COM1";
}
System::Void ComPort::MyForm::com2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->PortName = L"COM2";
	this->portNameStatusLabel->Text = L"COM2";
}
System::Void ComPort::MyForm::com3ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->PortName = L"COM3";
	this->portNameStatusLabel->Text = L"COM3";
}
System::Void ComPort::MyForm::com4ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->PortName = L"COM4";
	this->portNameStatusLabel->Text = L"COM4";
}
System::Void ComPort::MyForm::com5ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->PortName = L"COM5";
	this->portNameStatusLabel->Text = L"COM5";
}
System::Void ComPort::MyForm::toolStripMenuItem1200_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 1200;
	this->portSpeedStatusLabel->Text = L"1200";
}
System::Void ComPort::MyForm::toolStripMenuItem2400_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 2400;
	this->portSpeedStatusLabel->Text = L"2400";
}
System::Void ComPort::MyForm::toolStripMenuItem4800_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 4800;
	this->portSpeedStatusLabel->Text = L"4800";
}
System::Void ComPort::MyForm::toolStripMenuItem9600_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 9600;
	this->portSpeedStatusLabel->Text = L"9600";
}
System::Void ComPort::MyForm::toolStripMenuItem19200_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 19200;
	this->portSpeedStatusLabel->Text = L"19200";
}
System::Void ComPort::MyForm::toolStripMenuItem38400_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 38400;
	this->portSpeedStatusLabel->Text = L"38400";
}
System::Void ComPort::MyForm::toolStripMenuItem57600_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 57600;
	this->portSpeedStatusLabel->Text = L"57600";
}
System::Void ComPort::MyForm::toolStripMenuItem115200_Click(System::Object^ sender, System::EventArgs^ e) {
	mySerialPort->BaudRate = 115200;
	this->portSpeedStatusLabel->Text = L"115200";
}



System::Void ComPort::MyForm::toConnectToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Thread^ outThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::outThread));
	Thread^ inThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::inThread));
	
	if (!mySerialPort->IsOpen) {
		mySerialPort->Open();

		this->isConnectStatusLabel->Text = L"Подключено";
		this->statusStrip1->BackColor = System::Drawing::Color::FromArgb(
				static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)));

		flag.outCircleWorks = true;
		flag.inCircleWorks = true;
		outThread->Start();
		inThread->Start();
	} else {
		flag.outCircleWorks = false;
		flag.inCircleWorks = false;
		
		this->isConnectStatusLabel->Text = L"Отключено";
		this->statusStrip1->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(205)),
			static_cast<System::Int32>(static_cast<System::Byte>(215)),
			static_cast<System::Int32>(static_cast<System::Byte>(61)));
		
		mySerialPort->Close();
	}
}


System::Void ComPort::MyForm::buttonHightSet_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ hight = this->textBoxHightInput->Text;
	this->labelHightSet->Text = hight;

	altimeter.setDistance(static_cast<float>(Convert::ToDouble(hight)));
	data.word = altimeter.getWord();
	data.testByte++;
	flag.isWordChanged = true;

	/*
	while (!flag.isAltimeterFree);
	flag.isAltimeterFree = false;
	altimeter.setDistance(static_cast<float>(Convert::ToDouble(hight)));
	while (!flag.isDataFree);
	flag.isDataFree = false;
	data.word = altimeter.getWord();
	flag.isDataFree = true;
	flag.isAltimeterFree = true;
	
	flag.isWordChanged = true;
	*/
	// TO DO - создать класс Massage, который будет содержать структуру отправляемого и принимаемого сообщения
}

System::Void ComPort::MyForm::textBoxHightInput_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter)
		this->buttonHightSet_Click(sender, e);
}

System::Void ComPort::MyForm::textBoxHightInput_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	System::String^ inputString = this->textBoxHightInput->Text;
	System::Double inputDouble = System::Convert::ToDouble(inputString);
	if (e->Delta > 0)
		inputDouble++;
	else
		inputDouble--;

	/*if (e->Delta > 0)
		testByte++;
	else
		testByte--;*/
	while (flag.isWordChanged);
	//dataUpdated = true;

	this->textBoxHightInput->Text = Convert::ToString(inputDouble);
	this->buttonHightSet_Click(sender, e);
}
