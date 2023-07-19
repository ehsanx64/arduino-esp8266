#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include "Wifi.h"

void Wifi_Setup() {
#if WIFI_AP_ENABLED
    // Set the module as a Wifi access point
    Serial.println("Setting WiFi Soft AP ... ");
    if (WiFi.softAP(WIFI_AP_ESSID, WIFI_AP_PSKEY)) {
        Serial.println("Access point ready!");
        Serial.printf("ESSID: %s\nPSKEY: %S\n", WIFI_AP_ESSID, WIFI_AP_PSKEY);
    } else {
        Serial.println("Failed!");
    }

#else
    // If Wifi access point is not enabled, we'll continue as a station
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_STA_ESSID, WIFI_STA_PSKEY);

    // Wait for connection
    Serial.printf("Trying to connect to '%s' ", WIFI_STA_ESSID);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("Connected!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
#endif

    if (MDNS.begin(MDNS_NAME)) {
        Serial.println("MDNS Name: " + String(MDNS_NAME));
    }
}
