
#define SERVO_FREQ 50 // or whatever value you want
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>


Adafruit_PWMServoDriver pwm1;
Adafruit_PWMServoDriver pwm2;
Adafruit_PWMServoDriver pwm3;

// Define the mouth servo
void initMouth() {
  Wire.begin();

  pwm1.begin();
  pwm2.begin();
  pwm3.begin();

   pwm3.setOscillatorFrequency(27000000); // Set oscillator frequency
  pwm3.setPWMFreq(SERVO_FREQ);  // Set PWM frequency for servos
}
void mouthFunction() {
  pwm3.setPWM(0, 0, 130);  // Open the mouth
  delay(200);
  pwm3.setPWM(0, 0, 70);   // Close the mouth
  delay(200);
  pwm3.setPWM(0, 0, 130);  // Open the mouth
  delay(200);
  pwm3.setPWM(0, 0, 70);   // Close the mouth
  delay(200);
  pwm3.setPWM(0, 0, 70);   // Close the mouth
  delay(200);
  pwm3.setPWM(0, 0, 130);  // Open the mouth
  delay(200);
  pwm3.setPWM(0, 0, 70);   // Close the mouth
}

void test90() {
  delay(200);
  pwm3.setPWM(0, 0, 90);   // Test position 90 degrees
  delay(200);
}

void test0() {
  delay(200);
  pwm3.setPWM(0, 0, 0);    // Test position 0 degrees
  delay(200);
}