#pragma once
#include <Arduino.h>

void hubInt();
void hubLoop();

void hubRoute(const String& topic, const String& payload);