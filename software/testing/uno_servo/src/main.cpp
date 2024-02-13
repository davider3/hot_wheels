#include <Arduino.h>
#include <Servo.h>

#define PIN 9

Servo steering;

void setup() {
  steering.attach(PIN);
}

void loop() {
  for(int i=0; i<=180; ++i){
    steering.write(i);
    delay(10);
  }
  for(int i=180; i>=0; --i){
    steering.write(i);
    delay(10);
  }
}
