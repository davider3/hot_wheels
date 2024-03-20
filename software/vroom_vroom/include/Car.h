#ifndef CAR_H_
#define CAR_H_

#include <Arduino.h>
#include "Comms.h"
#include "Motor.h"
// #include "Servo.h"

class Car{
private:
    int headlights;
    Motor motor;
    // Servo steer;
    Comms radio;

public:
    Car();

    Car(int, int, int, int, int);

    void drive();

};


#endif