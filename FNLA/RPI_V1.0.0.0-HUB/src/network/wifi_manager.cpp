#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>   
#endif

#include "wifi_manager.h"
#include "../config/config.h"

void wifiInit() {
    Serial.print("WiFi: connecting");
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi: CONNECTED");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());

}
bool wiifiIsConnected() {
    return WiFi.status() == WL_CONNECTED;
}