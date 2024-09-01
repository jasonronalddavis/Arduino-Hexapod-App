#include "chat.h"
#include "Adafruit_PWMServoDriver.h"
#include "SD.h"
#include "SPI.h"
#include "FS.h"



// Instantiate the PWM servo driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


// Pins for I2S
#define SD_CS          5
#define SPI_MOSI      23
#define SPI_MISO      19
#define SPI_SCK       18
#define I2S_DOUT      25
#define I2S_BCLK      27
#define I2S_LRC       26

Audio audio;
Ticker ticker;
char chbuf[100];

void tckr1s() {
    // Example function to trigger voice playback at specific intervals
    // Implement your logic here if needed
}

void initChat(Adafruit_PWMServoDriver& pwm) {
    // Initialize SPI and SD card for audio playback
    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI);
    if (!SD.begin(SD_CS)) {
        Serial.println("SD Card initialization failed!");
        return;
    }
    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(10); // 0...21
    ticker.attach(1, tckr1s);

    // Example: set initial PWM values
    pwm.setPWM(0, 0, 300);
}

void handleAudioLoop() {
    audio.loop();
}

void playVoiceCommand(const char* fileName) {
    sprintf(chbuf, "/voice_time/%s.mp3", fileName);
    audio.connecttoFS(SD, chbuf);
}

void audio_eof_mp3(const char *info) {
    // Handle end of audio file playback if needed
}
