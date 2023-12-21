#include <Arduino.h>
#include <Servo.h>
#include "Eyes/eyes.h"
#include "legs/crawlf.h"
#include "Mouth/mouth.h"
#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);  // RX, TX pins on Arduino Mega

void processBluetoothData(const String& data);

bool crawl = false;
int counter = 0;

void setup() {
  Serial.begin(115200);  // Initialize Serial for debugging
  BTSerial.begin(115200);  // Initialize SoftwareSerial for Bluetooth
  initEyes();
  initLegs();
  initMouth();
}

void loop() {
  if (counter == 0) {
    // Your initialization code here...
    // This part will run only once at the beginning.

    crawl = true;
  }

  counter++;

  // Your main loop code here...

  // Handle Bluetooth commands
  if (BTSerial.available()) {
    String receivedData = BTSerial.readStringUntil('\n');
    processBluetoothData(receivedData);
  }
}

void processBluetoothData(const String& data) {
  // Process the received data and perform corresponding actions
  if (data == "crawl_forward") {
    crawlForward();
  } else {
    // Handle other commands or data as needed
  }
}
