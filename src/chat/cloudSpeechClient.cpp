#include "CloudSpeechClient.h"
#include "Audio.h" // Include your audio handling library
#include <base64.h>
#include <ArduinoJson.h>
#include "../config.h" // Make sure this file contains necessary network parameters
#include <HTTPClient.h>
#include <Arduino.h>

CloudSpeechClient::CloudSpeechClient(Authentication authentication) {
    this->authentication = authentication;
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) delay(1000);
    client.setCACert(root_ca);
    if (!client.connect(server, 443)) Serial.println("Connection failed!");
}

CloudSpeechClient::~CloudSpeechClient() {
    client.stop();
    WiFi.disconnect();
}

void CloudSpeechClient::PrintHttpBody2(Audio* audio) {
    // This function will encode and print the audio data in chunks
    String enc = base64::encode(audio->paddedHeader, audio->headerSize); // Ensure these are defined in your Audio class
    enc.replace("\n", "");
    client.print(enc);

    for (int i = 0; i < audio->totalDataSize; i += audio->chunkSize) {
String enc = base64::encode(reinterpret_cast<uint8_t*>(audio->paddedHeader), audio->headerSize);        enc.replace("\n", "");
        client.print(enc);
    }
}

void CloudSpeechClient::Transcribe(Audio* audio) {
    String HttpBody1 = "{\"config\":{\"encoding\":\"LINEAR16\",\"sampleRateHertz\":16000,\"languageCode\":\"en-IN\"},\"audio\":{\"content\":\"";
    String HttpBody3 = "\"}}\r\n\r\n";
    int httpBody2Length = (audio->totalDataSize + audio->headerSize) * 4 / 3; // Base64 encoding increases size by 1/3
    String ContentLength = String(HttpBody1.length() + httpBody2Length + HttpBody3.length());

    String HttpHeader = "POST /v1/speech:recognize?key=" + apiKey +
                        " HTTP/1.1\r\nHost: speech.googleapis.com\r\nContent-Type: application/json\r\nContent-Length: " +
                        ContentLength + "\r\n\r\n";
    
    client.print(HttpHeader);
    client.print(HttpBody1);
    PrintHttpBody2(audio);
    client.print(HttpBody3);

    while (!client.available());
    String response = client.readString();
    Serial.print("Response: "); Serial.println(response);
}

