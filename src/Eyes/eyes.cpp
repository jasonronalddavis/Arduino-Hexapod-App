
//eyes.cpp
#include <Arduino.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
// Servo servos_ESP32[SERVO_COUNT_ESP32]; // Array to hold ESP32 servo objects
Adafruit_PWMServoDriver eBoard = Adafruit_PWMServoDriver(0x40); // Initialize the PCA9685 object for board 1

void initEyes(){
 eBoard.begin(); // Begin communication with board 1
  eBoard.setPWMFreq(60); // Set PWM frequency to 60Hz
}


int blinkPulse(int ang) {
    int SERVOMIN = 125; // Minimum pulse length count
  int SERVOMAX = 575; // Maximum pulse length count
  int pulse = map(ang, 0, 180, SERVOMIN, SERVOMAX); // Map angle to pulse width
  Serial.print("Angle: "); Serial.print(ang);
  Serial.print(" pulse: "); Serial.println(pulse);
  return pulse;
}



int eyePulse(int ang) {
int SERVOMIN = 125; // Minimum pulse width in microseconds
  int SERVOMAX = 575; // Maximum pulse width in microseconds
  int pulse = map(ang, 0, 180, SERVOMIN, SERVOMAX); // Map angle to pulse width
  Serial.print("Angle: "); Serial.print(ang);
  Serial.print(" pulse: "); Serial.println(pulse);
  return pulse;
}




// Function to move the eyeball along the X-axis
void moveEyeballX(int angle) {
  int pulse = eyePulse(angle);
    eBoard.setPWM(10, 0, pulse); // Adjust the servo motor connected to control the eyeball along the X-axis
  // Adjust the servo motor connected to control the eyeball along the X-axis
}


void moveEyeballY(int angle) {
  int pulse = eyePulse(angle);
    eBoard.setPWM(11, 0, pulse); // Adjust the servo motor connected to control the eyeball along the X-axis
  // Adjust the servo motor connected to control the eyeball along the Y-axis
}


void eyelid(int angle) {
 int pulse = blinkPulse(angle);
  // Adjust the servo motor connected to control the eyeball along the Y-axis
}



void blinkDown() {
  eBoard.setPWM(12, 0, blinkPulse(75));
}

void blinkUp() {
  eBoard.setPWM(12, 0, blinkPulse(150));
}



// Control eye and eyelid movements
// void eyeFunction() {
//   // // Eye movements
//   // eyeX.write(75);
//   // delay(900);
//   // eyeX.write(140);
//   // delay(900);
//   // eyeX.write(75);
//   // delay(500);
//   // eyeX.write(140);

//   // eyeY.write(20);
//   // delay(500);
//   // eyeY.write(60);
//   // delay(500);
//   // eyeY.write(20);
//   // delay(500);
//   // eyeY.write(60);
//   // delay(900);

//   // // Eyelid movements
//   // eyelids.write(75);
//   // delay(250);
//   // eyelids.write(140);
//   // delay(250);
//   // eyelids.write(75);
//   // delay(250);
//   // eyelids.write(140);
//   // delay(250);
// }

