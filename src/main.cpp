//IMPORTING MORE THAN ONE FUNCTION STOP BLE SERVER
#include <Arduino.h>
// SET_LOOP_TASK_STACK_SIZE( 16*1024 );    // 16KiB Stack Size
#include <NimBLEDevice.h>
#include <NimBLEServer.h>
#include <NimBLEUtils.h>
//  #include <NimBLE2902.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include "Eyes/eyes.h"
#include "legs/crawlf.h"
#include "Mouth/mouth.h"
#include "test/test.h"
#include "test/lifttest.h" // BLUETOOTH STOPS BROADCASTING WHEN I UTILIZE
//A FUNCTION WITHIN THIS FILE. FUNCTION initLift(); IS PLACED WITHIN SETUP 



// Forward declaration
void processReceivedData(const char* data);

NimBLEServer* pServer = nullptr;
NimBLECharacteristic* pCharacteristic = nullptr;
bool deviceConnected = false;
int txValue = 0;

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
  // Implement your logic to handle the received data
  // For example, you can use a switch statement to perform different actions based on data
  // Ensure to replace this with your desired logic

  int dataAsInt = atoi(data);
  if (dataAsInt == 83){
    testStretch();
  }
  // Add more processing logic as needed
}

void setup() {
  initTest();
  initLift(); // BLUETOOTH STOPS BROADCASTING WHEN I UTILIZE
//A FUNCTION WITHIN THIS FILE
  Serial.begin(115200);
  Serial1.begin(115200);  // Initialize Serial1 for debugging
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
