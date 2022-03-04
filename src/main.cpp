#include "common.h"

byte wifiReconnect = 1, wifiReconnectCount = 0;
byte lightState = 1, sensorState = 0, alwaysOn = 0;

unsigned long onInterval = AUTO_ON_LIGHT_INTERVAL;
unsigned long preReadInt, preReTryInt, preReFailInt;
unsigned long currentMillis, preLightInt, preReadNTP;


void setup() {
    pinMode(RELAY, OUTPUT);
    pinMode(REDLED, OUTPUT);
    pinMode(GREENLED, OUTPUT);
    pinMode(PIR_SENSOR, INPUT);
    digitalWrite(RELAY, lightState);

    Serial.begin(115200);
    Serial.println("\nBooting...\n");

    WiFi.persistent(false);   // Don't save WiFi configuration in flash
    WiFi.mode(WIFI_STA);      // Set WiFi to station mode
    addMultipleAPToConnect(); // Adding all SSIDs to wifiMulti
    connectToAvailableAP(); // Connect to any wifi network
    timeNTPClientInit(); // NTP Server
    otaUpdateSetup(); // Setup OTA
    otaMDNSSetup(); // DNS for hostname
}

void loop() {
    // Timer at which we change states.
    currentMillis = millis();

    // Maintain WiFi connection
    if ((WiFi.status() != WL_CONNECTED) &&
        (wifiReconnect == 1) &&
        (currentMillis - preReTryInt >= WIFI_RECONNECT_INTERVAL)) {
        if (connectToAvailableAP()) {
            wifiReconnectCount++;
        }
        preReTryInt = currentMillis;
    }
    
    if (wifiReconnectCount == WIFI_RECONNECT_FAIL_COUNT) {
        wifiReconnect = 0;
        preReFailInt = currentMillis;
        Serial.println("Max reconnect fail count reached");
    }
    
    // Stop Reconnecting and Try after few minutes
    if ((wifiReconnect == 0) &&
        (currentMillis - preReFailInt >= WIFI_RETRY_FAIL_INTERVAL)) {
        wifiReconnect = 1;
        Serial.println("Resetting wifiReconnect flag and Try reconnection");

    }
    
    // Allow NTP time update 
    if ((WiFi.status() == WL_CONNECTED) && 
        (currentMillis - preReadNTP >= UPDATE_NTP_INTERVAL)) {
        timeNTPClientUpdate();
        preReadNTP = currentMillis;
    }

    // Allow OTA update only for few minutes after booting
    if ((WiFi.status() == WL_CONNECTED) && 
        (currentMillis <= ALLOWED_OTA_INTERVAL)) {
        ArduinoOTA.handle();
    }

    // Reading the state of sensor
    if ((alwaysOn == 0) && 
        (currentMillis - preReadInt >= PIR_SENSOR_INTERVAL)) {
        sensorState = digitalRead(PIR_SENSOR);
        preReadInt = currentMillis;

        // Check if PIR sensor is HIGH and On Light
        if ((lightState == LOW) && (sensorState == HIGH)) {
            Serial.println("Light ON..");
            lightState = HIGH;
            preLightInt = currentMillis;
            digitalWrite(RELAY, lightState);
        } else if ((lightState == HIGH) && (sensorState == HIGH)) {
            Serial.println("Updated ON time..");
            preLightInt = currentMillis;
        } else if ((sensorState == LOW) && 
                    (currentMillis - preLightInt >= onInterval)) {
            Serial.println("Light OFF..");
            lightState = LOW;
            digitalWrite(RELAY, lightState);
        }
    } else if (alwaysOn == 1) {
        lightState = HIGH;
        digitalWrite(RELAY, lightState);
    }
}