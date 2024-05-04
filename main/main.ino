#include "car.h"
#include "Bluetooth.h"

Bluetooth bluetooth(8, 9);
Car car(Motor(7, 5, 6),Motor(2, 4, 3), UltraSonic(10, 11, 500), Light(12));


void setup() {
    Serial.begin(38400);
    bluetooth.begin(38400);
    car.setSafeDistance(20);
    car.setSpeed(150);
}

void loop() {
    if (bluetooth.available()) {
        char bIn = bluetooth.read();
        Serial.print(bIn);
        switch (bIn) {
        case 'Q': car.frontLeft(); break;
        case 'L': car.left(); break;
        case 'Z': car.backLeft(); break;
        case 'E': car.frontRight(); break;
        case 'R': car.right(); break;
        case 'C': car.backRight(); break;
        case 'G': car.back(); break;
        case 'F':
            if (car.isSafe()) car.front(); 
            else car.stop();
            break;
        
        
        case 'S': car.stop(); break;
        case 'J': car.setSpeed(bluetooth.readNumber()); break;
        case 'K': car.setSafeDistance(bluetooth.readNumber()); break;
        case 'M': car.lightOn(); break;
        case 'm': car.lightOff(); break;
        case 'N': car.avoidObstaclesOn(); break;
        case 'n': car.avoidObstaclesOff(); break;
        default: break;
        }
    }
    static unsigned long lastPingTime = 0;
    unsigned long currentMillis = millis();
    if (currentMillis - lastPingTime >= 60) {
        lastPingTime = currentMillis;
        if (!car.isSafe()) {
            car.stop();
            car.warningOn();
        }
        else {
            car.warningOff();
        }
    }   
}