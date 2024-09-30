#ifndef CUSTOM_AUDIO_H
#define CUSTOM_AUDIO_H

#include <Arduino.h>
#include "I2S.h"
#include <base64.h>

class customAudio {
    ITwoS* i2s;  // Object for managing I2S (inter-IC sound) communication
    static const int headerSize = 44;  // Size of the WAV file header
    static const int i2sBufferSize = 12000;  // Size of the buffer for I2S operations
    char i2sBuffer[i2sBufferSize];  // Buffer for I2S data

    // Function to create the WAV file header
    void CreateWavHeader(byte* header, int waveDataSize);

public:
    static const int wavDataSize = 90000;  // Size of the WAV data
    static const int dividedWavDataSize = i2sBufferSize / 4;  // Divided WAV data size
    char** wavData;  // Array of pointers to store divided WAV data
    byte paddedHeader[headerSize + 4] = {0};  // Padded WAV file header

    String content;  // Attribute to store the base64-encoded content of the audio

    // Constructor and destructor
    customAudio(MicType micType);
    ~customAudio();

    // Function to record the audio
    void Record();
    
    // Function to encode the audio data to base64
    void EncodeToBase64();  
};

#endif // CUSTOM_AUDIO_H
