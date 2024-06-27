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
bool crawlf = false;
bool crawlb = false;
bool crawlL = false;
bool crawlr = false;
bool blink_up = false;
bool blink_down;

void processReceivedData(const char* data);

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

    // Reset all crawl states before setting a new one
    crawlf = false;
    crawlb = false;
    crawlL = false;
    crawlr = false;

    if (dataAsInt == 20) {
        mouthDown();
    } else if (dataAsInt == 21) {
        mouthUp();
    } else if (strncmp(data, "x", 1) == 0) {
        int eyeData = atoi(data + 1);
        moveEyeballX(eyeData);
        Serial.print("Adjusting Eyeball ");
        Serial.println("x");
        Serial.println(eyeData); 
    } else if (strncmp(data, "y", 1) == 0) {
        int eyeData = atoi(data + 1);
        moveEyeballY(eyeData);
        Serial.print("Adjusting Eyeball ");
        Serial.println("y");
        Serial.println(eyeData); 
    } else if (strncmp(data, "e", 1) == 0) {
        int eyeData = atoi(data + 1);
        eyeLid(eyeData);
        Serial.print("Adjusting Eyelid ");
        Serial.println("e");
        Serial.println(eyeData); 
    } else if (strncmp(data, "S", 1) == 0) {
        Serial.println("Stretching..."); 
        testStretch();
    } else if (strncmp(data, "U", 1) == 0) {
        Serial.println("Lifting and Standing..."); 
        testLift();
    } else if (strncmp(data, "B", 1) == 0) {
        Serial.println("Bending..."); 
        testBend();
    } else if (strncmp(data, "T", 1) == 0) {
        Serial.println("Standing..."); 
        testStand();
    } else if (strncmp(data, "F", 1) == 0) {
        Serial.println("Crawling forward..."); 
        crawlf = true;
    } else if (strncmp(data, "Z", 1) == 0) {
        Serial.println("Crawling backward...");
        crawlb = true;
    } else if (strncmp(data, "R", 1) == 0) {
        Serial.println("Crawling right...");
        crawlr = true;
    } else if (strncmp(data, "L", 1) == 0) {
        Serial.println("Crawling left...");
        crawlL = true;
    } else if (strncmp(data, "d", 1) == 0) {
        Serial.println("Blinking up...");
        blinkUp();
    } else if (strncmp(data, "b", 1) == 0) {
        Serial.println("Blinking down...");
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
        NIMBLE_PROPERTY::WRITE | NIMBLE_PROPERTY::NOTIFY
    );
    pCharacteristic->setCallbacks(new MyCallbacks());
    pService->start();
    NimBLEAdvertising* pAdvertising = pServer->getAdvertising();
    pAdvertising->start();
    initTest();
    initMouth();
    initEyes();
}

void loop() {
    if (Serial1.available()) {
        String receivedData = Serial1.readStringUntil('\n');
        processReceivedData(receivedData.c_str());
    }
    if (crawlf) {
        crawlForward();
    }
    if (crawlb) {
        crawlBackward();
    }
    if (crawlL) {
        crawlLeft();
    }
    if (crawlr) {
        crawlRight();
    }
}
