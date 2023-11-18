/*
 * MQTT publish/subscribe functionality for ESP8266
 * Using PubSubClient library from http://imroy.github.io/pubsubclient
 */
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

#include "Mqtt.h"

#define BUFFER_SIZE 100

IPAddress broker;
WiFiClient wclient;
PubSubClient client(wclient);

void Mqtt_Setup() {
	Serial.println("Setting up the MQTT client ...");
	Mqtt_setBrokerIp();
	client.set_callback(Mqtt_Callback);
}

void Mqtt_Loop() {
	if (!client.connected()) {
    	Serial.println("Connecting to MQTT broker at " + broker.toString());
      	if (client.connect(MQTT::Connect(MQTT_CLIENT_NAME).set_auth(MQTT_BROKER_USERNAME, MQTT_BROKER_PASSWORD))) {
      		Serial.println("Connected to MQTT broker");
      		client.set_callback(Mqtt_Callback);      		
			client.subscribe(MQTT_BROKER_TOPIC + String("/heartbeat"));
			client.subscribe(MQTT_BROKER_TOPIC + String("/color"));
		 }		
	} else {
		client.publish((MQTT_BROKER_TOPIC + String("/heartbeat")).c_str(),String(millis()));
		client.loop();
		delay(2000);
    }
}

void Mqtt_Callback(const MQTT::Publish& pub) {
    Serial.print(pub.topic());
	Serial.print(" => ");
	uint8_t buf[BUFFER_SIZE];
	int read;
	
	if (pub.has_stream()) {
		memset(buf, 0, BUFFER_SIZE);
		
		while (read = pub.payload_stream()->read(buf, BUFFER_SIZE)) {
			Serial.write(buf, read);
		}
		
		pub.payload_stream()->stop();
		Serial.println("");
	} else {
		Serial.println(pub.payload_string());
		
		if (pub.topic() == MQTT_BROKER_TOPIC + String("/color")) {
			Mqtt_HandleColorTopic(pub.payload_string());
		}
    }
}

void Mqtt_setBrokerIp() {
	const char *brokerIp = MQTT_BROKER_IP;
	bool r = false;
	
	r = broker.isSet();
	if (r) {
		Serial.println("IP address is set");
	} else {
		Serial.println("IP address is not set. Trying to set it ...");
		r = broker.isValid(brokerIp);
		if (!r) {
			Serial.println("IP address is invalid");
		} else {
			r = broker.fromString(brokerIp);
			if (r) {
				Serial.println("IP address for broker updated");
			}	
		}
	}

	client.set_server(broker, MQTT_BROKER_PORT);
	Serial.println("MQTT Broker IP: " + broker.toString());
}

void Mqtt_HandleColorTopic(String payload) {
	if (payload == "red") {
		Serial.println("Set color to red");
	} else if (payload == "green") {
		Serial.println("Set color to green");
	} else if (payload == "blue") {
		Serial.println("Set color to blue");
	} else {
		Serial.println("Unsupported color");
	}
}
