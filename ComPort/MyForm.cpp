#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;


RadioAltimeter altimeter;
MyUtil::Message message;

struct Buffer {
	unsigned char outMessage[7];
	unsigned char inMessage[3];
} buffer = { 0, 0 };

struct Flag {
	bool outMessageChanged;
	bool outThreadWorks;
	bool inThreadWorks;
} flag = {false, false, false};


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
	array<unsigned char>^ outMessage = {0,0,0,0,0,0,0};

	while (flag.outThreadWorks) {
		this->mutex.WaitOne();
		if (flag.outMessageChanged) {
			for (int i = 0; i < 7; i++)
				outMessage[i] = buffer.outMessage[i];
			flag.outMessageChanged = false;
		}
		this->mutex.ReleaseMutex();

		this->mySerialPort->Write(outMessage, 0, 7);
		Thread::Sleep(10);
	}
}

void ComPort::MyForm::inThread() {
	array<unsigned char>^ inMessage = { 0, 0, 0 };

	while (flag.inThreadWorks) {
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

		flag.outThreadWorks = true;
		flag.inThreadWorks = true;
		outThread->Start();
		inThread->Start();
	} else {
		flag.outThreadWorks = false;
		flag.inThreadWorks = false;
		
		this->isConnectStatusLabel->Text = L"Отключено";
		this->statusStrip1->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(205)),
			static_cast<System::Int32>(static_cast<System::Byte>(215)),
			static_cast<System::Int32>(static_cast<System::Byte>(61)));
		
		mySerialPort->Close();
	}
}


System::Void ComPort::MyForm::buttonHightSet_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ hightString = this->textBoxHightInput->Text;
	System::Double hightDouble = System::Convert::ToDouble(hightString);
	if (hightDouble < 0) {
		hightDouble = 0;
		hightString = "0";
	} else if (hightDouble > 1500) {
		hightDouble = 1500.0;
		hightString = "1500";
	}
	this->textBoxHightInput->Text = hightString;
	this->labelHightSet->Text = hightString;

	altimeter.setDistance(hightDouble);
	unsigned int word = altimeter.getWord();
	message.setOutData(word);
	const unsigned char* outArray = message.getOutMessage();

	this->mutex.WaitOne();
	for (int i = 0; i < 7; i++)
		buffer.outMessage[i] = outArray[i];
	flag.outMessageChanged = true;
	this->mutex.ReleaseMutex();
}

System::Void ComPort::MyForm::textBoxHightInput_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter)
		this->buttonHightSet_Click(sender, e);
}

System::Void ComPort::MyForm::textBoxHightInput_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	System::String^ hightString = this->textBoxHightInput->Text;
	System::Double hightDouble = System::Convert::ToDouble(hightString);
	if (e->Delta > 0)
		hightDouble++;
	else
		hightDouble--;
	this->textBoxHightInput->Text = System::Convert::ToString(hightDouble);
	this->buttonHightSet_Click(sender, e);
}

System::Void ComPort::MyForm::checkBoxServiceability_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

}

System::Void ComPort::MyForm::checkBoxPUI_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

}
