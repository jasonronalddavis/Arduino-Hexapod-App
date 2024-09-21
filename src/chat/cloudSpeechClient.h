// #ifndef CLOUDSPEECHCLIENT_H
// #define CLOUDSPEECHCLIENT_H
// #include <WiFiClientSecure.h>
// #include "Audio.h"
// #include "driver/i2s.h"  // Include the ESP32 I2S driver
// #include "esp_system.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include <Arduino.h>
// #include "I2S.h"


// enum Authentication {
//   USE_ACCESSTOKEN,
//   USE_APIKEY
// };

// class CloudSpeechClient {
//   WiFiClientSecure client;
//   void PrintHttpBody2(CustomAudio* audio);
//   Authentication authentication;

// public:
//   CloudSpeechClient(Authentication authentication);
//   ~CloudSpeechClient();
//   void Transcribe(CustomAudio* audio);
// };

// #endif // _CLOUDSPEECHCLIENT_H