#define BLYNK_TEMPLATE_ID           "TMPL2igeY5_v8"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYNK_AUTH_TOKEN            "Xj3nJJzrGTliUnex2y6KatRakrbRrNPI"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <Arduino.h>
#include <Servo.h>
#include "Eyes/eyes.h"
#include "legs/crawlf.h"
#include "Mouth/mouth.h"
#include <Wire.h>
#include <BlynkSimpleStream.h>

// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial1

// Your ESP8266 baud rate:
#define ESP8266_BAUD 38400



// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";


BlynkTimer timer;



void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);



  Blynk.begin(Serial, "Xj3nJJzrGTliUnex2y6KatRakrbRrNPI");


  initLegs(myServo49, myServo51);
  initMouth();
  initEyes();
  Serial1.println("Setup completed");

  timer.setInterval(1000L, myTimerEvent);  // Setup a function to be called every second
}

void loop() {
  Blynk.run();
  timer.run();
  delay(100);  // Adjust delay as needed
}

BLYNK_WRITE(V4) {
  int value = param.asInt();
  int values[] = {value, value}; // Assuming the same value for both servos
  handleServoBlynkWrite(values, sizeof(values) / sizeof(values[0]));
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED() {
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2
void myTimerEvent() {
  Blynk.virtualWrite(V41, millis() / 1000);
}