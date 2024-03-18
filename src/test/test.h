#ifndef TEST_H
#define TEST_H

#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

// #define SERVO_COUNT_ESP32 18 // Number of servos attached to ESP32

extern Adafruit_PWMServoDriver board1; // Declare the PCA9685 object for board 1
extern Adafruit_PWMServoDriver board2; // Declare the PCA9685 object for board 1

void initPca();
// void attachAndSetAngle(Servo &servo, int pin, int angle);
int angleToPulse(int ang);
void testStretch();
void testLift();

#endif
