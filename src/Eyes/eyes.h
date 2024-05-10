#ifndef EYES_H
#define EYES_H

#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

extern Adafruit_PWMServoDriver eBoard;

void initEyes();
int eyePulse(int ang);
int blinkPulse(int ang);
void moveEyeballX(int angle);
void moveEyeballY(int angle);
void eyeLid(int angle);
void blinkDown();
void blinkUp();

#endif /* EYES_H */
