#pragma once

class RadioAltimeter final {
public:
    RadioAltimeter();

    RadioAltimeter setOffRadiation(bool status);
    RadioAltimeter setControlRA(bool status);
    RadioAltimeter setBanTest(bool status);

    RadioAltimeter setDistance(float distance);
    /*
    bool isOffRadiationSet() const;
    bool isControlRASet() const;
    bool isBanTestSet() const;
    */
    bool getServiceability() const;
    bool getPermissionToUse() const;
    unsigned int getWord();

private:
    struct DataIn {
        bool offRadiation;
        bool controlRA;
        bool banTest;
        float distance;
    } dataIn;

    struct DataOut {
        bool serviceability;
        bool permissionToUse;
        unsigned int word;
    } dataOut;

    struct WordStructure {
        const unsigned int address;
        unsigned int infoPart;
        unsigned int matrix;
        unsigned int parity;
    } wordStructure = { 0x07 };

    unsigned int calculateInfoPart(float meters) const;
    unsigned int calculateMatrix(DataIn& dataIn) const;
    unsigned int calculateParity(WordStructure& wordStructure) const;
};
