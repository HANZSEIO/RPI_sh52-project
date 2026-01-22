#include <Arduino.h>
#include "network/wifi_manager.h"
#include "mqtt/mqtt_client.h"
#include "relay/relay_controller.h"

unsigned long lastPrint = 0;

void setup() {
    Serial.begin(115200);
    delay(1000);

    relayInit();
    wifiInit();
    mqttInit();

    Serial.println("=== NODE ESP8266 BOOT ===");
}

void loop() {
    wifiLoop();
    mqttLoop();

    if (millis() - lastPrint > 3000) {
        lastPrint = millis();

        Serial.println("--------------------------");

        if (wifiIsConnected()) {
            Serial.print("WiFi: CONNECTED ");
            Serial.println(wifiGetIP());
        } else {
            Serial.println("WiFi: DISCONNECTED");
        }

        if (mqttIsConnected()) {
            Serial.println("MQTT: CONNECTED");
        } else {
            Serial.println("MQTT: DISCONNECTED / reconnecting...");
        }

        for (int i = 1; i <= 4; i++) {
            Serial.print("Relay");
            Serial.print(i);
            Serial.print(": ");
            Serial.println(relayGet(i) ? "ON" : "OFF");
        }
    }

    yield();
}
