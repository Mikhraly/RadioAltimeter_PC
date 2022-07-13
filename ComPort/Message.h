#pragma once
#include <stdint.h>
#include "RadioAltimeter.h"

class Message final {
public:
	void setOutData(const unsigned int& word, const bool serviceability, const bool permissionToUse);
	const uint8_t& getOutMessage();

private:
	uint8_t outMessage[7] = {0};
	
	struct OutData {
		unsigned int word = 0;
		bool serviceability = false;
		bool permissionToUse = false;
	} outData;

	uint8_t crc8_ccitt_calculate(const uint8_t* array, uint8_t num);
	uint8_t crc8_ccitt_update(uint8_t inCrc, uint8_t inData);
};