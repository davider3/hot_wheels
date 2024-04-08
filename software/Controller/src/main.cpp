#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include "params.h"
#include "Controller.h"

Controller control;

void setup() {

}

void loop() {
    control.control();
    delay(100);
}