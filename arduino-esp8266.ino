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


}

void loop() {
#if RGB_SHIELD_ENABLED
    RgbShield_colorLoop();
#endif   

    delay(GENERAL_DELAY);
}
