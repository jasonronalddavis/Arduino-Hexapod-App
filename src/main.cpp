#include <Arduino.h>
#include <NimBLEDevice.h>
#include <NimBLEServer.h>
#include <NimBLEUtils.h>
// #include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
#include "Eyes/eyes.h"
#include "legs/crawlf.h"
#include "Audio.h"
#include "chat/cloudSpeechClient.h"
#include "Mouth/mouth.h"
#include "test/test.h"
// #include "SD.h"
// #include "FS.h"
// #include "Ticker.h"
// #include <HTTPClient.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>                       
// #include "config.h"
// #include "driver/i2s.h"  // Include the ESP32 I2S driver
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "esp_core_dump.h"


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




const char* sSid = "iPhone";
const char* passWord = "Barnes!!";

// API Keys
const char* apikey = "AIzaSyB_eFvcXt8CfCLd-fMd83Ze0bcwHRBdFFc";  // Use const char*// Server details


 const char* s2tServer = "speech.googleapis.com";
 const char* root_Ca =
"-----BEGIN CERTIFICATE-----\n"
"MIIF4DCCBMigAwIBAgIRAOvK+wvE9RNiCvEgVTZHYXMwDQYJKoZIhvcNAQELBQAw\n"
"OzELMAkGA1UEBhMCVVMxHjAcBgNVBAoTFUdvb2dsZSBUcnVzdCBTZXJ2aWNlczEM\n"
"MAoGA1UEAxMDV1IyMB4XDTI0MDgwNTA3MTgyMFoXDTI0MTAyODA3MTgxOVowIjEg\n"
"MB4GA1UEAxMXdXBsb2FkLnZpZGVvLmdvb2dsZS5jb20wWTATBgcqhkjOPQIBBggq\n"
"hkjOPQMBBwNCAATp8201ynPGaIqwfpq//m5duZr+OpqnZ6y5bJ74R9PK+d7t96Mc\n"
"lQxJH+cdlsjQkcue/bRC+9gSqnCKBp5Q0qmao4IDwTCCA70wDgYDVR0PAQH/BAQD\n"
"AgeAMBMGA1UdJQQMMAoGCCsGAQUFBwMBMAwGA1UdEwEB/wQCMAAwHQYDVR0OBBYE\n"
"FI79jH9ydHKcCIuNsxDvjAyhbV3EMB8GA1UdIwQYMBaAFN4bHu15FdQ+NyTDIbvs\n"
"NDltQrIwMFgGCCsGAQUFBwEBBEwwSjAhBggrBgEFBQcwAYYVaHR0cDovL28ucGtp\n"
"Lmdvb2cvd3IyMCUGCCsGAQUFBzAChhlodHRwOi8vaS5wa2kuZ29vZy93cjIuY3J0\n"
"MIIBmAYDVR0RBIIBjzCCAYuCF3VwbG9hZC52aWRlby5nb29nbGUuY29tghQqLmNs\n"
"aWVudHMuZ29vZ2xlLmNvbYIRKi5kb2NzLmdvb2dsZS5jb22CEiouZHJpdmUuZ29v\n"
"Z2xlLmNvbYITKi5nZGF0YS55b3V0dWJlLmNvbYIQKi5nb29nbGVhcGlzLmNvbYIT\n"
"Ki5waG90b3MuZ29vZ2xlLmNvbYIXKi55b3V0dWJlLTNyZC1wYXJ0eS5jb22CEXVw\n"
"bG9hZC5nb29nbGUuY29tghMqLnVwbG9hZC5nb29nbGUuY29tghJ1cGxvYWQueW91\n"
"dHViZS5jb22CFCoudXBsb2FkLnlvdXR1YmUuY29tgh91cGxvYWRzLnN0YWdlLmdk\n"
"YXRhLnlvdXR1YmUuY29tghViZy1jYWxsLWRvbmF0aW9uLmdvb2eCG2JnLWNhbGwt\n"
"ZG9uYXRpb24tYWxwaGEuZ29vZ4IcYmctY2FsbC1kb25hdGlvbi1jYW5hcnkuZ29v\n"
"Z4IZYmctY2FsbC1kb25hdGlvbi1kZXYuZ29vZzATBgNVHSAEDDAKMAgGBmeBDAEC\n"
"ATA2BgNVHR8ELzAtMCugKaAnhiVodHRwOi8vYy5wa2kuZ29vZy93cjIvb1E2bnly\n"
"OEYwbTAuY3JsMIIBAwYKKwYBBAHWeQIEAgSB9ASB8QDvAHYAdv+IPwq2+5VRwmHM\n"
"9Ye6NLSkzbsp3GhCCp/mZ0xaOnQAAAGRIZ4zmgAABAMARzBFAiEAxX37LanL4NY9\n"
"7wns4SdpAUINEMR4Lh9lUde0BBjEFcwCIDgAmvfg3TPH7DnwkGOE2IsGQMYOccnR\n"
"BI2FCAvSIJt6AHUASLDja9qmRzQP5WoC+p0w6xxSActW3SyB2bu/qznYhHMAAAGR\n"
"IZ4zjgAABAMARjBEAiBlKwkwkGleVLNPVbDEdqzcbpJWiAHq5PKaw5yvoeK7AAIg\n"
"dvkctZDH2pYFJzhZW3+V+mtU7hZE28/p5XKzIKcnvVowDQYJKoZIhvcNAQELBQAD\n"
"ggEBAJPwb4seiRTvhTekn1Zs3njA+r9SIJuXlrs2D1SuBq+jrnARdFfcyWTHHS5d\n"
"RPFhEtvc1mXuV605tJ7iyokiGtEt7IbpwRr7ziBnIpXNUY8LZUZ+EeK8ZucuTAce\n"
"jTUaLieiB/pBLR5tHJBds75O5c02X4lpxeOH/iClIVGJEnmYjVsSrzj+2NkaxEkI\n"
"MYv1xfmkdx77XdMkMJecaKe6rs9WMgDTsq5LJ732oHvSFy9yCvJ0f8QnQfN0ijbm\n"
"wD4QPz7MVggCKD15jXQ6G1aw0ieKJnyl5Ur/qXpnB/c361QIEE1y9mTWkpMO9RsL\n"
"zE2ZUoihL3OnO+Fr0as8OnNIm4Q=\n"
"-----END CERTIFICATE-----\n";



