#include "CloudSpeechClient.h"
// #include "../config.h" // Ensure this contains the necessary configuration
#include <base64.h>
#include <ArduinoJson.h>

//fullAudioData
// WiFi credentials
const char* ssid = "iPhone";
const char* password = "Barnes!!";

// API Key
const char* apiKey = "AIzaSyB_eFvcXt8CfCLd-fMd83Ze0bcwHRBdFFc";

// Google Cloud Speech-to-Text Server
const char* server = "speech.googleapis.com";  // Use the host only, without HTTPS prefix.

// SSL root certificate
const char* root_ca =
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

// HTTP Header for Google API requests
String HttpHeader = String("POST /v1/speech:recognize?key=") + apiKey + 
                    " HTTP/1.1\r\nHost: speech.googleapis.com\r\nContent-Type: application/json\r\n\r\n";

// CustomAudio constructor and other methods follow...






//customAudio
CloudSpeechClient::CloudSpeechClient(Authentication authentication) 
{
  this->authentication = authentication;
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(1000);
  client.setCACert(root_ca);
  if (!client.connect(server, 443)) Serial.println("Connection failed!");
}

String ans;

CloudSpeechClient::~CloudSpeechClient() {
  client.stop();
  WiFi.disconnect();
}

void CloudSpeechClient::PrintHttpBody2(customAudio* audio)
{
  String enc = base64::encode(audio->paddedHeader, sizeof(audio->paddedHeader));
  enc.replace("\n", "");  // delete last "\n"
  client.print(enc);      // HttpBody2
  char** wavData = audio->wavData;
  for (int j = 0; j < audio->wavDataSize / audio->dividedWavDataSize; ++j) {
    enc = base64::encode((byte*)wavData[j], audio->dividedWavDataSize);
    enc.replace("\n", "");// delete last "\n"
    client.print(enc);    // HttpBody2
  }
}

















void CloudSpeechClient::Transcribe(customAudio* audio) {
    // Base64-encode the audio data
    audio->EncodeToBase64();

    // Create the body for the request
    String HttpBody1 = "{\"config\":{\"encoding\":\"LINEAR16\",\"sampleRateHertz\":16000,\"languageCode\":\"en-US\"},\"audio\":{\"content\":\"";
    String HttpBody3 = "\"}}\r\n\r\n";

    // Calculate the base64-encoded data length
    int httpBody2Length = (audio->wavDataSize + sizeof(audio->paddedHeader)) * 4 / 3; // 4/3 is from base64 encoding
    String ContentLength = String(HttpBody1.length() + httpBody2Length + HttpBody3.length());

    // Construct the full HTTP header with the correct content length
    String fullHttpHeader = String("POST /v1/speech:recognize?key=") + apiKey +
                            " HTTP/1.1\r\nHost: speech.googleapis.com\r\nContent-Type: application/json\r\nContent-Length: " + ContentLength + "\r\n\r\n";

    // Send the HTTP header and body to the server
    client.print(fullHttpHeader);
    client.print(HttpBody1);
    PrintHttpBody2(audio);  // Encode and send the audio data
    client.print(HttpBody3);

    // Wait for the server response
    String My_Answer = "";
    while (!client.available());

    // Read the response
    while (client.available()) {
        char temp = client.read();
        My_Answer += temp;
    }

    // Extract the JSON data from the server response
    int position = My_Answer.indexOf('{');
    if (position >= 0) {
        ans = My_Answer.substring(position);
        Serial.print("JSON Data: ");
        Serial.println(ans);
    }
}
