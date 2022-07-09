#include "Message.h"

const unsigned char& Message::getOutMessage(RadioAltimeter& altimeter) {
	return this->outMessage[0];
}

const unsigned char& Message::buildOutMessage() {
	unsigned char outMessage[7] = { 0 };

	outMessage[0] = outStruct.head;
	

	return outMessage[0];
}
