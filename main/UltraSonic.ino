#include "UltraSonic.h"

UltraSonic::UltraSonic(byte trig, byte echo, unsigned int maxDis): NewPing(trig, echo, maxDis) {
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}
