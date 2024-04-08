/* 
 * Project to be uploaded to a RC controller
 * Created By David Reinhardt
 */

#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include "params.h"
#include "Controller.h"

Controller control;

void setup() {
    control = Controller();
}

void loop() {
    control.control();
    delay(100);
}