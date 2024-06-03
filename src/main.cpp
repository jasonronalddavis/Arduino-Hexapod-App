//main.cpp
#include <Arduino.h>
#include <NimBLEDevice.h>
#include <NimBLEServer.h>
#include <NimBLEUtils.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
#include "Eyes/eyes.h"
#include "legs/crawlf.h"
#include "Mouth/mouth.h"
#include "test/test.h"

NimBLEServer* pServer = nullptr;
NimBLECharacteristic* pCharacteristic = nullptr;
bool deviceConnected = false;
bool crawlf = false; // Variable to track crawling motion
bool crawlb = false; // Variable to track crawling motion
bool eyeY = false;
bool eyeX = false;
bool blink_up = false;
bool blink_down;
bool mouth = false;

void processReceivedData(const char* data);
// void moveEye(int data); // Function prototype declaration

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID_RX "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class MyCallbacks : public NimBLECharacteristicCallbacks {
 void onWrite(NimBLECharacteristic* pCharacteristic) {
    std::string rxValue = pCharacteristic->getValue();
    
    if (rxValue.length() > 0) {
        processReceivedData(rxValue.c_str());
    }
}
   void onConnect(NimBLEServer* pServer) {
    Serial.println("Connected!");
    Serial1.println("success");
  }
  void onDisconnect(NimBLEServer* pServer) {
    Serial.println("Disconnected!");
  }
};

void processReceivedData(const char* data) {
    int dataAsInt = atoi(data);
    Serial.print("-Axis to: "); 
      if (dataAsInt == 20){
    mouthDown();
  }
  if (dataAsInt == 21){
    mouthUp();
  }
  if (strncmp(data, "x", 1) == 0){
    int eyeData = atoi(data + 1);
     moveEyeballX(eyeData);
    Serial.print("Adjusting Eyeball ");
    Serial.println("x");
    Serial.println(eyeData); 
    crawlf = false;
  }
  if (strncmp(data, "y", 1) == 0) {
    int eyeData = atoi(data + 1);
    moveEyeballY(eyeData);
    Serial.print("Adjusting Eyeball ");
    Serial.println("y");
    Serial.println(eyeData); 
    crawlf = false;
  }
  if (strncmp(data, "e", 1) == 0) {
    int eyeData = atoi(data + 1);
    eyeLid(eyeData);
    Serial.print("Adjusting Eyeball ");
    Serial.println("e");
    Serial.println(eyeData); 
    crawlf = false;
  }
  if (strncmp(data, "S", 1) == 0){
    Serial.println("Stretching..."); 
    testStretch();
    crawlf = false;
  }
  if (strncmp(data, "U", 1) == 0) {    
    Serial.println("Lifting and Standing..."); 
    testLift();
    crawlf = false;
  }
  if (strncmp(data, "B", 1) == 0){
    Serial.println("bending..."); 
      testBend();
      crawlf = false;
  }
  if (strncmp(data, "T", 1) == 0) {    
    Serial.println("Lifting and Standing..."); 
    testStand();
    mouth = false;
    crawlf = false;
  }
  if (strncmp(data, "F", 1) == 0) {    
    Serial.println("Crawling forward..."); 
    crawlf = true;
    crawlb = false;
  }
    if (strncmp(data, "Z", 1) == 0) {    
    Serial.println("Crawling backward...");
    crawlb = true;
    crawlf = false;
  }
  if (strncmp(data, "d", 1) == 0) {    
       Serial.println("15");
       crawlf = false;
       mouth = false; 
      eyeX= false;
      eyeY= false;
       blinkUp();
  }
  if (strncmp(data, "b", 1) == 0){    
       Serial.println(dataAsInt); 
       crawlf = false;
       mouth = false;
      eyeX= false;
      eyeY= false;
       blinkDown();
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
  initTest();
  initMouth();
  initEyes();
}

void loop() {
//  crawlForward();
  while (Serial1.available()) {
    String receivedData = Serial1.readStringUntil('\n');
    processReceivedData(receivedData.c_str());
    // If crawlForward is true, continuously call the crawlForward function
}
if (crawlf == true){ 
crawlForward();
}
if (crawlb == true){ 
crawlBackward();
}
}