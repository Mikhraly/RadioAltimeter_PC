#include "Message.h"

using namespace MyUtil;

Message Message::setOutData(const unsigned int& word, const bool serviceability, const bool permissionToUse) {
    this->outData.word = word;
    this->outData.serviceability = serviceability;
    this->outData.permissionToUse = permissionToUse;
    return *(this);
}

Message Message::setOutData(const unsigned int& word) {
    this->outData.word = word;
    return *(this);
}

Message Message::setOutData(const bool serviceability, const bool permissionToUse) {
    this->outData.serviceability = serviceability;
    this->outData.permissionToUse = permissionToUse;
    return *(this);
}

const uint8_t* Message::getOutMessage() {
	this->outMessage[0] = 0x7E;
    this->outMessage[1] = static_cast<uint8_t>(outData.word);
    this->outMessage[2] = static_cast<uint8_t>(outData.word >> 8);
    this->outMessage[3] = static_cast<uint8_t>(outData.word >> 16);
    this->outMessage[4] = static_cast<uint8_t>(outData.word >> 24);
    this->outMessage[5] = static_cast<uint8_t>(outData.serviceability | outData.permissionToUse << 1);
    this->outMessage[6] = crc8_ccitt_calculate(outMessage, 6);
    return this->outMessage;
}

uint8_t Message::crc8_ccitt_calculate(const uint8_t *array, uint8_t num) {
    uint8_t crc = 0xFF;
    for (int i = 0; i < num; i++)
        crc = crc8_ccitt_update(crc, array[i]);
    return crc;
}

uint8_t Message::crc8_ccitt_update(uint8_t inCrc, uint8_t inData) {
    uint8_t data = inCrc ^ inData;

    for (uint8_t i = 0; i < 8; i++) {
        if ((data & 0x80) != 0) {
            data <<= 1;
            data ^= 0x07;
        } else {
            data <<= 1;
        }
    }
    return data;
}