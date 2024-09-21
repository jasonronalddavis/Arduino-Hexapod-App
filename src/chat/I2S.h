#ifndef I2S_H
#define I2S_H

#include <Arduino.h>
#include "driver/i2s.h"  // Include the ESP32 ITwoS driver
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Define microphone types to be used with the I2S configuration
enum MicType {
    INMP441,
    ADMP441  // Add this
};

// I2S class to handle microphone input via I2S protocol
class ITwoS {
private:
    i2s_bits_per_sample_t BITS_PER_SAMPLE;  // Bits per sample
public:
    i2s_config_t i2s_config;  // I2S configuration struct
    i2s_pin_config_t pin_config;  // Pin configuration for I2S

    ITwoS(MicType micType);  // Constructor with microphone type
    ~ITwoS();  // Destructor to clean up I2S driver
    int read(char* data, int numData);  // Read data from I2S
    int getBitsPerSample();  // Get the number of bits per sample
};

// Function prototypes
extern ITwoS audioInput;

// Define constants for pin configuration and I2S setup
#define I2S_SD 15
#define I2S_SCK 17
#define I2S_WS 16
#define SAMPLE_RATE 44100
#define BUFFERLEN 64
#define I2S_PORT I2S_NUM_0
#define SAMPLE_BUFFER_SIZE 512
#define noiseThreshold 50.0  // Adjust this value as needed for noise filtering

#endif // I2S_H
