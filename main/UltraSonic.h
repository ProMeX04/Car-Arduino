#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <NewPing.h>

class UltraSonic : public NewPing {
public:
    UltraSonic(byte, byte, unsigned int);
};

#endif
