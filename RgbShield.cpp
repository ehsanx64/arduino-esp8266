#include <WS2812FX.h>
#include "RgbShield.h"

// The single WS2812B LED on the shield is connected to D2 port on Wemos D1 Mini (lite)
Adafruit_NeoPixel led = Adafruit_NeoPixel(1, D2, NEO_GRB);

// Set first pixel (the only pixel on the shield) to the given color
void setColor(uint32_t color) {
    led.setPixelColor(0, color);
    led.show();
}

// More control over delays
int getDelay() {
    return (int) COLOR_DELAY / 5;
}

// Main application for now
void RgbShield_colorLoop() {
    int i = 0;
    
    // Green loop
    for (i = 0; i < COLOR_MAX; i++) {
#if IS_LOGGING
        Serial.println("Adding green: " + String(i));
#endif
        setColor(led.Color(i, 0, 0));
        delay(getDelay());
    }

    // Red loop
    for (i = 0; i < COLOR_MAX; i++) {
#if IS_LOGGING
        Serial.println("Adding red: " + String(i));
#endif
        setColor(led.Color(COLOR_MAX, i, 0));
        delay(getDelay());
    }

    // Blue loop
    for (i = 0; i < COLOR_MAX; i++) {
#if IS_LOGGING
        Serial.println("Adding blue: " + String(i));
#endif
        setColor(led.Color(COLOR_MAX, COLOR_MAX, i));
        delay(getDelay());
    }

    // Remove green
    for (i = COLOR_MAX; i >= 0; i--) {
#if IS_LOGGING
        Serial.println("Removing green: " + String(i));
#endif
        setColor(led.Color(i, COLOR_MAX, COLOR_MAX));
        delay(getDelay());
    }

    // Remove red
    for (i = COLOR_MAX; i >= 0; i--) {
#if IS_LOGGING
        Serial.println("Removing red: " + String(i));
#endif
        setColor(led.Color(0, i, COLOR_MAX));
        delay(getDelay());
    }

    // Remove blue
#if IS_LOGGING
        Serial.println("Removing blue: " + String(i));
#endif

    for (i = COLOR_MAX; i >= 0; i--) {
        setColor(led.Color(0, 0, i));
        delay(getDelay());
    }
}

void RgbShield_Setup() {
    led.begin();
    led.show();
}
