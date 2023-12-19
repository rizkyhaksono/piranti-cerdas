#include <Wire.h>
#include <MPU6050_tockn.h>
#include <HTTPClient.h>
#include <WiFi.h>

const char* ssid = "Widodo";
const char* password = "bigbunda123";
const char* serverName = "http://192.168.106.81/modul6/insert_data.php";
const char* apiKey = "d7af46c2-a29e-4f00-aeef-4e7555d8b5de";
MPU6050 mpu6050(Wire);

int LED_PIN = 32;
int BUZZER_PIN = 14;

void setup() {
  Serial.begin(9600);
  delay(1000); // Add delay to ensure serial monitor connection

  Wire.begin();
  mpu6050.begin();
  connectToWiFi();

  ledcSetup(0, 5000, 8);
  ledcAttachPin(LED_PIN, 0);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  mpu6050.update();
  Serial.print("Angle X: ");
  float angleX = mpu6050.getAngleX();
  float angleY = mpu6050.getAngleY();

  Serial.print("Angle X: ");
  Serial.print(angleX);
  Serial.print("\tAngle Y: ");
  Serial.println(angleY);

  if (mpu6050.getAngleX() > 20 || mpu6050.getAngleY() > 20 || mpu6050.getAngleX() < -10 || mpu6050.getAngleY() < -10) {
    ledcWrite(0, 0);
    digitalWrite(LED_PIN, LOW);
    tone(BUZZER_PIN, 1000, 1000);
    Serial.println("Bidang tidak datar!");
  } else {
    ledcWrite(0, 255);
    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Bidang datar!");
  }

  // delay(1000);
  sendDataToServer();

}

void sendDataToServer() {
  char url[256];
  sprintf(url, "%s?apikey=%s&angkax=%f&angkay=%f",
          serverName, apiKey, mpu6050.getAngleX(), mpu6050.getAngleY());

  HTTPClient http;
  http.begin(url);
  int httpResponseCode = http.GET();

  if (httpResponseCode == 200) {
    Serial.println("Data sent successfully!");
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

void connectToWiFi() {
  WiFi.begin(ssid, password);
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(1000);
    Serial.println("Connecting to WiFi....");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
    Serial.println("Local IP: " + WiFi.localIP().toString());
  } else {
    Serial.println("Failed to connect to WiFi. Please check your credentials.");
  }
}
