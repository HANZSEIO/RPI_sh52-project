#include <Arduino.h>
#include "network/wifi_manager.h"
#include "mqtt/mqtt_client.h"
#include "hub/hub_router.h"
void setup() {
    Serial.begin(115200);
    Serial.println("\nBOOTING SMART HOME HUB");

    wifiInit();
    mqttInit();
}

void loop() {
    mqttLoop();
    delay(10);
}