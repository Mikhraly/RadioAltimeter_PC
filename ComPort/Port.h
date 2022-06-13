#pragma once

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
	void outThread();
};
