#include <SoftwareSerial.h>

EspSoftwareSerial::UART ssw;

const short unsigned int SSW_TX = 2;
const short unsigned int SSW_RX = 0;

void SoftwareSerial_Setup() {
    ssw.begin(19200, SWSERIAL_8N1, SSW_RX, SSW_TX, false);

    if (!ssw) {
        Serial.println("Failed to initialize ssw");
        while (1) delay(1000);
    } else {
        Serial.println("ssw initialized");
    }
}
