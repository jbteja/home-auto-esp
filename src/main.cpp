#include "common.h"

void setup() {
    Serial.begin(115200);
    Serial.println("\nBooting..");
    
    WiFi.persistent(false);  // Don't save WiFi configuration in flash
    WiFi.mode(WIFI_STA); // Set WiFi to station mode
    addMultipleAPToConnect(); // Adding all SSIDs to wifiMulti
}

void loop() {
    connectToAvailableAP(); // Maintain WiFi connection
    delay(1000);
}