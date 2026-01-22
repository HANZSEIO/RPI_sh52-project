#pragma once
#include <Arduino.h>

void relayInit();
void relaySet(uint8_t index, bool on);
bool relayGet(uint8_t index);
