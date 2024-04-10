#ifndef COMMS_H_
#define COMMS_H_

#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

class Comms{
private:
    char dir = '1';
    char throttle[3] = {'0', '0', '0'};
    char steering[3] = {'0', '9', '0'};
    char lights = '0';
    char send[16];
    int i = 0;

public:
    Comms();

    void checkComm();
    void sendSignal(IPAddress ip);

    int getThrottle();
    int getSteeing();
    int getLights();
    int getDir();

};


#endif