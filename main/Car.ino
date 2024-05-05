#include "Car.h"

Car::Car(Motor leftMotor, Motor rightMotor, UltraSonic sonar, Light light)
    : leftMotor(leftMotor), rightMotor(rightMotor), sonar(sonar), light(light) {}

void Car::setup(){
    setSpeed(255);
    setSafeDistance(20);
    lightOff();
}
void Car::setSafeDistance(byte safeDistance) {this->safeDistance = safeDistance;}

void Car::left() {
    direct = 'L';
    leftMotor.reverse();
    rightMotor.forward();
}

void Car::right() {
    direct = 'R';
    leftMotor.forward();
    rightMotor.reverse();
}

void Car::front() {
    if (safe) {
        direct = 'F';
        leftMotor.forward();
        rightMotor.forward();
    }
}

void Car::back() {
    direct = 'B';
    leftMotor.reverse();
    rightMotor.reverse();
}

void Car::frontLeft(){
    direct = 'Q';
    leftMotor.halt();
    rightMotor.forward();
}   

void Car::frontRight(){
    direct = 'E';
    leftMotor.forward();
    rightMotor.halt();
} 

void Car::backLeft(){
    direct = 'Z';
    leftMotor.halt();
    rightMotor.reverse();
} 

void Car::backRight(){
    direct = 'C';
    leftMotor.reverse();
    rightMotor.halt();
} 

void Car::stop() {
    leftMotor.halt();
    rightMotor.halt();
}

char Car::getDirect() {return this->direct;}
void Car::lightOn() {light.on();}
void Car::lightOff() {light.off();}

bool Car::isSafe() {
    byte distance = sonar.ping_cm();
    if (not autoAvoid or distance >= safeDistance or direct != 'F') {
        safe = true;
        return true;
    }
    else {
        safe = false;
        return false;
    }
}

void Car::avoidObstaclesOn() {autoAvoid = true;}
void Car::avoidObstaclesOff() {autoAvoid = false;}

void Car::setSpeed(byte speed) {
    leftMotor.setPower(speed);
    rightMotor.setPower(speed);
}

void Car::warningOn(){
    light.flickerOn();
}

void Car::warningOff(){
    light.flickerOff();
}