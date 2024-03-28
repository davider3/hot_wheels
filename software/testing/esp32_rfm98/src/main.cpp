#include <Arduino.h>
#include <SPI.h>
#include <RH_RF95.h>

#define RFM95_CS 17
#define RFM95_RST 16
#define RFM95_INT 2
#define RFM95_FREQ 433.0

RH_RF95 rf95(RFM95_CS, RFM95_INT);

void setup() {
    Serial.begin(9600);
    
    // RESET THE MODULE
    pinMode(RFM95_RST, OUTPUT);
    digitalWrite(RFM95_RST, HIGH);
    delay(10);
    digitalWrite(RFM95_RST, LOW);
    delay(10);
    digitalWrite(RFM95_RST, HIGH);
    delay(10);

    // SETUP LORA MODULE
    if (!rf95.init()) {
        Serial.println("RFM95 initialization failed!");
        while (1);
    }
    rf95.setFrequency(RFM95_FREQ);
    rf95.setTxPower(23, false);
}

void loop() {
    if (rf95.available()) {
        uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
        uint8_t len = sizeof(buf);
        if (rf95.recv(buf, &len)) {
            Serial.print("Received: ");
            Serial.println((char*)buf);
        }
    }
    // Send a message
    const char* message = "Hello, LoRa!"; // Your message here
    rf95.send((uint8_t*)message, strlen(message)); // Corrected arguments
    rf95.waitPacketSent();
    delay(1000);
}
