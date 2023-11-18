/*
 * ESP8266 Development using Arduino Framework
 */

/*
 * Features
 * 
 * Comment/uncomment each header to enable/disable it
 */
//#include "RgbShield.h"
#include "Wifi.h"
//#include "Ota.h"
#include "Mqtt.h"
#include "WebServer.h"
#include "SoftwareSerial.h"

/*
 * Configuration
 */
// Set to true to display/log to serial port
#define IS_LOGGING true

/*
 * General Globals
 */
// A general delay exists in the loop() function, this controlls that
#define GENERAL_DELAY 10

/*
 * Classic Arduino functions
 */
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

#if IS_LOGGING
    Serial.begin(115200);
    Serial.println();
    Serial.println("Running setup ...");
    Serial.println();
#endif
        
#if RGB_SHIELD_ENABLED
    RgbShield_Setup();
#endif

#if WIFI_ENABLED
    Wifi_Setup();
#endif

#if OTA_ENABLED
    Ota_Setup();
#endif

#if MQTT_ENABLED
    Mqtt_Setup();
#endif

#if WEBSERVER_ENABLED
    WebServer_Setup();
#endif

#if SOFTWARESERIAL_ENABLED
    SoftwareSerial_Setup();
#endif
}

void loop() {
#if RGB_SHIELD_ENABLED
    RgbShield_colorLoop();
#endif

#if WIFI_ENABLED
    Wifi_Loop();
#endif

#if OTA_ENABLED
    Ota_Loop();
#endif

#if MQTT_ENABLED
    Mqtt_Loop();
#endif
   
#if WEBSERVER_ENABLED
    WebServer_Loop();
#endif

    delay(GENERAL_DELAY);
}
