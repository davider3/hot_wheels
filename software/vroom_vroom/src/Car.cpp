#include "Car.h"

Car::Car(){
    
}

Car::Car(int mtrPin1, int mtrPin2, int servoPin, int lights, int enPin){
    motor = Motor(mtrPin1, mtrPin2, enPin);
    // steer.attach(servoPin);
    headlights = lights;
    pinMode(headlights, OUTPUT);
};

void Car::drive(){
    // TODO: read from comms
    int values[4] = {1, 255, 180, 1};

    if(values[0] == 0){
        motor.forward(values[1]);
    }else{
        motor.backward(values[1]);
    }

    // steer.write(values[2]);

    digitalWrite(headlights, values[3]);
}