String Httpheaderr = String("POST /v1/speech:recognize?key=") + apikey + " HTTP/1.1\r\nHost: speech.googleapis.com\r\nContent-Type: application/json\r\nContent-Length: 0\r\n\r\n";




// int32_t raw_samples[SAMPLE_BUFFER_SIZE];
// int16_t sBuffer_2[BUFFERLEN];

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
    delay(500);
    Serial.println("\nInitializing...");

    // Connect to WiFi
    WiFi.begin(sSid, passWord);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
        int wifiStatus = WiFi.status();
        Serial.print(" WiFi Status: ");
        Serial.println(wifiStatus);
    }

    Serial.println("\nConnected to WiFi");

    // Setup WiFiClientSecure and connect to Google Speech-to-Text API
    WiFiClientSecure client;
    
    // Set timeout and insecure mode for testing
    client.setTimeout(5000);  // Set timeout to 5 seconds
    client.setInsecure();     // Disable SSL certificate verification (for testing)

    Serial.println("Attempting to connect to Google API server...");
    if (!client.connect(s2tServer, 443)) {
        Serial.println("Connection to server failed");
    } else {
        Serial.println("Connected to server successfully");

        // Use the global Httpheaderr from config.h
        client.print(Httpheaderr);
        Serial.println("Sent request header.");
        
        Serial.println("Waiting for response...");
        while (client.connected() && !client.available()) {
            delay(10);
            Serial.print(".");
        }

        String response = "";
        while (client.available()) {
            response += client.readString();
        }

        if (response.length() > 0) {
            Serial.println("\nServer response:");
            Serial.println(response);
        } else {
            Serial.println("\nNo response from server.");
        }

        client.stop();
        Serial.println("Closed connection.");
    }

    // Start audio recording
    customAudio* audio = new customAudio(INMP441);
    audio->Record();
    Serial.println("Recording Completed. Now Processing...");

    // Send the recorded audio for transcription
    CloudSpeechClient* cloudSpeechClient = new CloudSpeechClient(USE_APIKEY);
    cloudSpeechClient->Transcribe(audio);

    delete cloudSpeechClient;
    delete audio;

    // Initialize other components
    initTest();
    initMouth();
    initEyes();
    delay(500);
}



// void sendTextToServer(String text) {
//     if (WiFi.status() == WL_CONNECTED) {
//         HTTPClient http;
//         http.begin(client, "http://<your-server-url>/chat"); // Set your server URL here
//         http.addHeader("Content-Type", "application/json");

//         String body = "{\"text\": \"" + text + "\"}";
//         int httpResponseCode = http.POST(body);

//         if (httpResponseCode > 0) {
//             String response = http.getString();
//             Serial.println("Server response: " + response);
//             playResponseFromServer(response);  // Play the chatbot's response
//         } else {
//             Serial.println("Error on sending POST: " + httpResponseCode);
//         }
//         http.end();
//     } else {
//         Serial.println("WiFi Disconnected");
//     }
// }

void playResponseFromServer(String response) {
    Serial.println("Playing response: " + response);
    
    // Example: You may need to convert the response to a format your audio class can handle (e.g., WAV)
    // Assuming the response is some audio data or file you need to play
    // audio->Record();  // Assuming you have functionality to play or handle the audio response

    // Handle actual playback here...
    // This could involve playing the response over a speaker, I2S, etc.
}  


void loop() {
    // // False print statements to "lock range" on serial plotter display
    // int rangelimit = 3000;
    // Serial.print(rangelimit * -1);
    // Serial.print(" ");
    // Serial.print(rangelimit);
    // Serial.print(" ");

    // // Get I2S data and place in data buffer
    // size_t bytesIn = 0;
    // int16_t sBuffer_2[BUFFERLEN];
    // esp_err_t result = i2s_read(I2S_PORT, &sBuffer_2, BUFFERLEN, &bytesIn, portMAX_DELAY);

    // if (result == ESP_OK) {
    //     // Read I2S data buffer
    //     int16_t samples_read = bytesIn / 8;
    //     if (samples_read > 0) {
    //         float mean = 0;
    //         for (int16_t i = 0; i < samples_read; ++i) {
    //             mean += (sBuffer_2[i]);
    //         }

    //         // Average the data reading
    //         mean /= samples_read;

    //         // Noise gate: check if the signal exceeds the threshold
    //         if (abs(mean) > noiseThreshold) {
    //             Serial.println(mean);
    //         }
    //     }
    //  }
    // }
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
}