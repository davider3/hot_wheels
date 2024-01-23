#include <Arduino.h>

#define RED 11
#define GREEN 12
#define BLUE 13
#define MTR1 10
#define MTR2 9

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
  // for(int i=0; i<256; i+=10){
  //   Serial.println(i);
  //   analogWrite(MTR1, i);
  //   delay(1000);
  // }

}