#include "Car.h"
#include "params.h"

Car::Car(){
    motor = Motor(FORWARD, BACKWARD, ENPIN);
    steer.attach(STEERING);
    headlights = LIGHTS;
    pinMode(headlights, OUTPUT);
    radio = Comms();
};

void Car::drive(){
    radio.checkComm();

    if(radio.getDir()){
        motor.forward(radio.getThrottle());
    }else{
        motor.backward(radio.getThrottle());
    }

    steer.write(radio.getSteeing());

    digitalWrite(headlights, radio.getLights());
}