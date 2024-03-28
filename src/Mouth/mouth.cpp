#include <Arduino.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
#define SERVO_COUNT_ESP32 18 // Number of servos attached to ESP32

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




void mouthFunction() {

 mBoard.setPWM(1, 0, mouthPulse(70));

//     mouth.write(70);
//   delay(300);
//   mouth.write(130);
//   delay(300);
//   mouth.write(70);
//   delay(300);
//    mouth.write(130);
}
