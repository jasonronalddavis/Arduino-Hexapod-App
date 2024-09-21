#include <Arduino.h>
#include <NimBLEDevice.h>
#include <NimBLEServer.h>
#include <NimBLEUtils.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
#include "Eyes/eyes.h"
#include "legs/crawlf.h"
#include "Mouth/mouth.h"
#include "test/test.h"
#include "chat/I2S.h"
#include "chat/cloudSpeechClient.h"
#include "Audio.h"
#include "SD.h"
#include "FS.h"
#include "Ticker.h"
#include <HTTPClient.h>
#include <WiFi.h>
#include "config.h"
#include "driver/i2s.h"  // Include the ESP32 I2S driver
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_core_dump.h"

// ITwoS audioInput(INMP441);
NimBLEServer* pServer = nullptr;
NimBLECharacteristic* pCharacteristic = nullptr;
bool deviceConnected = false;
bool crawlf = false;
bool crawlb = false;
bool crawlL = false;
bool crawlr = false;
bool blink_up = false;
bool blink_down;


int32_t raw_samples[SAMPLE_BUFFER_SIZE];
int16_t sBuffer_2[BUFFERLEN];

// CustomAudio *audio;
void processReceivedData(const char* data);
void playResponseFromServer(String response);




WiFiClient client;
#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID_RX "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class MyCallbacks : public NimBLECharacteristicCallbacks {
    void onWrite(NimBLECharacteristic* pCharacteristic) {
        std::string rxValue = pCharacteristic->getValue();
        if (rxValue.length() > 0) {
            processReceivedData(rxValue.c_str());
        }
    }
    void onConnect(NimBLEServer* pServer) {
        Serial.println("Connected!");
        Serial1.println("success");
    }
    void onDisconnect(NimBLEServer* pServer) {
        Serial.println("Disconnected!");
    }
};

void processReceivedData(const char* data) {
    int dataAsInt = atoi(data);
    Serial.print("-Axis to: "); 

    // Reset all crawl states before setting a new one
    crawlf = false;
    crawlb = false;
    crawlL = false;
    crawlr = false;

    if (dataAsInt == 20) {
        mouthDown();
    } else if (dataAsInt == 21) {
        mouthUp();
    } else if (strncmp(data, "x", 1) == 0) {
        int eyeData = atoi(data + 1);
        moveEyeballX(eyeData);
        Serial.print("Adjusting Eyeball ");
        Serial.println("x");
        Serial.println(eyeData); 
    } else if (strncmp(data, "y", 1) == 0) {
        int eyeData = atoi(data + 1);
        moveEyeballY(eyeData);
        Serial.print("Adjusting Eyeball ");
        Serial.println("y");
        Serial.println(eyeData); 
    } else if (strncmp(data, "e", 1) == 0) {
        int eyeData = atoi(data + 1);
        eyeLid(eyeData);
        Serial.print("Adjusting Eyelid ");
        Serial.println("e");
        Serial.println(eyeData); 
    } else if (strncmp(data, "S", 1) == 0) {
        Serial.println("Stretching..."); 
        testStretch();
    } else if (strncmp(data, "U", 1) == 0) {
        Serial.println("Lifting and Standing..."); 
        testLift();
    } else if (strncmp(data, "B", 1) == 0) {
        Serial.println("Bending..."); 
        testBend();
    } else if (strncmp(data, "T", 1) == 0) {
        Serial.println("Standing..."); 
        testStand();
    } else if (strncmp(data, "F", 1) == 0) {
        Serial.println("Crawling forward..."); 
        crawlf = true;
    } else if (strncmp(data, "Z", 1) == 0) {
        Serial.println("Crawling backward...");
        crawlb = true;
    } else if (strncmp(data, "R", 1) == 0) {
        Serial.println("Crawling right...");
        crawlr = true;
    } else if (strncmp(data, "L", 1) == 0) {
        Serial.println("Crawling left...");
        crawlL = true;
    } else if (strncmp(data, "d", 1) == 0) {
        Serial.println("Blinking up...");
        blinkUp();
    } else if (strncmp(data, "b", 1) == 0) {
        Serial.println("Blinking down...");
        blinkDown();
    }
}




// void i2s_install_2() {
//   const i2s_config_t i2s_config = {
//     .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX),
//     .sample_rate = 44100,
//     .bits_per_sample = i2s_bits_per_sample_t(16),
//     .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
//     .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_STAND_I2S),
//     .intr_alloc_flags = 0,
//     .dma_buf_count = 8,
//     .dma_buf_len = BUFFERLEN,
//     .use_apll = false
//   };
//   i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
// }


