#ifndef LIGHT_H
#define LIGHT_H

class Light {
private:
    byte pin;
public:
    Light(byte pinNumber, byte defaultState = LOW);
    bool getStatus();
    void on();
    void off();
    void flicker();
};

#endif
