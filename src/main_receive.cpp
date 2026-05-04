#include <Arduino.h>

HardwareSerial MySerial(2);

#define LED_PIN 13

void setup() {
  Serial.begin(9600);
  MySerial.begin(9600, SERIAL_8N1, 15, 14); // RX, TX

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println("Receiver started");
}

void loop() {
  if (MySerial.available()) {

    String msg = MySerial.readStringUntil('\n');
    msg.trim(); 

    Serial.print("Received: ");
    Serial.println(msg);

    if (msg == "HELLO") {
      Serial.println("blinking LED");
      digitalWrite(LED_PIN, HIGH);
      delay(500);
      digitalWrite(LED_PIN, LOW);
    }
  }
}