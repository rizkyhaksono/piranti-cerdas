#include <WiFi.h>

const char* ssid = "Widodo";
// const char* ssid = "test2";
const char* password = "anjing69";

void setup() {
  // Serial.begin(115200);
  Serial.begin(9600);
  WiFi.begin(ssid,password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println(WiFi.localIP());
  Serial.println("Connected to WiFi");
}

void loop() {
  
}