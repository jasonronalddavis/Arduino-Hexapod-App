#ifndef AUDIO_H
#define AUDIO_H
#include <Arduino.h>
#include "chat.h"  // Assuming I2S.h contains the definition for I2S and MicType

class Audio {
public:
    I2S* i2s;
    static const int headerSize = 44;
    static const int i2sBufferSize = 12000;  // Buffer size for I2S operations
    char i2sBuffer[i2sBufferSize];           // Buffer to store raw I2S data
    static const int wavDataSize = 90000;    // Total data size for wave, adjust as needed
    static const int dividedWavDataSize = i2sBufferSize / 4;  // Data chunks size
    char** wavData;                          // Array of pointers for divided data handling
    byte paddedHeader[headerSize + 4] = {0}; // Header for WAV format, padded for base64 encoding
    int totalDataSize;                       // Total size of the data collected
    int chunkSize;                           // Size of each data chunk for processing
    char* data;                              // Pointer to store the full or partial raw data

    Audio(MicType micType);  // Constructor to set up I2S based on mic type
    ~Audio();                // Destructor to clean up resources

    void Record();           // Function to handle recording
    void CreateWavHeader(byte* header, int waveDataSize);  // Create WAV header
};

#endif // AUDIO_H