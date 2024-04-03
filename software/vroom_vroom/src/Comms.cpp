#include "Comms.h"
#include "params.h"

Comms::Comms(){
    LoRa.setPins(NSS, RESET, INTERRUPT);
    if(!LoRa.begin(RAD_FREQ)){
        // TODO: turn on builtin LED
        while(1);
    }
    LoRa.setSyncWord(0x34);
}

void Comms::checkComm(){
    i = 0;
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
        while(LoRa.available()){
            // GET THROTTLE DATA
            if(i<1){
                dir = (char)LoRa.read();
            }
            if(i<4){
                throttle[i] = (char)LoRa.read();
            }
            // GET STEERING DATA
            else if(i<7){
                steering[i-3] = (char)LoRa.read();
            }
            // GET LIGHTS
            else if(i<8){
                lights = (char)LoRa.read();
            }
            ++i;
        }
    }
}

int Comms::getLights(){
    return String(lights).toInt();
}

int Comms::getSteeing(){
    return String(steering).toInt();
}

int Comms::getThrottle(){
    return String(throttle).toInt();
}

int Comms::getDir(){
    return String(dir).toInt();
}

