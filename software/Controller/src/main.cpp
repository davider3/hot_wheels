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

    Serial.begin(9600);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    control = Controller();
    digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
    control.control();
    delay(50);
}