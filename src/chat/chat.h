#ifndef CHAT_H
#define CHAT_H

#include <Arduino.h>
#include "Audio.h"
#include "Adafruit_PWMServoDriver.h"
#include "FS.h"
#include "SD.h"
#include "SPI.h"

extern Audio audio;

// Function declarations
void initChat();
void handleAudioLoop();
void playVoiceCommand(const char* fileName);
String audioToText();

// Constants for I2S configuration
#define I2S_DOUT 25
#define I2S_BCLK 27
#define I2S_LRC 26

#endif // CHAT_H
