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

// WIFI
// const char* ssid = "David";
// const char* password = "ckmh013$";
const char* ssid = "Helm's Depot";
const char* password = "sweetballoon047";

void setup() {
    Serial.begin(115200);
    Serial.setDebugOutput(true);

    delay(5000);
    Serial.println();
    Serial.println("Begin");

    // ip = camSetup(ssid, password);
    // Serial.println("Cam setup");
    
    car = Car();
    // car.sendIP(ip);
    Serial.println(ip);
}

void loop() {

    car.drive();
    car.printDebug();
    // Serial.println(ip);
    delay(100);
}