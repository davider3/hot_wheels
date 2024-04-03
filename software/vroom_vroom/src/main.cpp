#include <Arduino.h>
#include "Camera.h"
#include "Car.h"
#include "params.h"

// const char* ssid = "Helm's Depot";
// const char* password = "sweetballoon047";

const char* ssid = "David";
const char* password = "ckmh013$";

IPAddress ip;
Car car;

void setup() {

  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  ip = camSetup(ssid, password);
  
  car = Car(FORWARD, BACKWARD, STEERING, LIGHTS, -1);
}

void loop() {

  car.drive();

  Serial.println(ip);
}