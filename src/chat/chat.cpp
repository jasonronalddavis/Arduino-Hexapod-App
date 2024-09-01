#include "chat.h"
#include "Adafruit_PWMServoDriver.h"
#include "SD.h"
#include <SPI.h>
#include <FS.h>
#include "Audio.h"

// Instantiate the PWM servo driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// I2S pin definitions
#define I2S_DOUT 25
#define I2S_BCLK 27
#define I2S_LRC  26
#define SAMPLE_RATE 16000

Audio audio;
i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S_MSB,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 4,
    .dma_buf_len = 512
};

i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_BCLK,
    .ws_io_num = I2S_LRC,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_DOUT
};

void initI2S() {
    i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
    i2s_set_pin(I2S_NUM_0, &pin_config);
}

void initChat() {
    pwm.begin();
    pwm.setPWMFreq(60);
    initI2S();
    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
    if (!SD.begin(SD_CS)) {
        Serial.println("SD Card initialization failed!");
        return;
    }
    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(10);
}

void handleAudioLoop() {
    audio.loop();
}

String audioToText() {
    Serial.println("Capturing audio...");
    const int numSamples = 1024;
    char data[numSamples];
    size_t bytes_read;
    i2s_read(I2S_NUM_0, &data, numSamples, &bytes_read, portMAX_DELAY);

    if (bytes_read > 0) {
        Serial.println("Audio captured successfully.");
        // Add your transcription logic here
    } else {
        Serial.println("Failed to capture audio.");
    }

    return "Audio processing not implemented";
}

void playVoiceCommand(const char* fileName) {
    char chbuf[100];  // Buffer to hold the constructed file path
    sprintf(chbuf, "/voice_time/%s.mp3", fileName);  // Construct the file path
    audio.connecttoFS(SD, chbuf);  // Play the file from SD card using the Audio library
    Serial.print("Playing file: ");  // Optional: Output the file being played
    Serial.println(chbuf);
}