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

/// @brief checks if a message is being received.
///        If yes then it parses the message and 
///        saves the data
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

/// @brief Gets value for the lights
/// @return 1 for lights on
///         0 for lights off
int Comms::getLights(){
    return String(lights).toInt();
}

/// @brief Gets value for the steering
/// @return integer in range 0-180
int Comms::getSteeing(){
    return String(steering).toInt();
}

/// @brief Gets value for the throttle
/// @return integer in range 0-255
int Comms::getThrottle(){
    return String(throttle).toInt();
}

/// @brief Gets value for the direction to drive
/// @return 1 for forwards
///         0 for backwards
int Comms::getDir(){
    return String(dir).toInt();
}

