#include "Car.h"

Car::Car(){
    
}

Car::Car(int mtrPin1, int mtrPin2, int servoPin, int lights, int enPin){
    motor = Motor(mtrPin1, mtrPin2, enPin);
    steer.attach(servoPin);
    headlights = lights;
    pinMode(headlights, OUTPUT);
};

void Car::drive(){
    // TODO: read from comms
    radio.checkComm();

    if(radio.getDir()){
        motor.forward(radio.getThrottle());
    }else{
        motor.backward(radio.getThrottle());
    }

    steer.write(radio.getSteeing());

    digitalWrite(headlights, radio.getLights());
}