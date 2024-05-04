#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <SoftwareSerial.h>

class Bluetooth : public SoftwareSerial {
public:
    Bluetooth(byte rx, byte tx);
    unsigned int readNumber();
};

#endif
