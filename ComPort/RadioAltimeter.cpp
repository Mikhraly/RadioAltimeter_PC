#include "RadioAltimeter.h"

RadioAltimeter::RadioAltimeter() {

    dataIn.offRadiation = false;
    dataIn.controlRA = false;
    dataIn.banTest = false;
    dataIn.distance = 1.5;

    dataOut.serviceability = true;
    dataOut.permissionToUse = true;
}


RadioAltimeter RadioAltimeter::setOffRadiation(bool status) {
    dataIn.offRadiation = status;
    return *(this);
}

RadioAltimeter RadioAltimeter::setControlRA(bool status) {
    dataIn.controlRA = status;
    return *(this);
}

RadioAltimeter RadioAltimeter::setBanTest(bool status) {
    dataIn.banTest = status;
    return *(this);
}

RadioAltimeter RadioAltimeter::setDistance(float meters) {
    dataIn.distance = meters;
    wordStructure.infoPart = calculateInfoPart(dataIn.distance);
    return *(this);
}

/*
bool RadioAltimeter::isOffRadiationSet() const {
    return dataIn.offRadiation;
}

bool RadioAltimeter::isControlRASet() const{
    return dataIn.controlRA;
}

bool RadioAltimeter::isBanTestSet() const{
    return dataIn.banTest;
}
*/

bool RadioAltimeter::getServiceability() const {
    return dataOut.serviceability;
}

bool RadioAltimeter::getPermissionToUse() const {
    return dataOut.permissionToUse;
}

unsigned int RadioAltimeter::getWord() {
    wordStructure.matrix = calculateMatrix(dataIn);
    wordStructure.parity = calculateParity(wordStructure);
    return (wordStructure.address | wordStructure.infoPart << 8 | wordStructure.matrix << 29 | wordStructure.parity << 31);
}

unsigned int RadioAltimeter::calculateInfoPart(float meters) const {
    if (meters > 1500) meters = 1500; // Ограничение радиовысотомера (131071 - ограничение слова данных)
    if (dataIn.controlRA == true && dataIn.banTest == false)
        return (unsigned int)(15 * 16);
    else
        return (unsigned int)(meters * 16);
}

unsigned int RadioAltimeter::calculateMatrix(DataIn& dataIn) const {
    if (dataIn.offRadiation == true || (dataIn.controlRA == true && dataIn.banTest == false))
        return 1;
    else
        return 0;
}

unsigned int RadioAltimeter::calculateParity(WordStructure& wordStructure) const {
    unsigned int wordWithoutParity = wordStructure.address | wordStructure.infoPart << 8 | wordStructure.matrix << 29;
    unsigned int counter = 0;
    for (int i = 0; i < 31; i++) {
        if (wordWithoutParity & 1 << i) counter++;
    }
    if (counter % 2)
        return 0;
    else
        return 1;
}
