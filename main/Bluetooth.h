#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <SoftwareSerial.h>

class Bluetooth : public SoftwareSerial {
public:
    Bluetooth(byte, byte);
    unsigned int readNumber();
};

#endif
