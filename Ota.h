#ifndef OTA_DEFINED
#define OTA_DEFINED

#include "Wifi.h"

#define OTA_ENABLED true
#define OTA_HOSTNAME MDNS_NAME


// Function prototypes (global)
void Ota_Setup();
void Ota_Loop();

void flash(int count);

#endif
