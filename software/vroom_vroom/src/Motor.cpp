#include "Motor.h"

Motor::Motor(){
    
}

Motor::Motor(int go, int back, int en){
    goPin = go;
    backPin = back;
    enPin = en;
    pinMode(goPin, OUTPUT);
    pinMode(backPin, OUTPUT);
    if(enPin != -1){
        pinMode(enPin, OUTPUT);
    }
}

void Motor::forward(int val){
    analogWrite(backPin, 0);
    analogWrite(goPin, val);
}

void Motor::backward(int val){
    analogWrite(goPin, 0);
    analogWrite(backPin, val);
}

void Motor::power(bool turnOn){
    if(enPin != -1){
        digitalWrite(enPin, turnOn);
    }
}