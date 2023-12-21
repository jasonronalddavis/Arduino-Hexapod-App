// I am having issues installing espressif32 in platformio ide. I have decided to choose
// a different bluetooth library that is compatible with my esp3S module. I am using a react
// app to transmit bluetooth commands to my hexapod robot. Here is a description of 
// NimBLE-Arduino by h2zero Bluetooth low energy (BLE) library for arduino-esp32 based on NimBLE.
// This is a more updated and lower resource alternative to the original bluedroid BLE library for esp32. Uses 50% less flash space
// and approximately 100KB less ram with the same functionality. Nearly 100% compatible with existing application code, migration guide included.
// Here is a code example

// /**
//  * A BLE client example that is rich in capabilities.
//  * There is a lot new capabilities implemented.
//  * author unknown
//  * updated by chegewara
//  * updated for NimBLE by H2zero
//  */
 
// /** NimBLE differences highlighted in comment blocks **/

// /*******original********
// #include "BLEDevice.h"
// ***********************/
// #include "NimBLEDevice.h"

// // The remote service we wish to connect to.
// static BLEUUID serviceUUID("4fafc201-1fb5-459e-8fcc-c5c9c331914b");
// // The characteristic of the remote service we are interested in.
// static BLEUUID    charUUID("beb5483e-36e1-4688-b7f5-ea07361b26a8");

// static boolean doConnect = false;
// static boolean connected = false;
// static boolean doScan = false;
// static BLERemoteCharacteristic* pRemoteCharacteristic;
// static BLEAdvertisedDevice* myDevice;

// static void notifyCallback(
//   BLERemoteCharacteristic* pBLERemoteCharacteristic,
//   uint8_t* pData,
//   size_t length,
//   bool isNotify) {
//     Serial.print("Notify callback for characteristic ");
//     Serial.print(pBLERemoteCharacteristic->getUUID().toString().c_str());
//     Serial.print(" of data length ");
//     Serial.println(length);
//     Serial.print("data: ");
//     Serial.println((char*)pData);
// }

// /**  None of these are required as they will be handled by the library with defaults. **
//  **                       Remove as you see fit for your needs                        */  
// class MyClientCallback : public BLEClientCallbacks {
//   void onConnect(BLEClient* pclient) {
//   }

//   void onDisconnect(BLEClient* pclient) {
//     connected = false;
//     Serial.println("onDisconnect");
//   }
// /***************** New - Security handled here ********************
// ****** Note: these are the same return values as defaults ********/
//   uint32_t onPassKeyRequest(){
//     Serial.println("Client PassKeyRequest");
//     return 123456; 
//   }
//   bool onConfirmPIN(uint32_t pass_key){
//     Serial.print("The passkey YES/NO number: ");Serial.println(pass_key);
//     return true; 
//   }

//   void onAuthenticationComplete(ble_gap_conn_desc desc){
//     Serial.println("Starting BLE work!");
//   }
// /*******************************************************************/
// };

// bool connectToServer() {
//     Serial.print("Forming a connection to ");
//     Serial.println(myDevice->getAddress().toString().c_str());
    
//     BLEClient*  pClient  = BLEDevice::createClient();
//     Serial.println(" - Created client");

//     pClient->setClientCallbacks(new MyClientCallback());

//     // Connect to the remove BLE Server.
//     pClient->connect(myDevice);  // if you pass BLEAdvertisedDevice instead of address, it will be recognized type of peer device address (public or private)
//     Serial.println(" - Connected to server");

//     // Obtain a reference to the service we are after in the remote BLE server.
//     BLERemoteService* pRemoteService = pClient->getService(serviceUUID);
//     if (pRemoteService == nullptr) {
//       Serial.print("Failed to find our service UUID: ");
//       Serial.println(serviceUUID.toString().c_str());
//       pClient->disconnect();
//       return false;
//     }
//     Serial.println(" - Found our service");


//     // Obtain a reference to the characteristic in the service of the remote BLE server.
//     pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);
//     if (pRemoteCharacteristic == nullptr) {
//       Serial.print("Failed to find our characteristic UUID: ");
//       Serial.println(charUUID.toString().c_str());
//       pClient->disconnect();
//       return false;
//     }
//     Serial.println(" - Found our characteristic");

//     // Read the value of the characteristic.
//     if(pRemoteCharacteristic->canRead()) {
//       std::string value = pRemoteCharacteristic->readValue();
//       Serial.print("The characteristic value was: ");
//       Serial.println(value.c_str());
//     }

//     if(pRemoteCharacteristic->canNotify())
//       pRemoteCharacteristic->registerForNotify(notifyCallback);

