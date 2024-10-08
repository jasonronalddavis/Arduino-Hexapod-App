#ifndef CLOUDSPEECHCLIENT_H
#define CLOUDSPEECHCLIENT_H
#include <WiFiClientSecure.h>
#include "Audio.h"



enum Authentication {
  USE_ACCESSTOKEN,
  USE_APIKEY
};

class CloudSpeechClient {
  WiFiClientSecure client;
  void PrintHttpBody2(customAudio* audio);
  Authentication authentication;

public:
  CloudSpeechClient(Authentication authentication);
  ~CloudSpeechClient();
  void Transcribe(customAudio* audio);
};

#endif // _CLOUDSPEECHCLIENT_H