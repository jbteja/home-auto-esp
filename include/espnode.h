#ifndef ESP_NODE_TYPE_ID_H
#define ESP_NODE_TYPE_ID_H

#define SW_VERSION "1.0.0"
#define HW_VERSION "1.0.0"

#define HOSTNAME_ESP "bt-espnode-1f-steps"

#define REDLED 5 // Digital pin D1 
#define GREENLED 4 // Digital pin D2

#define PIR_SENSOR 12  // Digital pin D6
#define RELAY 13  // Digital pin D7

#define PIR_SENSOR_INTERVAL 100 // In Millis
#define AUTO_ON_LIGHT_INTERVAL 30*1000

#define OTA_PORT 3232
#define ALLOWED_OTA_INTERVAL 90000000
//#define ALLOWED_OTA_INTERVAL 15*60*1000 // 15 Min

#define WIFI_RECONNECT_FAIL_COUNT 5
#define WIFI_RECONNECT_INTERVAL 60*1000 // 1 Min
#define WIFI_RETRY_FAIL_INTERVAL 10*60*1000 // 10 Min
#define UPDATE_NTP_INTERVAL 10*60*1000

#endif /* ESP_NODE_TYPE_ID_H */
