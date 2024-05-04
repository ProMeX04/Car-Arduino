#ifndef MOTOR_H
#define MOTOR_H

class Motor {
private:
    byte pin1, pin2, pinE;

public:
    Motor(byte pin1, byte pin2, byte pinE);
    void control(byte, byte);
    void forward();
    void forward(byte);
    void reverse();
    void reverse(byte);
    void halt();
    void setPower(byte);
    byte getPower();
};

#endif
