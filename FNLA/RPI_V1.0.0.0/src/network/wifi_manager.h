#pragma once
#include <ESP8266WiFi.h>

void wifiInit();
void wifiLoop();
bool wifiIsConnected();
IPAddress wifiGetIP();
