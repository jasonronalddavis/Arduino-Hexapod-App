// #include "CloudSpeechClient.h"
// #include "Audio.h" // Ensure this includes the definition for CustomAudio
// #include <base64.h>
// #include <ArduinoJson.h>
// #include "../config.h" // Ensure this contains the necessary configuration
// #include <HTTPClient.h>
// #include <Arduino.h>
// #include "driver/i2s.h"  // Include the ESP32 I2S driver
// #include "esp_system.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "I2S.h"


// CloudSpeechClient::CloudSpeechClient(Authentication authentication) {
//     this->authentication = authentication;
//     WiFi.begin(ssid, password);
//     while (WiFi.status() != WL_CONNECTED) delay(1000);
//     client.setCACert(root_ca);
//     if (!client.connect(server, 443)) Serial.println("Connection failed!");
// }

// CloudSpeechClient::~CloudSpeechClient() {
//     client.stop();
//     WiFi.disconnect();
// }

// void CloudSpeechClient::PrintHttpBody2(CustomAudio* audio) {
//     String enc = base64::encode(reinterpret_cast<const uint8_t*>(audio->paddedHeader), audio->headerSize);
//     enc.replace("\n", "");
//     client.print(enc);

//     for (int i = 0; i < audio->totalDataSize; i += audio->chunkSize) {
//         enc = base64::encode(reinterpret_cast<const uint8_t*>(audio->data + i), audio->chunkSize);
//         enc.replace("\n", "");
//         client.print(enc);
//     }
// }

// void CloudSpeechClient::Transcribe(CustomAudio* audio) {
//     String HttpBody1 = "{\"config\":{\"encoding\":\"LINEAR16\",\"sampleRateHertz\":16000,\"languageCode\":\"en-IN\"},\"audio\":{\"content\":\"";
//     String HttpBody3 = "\"}}\r\n\r\n";
//     int httpBody2Length = (audio->totalDataSize + audio->headerSize) * 4 / 3;
//     String ContentLength = String(HttpBody1.length() + httpBody2Length + HttpBody3.length());
//     String HttpHeader = "POST /v1/speech:recognize?key=" + apiKey +
//                         " HTTP/1.1\r\nHost: speech.googleapis.com\r\nContent-Type: application/json\r\nContent-Length: " +
//                         ContentLength + "\r\n\r\n";

//     client.print(HttpHeader);
//     client.print(HttpBody1);
//     PrintHttpBody2(audio);
//     client.print(HttpBody3);

//     while (!client.available());
//     String response = client.readString();
//     Serial.print("Response: "); Serial.println(response);
// }
