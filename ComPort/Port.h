#pragma once

using namespace System;
using namespace System::IO::Ports;

ref class Port {
public:
	Port(String^ portName, int portBaudRate);
	~Port();
	void write(String^ text);
	
private:
	SerialPort^ comPort = gcnew SerialPort();
};

