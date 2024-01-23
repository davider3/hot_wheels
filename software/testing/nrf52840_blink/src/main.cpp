#include <Arduino.h>

void setup(){
  pinMode(11, OUTPUT); // RED
  pinMode(12, OUTPUT); // GREEN
  pinMode(13, OUTPUT); // BLUE
}

void loop(){
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}