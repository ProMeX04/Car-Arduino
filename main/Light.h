#ifndef LIGHT_H
#define LIGHT_H

class Light {
private:
    byte pin;
    char state;
    unsigned long previousTime = 0;

public:
    Light(byte, byte = LOW);
    bool getState();
    void on(bool = true);
    void off(bool = true);
    void flickerOn();
    void flickerOff();
};

#endif
