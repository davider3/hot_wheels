#include <Arduino.h>

String sendMessage;
String receivedMessage;

void setup(){
  // SETUP UP INTERNAL LEDS
  pinMode(11, OUTPUT); // RED
  pinMode(12, OUTPUT); // GREEN
  pinMode(13, OUTPUT); // BLUE
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);

  // SETUP SERIAL MONITOR
  Serial.begin(9600);
  delay(25);

  // SETUP UART COMMUNICATION WITH SERIAL
  Serial1.begin(9600);
  digitalWrite(11, LOW);
  Serial.println("Connected");
  delay(25);
}

void loop(){
  while (Serial1.available() > 0) {
    char receivedChar = Serial1.read();

    if (receivedChar == '\n') {
      // Print the received message in the Serial monitor
      Serial.println(receivedMessage);
      // Reset the received message
      receivedMessage = "";
    } else {
      // Append characters to the received message
      receivedMessage += receivedChar;  
    }
  }
}