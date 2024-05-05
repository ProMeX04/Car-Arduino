#include "Motor.h"

Motor::Motor(byte pin1, byte pin2, byte pinE)
    : pin1(pin1), pin2(pin2), pinE(pinE) {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pinE, OUTPUT);
}

void Motor::control(byte x, byte y) {
    digitalWrite(pin1, x);
    digitalWrite(pin2, y);
}

void Motor::forward() {control(HIGH, LOW);}
void Motor::forward(byte power) {
    setPower(power);
    control(HIGH, LOW);
}

void Motor::reverse() {control(LOW, HIGH);}
void Motor::reverse(byte power) {
    setPower(power);
    control(LOW, HIGH);
}

void Motor::halt() {control(LOW, LOW);}

void Motor::setPower(byte power) {
    analogWrite(pinE, power);
}

byte Motor::getPower() {return analogRead(pinE);}