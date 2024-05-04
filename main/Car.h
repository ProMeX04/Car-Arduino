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

    bool autoAvoid = false;
    bool safe = true;
    int safeDistance;
    char direct;
public:
    Car(Motor leftMotor, Motor rightMotor, UltraSonic sonar, Light light);
    void setSafeDistance(byte safeDistance);
    void left();
    void right();
    void front();
    void back();
    void stop();
    char getDirect();
    void lightOn();
    void lightOff();
    bool isSafe();
    void avoidObstaclesOn();
    void avoidObstaclesOff();
    void setSpeed(byte strength);
    void warning();
};

#endif