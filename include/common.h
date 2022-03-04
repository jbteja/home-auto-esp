#ifndef GENERIC_COMMON_H
#define GENERIC_COMMON_H

#include "espnode.h"

#if defined(ESP32)
// Include the Wi-Fi library
#include <WiFi.h>

// Include the Wi-Fi-Multi library
#include <WiFiMulti.h>

// Include the mDNS library for DNS
#include <ESPmDNS.h>

#elif defined(ESP8266)
// Include the Wi-Fi library
#include <ESP8266WiFi.h>

// Include the Wi-Fi-Multi library
#include <ESP8266WiFiMulti.h>

// Include the mDNS library for DNS
#include <ESP8266mDNS.h>
#endif

// Include the Arduino OTA library
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
void otaMDNSSetup(void);
void otaUpdateSetup(void);

// Include the library for Clock
#include <NTPClient.h>
void timeNTPClientInit(void);
void timeNTPClientUpdate(void);

void addMultipleAPToConnect(void);
int connectToAvailableAP(void);

// Include the firebase library for RTDB
// #include <Firebase_ESP_Client.h>

// Define the API Key of firebase
#define API_KEY "API_KEY"

// Define the RTDB URL */
#define DATABASE_URL "URL" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

// Define the email and password that registered to the project
#define USER_EMAIL "USER_EMAIL"
#define USER_PASSWORD "USER_PASSWORD"

// Define the database secret in case we need to access database rules
#define DATABASE_SECRET "DATABASE_SECRET"

#endif /* GENERIC_COMMON_H */