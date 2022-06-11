#pragma once

using namespace System;
using namespace System::IO::Ports;

ref class Port {
public:
	Port(String^ portName, int portBaudRate);
	~Port();
	
private:
	SerialPort^ comPort = gcnew SerialPort();
};

