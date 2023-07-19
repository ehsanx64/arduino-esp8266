/*
 * ESP8266 Development using Arduino Framework
 */

/*
 * Features
 * 
 * Comment/uncomment each header to enable/disable it
 */
#include "RgbShield.h"

#define LOGGING false

// General loop() delay
#define GENERAL_DELAY 1000

/*
 * Classic Arduino functions
 */
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
        
#if WITH_RGB_SHIELD
    rgb_shield_setup();
#endif

#if LOGGING
    Serial.begin(115200);
#endif
}

void loop() {
#if LOGGING
    Serial.println("Loop...");
#endif

#if WITH_RGB_SHIELD
    rgb_shield_color_loop();
#endif   

    delay(GENERAL_DELAY);
}
