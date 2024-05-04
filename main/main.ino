#include "car.h"
#include "Bluetooth.h"

Bluetooth bluetooth(8, 9);
Car car(Motor(2, 4, 3, 0), Motor(7, 5, 6, 0), UltraSonic(10, 11, 500), Light(12));


void setup() {
    Serial.begin(38400);
    bluetooth.begin(38400);
    car.setSafeDistance(20);
    car.setSpeed(150);
}

void loop() {
    if (bluetooth.available()) {
        char bIn = bluetooth.read();
        switch (bIn) {
        case 'Q':
        case 'L':
        case 'Z': car.left(); break;
        case 'E':
        case 'R':
        case 'C': car.right(); break;
        case 'F':
            if (car.isSafe()) car.front(); 
            else car.stop();
            break;
        
        case 'G': car.back(); break;
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
            car.warning();
        }
    }   
}