// void i2s_setpin_2() {
//   const i2s_pin_config_t pin_config = {
//     .bck_io_num = I2S_SCK,
//     .ws_io_num = I2S_WS,
//     .data_out_num = -1,
//     .data_in_num = I2S_SD
//   };
//   i2s_set_pin(I2S_PORT, &pin_config);
// }



void setup() {
    Serial.begin(115200);
    Serial1.begin(115200);
   Serial.println(" ");
   delay(1000);
     // Initialize the CustomAudio system
    // audio = new CustomAudio(MicType::INMP441);  // Assuming `MicType::I2S` is your microphone type
    // audio->CreateWavHeader(audio->paddedHeader, CustomAudio::wavDataSize);

    // // Initialize chat (voice commands) module immediately
    // // Setup WiFi connection after chat initialization
    // // WiFi.begin(ssid, password);
    // // while (WiFi.status() != WL_CONNECTED) {
    // //     delay(1000);
    // //     Serial.println("Connecting to WiFi...");
    // // }
    // // Serial.println("Connected to WiFi");

    // // Initialize Bluetooth and other components
    // NimBLEDevice::init("PEANUT");
    // pServer = NimBLEDevice::createServer();
    // NimBLEService* pService = pServer->createService(SERVICE_UUID);
    // pCharacteristic = pService->createCharacteristic(
    //     CHARACTERISTIC_UUID_RX,
    //     NIMBLE_PROPERTY::WRITE | NIMBLE_PROPERTY::NOTIFY
    // );
    // pCharacteristic->setCallbacks(new MyCallbacks());
    // pService->start();
    // NimBLEAdvertising* pAdvertising = pServer->getAdvertising();
    // pAdvertising->start();
    initTest();
    initMouth();
    initEyes();
   i2s_driver_install(I2S_NUM_0, &audioInput.i2s_config, 0, NULL);
    i2s_set_pin(I2S_NUM_0, &audioInput.pin_config);
    i2s_start(I2S_PORT);
    delay(500);
}


void sendTextToServer(String text) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(client, "http://<your-server-url>/chat"); // Set your server URL here
        http.addHeader("Content-Type", "application/json");

        String body = "{\"text\": \"" + text + "\"}";
        int httpResponseCode = http.POST(body);

        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println("Server response: " + response);
            playResponseFromServer(response);  // Play the chatbot's response
        } else {
            Serial.println("Error on sending POST: " + httpResponseCode);
        }
        http.end();
    } else {
        Serial.println("WiFi Disconnected");
    }
}

void playResponseFromServer(String response) {
    Serial.println("Playing response: " + response);
    
    // Example: You may need to convert the response to a format your audio class can handle (e.g., WAV)
    // Assuming the response is some audio data or file you need to play
    // audio->Record();  // Assuming you have functionality to play or handle the audio response

    // Handle actual playback here...
    // This could involve playing the response over a speaker, I2S, etc.
}  


void loop() {
    // False print statements to "lock range" on serial plotter display
    int rangelimit = 3000;
    Serial.print(rangelimit * -1);
    Serial.print(" ");
    Serial.print(rangelimit);
    Serial.print(" ");

    // Get I2S data and place in data buffer
    size_t bytesIn = 0;
    int16_t sBuffer_2[BUFFERLEN];
    esp_err_t result = i2s_read(I2S_PORT, &sBuffer_2, BUFFERLEN, &bytesIn, portMAX_DELAY);

    if (result == ESP_OK) {
        // Read I2S data buffer
        int16_t samples_read = bytesIn / 8;
        if (samples_read > 0) {
            float mean = 0;
            for (int16_t i = 0; i < samples_read; ++i) {
                mean += (sBuffer_2[i]);
            }

            // Average the data reading
            mean /= samples_read;

            // Noise gate: check if the signal exceeds the threshold
            if (abs(mean) > noiseThreshold) {
                Serial.println(mean);
            }
        }
     }
    }
// ...


    // // If there is captured audio text, send it to the server
    // // Example response from server for testing (replace this with actual server response)
    // String serverResponse = "This is a response from the chatbot";
    // playResponseFromServer(serverResponse);  // Play the response audio

    // // Check if any BLE data is available (for robot movement)
    // if (Serial1.available()) {
    //     String receivedData = Serial1.readStringUntil('\n');
    //     processReceivedData(receivedData.c_str());
    // }

    // // Handle robot movements based on BLE commands
    // if (crawlf) {
    //     crawlForward();
    // }
    // if (crawlb) {
    //     crawlBackward();
    // }
    // if (crawlL) {
    //     crawlLeft();
    // }
    // if (crawlr) {
    //     crawlRight();
    // }

    // // Optional: Handle any blinking behavior or additional robot actions
    // if (blink_up) {
    //     blinkUp();
    // }
    // if (blink_down) {
    //     blinkDown();
    // }

    // Delay to prevent spamming server too frequently
