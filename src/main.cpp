#include <Arduino.h>

HardwareSerial MySerial(2);

void setup() {
  Serial.begin(115200); // USB debug
  MySerial.begin(9600, SERIAL_8N1, 15, 14); // RX, TX

  Serial.println("Sender started");
}

void loop() {
  MySerial.println("HELLO");
  Serial.println("Sent: HELLO");

  delay(1000);
}