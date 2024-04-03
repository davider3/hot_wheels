#include "Comms.h"
#include "params.h"

Comms::Comms(){
    LoRa.setTxPower(20);
    LoRa.setPins(NSS, RESET, DI00);
    if(!LoRa.begin(RAD_FREQ)){
        // TODO: turn on builtin LED
        while(1);
    }
    LoRa.setSyncWord(0x34);
}

void Comms::sendSignal(int dir, int speed, int steer, int lights){

    char fast[4];
    snprintf(fast, sizeof(fast), "%03d", speed);

    char angle[4];
    snprintf(angle, sizeof(angle), "%03d", steer);

    LoRa.beginPacket();
    LoRa.print(dir);
    LoRa.print(fast);
    LoRa.print(angle);
    LoRa.print(lights);
    LoRa.endPacket();
}