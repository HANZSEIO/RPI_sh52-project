#pragma once
#include <Arduino.h>

void mqttInit();
void mqttLoop();
void mqttPublishState(uint8_t relay, bool state);
bool mqttIsConnected();
void mqttCallback(char* topic, byte* payload, unsigned int length);
