#include <SPI.h>
#include <LoRa.h>
#include <Arduino.h>

#define RESET D6
#define NSS D7
#define DI00 5
#define SCK D8  // SPI Clock
#define MISO D9  // SPI Data Master In Slave Out
#define MOSI D10  // SPI Data Master Out Slave In

char dir = '0';
char throttle[3] = {'0', '0', '0'};
char steering[3] = {'0', '9', '0'};
char lights = '0';
int i;
char vals[8];

void setup() {
  Serial.begin(9600);

  SPI.begin(SCK, MISO, MOSI, NSS);

  LoRa.setPins(NSS, RESET, DI00);
  Serial.println("Trying");
  if (!LoRa.begin(433000000)) {
    Serial.println("Starting LoRa failed!");
    while (1){
      Serial.println("FAIL");
    }
  }
  Serial.println("Connected!");
  LoRa.setSyncWord(0x34);

  // pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
  i = 0;
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    while (LoRa.available()) {
      vals[i] = (char)LoRa.read();
      ++i;
    }

    dir = vals[0];
    throttle[0] = vals[1] - '0'; 
    throttle[1] = vals[2] - '0';
    throttle[2] = vals[3] - '0';
    steering[0] = vals[4] - '0';
    steering[1] = vals[5] - '0';
    steering[2] = vals[6] - '0';
    lights = vals[7];

    int throttleValue = throttle[0] * 100 + throttle[1] * 10 + throttle[2];
    int steeringValue = steering[0] * 100 + steering[1] * 10 + steering[2];
    
    Serial.print("Throttle: ");
    // for (int j = 0; j < 3; ++j) {
    //   Serial.print(throttle[j]);
    // }
    Serial.print(throttleValue);
    Serial.print(String(dir).toInt() ? " Forward " : " Backward ");
    Serial.print("Steering: ");
    // for (int j = 0; j < 3; ++j) {
    //   Serial.print(steering[j]);
    // }
    Serial.print(steeringValue);
    Serial.print(" Lights are ");
    Serial.print(String(lights).toInt() ? "on" : "off");
    Serial.println();
    Serial.println(String(vals));
  }
}
