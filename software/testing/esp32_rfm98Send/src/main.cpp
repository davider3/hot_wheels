#include <SPI.h>
#include <LoRa.h>
char rec[8];
int i = 0;
int val = 0;

#define RESET 5
#define NSS 15
#define DI00 2

int device_id = 8642;

void setup() {
  LoRa.setTxPower(20);
  Serial.begin(9600);
  LoRa.setPins(NSS, RESET, DI00);
  if (!LoRa.begin(433000000)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("Connected!");
  LoRa.setSyncWord(0x34);

  pinMode(4, INPUT);
}

void loop() {

  val = analogRead(4)/16;

  char string[4];
  int data = 1010;
  snprintf(string, sizeof(string), "%03d", val);
  Serial.println(string);

  // Serial.println(val);
  LoRa.beginPacket();
  LoRa.print(string);
  LoRa.print("250");
  LoRa.print("1");
  LoRa.endPacket();
  delay(250);
}
