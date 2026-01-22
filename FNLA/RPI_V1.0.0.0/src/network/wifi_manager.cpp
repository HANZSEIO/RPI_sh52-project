#include "wifi_manager.h"
#include "../config/config.h"

unsigned long lastWiFiCheck = 0;

void wifiInit() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

     Serial.print("WiFi connecting to ");
        Serial.println(WIFI_SSID);
}

void wifiLoop() {
    if (millis() - lastWiFiCheck < 5000) return;
    lastWiFiCheck = millis();

    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi: DISCONNECTED");
        WiFi.disconnect();
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    } else {
        Serial.print("WiFi: CONNECTED IP=");
        Serial.println(WiFi.localIP());
    }
}

bool wifiIsConnected() {
    return WiFi.status() == WL_CONNECTED;
}

IPAddress wifiGetIP() {
    return WiFi.localIP();
}
