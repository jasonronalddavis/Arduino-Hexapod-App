

#ifndef CRAWLF_H
#define CRAWLF_H

#include <Arduino.h>
#include <Servo.h>
#include <ESP8266WiFi.h>

// Function declarations
void initLegs(Servo& servo49, Servo& servo51);
void crawlOne();
void crawlTwo();
void crawlThree();
void crawlFour();
void liftFunction();
void standFunction();
void flexFunction();
void stretch();
void crawlForward();
void defaultMove();
void handleServoBlynkWrite(int values[], int numServos);
void myTimerEvent(); 


extern Servo myServo2;
extern Servo myServo3;
extern Servo myServo4;
extern Servo myServo5;
extern Servo myServo6;
extern Servo myServo7;
extern Servo myServo8;
extern Servo myServo9;
extern Servo myServo10;
extern Servo myServo11;
extern Servo myServo12;
extern Servo myServo13;
extern Servo myServo14;
extern Servo myServo15;
extern Servo myServo16;
extern Servo myServo17;
extern Servo myServo18;
extern Servo myServo19;
extern Servo myServo49;
extern Servo myServo51;

extern Servo myServos[];

#endif