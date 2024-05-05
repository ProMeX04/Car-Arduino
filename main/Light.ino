#include "Light.h"

Light::Light(byte pinNumber) : pin(pinNumber), previousTime(0){pinMode(pin, OUTPUT);}

bool Light::getState() {return digitalRead(pin) == HIGH;}
void Light::on(bool changeState = true) {
    digitalWrite(pin, HIGH);
    if (changeState) state = HIGH;
}

void Light::off(bool changeState = true) {
    digitalWrite(pin, LOW);
    if (changeState) state = LOW;
}
void Light::flickerOn() {
    long currentTime = millis();
    if (currentTime - previousTime > 50){
        if (getState() == HIGH) off(false);
        else on(false);
    }
    previousTime = currentTime;
}

void Light::flickerOff() {
    digitalWrite(pin, state);
}

