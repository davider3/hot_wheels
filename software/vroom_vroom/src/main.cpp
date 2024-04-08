/* 
 * Project to be uploaded to a RC FPV HotWheels Car
 * Created By David Reinhardt
 */

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

  // TODO: send the ip to the controller
}