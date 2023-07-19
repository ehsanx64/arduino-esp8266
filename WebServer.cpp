#include <ESP8266WebServer.h>

#include "WebServer.h"

ESP8266WebServer webServer(80);

void WebServer_Setup() {
    webServer.onNotFound(WebServer_NotFoundHandler);

    webServer.addHook([](const String & method, const String & url, WiFiClient * client, ESP8266WebServer::ContentTypeFunction contentType) {
        (void)method;       // GET, PUT, ...
        (void)url;          // example: /root/myfile.html
        (void)client;       // the webserver tcp client connection
        (void)contentType;  // contentType(".html") => "text/html"
        Serial.printf("A useless web hook has passed\n");
        Serial.printf("(this hook is in 0x%08x area (401x=IRAM 402x=FLASH))\n", esp_get_program_counter());
        Serial.println("URL: " + url);
        Serial.println("Method: " + method);
        return ESP8266WebServer::CLIENT_REQUEST_CAN_CONTINUE;
    });

    webServer.begin();
}

void WebServer_Loop() {
    webServer.handleClient();
}

void WebServer_NotFoundHandler() {
    String message = "File Not Found\n\n";
    message += "URI: ";
    message += webServer.uri();
    message += "\nMethod: ";
    message += (webServer.method() == HTTP_GET) ? "GET" : "POST";
    message += "\nArguments: ";
    message += webServer.args();
    message += "\n";
    
    for (uint8_t i = 0; i < webServer.args(); i++) {
        message += " " + webServer.argName(i) + ": " + webServer.arg(i) + "\n";
    }
    
    webServer.send(404, "text/plain", message);
}
