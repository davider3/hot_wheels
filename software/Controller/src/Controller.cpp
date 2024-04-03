#include "Controller.h"

Controller::Controller(){
    pinMode(JOYSTICK, INPUT);
    pinMode(TRIGGER, INPUT); 
    pinMode(LIGHTS, INPUT);
    throttle = 0;
    steer = 90;
    lights = 0;
    dir = 1;

    radio = Comms();
}

void Controller::control(){
    // TODO: logic to get speed and direction from joystick
    throttle = analogRead(TRIGGER) / 16;
    steer = analogRead(JOYSTICK) * 0.043945;
    lights = digitalRead(LIGHTS);

    radio.sendSignal(dir, throttle, steer, lights);
}