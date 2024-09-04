#ifndef CHAT_H
#define CHAT_H

#include <Arduino.h>
#include "driver/i2s.h"  // Include the ESP32 I2S driver
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Define microphone types to be used with the I2S configuration
enum MicType {
    ADMP441,
    ICS43434,
    M5GO,
    M5STACKFIRE
};

// I2S class to handle microphone input via I2S protocol
class I2S {
    i2s_config_t i2s_config;  // I2S configuration struct
    i2s_pin_config_t pin_config;  // Pin configuration for I2S
public:
    I2S(MicType micType);  // Constructor with microphone type
    ~I2S();  // Destructor to clean up I2S
    void setup();  // Setup I2S based on the MicType
    int read(char* data, int numData);  // Read data from I2S
    int getBitsPerSample() const;  // Get the number of bits per sample
};

// Function prototypes
void initI2S();  // Initialize I2S configuration
String audioToText();  // Function to capture audio and convert to text

// Constants for I2S configuration
#define I2S_DOUT 25
#define I2S_BCLK 27
#define I2S_LRC 26
#define SAMPLE_RATE 16000

#endif // CHAT_H
