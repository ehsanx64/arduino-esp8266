#ifndef MQTT_DEFINED
#define MQTT_DEFINED

#include <PubSubClient.h>

#include "Wifi.h"

#define MQTT_ENABLED true
#define MQTT_BROKER_IP "0.0.0.0"
#define MQTT_BROKER_PORT 1883
#define MQTT_BROKER_USERNAME "user"
#define MQTT_BROKER_PASSWORD "pass"
#define MQTT_BROKER_TOPIC "testing"

#define MQTT_CLIENT_NAME "ArduinoPubSubClient"

// Function prototypes (global)
void Mqtt_Setup();
void Mqtt_Loop();

void Mqtt_Callback(const MQTT::Publish& pub);
void Mqtt_setBrokerIp();
void Mqtt_HandleColorTopic(String payload);

#endif
