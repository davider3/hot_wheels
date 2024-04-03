#include <Arduino.h>
#include "Camera.h"
#include "Car.h"
#include "params.h"

IPAddress ip;
Car car;

void setup() {

  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  ip = camSetup(ssid, password);
  
  car = Car();
}

void loop() {

  car.drive();

  Serial.println(ip);
}