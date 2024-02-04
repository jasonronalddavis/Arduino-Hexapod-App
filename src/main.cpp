#include <Arduino.h>
#include <Servo.h>
#include "Eyes/eyes.h"
#include "legs/crawlf.h"
#include "Mouth/mouth.h"
#include <Wire.h>
#include <SoftwareSerial.h>


#define espSerial Serial1
bool stand = false;
 bool test_90 = false;
bool test_0 = false;
bool stretchBool = false;
int counter = 0;


// void processBluetoothData(const String& data);

void setup() {
  Serial1.begin(115200);  // Initialize Serial1 for debugging
  espSerial.begin(115200);  // Use Serial1 for communication with ESP32
  initEyes();
  initLegs();
  initMouth();
  Serial1.println("Setup completed");

}

void loop() {
// stretch();
    
  // Process Bluetooth data if available
 while (Serial1.available()) {
    String receivedData = Serial1.readStringUntil('\n');
   
    
    // Print the received data
    Serial1.println(receivedData);
    String dataString = String(receivedData);

    // Print the converted dataString
    Serial1.print("Converted data: ");
    Serial1.println(dataString);

    // Determine the datatype and print it

  }
    String receivedData = Serial1.readStringUntil('\n');
   
    
    // Print the received data
    Serial1.println(receivedData);
    String dataString = String(receivedData);

    if (dataString.toInt() < 0 ) {
      Serial1.println("Datatype: Integer");
    } else if (dataString.toFloat() != 0.0) {
      Serial1.println("Datatype: Float");
    } else if (dataString == "true" || dataString == "false") {
      Serial1.println("Datatype: Boolean");
    } else if (dataString.length() == 1) {
      Serial1.println("Datatype: Character");
    } else {
      Serial1.println("Datatype: String");
    }
if (dataString.toInt() < 0 ) {
      Serial1.println("Datatype: Integer");
    }


}

// // void processBluetoothData(const String& data) {
// //   // Serial1.print("Received data: ");
// //   // Serial1.println(data);
// // if (data.toInt() == 70){
// //   test_90 = true;
// //   test_0 = false;
// // test90();
// // //Servo moves to 90 degrees
// // }

// // if (data.toInt() == 66){
// //    test_0 = true;
// //   test_90 = false;
// // test0();
// // //Servo moves to 0 degrees
// // }
//   // Execute crawlForward() for any received data
// }
