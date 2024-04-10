#ifndef COMMS_H_
#define COMMS_H_

#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

class Comms{
private:
    char fast[4];
    char angle[4];
    char ipAddress[16] = {'-', '-', '-', '-',
                          '-', '-', '-', '-',
                          '-', '-', '-', '-',
                          '-', '-', '-', '-'};
    int i = 0;

public:
    Comms();

    void sendSignal(int dir, int speed, int steer, int lights);

    bool checkComm();

    String getIPAddress();

};


#endif