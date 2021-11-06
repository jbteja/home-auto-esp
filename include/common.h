#ifndef GENERIC_COMMON_H
#define GENERIC_COMMON_H

// Include the Wi-Fi library
#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

// Include the Wi-Fi-Multi library
#include <ESP8266WiFiMulti.h>

// Include the mDNS library for DNS
#include <ESP8266mDNS.h>

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

void addMultipleAPToConnect(void);
void connectToAvailableAP(void);

#endif /* GENERIC_COMMON_H */