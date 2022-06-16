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


void Port::startOutThread() {
	Thread^ outThread = gcnew Thread(gcnew ThreadStart(this, &Port::outThread));
	outThread->Start();
}
