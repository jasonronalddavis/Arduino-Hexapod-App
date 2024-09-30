#ifndef I2S_H
#define I2S_H

#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2s.h"  // Include the ESP32 ITwoS driver
#include "esp_system.h"


// Define microphone types to be used with the I2S configuration

enum MicType {
  INMP441,
  ADMP441,
  ICS43434,
  M5GO,
  M5STACKFIRE
};

class ITwoS {
  i2s_bits_per_sample_t BITS_PER_SAMPLE;
public:
  ITwoS(MicType micType);
  int Read(char* data, int numData);
  int GetBitPerSample();
};

#endif // I2S_H
