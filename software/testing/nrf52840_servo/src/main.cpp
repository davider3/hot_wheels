#include <Arduino.h>
#include <Servo.h>

#define RED 11
#define GREEN 12
#define BLUE 13
#define PIN D0

// DECLARE SERVO OBJECT
Servo steering;

void setup(){
  // SETUP LEDS
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);

  // SETUP SERVO
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

