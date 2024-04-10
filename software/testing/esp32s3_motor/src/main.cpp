#include <Arduino.h>

#define MTR1 0
#define MTR2 1

void setup(){

  // DEFINE MOTOR PINS AS OUTPUTS
  pinMode(MTR1, OUTPUT);
  pinMode(MTR2, OUTPUT);

  // START SERIAL MONITOR
  Serial.begin(9600);

}

void loop(){
  analogWrite(MTR2, 120);
  Serial.println("yup");
  delay(1000);
}