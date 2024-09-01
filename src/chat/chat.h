#ifndef CHAT_H
#define CHAT_H

#include "Arduino.h"
#include "Audio.h"
#include "Adafruit_PWMServoDriver.h"
#include "Ticker.h"

extern Audio audio;
extern Ticker ticker;

void initChat();
void handleAudioLoop();
void playVoiceCommand(const char* fileName);

#endif
