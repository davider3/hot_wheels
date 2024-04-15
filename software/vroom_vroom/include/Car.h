#ifndef CAR_H_
#define CAR_H_

#include <Arduino.h>
#include "Comms.h"
#include "Motor.h"
#include "s3servo.h"

class Car{
private:
    int headlights;
    Motor motor;
    s3servo steer;
    Comms radio;

public:
    Car();

    void drive();
    void sendIP(IPAddress ip);
    void printDebug();
};


#endif