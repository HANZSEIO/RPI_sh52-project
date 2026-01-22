#include "mqtt_client.h"
#include <PubSubClient.h>
#include "../hub/hub_router.h"

#include <ESP8266WiFi.h>
#include "../config/config.h"


WiFiClient espClient;
PubSubClient mqtt(espClient);

void mqttCallBack(char* topic, byte* payload, unsigned int lenght) {
    String msg;
    for (unsigned int i = 0; i < lenght; i++) {
        // msg += (char)payload[i];
    }

    hubRoute(String(topic), msg);
}

void mqttInit() {
    mqtt.setServer(MQTT_SERVER, MQTT_PORT);
    mqtt.setCallback(mqttCallBack);
}

void mqttLoop() {
    if (!mqtt.connected()) {
        // Serial.println("MQTT: DISCONNECTED / reconnecting...");
        if (mqtt.connect(DEVICE_NAME, MQTT_USER, MQTT_PASS)) {
            Serial.println("MQTT: CONNECTED");
            mqtt.subscribe("smarthome/#");
            // mqtt.subscribe("smarthome/+/relay/+/state");
            // Serial.print("MQTT: subscribe to all nodes");
        } else {
            Serial.println("MQTT: FAILED");
        }
        mqtt.loop();
    }
}
    void mqttPublish(const String& topic, const String& payload) {
        mqtt.publish(topic.c_str(), payload.c_str());
    }

    bool mqttIsConnected() {
        return mqtt.connected();
    }
