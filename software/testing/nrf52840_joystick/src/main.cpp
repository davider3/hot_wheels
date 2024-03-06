#include <Arduino.h>

#define X A5
#define Y A4
#define PUSH 3

void setup() {
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(PUSH, INPUT);

  // SETUP SERIAL MONITOR
  Serial.begin(9600);
  delay(100);
  Serial.println("Serial Began");
}

void loop() {
  Serial.print("X position: ");
  Serial.println(analogRead(X));
  Serial.print("Y position: ");
  Serial.println(analogRead(Y));
  Serial.print("Button: ");
  Serial.println(digitalRead(PUSH));
  delay(200);
}
