#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;


RadioAltimeter altimeter;
MyUtil::Message message;

struct Buffer {
	unsigned char outMessage[7];
	unsigned char inMessage[3];		// do not used
} buffer = { 0, 0 };

struct Flag {
	bool outMessageChanged;
	bool firstInMessageOK;
	bool outThreadWorks;
	bool inThreadWorks;
} flag = {false, false, false, false};

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
	this->buttonHightSet_Click();
	this->checkBoxes_CheckedChanged();

	array<unsigned char>^ outMessage = {0,0,0,0,0,0,0};

	while (flag.outThreadWorks) {
		if (flag.firstInMessageOK) {
			this->mutex.WaitOne();
			if (flag.outMessageChanged) {
				for (int i = 0; i < 7; i++)
					outMessage[i] = buffer.outMessage[i];
				flag.outMessageChanged = false;
			}
			this->mutex.ReleaseMutex();

			this->mySerialPort->Write(outMessage, 0, 7);
			Thread::Sleep(500);
		}
	}
}

/// <summary>
/// Поток приема данных из COM-порта
/// </summary>
void ComPort::MyForm::inThread() {
	array<Byte>^ inBuffer = { 0, 0, 0 };
	unsigned char in[3];
	unsigned char inByte;
	
	int count = 0;
	unsigned char crc8 = 0xFF;

	bool offRadiation = false;
	bool controlRA = false;
	bool banTest = false;

	try {
		while (flag.inThreadWorks) {
			this->mySerialPort->Read(inBuffer, 0, 1);
			inByte = inBuffer[0];

			if (count == 0 && inByte == 0x7E) {
				in[0] = inByte;
				crc8 = MyUtil::crc8_ccitt_update(crc8, inByte);
				count++;
			}
			else if (count == 1) {
				in[1] = inByte;
				crc8 = MyUtil::crc8_ccitt_update(crc8, inByte);
				count++;
			}
			else if (count == 2) {
				in[2] = inByte;
				if (crc8 == in[2]) {
					offRadiation = in[1] & 0b1 ? true : false;
					controlRA = (in[1] & 0b10) >> 1 ? true : false;
					banTest = (in[1] & 0b100) >> 2 ? true : false;

					this->mutex.WaitOne();
					altimeter.setOffRadiation(offRadiation).setControlRA(controlRA).setBanTest(banTest);
					message.setOutData(altimeter.getWord());
					const unsigned char* outArray = message.getOutMessage();
					for (int i = 0; i < 7; i++)
						buffer.outMessage[i] = outArray[i];
					flag.outMessageChanged = true;
					this->mutex.ReleaseMutex();

					this->checkBoxOffRadiation->Checked = offRadiation;
					this->checkBoxControlRA->Checked = controlRA;
					this->checkBoxBanTest->Checked = banTest;

					flag.firstInMessageOK = true;
				}
				count = 0;
				crc8 = 0xFF;
			}

		}
	} catch (System::IO::IOException^ e) {}

	flag.firstInMessageOK = false;
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
	this->buttonHightSet_Click();
}

System::Void ComPort::MyForm::buttonHightSet_Click() {
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

	this->mutex.WaitOne();
	altimeter.setDistance(hightDouble);
	message.setOutData(altimeter.getWord());
	const unsigned char* outArray = message.getOutMessage();
	for (int i = 0; i < 7; i++)
		buffer.outMessage[i] = outArray[i];
	flag.outMessageChanged = true;
	this->mutex.ReleaseMutex();
}

System::Void ComPort::MyForm::textBoxHightInput_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter)
		this->buttonHightSet_Click();
}

System::Void ComPort::MyForm::textBoxHightInput_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	System::String^ hightString = this->textBoxHightInput->Text;
	System::Double hightDouble = System::Convert::ToDouble(hightString);
	if (e->Delta > 0)
		hightDouble++;
	else
		hightDouble--;
	this->textBoxHightInput->Text = System::Convert::ToString(hightDouble);
	this->buttonHightSet_Click();
}

System::Void ComPort::MyForm::checkBoxServiceability_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->checkBoxes_CheckedChanged();
}

System::Void ComPort::MyForm::checkBoxPUI_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->checkBoxes_CheckedChanged();
}

System::Void ComPort::MyForm::checkBoxes_CheckedChanged() {
	this->mutex.WaitOne();
	message.setOutData(this->checkBoxServiceability->Checked, this->checkBoxPUI->Checked);
	const unsigned char* outArray = message.getOutMessage();
	for (int i = 0; i < 7; i++)
		buffer.outMessage[i] = outArray[i];
	flag.outMessageChanged = true;
	this->mutex.ReleaseMutex();
}
