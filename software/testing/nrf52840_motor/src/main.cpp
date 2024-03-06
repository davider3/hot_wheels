#include <Arduino.h>

#define RED 11
#define GREEN 12
#define BLUE 13
#define MTR1 2
#define MTR2 3

void setup(){
  // DEFINE RGB LED PINS AS OUTPUTS
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // DEFINE MOTOR PINS AS OUTPUTS
  pinMode(MTR1, OUTPUT);
  pinMode(MTR2, OUTPUT);

  // START SERIAL MONITOR
  Serial.begin(9600);

}

void loop(){
  analogWrite(MTR2, 255);
}