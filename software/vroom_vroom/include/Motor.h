#ifndef MOTOR_H_
#define MOTOR_H_

#include <Arduino.h>

class Motor{
private:
    int goPin;
    int backPin;
    int enPin;

public:
    Motor(int, int, int);

    void forward(int);

    void backward(int);

    void power(bool);

};


#endif