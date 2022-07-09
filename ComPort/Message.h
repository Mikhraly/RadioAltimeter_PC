#pragma once
#include "RadioAltimeter.h"

class Message final {
public:
	const unsigned char& getOutMessage(RadioAltimeter& altimeter);

private:
	unsigned char outMessage[7] = {0};
	
	struct OutStruct {
		unsigned char head = 0x7E;
		unsigned int word = 0;
		bool serviceability = false;
		bool permissionToUse = false;
		unsigned char crc = 0xFF;
	} outStruct;

	const unsigned char& buildOutMessage();
};