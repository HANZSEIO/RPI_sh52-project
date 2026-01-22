#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "mqtt_client.h"
#include "../config/config.h"
#include "../protocol/topic.h"
#include "../network/wifi_manager.h"
#include "../relay/relay_controller.h"


WiFiClient espClient;
PubSubClient mqtt(espClient);

void mqttInit() {
    mqtt.setServer(MQTT_SERVER, MQTT_PORT);
    mqtt.setCallback(mqttCallback);
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
    String msg;
    for (unsigned int i = 0; i < length; i++) {
        msg += (char)payload[i];
    }

    for (uint8_t i = 1; i <= 4; i++) {
        if (String(topic) == relaySetTopic(i)) {
            bool on = (msg == "ON");
            relaySet(i - 1, on);
            mqttPublishState(i, on);
        }
    }
}

void mqttLoop() {
    if (!wifiIsConnected()) return;

    if (!mqtt.connected()) {
        Serial.println("MQTT reconnecting...");

        if (mqtt.connect(
            NODE_ID,
            MQTT_USER,
            MQTT_PASS,
            statusTopic().c_str(),
            1,
            true,
            "offline"
        )) {

            mqtt.publish(statusTopic().c_str(), "online", true);

            for (uint8_t i = 1; i <= 4; i++) {
                mqtt.subscribe(relaySetTopic(i).c_str());
            }

        } else {
            Serial.print("MQTT failed, rc=");
            Serial.println(mqtt.state());
        }
    }

    mqtt.loop();
}

void mqttPublishState(uint8_t relay, bool state) {
    mqtt.publish(
        relayStateTopic(relay).c_str(),
        state ? "ON" : "OFF",
        true
    );
}

bool mqttIsConnected() {
    return mqtt.connected();
}
