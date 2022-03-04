#include "common.h"

ESP8266WiFiMulti wifiMulti;
const uint32_t connectTimeoutMs = 5000; // WiFi connect timeout per AP.

WiFiUDP ntpUDP; // Define NTP Client to get time
NTPClient timeClient(ntpUDP, "asia.pool.ntp.org");

void addMultipleAPToConnect(void) {
    // Add all WiFi SSID and Password of the networks here
    wifiMulti.addAP("ssid_from_AP_1", "your_password_for_AP_1");
    wifiMulti.addAP("ssid_from_AP_2", "your_password_for_AP_2");
    wifiMulti.addAP("ssid_from_AP_3", "your_password_for_AP_3");
}

/* Returns 1 on success and 0 on failure */
int connectToAvailableAP(void) {
    WiFi.setHostname(HOSTNAME_ESP);

    // Maintain WiFi connection
    if (wifiMulti.run(connectTimeoutMs) == WL_CONNECTED) {
        Serial.print("[WiFi] Connected: " + WiFi.SSID() + " ");
        Serial.println(WiFi.localIP());
        return 1;
    } else {
        Serial.println("[WiFi] Not connected!");
        return 0;
    }
}

void timeNTPClientInit(void) {
    timeClient.begin();
    timeClient.setTimeOffset(19800); // India
    timeClient.setUpdateInterval(UPDATE_NTP_INTERVAL);
}

void timeNTPClientUpdate(void) {
    if(!timeClient.isTimeSet()) {
        Serial.println("[NTP] Time not set, Calling forceUpdate");
        timeClient.forceUpdate(); 
    } else {
        timeClient.update();
    }
    Serial.println("[NTP] " + timeClient.getFormattedDateTime());
}