#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>

// Servo servos_ESP32[SERVO_COUNT_ESP32]; // Array to hold ESP32 servo objects
Adafruit_PWMServoDriver mBoard = Adafruit_PWMServoDriver(0x41); // Initialize the PCA9685 object for board 2

void initMouth(){
   mBoard.begin(); // Begin communication with board 1
  mBoard.setPWMFreq(60); // Set PWM frequency to 60Hz
}

// void attachAndSetAngle(Servo &servo, int pin, int angle) {
//   servo.attach(pin); // Attach servo to pin
//   servo.write(angle); // Set initial angle
// }


int mouthPulse(int ang) {
  int SERVOMIN = 125; // Minimum pulse length count
  int SERVOMAX = 575; // Maximum pulse length count
  int pulse = map(ang, 0, 180, SERVOMIN, SERVOMAX); // Map angle to pulse width
  Serial.print("Angle: "); Serial.print(ang);
  Serial.print(" pulse: "); Serial.println(pulse);
  return pulse;
}

// void mouthFunction(int angle) {
//   int pulse = mouthPulse(angle);
//     mBoard.setPWM(13, 0, pulse); // Adjust the servo motor connected to control the eyeball along the X-axis
//   // Adjust the servo motor connected to control the eyeball along the X-axis
// }

void mouthUp(){
    mBoard.setPWM(13, 0, mouthPulse(45)); // Adjust the servo motor connected to control the eyeball along the X-axis
}

void mouthDown(){
    mBoard.setPWM(13, 0,  mouthPulse(130)); // Adjust the servo motor connected to control the eyeball along the X-axis
}