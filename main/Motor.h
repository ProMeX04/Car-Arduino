#ifndef MOTOR_H
#define MOTOR_H

class Motor {
private:
    byte pin1, pin2, pinE, power;

public:
    Motor(byte pin1, byte pin2, byte pinE, byte power);
    void control(byte a, byte b);
    void forward();
    void forward(byte power);
    void reverse();
    void reverse(byte power);
    void halt();
    void setPower(byte power);
};

#endif
