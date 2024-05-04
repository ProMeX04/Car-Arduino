#include "Motor.h"

Motor::Motor(byte pin1, byte pin2, byte pinE, byte power)
    : pin1(pin1), pin2(pin2), pinE(pinE), power(power) {
        pinMode(pin1, OUTPUT);
        pinMode(pin2, OUTPUT);
        pinMode(pinE, OUTPUT);
    }

void Motor::control(byte a, byte b) {
    digitalWrite(pin1, a);
    digitalWrite(pin2, b);
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

void Motor::halt() {
    control(LOW, LOW);
}

void Motor::setPower(byte power) {
    this->power = power;
    analogWrite(pinE, power);
}
