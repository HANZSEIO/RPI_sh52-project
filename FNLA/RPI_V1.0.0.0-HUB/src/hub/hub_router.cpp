#include "hub_router.h"
#include <Arduino.h>
#include "../mqtt/mqtt_client.h"

void hubInit() {
    //state machine buat nanti ya mbut
}

void hubRoute(const String& topic, const String& payload) {
    // Serial.print("[HUB] ");
    // Serial.print(topic);
    // Serial.print(" => ");

    mqttPublish(topic, payload);
}