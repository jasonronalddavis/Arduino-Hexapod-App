#include <ESP32Servo.h>
#include <Arduino.h>
#include "Eyes/eyes.h"
#include "legs/crawlf.h"
#include "Mouth/mouth.h"
#include "test/test.h"
#include "test/lifttest.h"
#include <Wire.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// Forward declaration
void processReceivedData(const char* data);

BLEServer* pServer = NULL;
BLECharacteristic* pCharacteristic = NULL;
bool deviceConnected = false;
int txValue = 0;

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID_RX "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
    Serial.println("Device connected");
  }

  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
    Serial.println("Device disconnected");
  }
};

class MyCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic* pCharacteristic) {
    std::string rxValue = pCharacteristic->getValue();
    if (rxValue.length() > 0) {
      Serial.print("Received Value: ");
      Serial.println(rxValue.c_str());

      // Process the received data
      processReceivedData(rxValue.c_str());
    }
  }
};

void processReceivedData(const char* data) {
  // Implement your logic to handle the received data
  // For example, you can use a switch statement to perform different actions based on data
  // Ensure to replace this with your desired logic


  int dataAsInt = atoi(data);
if (dataAsInt == 83){
testStretch();
}
if (dataAsInt == 70){
testLift();
}
  // Add more processing logic as needed
}

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);  // Initialize Serial1 for debugging

  initEyes();
  initLegs();
  initMouth();
  initTest();
  initLift();
  Serial1.println("Setup completed");

  BLEDevice::init("PEANUT");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService* pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID_RX,
      BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristic->setCallbacks(new MyCallbacks());

  pService->start();
  BLEAdvertising* pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
  Serial.println("Waiting for a client connection to notify...");
}

void loop() {
  // Process Bluetooth data if available
  while (Serial1.available()) {
    String receivedData = Serial1.readStringUntil('\n');
    
    // Print the received data
    Serial1.println(receivedData);

    // Process the received data
    processReceivedData(receivedData.c_str());
  }

  if (deviceConnected) {
    // Send data to ESP32 if needed
    pCharacteristic->setValue("Hello from ESP32");
    pCharacteristic->notify();
    delay(1000);
  }

  // Your other loop logic here
}
