#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <Arduino.h>
#include "params.h"
#include "Comms.h"
#include "Display.h"

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
    // TODO: implement screen code
    // Display screen;

    void throttleCalc();
    void steerCalc();
    void calibrate();

public:

    Controller();
    Controller(bool);

    void control();

};

#endif