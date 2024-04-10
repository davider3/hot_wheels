#include "Car.h"
#include "params.h"

Car::Car(){
    motor = Motor(FORWARD, BACKWARD, ENPIN);
    steer.attach(STEERING);
    headlights = LIGHTS;
    pinMode(headlights, OUTPUT);
    radio = Comms();
};


/// @brief this is the main function to control the car.
///        It will get messages from the radio controller
///        and then write those values to the actuators
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

void Car::sendIP(IPAddress ip){
    radio.sendSignal(ip);
}