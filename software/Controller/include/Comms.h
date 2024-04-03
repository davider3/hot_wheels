#ifndef COMMS_H_
#define COMMS_H_

#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

class Comms{
private:


public:
    Comms();

    void sendSignal(int dir, int speed, int steer, int lights);

};


#endif