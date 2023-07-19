#ifndef WIFI_DEFINED
#define WIFI_DEFINED

/*
 * Configuration
 */
#define WIFI_ENABLED true
#define WIFI_AP_ENABLED false

// Wifi access point credentials
#define WIFI_AP_ESSID "Electrofruit"
#define WIFI_AP_PSKEY "ef0123456789"

// Wifi station credentials
#define WIFI_STA_ESSID "Electrofruit"
#define WIFI_STA_PSKEY "ef0123456789"

// mDNS
#define MDNS_NAME "Electrofruit"

// Function prototypes (global)
void Wifi_Setup();
void Wifi_Loop();

#endif
