#ifndef LIGHT_H
#define LIGHT_H

class Light {
private:
    byte pin;
    bool state;
    unsigned long previousTime;

public:
    Light(byte);
    bool getState();
    void on(bool = true);
    void off(bool = true);
    void flickerOn();
    void flickerOff();
};

#endif
