#include "Port.h"

Port::Port(String^ portName, int portBaudRate) {
	this->comPort->PortName = portName;
	this->comPort->BaudRate = portBaudRate;
	this->comPort->DataBits = 8;
	this->comPort->StopBits = StopBits::One;
	this->comPort->Parity = Parity::None;
	this->comPort->Handshake = Handshake::None;

	this->open();
}

Port::~Port() {}


void Port::open() {
	this->comPort->Open();
}

void Port::close() {
	this->comPort->Close();
}

void Port::write(String^ text) {
	this->comPort->Write(text);
}

void Port::startOutThread() {
	Thread^ outThread = gcnew Thread(gcnew ThreadStart(this, &Port::outThread));
	outThread->Start();
}

void Port::outThread() {
	array<unsigned char>^ buffer = { 0x7E, 0xAA, 0xFF };

	while (true) {
		this->comPort->Write(buffer, 0, 3);
		Thread::Sleep(0);
	}
}