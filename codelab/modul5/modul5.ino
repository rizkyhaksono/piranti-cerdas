#define BLYNK_TEMPLATE_ID "TMPL6IminfV2W"
#define BLYNK_TEMPLATE_NAME "M4"
#define BLYNK_AUTH_TOKEN "PgybQeSID-ZuWJxOhW4yCvxkkpn1FuY7"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define LIGHT_SENSOR_PIN 32

BlynkTimer timer;

// konfigurasi nama hotspot/SSID beserta password
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Widodo";
char pass[] = "bigbunda123";

void send_data() {
  delay(1000);
  int analogValue = analogRead(LIGHT_SENSOR_PIN);
  Serial.print("Analog value: ");
  Serial.println(analogValue);
  Blynk.virtualWrite(V0, analogValue);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  timer.setInterval(1000L, send_data);
}

void loop() {
  Blynk.run();
  timer.run();
}
