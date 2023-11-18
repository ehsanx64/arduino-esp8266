#include <ArduinoOTA.h>
#include "Ota.h"

#define LED 2

// Main application for now
void Ota_Loop() {
	ArduinoOTA.handle();
}

void Ota_Setup() {
	pinMode(LED, OUTPUT);
	flash(2);

	// Hostname defaults to esp8266-[ChipID]
	ArduinoOTA.setHostname(OTA_HOSTNAME);
	
    ArduinoOTA.onStart([]() {
		String type;
		
		digitalWrite(LED, LOW);
		if (ArduinoOTA.getCommand() == U_FLASH) {
			type = "sketch";
		} else {  // U_FS
			type = "filesystem";
		}
		
		// NOTE: if updating FS this would be the place to unmount FS using FS.end()
		Serial.println("Start updating " + type);
	});
	
	ArduinoOTA.onEnd([]() {
		flash(10);
		Serial.println("\nEnd");
	});
	
	ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
		flash(1);
		Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
	});
	
	ArduinoOTA.onError([](ota_error_t error) {
		Serial.printf("Error[%u]: ", error);
		if (error == OTA_AUTH_ERROR) {
			Serial.println("Auth Failed");
		} else if (error == OTA_BEGIN_ERROR) {
			Serial.println("Begin Failed");
		} else if (error == OTA_CONNECT_ERROR) {
			Serial.println("Connect Failed");
		} else if (error == OTA_RECEIVE_ERROR) {
			Serial.println("Receive Failed");
		} else if (error == OTA_END_ERROR) {
			Serial.println("End Failed");
		}
	});
	
	ArduinoOTA.begin();

	digitalWrite(LED, LOW);
}

void flash(int count) {
	for (int i = 0; i < count; i++) {
		digitalWrite(LED, LOW);
		delay(50);
		digitalWrite(LED, HIGH);
		delay(100);
	}	
}
