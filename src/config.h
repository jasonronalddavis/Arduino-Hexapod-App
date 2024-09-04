#ifndef CONFIG_H
#define CONFIG_H
#include <Arduino.h>

// WiFi credentials
extern const char* ssid;
extern const char* password;

// API Keys
extern const String apiKey;

// Server details
extern const char* server;
extern const char* root_ca;

#endif // CONFIG_H