#ifndef MOUTH_H
#define MOUTH_H


#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

extern Adafruit_PWMServoDriver mBoard;
// Function declarations
int mouthPulse(int ang);
void initMouth();
void mouthUp();
void mouthDown();
#endif