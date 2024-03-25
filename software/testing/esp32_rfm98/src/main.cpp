#include <Arduino.h>
#include <SPI.h>
#include <RH_RF95.h>

#define RFM95_CS 10
#define RFM95_RST 9
#define RFM95_INT 2

RH_RF95 rf95(RFM95_CS, RFM95_INT);

bool state;

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);

  Serial.begin(9600);

  state = 1;

  digitalWrite(BUILTIN_LED, state);
}

void loop() {
  
}
