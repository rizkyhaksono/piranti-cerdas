#include <WiFi.h>

const char* primarySSID = "Widodo";
const char* primaryPassword = "bigbunda123";

void setup() {
  Serial.begin(115200);
  connectToWiFi(primarySSID, primaryPassword);
}

void loop() {
}

void connectToWiFi(const char* ssid, const char* password) {
  Serial.println("Mencoba menghubungkan ke WiFi...");
  
  WiFi.begin(ssid, password);

  int tryCount = 0;
  bool connected = false;
  
  while (!connected && tryCount < 4) {
    delay(1000);
    tryCount++;

    if (tryCount == 1) {
      Serial.println("Gagal terhubung ke WiFi utama. Mencoba jaringan WiFi terbuka...");
      WiFi.begin("", "");
    } else if (tryCount == 2) {
      Serial.println("Gagal terhubung ke WiFi terbuka. Mencoba jaringan WiFi terbuka lainnya...");
      WiFi.scanNetworks();
      for (int i = 0; i < WiFi.scanComplete(); i++) {
        if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
          Serial.print("Mencoba terhubung ke jaringan WiFi terbuka: ");
          Serial.println(WiFi.SSID(i));
          WiFi.begin(WiFi.SSID(i), "");
          break;
        }
      }
    } else if (tryCount == 3) {
      Serial.println("Gagal terhubung ke semua jaringan WiFi yang tersedia.");
    }
    
    if (WiFi.status() == WL_CONNECTED) {
      connected = true;
    }
  }

  if (connected) {
    Serial.println("Terhubung ke jaringan WiFi:");
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());
    Serial.print("Alamat IP: ");
    Serial.println(WiFi.localIP());
  } else {
      connectToOpenWiFi();
  }
}

void connectToOpenWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  int numNetworks = WiFi.scanNetworks();
  if (numNetworks == 0) {
    Serial.println("No open networks found.");
  } else {
    for (int i = 0; i < numNetworks; i++) {
      if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
        Serial.print("Connecting to open network: ");
        Serial.println(WiFi.SSID(i));
        WiFi.begin(WiFi.SSID(i).c_str());
        while (WiFi.status() != WL_CONNECTED) {
          delay(1000);
          Serial.println("Connecting...");
        }
        Serial.println("Connected to WiFi:");
        Serial.print("SSID: ");
        Serial.println(WiFi.SSID());
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
        break;
      }
    }
  }
}
