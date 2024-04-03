#include "Comms.h"
#include "params.h"

Comms::Comms(int ss, int rst, int inter){
    LoRa.setPins(ss, rst, inter);
    if(!LoRa.begin(RAD_FREQ)){
        // TODO: turn on builtin LED
        while(1);
    }
    LoRa.setSyncWord(0x34);
}

void Comms::receiveComm(){
    i = 0;
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
        while(LoRa.available()){
            // GET THROTTLE DATA
            if(i<3){
                throttle[i] = (char)LoRa.read();
            }
            // GET STEERING DATA
            else if(i<6){
                steering[i-3] = (char)LoRa.read();
            }
            // GET LIGHTS
            else if(i<7){
                lights = (char)LoRa.read();
            }
            ++i;
        }
    }
}

int Comms::getLights(){
    
}

