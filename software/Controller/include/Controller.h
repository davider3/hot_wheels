#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <Arduino.h>
#include "params.h"
#include "Comms.h"

class Controller{
private:
    int throttle;
    int steer;
    int lights;
    int dir;
    int throttleBias;
    int steerBias;
    int i;

    Comms radio;

    void throttleCalc();
    void steerCalc();
    void calibrate();

public:

    Controller();

    void control();

};

#endif