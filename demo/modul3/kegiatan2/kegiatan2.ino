#include <MPU6050_tockn.h>
#include <WiFi.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

const char* ssid = "Widodo";

const int buzzerPin = 25;

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  WiFi.begin(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets();
}

void loop() {
  mpu6050.update();
  Serial.print("Angle X : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tAngle Y : ");
  Serial.println(mpu6050.getAngleY());
  if (mpu6050.getAngleX() > 20) {
    analogWrite(buzzerPin, 63);
    Serial.println("Tilted Forward");
    delay(500);
  } else if (mpu6050.getAngleX() < -20) {
    analogWrite(buzzerPin, 126);
    Serial.println("Tilted Back");
    delay(500);
  } else if (mpu6050.getAngleY() > 20) {
    analogWrite(buzzerPin, 189);
    Serial.println("Tilted To The Left");
    delay(500);
  } else if (mpu6050.getAngleY() < -20) {
    analogWrite(buzzerPin, 255);
    Serial.println("Tilted To The Right");
    delay(500);
  } else {
    analogWrite(buzzerPin, 0);
    delay(500);
  }
}