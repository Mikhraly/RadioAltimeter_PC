#pragma once

#include <string>
#include <array>

using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;


ref class Port {
public:
	Port(String^ portName, int portBaudRate);
	~Port();

	void write(String^ text);
	void startOutThread();

private:
	SerialPort^ comPort = gcnew SerialPort();
	void outThread() {
		array<unsigned char>^ buffer = { 0x7E, 0xAA, 0xFF };

		while (true) {
			this->comPort->Write(buffer, 0, 3);
			Thread::Sleep(0);
		}
	}
};