//     connected = true;
//     return true;
// }

// /**
//  * Scan for BLE servers and find the first one that advertises the service we are looking for.
//  */
// class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
//  /**
//    * Called for each advertising BLE server.
//    */
   
// /*** Only a reference to the advertised device is passed now
//   void onResult(BLEAdvertisedDevice advertisedDevice) { **/     
//   void onResult(BLEAdvertisedDevice* advertisedDevice) {
//     Serial.print("BLE Advertised Device found: ");
//     Serial.println(advertisedDevice->toString().c_str());

//     // We have found a device, let us now see if it contains the service we are looking for.
// /********************************************************************************
//     if (advertisedDevice.haveServiceUUID() && advertisedDevice.isAdvertisingService(serviceUUID)) {
// ********************************************************************************/
//     if (advertisedDevice->haveServiceUUID() && advertisedDevice->isAdvertisingService(serviceUUID)) {

//       BLEDevice::getScan()->stop();
// /*******************************************************************
//       myDevice = new BLEAdvertisedDevice(advertisedDevice);
// *******************************************************************/
//       myDevice = advertisedDevice; /** Just save the reference now, no need to copy the object */
//       doConnect = true;
//       doScan = true;

//     } // Found our server
//   } // onResult
// }; // MyAdvertisedDeviceCallbacks


// void setup() {
//   Serial.begin(115200);
//   Serial.println("Starting Arduino BLE Client application...");
//   BLEDevice::init("");

//   // Retrieve a Scanner and set the callback we want to use to be informed when we
//   // have detected a new device.  Specify that we want active scanning and start the
//   // scan to run for 5 seconds.
//   BLEScan* pBLEScan = BLEDevice::getScan();
//   pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
//   pBLEScan->setInterval(1349);
//   pBLEScan->setWindow(449);
//   pBLEScan->setActiveScan(true);
//   pBLEScan->start(5, false);
// } // End of setup.


// // This is the Arduino main loop function.
// void loop() {

//   // If the flag "doConnect" is true then we have scanned for and found the desired
//   // BLE Server with which we wish to connect.  Now we connect to it.  Once we are 
//   // connected we set the connected flag to be true.
//   if (doConnect == true) {
//     if (connectToServer()) {
//       Serial.println("We are now connected to the BLE Server.");
//     } else {
//       Serial.println("We have failed to connect to the server; there is nothin more we will do.");
//     }
//     doConnect = false;
//   }

//   // If we are connected to a peer BLE Server, update the characteristic each time we are reached
//   // with the current time since boot.
//   if (connected) {
//     String newValue = "Time since boot: " + String(millis()/1000);
//     Serial.println("Setting new characteristic value to \"" + newValue + "\"");
    
//     // Set the characteristic's value to be the array of bytes that is actually a string.
//     /*** Note: write / read value now returns true if successful, false otherwise - try again or disconnect ***/
//     pRemoteCharacteristic->writeValue(newValue.c_str(), newValue.length());
//   }else if(doScan){
//     BLEDevice::getScan()->start(0);  // this is just eample to start scan after disconnect, most likely there is better way to do it in arduino
//   }
  
//   delay(1000); // Delay a second between loops.
// } // End of loop


// I would like you to regenerate a .cpp and .h file to fit the NimBLE library format. Here is what ble.cpp currently looks like

// // BLECharacteristic *pCharacteristic;
// std::function<void()> commandHandler;  // Command handler function

// void initBluetooth() {
//   BLEDevice::init("megaatmega2560");  // Replace with your device name

//   // Create the BLE Server
//   pServer = BLEDevice::createServer();
//   pService = pServer->createService(SERVICE_UUID);

//   // Create a BLE Characteristic
//   pCharacteristic = pService->createCharacteristic(
//       CHARACTERISTIC_UUID,
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

// void handleBluetoothCommands(void (*_commandHandler)()) {
//   // Read the value from the BLE characteristic
//   std::string receivedCommand = pCharacteristic->getValue();

//   // Convert the string to a C++ string for easier comparison
//   String commandString = String(receivedCommand.c_str());

//   // Store the command handler function
//   commandHandler = _commandHandler;

//   // Execute the stored command handler function
//   commandHandler();
// }






// - MyHexapodProject
//   - src
//     - main.cpp
//     - Eyes
//       - Eyes.cpp
//       - Eyes.h
//     - Legs
//       - Legs.cpp
//       - Legs.h
//     - Mouth
//       - Mouth.cpp
//       - Mouth.h
//     - Bluetooth
//       - ble.cpp
//       - ble.h