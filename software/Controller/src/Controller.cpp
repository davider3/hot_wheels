#include "Controller.h"

Controller::Controller(){
    pinMode(JOYSTICK, INPUT);
    pinMode(TRIGGER, INPUT); 
    pinMode(LIGHTS, INPUT);
    throttle = 0;
    steer = 90;
    lights = 0;
    dir = 1;

    calibrate();

    radio = Comms();

    // TEST
    while(radio.checkComm());
    screen.showIP(radio.getIPAddress());

}

void Controller::calibrate(){
    throttleBias = 0;
    steerBias = 0;

    for(i = 0; i < 10; ++i){
        throttleBias += analogRead(TRIGGER);
        steerBias += analogRead(JOYSTICK);
    }

    steerBias = steerBias / 10;
    throttleBias = throttleBias / 10;
}

void Controller::control(){
    throttleCalc();
    steerCalc();
    lights = digitalRead(LIGHTS);

    Serial.print("Throttle: ");
    Serial.print(throttle);
    Serial.print(dir ? " forward " : " backward ");
    Serial.print("Turn: ");
    Serial.print(steer);
    Serial.print(" Lights are ");
    Serial.println(lights ? "on" : "off");

    radio.sendSignal(dir, throttle, steer, lights);
}

void Controller::throttleCalc(){
    throttle = analogRead(TRIGGER);

    if(throttle > throttleBias - 20 && throttle < throttleBias + 20){
        dir = 1;
        throttle = 0;
    } else if(throttle < throttleBias){
        dir = 0;
        // TODO: increase 0 to whatever value starts to spin the motors
        throttle = map(throttle, throttleBias, 0, 0, 255);
    } else if(throttle > throttleBias){
        dir = 1;
        // TODO: increase 0 to whatever value starts to spin the motors
        throttle = map(throttle, throttleBias, 4095, 0, 255);
    }else{
        dir = 1;
        throttle = 0;
    }
}

void Controller::steerCalc(){
    steer = analogRead(JOYSTICK);

    if(steer < steerBias){
        steer = map(steer, 0, steerBias, 0, 90);
    }else{
        steer = map(steer, steerBias, 4095, 90, 180);
    }
}