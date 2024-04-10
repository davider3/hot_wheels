#include "Comms.h"
#include "params.h"

Comms::Comms(){
    LoRa.setTxPower(20);
    LoRa.setPins(NSS, RESET, DI00);
    if(!LoRa.begin(RAD_FREQ)){
        Serial.println("LoRa initialization failed");
        digitalWrite(LED_BUILTIN, HIGH);
        while(1);
    }
    LoRa.setSyncWord(0x34);
}

void Comms::sendSignal(int dir, int speed, int steer, int lights){

    snprintf(fast, sizeof(fast), "%03d", speed);

    snprintf(angle, sizeof(angle), "%03d", steer);

    LoRa.beginPacket();
    LoRa.print(dir);
    LoRa.print(fast);
    LoRa.print(angle);
    LoRa.print(lights);
    LoRa.endPacket();
}

void Comms::checkComm(){
    i = 0;
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
        while(LoRa.available()){
            // GET THROTTLE DATA
            ipAddress[i] = (char)LoRa.read();
            ++i;
        }
    }
}