#ifndef CAR_H
#define CAR_H

#include "Motor.h"
#include "UltraSonic.h"
#include "Light.h"

class Car {
private:
    Motor leftMotor, rightMotor;
    UltraSonic sonar;
    Light light;
    byte speed;
    bool autoAvoid = false;
    bool safe = true;
    int safeDistance;
    char direct;
public:
    Car(Motor, Motor, UltraSonic, Light);
    void setup();
    void setSafeDistance(byte);
    void left();
    void right();
    void front();
    void back();
    void frontRight();
    void frontLeft();
    void backRight();
    void backLeft();
    void stop();
    char getDirect();
    void lightOn();
    void lightOff();
    bool isSafe();
    void avoidObstaclesOn();
    void avoidObstaclesOff();
    void setSpeed(byte);
    void warningOn();
    void warningOff();
};

#endif