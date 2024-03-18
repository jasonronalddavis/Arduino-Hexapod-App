#include <Arduino.h>
#include <NimBLEDevice.h>
#include <NimBLEServer.h>
#include <NimBLEUtils.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include "Eyes/eyes.h"
#include "legs/crawlf.h"
#include "Mouth/mouth.h"
#include "test/test.h"
#include <Adafruit_PWMServoDriver.h>


NimBLEServer* pServer = nullptr;
NimBLECharacteristic* pCharacteristic = nullptr;
bool deviceConnected = false;

void processReceivedData(const char* data);

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID_RX "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class MyCallbacks : public NimBLECharacteristicCallbacks {
  void onWrite(NimBLECharacteristic* pCharacteristic) {
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
  int dataAsInt = atoi(data);
  if (dataAsInt == 83) {
      Serial.println("test"); //if dataAsInt == 83, if servoInitialized is truthy, Serial.println("test"); and testStretch();
      testStretch(); // Call testStretch() if data is 83 and servos are initialized
  }
  if (dataAsInt == 70) {    
       Serial.println("lift");
       testLift();
}
}


void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  NimBLEDevice::init("PEANUT");
  pServer = NimBLEDevice::createServer();
  NimBLEService* pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID_RX,
      NIMBLE_PROPERTY::WRITE | NIMBLE_PROPERTY::NOTIFY);
  pCharacteristic->setCallbacks(new MyCallbacks());

  pService->start();
  NimBLEAdvertising* pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
  
  // Attach servo motors to serial pins
  initPca();
}

void loop() {
  while (Serial1.available()) {
    String receivedData = Serial1.readStringUntil('\n');
    Serial1.println(receivedData);
    processReceivedData(receivedData.c_str());
  }
}
