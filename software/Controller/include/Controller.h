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

    Comms radio;

public:

    Controller();

    void control();

};

#endif