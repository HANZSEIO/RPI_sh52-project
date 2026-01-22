#include "relay_controller.h"

static const uint8_t relayPins[4] = { D1, D2, D5, D6 };
static bool relayState[4] = { false, false, false, false };

void relayInit() {
    for (int i = 0; i < 4; i++) {
        pinMode(relayPins[i], OUTPUT);
        digitalWrite(relayPins[i], HIGH);
    }
    Serial.println("Relay init done");
}

void relaySet(uint8_t index, bool on) {
    if (index < 1 || index > 4) return;
    relayState[index - 1] = on;
    digitalWrite(relayPins[index - 1], on ? LOW : HIGH);
}

bool relayGet(uint8_t index) {
    if (index < 1 || index > 4) return false;
    return relayState[index - 1];
}
