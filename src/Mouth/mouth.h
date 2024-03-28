#ifndef MOUTH_H
#define MOUTH_H


#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

extern Adafruit_PWMServoDriver mBoard;
// Function declarations
void initMouth();
void mouthFunction();
#endif