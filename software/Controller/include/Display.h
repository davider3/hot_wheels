#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "params.h"

class Display{
private:
    String ipAddress;

public:
    Display();

    void showIP(String ip);

};


#endif