#include "Car.h"
#include "params.h"

Car::Car(){
    motor = Motor(FORWARD, BACKWARD, ENPIN);
    steer.attach(STEERING);
    headlights = LIGHTS;
    pinMode(headlights, OUTPUT);
    Serial.println("Connecting to comms");
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

    // steer.write(radio.getSteeing());

    digitalWrite(headlights, radio.getLights());
}

void Car::sendIP(IPAddress ip){
    // radio.sendSignal(ip);
}

void Car::printDebug(){
    // Serial.print("Throttle: ");
    // Serial.print(radio.getThrottle());
    // Serial.print(radio.getDir() ? " Forward " : " Backward ");
    // Serial.print("Steering: ");
    // Serial.print(radio.getSteeing());
    // Serial.print(" Lights are ");
    // Serial.println(radio.getLights() ? "on" : "off");
}