#include <Arduino.h>
#include <Servo.h>
#include "Eyes/eyes.h"
#include "legs/crawlf.h"
#include "Mouth/mouth.h"
#include <Wire.h>

#define espSerial Serial1
bool stand = false;
bool test_90 = false;
bool test_0 = false;
bool stretchBool = false;
int counter = 0;


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
stretch();

  // Process Bluetooth data if available
  if (Serial1.available()) {
    String receivedData = Serial1.readStringUntil('\n');
    processBluetoothData(receivedData);
  }

  // Your other code or delays as needed
  delay(1000); // Adjust delay as needed
}



void processBluetoothData(const String& data) {
  Serial1.print("Received data: ");
  Serial1.println(data);
if (data == 70){
test90();
//Servo moves to 90 degrees
}
if (data == 66){
test90();
//Servo moves to 0 degrees
}
  // Execute crawlForward() for any received data
 
}
