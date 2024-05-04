#include "Light.h"

Light::Light(byte pinNumber, byte defaultState) : pin(pinNumber) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, defaultState);
}

bool Light::getStatus() {return digitalRead(pin) == HIGH;}
void Light::on() {digitalWrite(pin, HIGH);}
void Light::off() {digitalWrite(pin, LOW);}
void Light::flicker() {
    on();
    delay(10);
    off();
}
