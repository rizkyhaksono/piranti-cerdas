#include <NewPing.h>
#include <HTTPClient.h>
#include <WiFi.h>

#define TRIGGER_PIN 26  // D26
#define ECHO_PIN 25     // D25
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define LIGHT_PIN 12     // D12, the pin to which the light is connected
#define SERVER_URL "http://172.20.10.5:3000/api/sensor" // Update with your server IP

#define RELAY_PIN 23

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

const int LDRPin = 34;
const char *ssid = "Rizky";
const char *password = "02270509";
// int RELAY_PIN = 35;

void setup() {
  Serial.begin(115200);
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(LDRPin, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
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
  // int relayValue = param.asInt();
  digitalWrite(RELAY_PIN, HIGH);

  if (distance != NO_ECHO) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Add your logic here based on the distance
    // For example, if distance is less than a certain threshold, trigger an action
    if (distance < 50) {
      // Your action or code here when the distance is less than 50 cm
      Serial.println("Object detected! Triggering action...");

      // Check if the distance is less than 15 cm and turn on the light
      // if (distance < 15 || LDRPin < 500) {
      if (distance < 15) {
        // digitalWrite(LIGHT_PIN, HIGH);  // Turn on the light
        digitalWrite(RELAY_PIN, HIGH);
        Serial.print("RELAY_PIN value: ");
        Serial.println(RELAY_PIN);
        // Serial.print("Harusnya nyalasih ini");
        // Send data to the server
        // sendData(distance, 2000); // Update with your desired LDR value
      }

      // if (distance > 15 || LDRPin > 500 || LDRPin < 2000) {
      //   digitalWrite(LIGHT_PIN, 128);
      // }

      // if (distance > 15 || LDRPin > 1000) {
      if (distance > 15) {
        // digitalWrite(LIGHT_PIN, LOW);
        digitalWrite(RELAY_PIN, HIGH);
        Serial.print("RELAY_PIN value: ");
        Serial.println(RELAY_PIN);
      }
    }
  } else {
    Serial.println("Error: No echo");
        digitalWrite(RELAY_PIN, HIGH);

    // analogWrite(LIGHT_PIN, LOW);
    // digitalWrite(RELAY_PIN, LOW);
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


// #include <NewPing.h>
// #include <WiFi.h>
// #include <AsyncTCP.h>
// #include <ArduinoJson.h>

// #define TRIGGER_PIN 26  // D26
// #define ECHO_PIN 25     // D25
// #define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
// #define LIGHT_PIN 12     // D12, the pin to which the light is connected
// #define SERVER_URL "http://172.20.10.5:3000/api/sensor" // Update with your server IP

// NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// const char *ssid = "lorem";
// const char *password = "test1234";

// AsyncWebServer server(80);

// void setup() {
//   Serial.begin(115200);
//   pinMode(LIGHT_PIN, OUTPUT);

//   // Connect to Wi-Fi
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to WiFi...");
//   }
//   Serial.println("Connected to WiFi");

//   // Route for handling HTTP POST requests
//   server.on("/api/sensor", HTTP_POST, [](AsyncWebServerRequest *request){
//     String jsonPayload = request->getParam("plain")->value();
//     Serial.print("Received JSON payload: ");
//     Serial.println(jsonPayload);

//     // Parse JSON payload
//     DynamicJsonDocument doc(1024);
//     DeserializationError error = deserializeJson(doc, jsonPayload);
//     if (error) {
//       Serial.print("Error parsing JSON: ");
//       Serial.println(error.c_str());
//       request->send(400, "application/json", "{\"error\":\"Invalid JSON\"}");
//       return;
//     }

//     int jarak = doc["jarak"];
//     int ldr_value = doc["ldr_value"];

//     // Handle your data as needed
//     // Add your logic here based on the received data

//     request->send(200, "application/json", "{\"status\":\"success\"}");
//   });
// }

// void loop() {
//   delay(50);  // Wait for the sensor to stabilize

//   unsigned int distance = sonar.ping_cm();

//   if (distance != NO_ECHO) {
//     Serial.print("Distance: ");
//     Serial.print(distance);
//     Serial.println(" cm");

//     // Add your logic here based on the distance
//     // For example, if distance is less than a certain threshold, trigger an action
//     if (distance < 50) {
//       // Your action or code here when the distance is less than 50 cm
//       Serial.println("Object detected! Triggering action...");

//       // Check if the distance is less than 15 cm and turn on the light
//       if (distance < 15) {
//         digitalWrite(LIGHT_PIN, HIGH);  // Turn on the light

//         // Send data to the server asynchronously
//         sendDataAsync(distance, 2000); // Update with your desired LDR value
//       } else {
//         digitalWrite(LIGHT_PIN, LOW);  // Turn off the light if the distance is greater than or equal to 15 cm
//       }
//     }
//   } else {
//     Serial.println("Error: No echo");
//   }

//   delay(500);  // Adjust the delay based on your requirements
// }

// void sendDataAsync(int jarak, int ldr_value) {
//   // Construct the JSON payload
//   String payload = "{\"jarak\":" + String(jarak) + ",\"ldr_value\":" + String(ldr_value) + "}";

//   // Send data to the server asynchronously
//   AsyncHTTPClient *httpClient = new AsyncHTTPClient();
//   httpClient->begin(SERVER_URL);
//   httpClient->addHeader("Content-Type", "application/json");

//   // Send POST request with the payload
//   httpClient->POST(payload);

//   // Don't forget to clean up
//   delete httpClient;
// }
