// #include "ble.h"

// BLECharacteristic *pCharacteristic;
// BLEServer *pServer;
// BLEService *pService;

// void initBluetooth() {
//   // Create the BLE Server
//   pServer = BLEDevice::createServer();
//   pService = pServer->createService("4fafc201-1fb5-459e-8fcc-c5c9c331914b");

//   // Create a BLE Characteristic
//   pCharacteristic = pService->createCharacteristic(
//       "beb5483e-36e1-4688-b7f5-ea07361b26a8",
//       BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);

//   // Start the service
//   pService->start();

//   // Start advertising
//   BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
//   pAdvertising->addServiceUUID(SERVICE_UUID);
//   pAdvertising->setScanResponse(true);
//   pAdvertising->setMinPreferred(0x06);
//   pAdvertising->setMinPreferred(0x12);
//   BLEDevice::startAdvertising();
// }