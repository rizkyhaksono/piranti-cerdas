#include <NewPing.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include "DHT.h"

#define TRIGGER_PIN 26  // D26
#define ECHO_PIN 25     // D25
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define LIGHT_PIN 12     // D12, the pin to which the light is connected
#define SERVER_URL "http://192.168.1.12:3000/api/sensor" // Update with your server IP

#define RELAY_PIN 14
#define DHTPIN 27
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

const int LDRPin = 34;
const char *ssid = "Widodo";
const char *password = "bigbunda123";
// int RELAY_PIN = 35;

void setup() {
  Serial.begin(115200);
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(LDRPin, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  dht.begin();
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void analyzeLightSensor(int lightSensorValue) {
  Serial.print("Light Sensor Value: ");
  Serial.println(lightSensorValue);

  if (lightSensorValue >= 0 && lightSensorValue <= 50) {
    Serial.println("Keadaan Gelap");
  } else if (lightSensorValue > 50 && lightSensorValue <= 500) {
    Serial.println("Keadaan Redup");
  } else if (lightSensorValue > 500 && lightSensorValue <= 2000) {
    Serial.println("Cahaya Terang");
  } else {
    Serial.println("Sangat Terang");
  }
}

void loop() {
  delay(50);  // Wait for the sensor to stabilize

  int lightValue = analogRead(LDRPin);
  analyzeLightSensor(lightValue);
  unsigned int distance = sonar.ping_cm();
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (distance != NO_ECHO) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    Serial.println("Object detected! Triggering action...");

    if (temperature < 30.0) {
      if (distance < 15 || lightValue < 1000) {
        // if (temperature > 30.0) {
        //     Serial.println("\nPERINGATAN: Suhu sangat panas! Aktifkan kipas angin kandang segera.");
        //     digitalWrite(RELAY_PIN, HIGH);
        // } else {
        //     Serial.println("\nSuhu dingin");
        //     digitalWrite(RELAY_PIN, LOW);
        // }
        // digitalWrite(RELAY_PIN, LOW);
        Serial.println("RELAY_PIN turned ON");
        digitalWrite(RELAY_PIN, LOW);
        Serial.print("RELAY_PIN value: ");
        Serial.print("\nHumidity: ");
        Serial.print(humidity);
        Serial.print(" %\t");
        Serial.print("\nTemperature: ");
        Serial.print(temperature);

        // sendData(distance, lightValue);
      }

      if (distance > 16 || lightValue > 1001) {
        // if (temperature > 30.0) {
        //     Serial.println("\nPERINGATAN: Suhu sangat panas! Aktifkan kipas angin kandang segera.");
        // } else {
        //     Serial.println("\nSuhu dingin");
        //     digitalWrite(RELAY_PIN, HIGH);
        // }
        // digitalWrite(RELAY_PIN, HIGH);
        Serial.println("RELAY_PIN turned OFF");
        digitalWrite(RELAY_PIN, HIGH);
        Serial.print("RELAY_PIN value: ");
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.print(" %\t");
        Serial.print("Temperature: ");
        Serial.print(temperature);

        // sendData(distance, lightValue);
      }
    } else {
        Serial.println("\nPERINGATAN: Suhu sangat panas! Aktifkan kipas angin kandang segera.");
        digitalWrite(RELAY_PIN, HIGH);
        Serial.print(" %\t");
        Serial.print("Temperature: ");
        Serial.print(temperature);
    }
  } else {
    Serial.println("Error: No echo");
  }

  delay(500);  // Adjust the delay based on your requirements
}

void sendData(int jarak, int ldr_value) {
  HTTPClient http;

  // Construct the JSON payload
  String payload = "{\"jarak\":" + String(jarak) + ",\"ldr_value\":" + String(ldr_value) + "}";

  http.begin(SERVER_URL);
  http.addHeader("Content-Type", "application/json");

  int httpResponseCode = http.POST(payload);

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.println("Error in HTTP request");
  }

  http.end();
}