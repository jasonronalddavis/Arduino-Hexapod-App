#include <Arduino.h>
#include <Servo.h>
#include "Eyes/eyes.h"
#include "legs/crawlf.h"
#include "Mouth/mouth.h"
#include <Wire.h>

#define espSerial Serial1

bool isBTSerialAvailable();
void processBluetoothData(const String& data);

void setup() {
  Serial1.begin(115200);  // Initialize Serial1 for debugging
  espSerial.begin(115200);  // Use Serial1 for communication with ESP32
  initEyes();
  initLegs();
  initMouth();
  Serial1.println("Setup completed");
}

void loop() {
  // Process Bluetooth data if available
  if (Serial1.available()) {
    String receivedData = Serial1.readStringUntil('\n');
    processBluetoothData(receivedData);
  }

  // Your other code or delays as needed
  delay(100); // Adjust delay as needed
}


bool isBTSerialAvailable() {
  return espSerial.available() > 0;
}

void processBluetoothData(const String& data) {
  Serial1.print("Received data: ");
  Serial1.println(data);
  // Process the received data and perform corresponding actions
  if (data == "crawl_forward") {
    crawlForward();
  } else {
    // Handle other commands or data as needed
  }
}
