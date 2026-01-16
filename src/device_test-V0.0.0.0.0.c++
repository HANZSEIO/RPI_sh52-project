#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Twins2.4";
const char* password = "200812556";

const char* mqtt_server = "192.168.100.4";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

//rellay ACTL
int relayPin[4] = {5,4,14,12};
bool relayState[4] = {0};

void callback(char* topic, byte* payload, unsigned int length) {
  String msg;
  for (unsigned int i = 0; i < length; i++) msg += (char)payload[i];

  for (int i = 0; i < 4; i++) {
    String t = "smarthome/node1/relay/" + String(i+1) + "/set";
    if (String(topic) == t) {
      if (msg == "ON") {
        digitalWrite(relayPin[i], LOW);
        relayState[i] = true;
      } else {
        digitalWrite(relayPin[i], HIGH);
        relayState[i] = false;
      }

      client.publish(
        ("smarthome/node1/relay/" + String(i + 1) + "/state").c_str(),
        relayState[i] ? "ON" : "OFF",
        true
      );
    }
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect(
          "node1",
          "smarthome/node1/status",
          0,
          true,
          "offline")) {

      Serial.println("MQTT: CONNECTED");
      client.publish("smarthome/node1/status", "online", true);

      for (int i = 0; i < 4; i++) {
        String topic = "smarthome/node1/relay/" + String(i + 1) + "/set";
        client.subscribe(topic.c_str());
        Serial.print("SUB: " + topic);
      }

    } else {
      Serial.println("MQTT FAIL, rc=");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nESP BOOT OKS");

  for (int i = 0; i < 4; i++) {
    pinMode(relayPin[i], OUTPUT);
    digitalWrite(relayPin[i], HIGH);
  }

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.print("IP ESP: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  static unsigned long t = 0;
  if (millis() - t > 2000) {
    Serial.print("millis=");
    Serial.print(millis());
    Serial.print(" | last=");
    Serial.println(t);
    t = millis();
  }

  delay(10); // anti WDT
}

