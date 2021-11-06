#include "common.h"

ESP8266WiFiMulti wifiMulti;
const uint32_t connectTimeoutMs = 5000; // WiFi connect timeout per AP.

void addMultipleAPToConnect(void) {

    // Add all WiFi SSID and Password of the networks here
    wifiMulti.addAP("ssid_from_AP_1", "your_password_for_AP_1");
    wifiMulti.addAP("ssid_from_AP_2", "your_password_for_AP_2");
    wifiMulti.addAP("ssid_from_AP_3", "your_password_for_AP_3");
}

void connectToAvailableAP(void) {
    // Maintain WiFi connection
    if (wifiMulti.run(connectTimeoutMs) == WL_CONNECTED) {
        Serial.print("WiFi connected: ");
        Serial.print(WiFi.SSID());
        Serial.print(" ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("WiFi not connected!");
    }
}
