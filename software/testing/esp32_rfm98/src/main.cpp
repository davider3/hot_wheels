#include <SPI.h>
#include <LoRa.h>
char rec[8];
int i = 0;
int val = 0;
char vals[8];
char pot1[4];

#define RESET 22
#define NSS 15
#define DI00 2

bool state = 0;

void setup() {
  Serial.begin(9600);
  LoRa.setPins(NSS, RESET, DI00);
  if (!LoRa.begin(433000000)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("Connected!");
  LoRa.setSyncWord(0x34);

  pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
  i = 0;
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    while (LoRa.available()) {
      vals[i] = (char)LoRa.read();
      i++;
      Serial.print(i);
      Serial.print(": ");
      Serial.println(vals[i-1]);
    }
    // val = String(rec).toInt();
    Serial.println(String(vals));
  }
}
