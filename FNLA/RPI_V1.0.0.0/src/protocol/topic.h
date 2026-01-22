#pragma once
#include "../config/config.h"

inline String baseTopic() {
    return String("smarthome/") + PRODUCT_ID;
}

inline String relaySetTopic(uint8_t relay) {
    return baseTopic() + "/relay/" + String(relay) + "/set";
}

inline String relayStateTopic(uint8_t relay) {
    return baseTopic() + "/relay/" + String(relay) + "/state";
}

inline String statusTopic() {
    return baseTopic() + "/status";
}
