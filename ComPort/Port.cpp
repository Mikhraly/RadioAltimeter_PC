#include "Port.h"

Port::Port(String^ portName, int portBaudRate) {
	this->comPort->PortName = portName;
	this->comPort->BaudRate = portBaudRate;
	this->comPort->DataBits = 8;
	this->comPort->StopBits = StopBits::One;
	this->comPort->Parity = Parity::None;
	this->comPort->Handshake = Handshake::None;

	this->comPort->Open();
}

Port::~Port() {
	//this->comPort->Close();
}

void Port::write(String^ text) {
	this->comPort->Write(text);
}


void Port::outThread() {
		Char c[] = { 0x30, 0x31, 0x32 };
		String^ s = "";
		s = s + c[0] + c[1] + c[2];
		
	while (true) {
		//this->write("From outThread");
		//Thread::Sleep(0);

		
		this->write(s);
		Thread::Sleep(0);
	}
}

void Port::startOutThread() {
	Thread^ outThread = gcnew Thread(gcnew ThreadStart(this, &Port::outThread));
	outThread->Start();
}