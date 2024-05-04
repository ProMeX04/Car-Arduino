#include "Bluetooth.h"

Bluetooth::Bluetooth(byte rx, byte tx): SoftwareSerial(rx, tx) {}

unsigned int Bluetooth::readNumber() {
    String readString;
    while (available()) {
        delay(3);
        char c = read();
        if (isdigit(c)) {
            readString += c;
        } else if (c == '\n') {
            break;
        }
    }
    return readString.toInt();
}
