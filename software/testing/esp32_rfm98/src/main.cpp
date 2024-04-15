#include <SPI.h>
#include <LoRa.h>
#include <Arduino.h>
char rec[8];
int i = 0;
int val = 0;
char vals[8];
char pot1[4];

#define RESET 6
#define NSS 7
#define DI00 2

bool state = 0;
char dir = '1';
char throttle[3] = {'0', '0', '0'};
char steering[3] = {'0', '9', '0'};
char lights = '0';

void setup() {
  Serial.begin(9600);
  LoRa.setPins(NSS, RESET, DI00);
  if (!LoRa.begin(433000000)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  delay(5000);
  Serial.println("Connected!");
  LoRa.setSyncWord(0x34);

  pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
  i = 0;
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    while (LoRa.available()) {
      // vals[i] = (char)LoRa.read();
      // i++;
      // Serial.print(i);
      // Serial.print(": ");
      // Serial.println(vals[i-1]);
                  // GET THROTTLE DATA
      if(i<1){
          dir = (char)LoRa.read();
      }
      if(i<4){
          throttle[i] = (char)LoRa.read();
      }
      // GET STEERING DATA
      else if(i<7){
          steering[i-3] = (char)LoRa.read();
      }
      // GET LIGHTS
      else if(i<8){
          lights = (char)LoRa.read();
      }
      ++i;
    }
    // val = String(rec).toInt();
    Serial.println(String(vals).toInt());
  }
}
