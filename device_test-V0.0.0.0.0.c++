#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Twins2.4";
const char* password = "200812556";

ESP8266WebServer server(80);

// Pin relay (active LOW)
int relayPin[6] = {5, 4, 14, 12, 13, 16}; // D1, D2, D5, D6, D7, D0
bool relayState[6] = {0, 0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 6; i++) {
    pinMode(relayPin[i], OUTPUT);
    digitalWrite(relayPin[i], HIGH); // OFF (active LOW)
  }

  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String html = "<h2>SMART HOME - 6 RELAY</h2>";

  for (int i = 0; i < 6; i++) {
    html += "Relay " + String(i + 1) + " : ";
    html += relayState[i] ? "ON" : "OFF";
    html += " <a href=\"/on?ch=" + String(i) + "\">ON</a>";
    html += " <a href=\"/off?ch=" + String(i) + "\">OFF</a><br>";
  }

  server.send(200, "text/html", html);
}

void handleOn() {
  int ch = server.arg("ch").toInt();
  relayState[ch] = true;
  digitalWrite(relayPin[ch], LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleOff() {
  int ch = server.arg("ch").toInt();
  relayState[ch] = false;
  digitalWrite(relayPin[ch], HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}