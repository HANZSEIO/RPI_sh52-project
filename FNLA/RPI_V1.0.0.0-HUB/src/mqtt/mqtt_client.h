#pragma once
#include <Arduino.h>

void mqttInit();
void mqttLoop();
bool mqttIsConnected();
void mqttPublish(const String& topic, const String& payload);