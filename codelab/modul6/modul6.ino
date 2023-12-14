
// #include <DHT.h>
// #define DHT_SENSOR_PIN  25 // ESP32 pin GPIO21 connected to DHT11 sensor
// #define DHT_SENSOR_TYPE DHT11

// DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

// void setup() {
//   Serial.begin(9600);
//   dht_sensor.begin(); // initialize the DHT sensor
// }

// void loop() {
//   // read humidity
//   float humi  = dht_sensor.readHumidity();
//   // read temperature in Celsius
//   float tempC = dht_sensor.readTemperature();
//   // read temperature in Fahrenheit
//   float tempF = dht_sensor.readTemperature(true);

//   // check whether the reading is successful or not
//   if ( isnan(tempC) || isnan(tempF) || isnan(humi)) {
//     Serial.println("Failed to read from DHT sensor!");
//   } else {
//     Serial.print("Humidity: ");
//     Serial.print(humi);
//     Serial.print("%");

//     Serial.print("  |  ");

//     Serial.print("Temperature: ");
//     Serial.print(tempC);
//     Serial.print("°C  ~  ");
//     Serial.print(tempF);
//     Serial.println("°F");
//   }

//   // wait a 2 seconds between readings
//   delay(500);
// }

// #define BLYNK_PRINT Serial
// #define BLYNK_TEMPLATE_ID "TMPL6ttHOvtGY"
// #define BLYNK_TEMPLATE_NAME "Temp"
// #define BLYNK_AUTH_TOKEN "roy9CGZ9u8QsKuXsMZrEgNBN4Dx4MsT2"

// #include <Blynk.h>
// #include <WiFi.h>
// #include <WiFiClient.h>
// #include <BlynkSimpleEsp32.h>

// char auth[] = BLYNK_AUTH_TOKEN;
// char ssid[] = "Tlogomas29";
// char pass[] = "sudahkahandashalat";

// #include "DHT.h"
// #define DHTPIN 32
// #define DHTTYPE DHT11
// DHT dht(DHTPIN, DHTTYPE);

// void setup()
// {
//     Serial.begin(115200);
//     Blynk.begin(auth, ssid, pass);
//     Serial.println("DHT11 Output!");
//     dht.begin();
// }

// void loop()
// {
//     Blynk.run();
//     float temperature = dht.readTemperature();
//     float humidity = dht.readHumidity();

//     if (isnan(temperature) || isnan(humidity))
//     {
//         Serial.println("Failed to read DHT11");
//     }
//     else
//     {
//         Serial.print("Humidity: ");
//         Serial.print(humidity);
//         Serial.print(" %\t");
//         Serial.print("Temperature: ");
//         Serial.print(temperature);
//         Serial.println(" *C");

//         // Kirim data ke Blynk (Menukar V0 dan V1)
//         Blynk.virtualWrite(V1, humidity);  // Kirim kelembaban ke pin virtual V1
//         Blynk.virtualWrite(V0, temperature);  // Kirim suhu ke pin virtual V0

//         delay(3000);
//     }
// }

// #define BLYNK_PRINT Serial
// #define BLYNK_TEMPLATE_ID "TMPL6ttHOvtGY"
// #define BLYNK_TEMPLATE_NAME "Temp"
// #define BLYNK_AUTH_TOKEN "roy9CGZ9u8QsKuXsMZrEgNBN4Dx4MsT2"

// #include <Blynk.h>
// #include <WiFi.h>
// #include <WiFiClient.h>
// #include <BlynkSimpleEsp32.h>

// BlynkTimer timer;

// char auth[] = BLYNK_AUTH_TOKEN;
// char ssid[] = "lorem";
// char pass[] = "test1234";

// #include "DHT.h"
// #define DHTPIN 25
// #define DHTTYPE DHT11
// DHT dht(DHTPIN, DHTTYPE);

// const int buzzerPin = 2; // Pin buzzer (contoh: GPIO 14)

// void setup()
// {
//     Serial.begin(115200);
//     Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
//     Serial.println("DHT11 Output!");
//     dht.begin();
//     pinMode(buzzerPin, OUTPUT);
//     digitalWrite(buzzerPin, LOW); // Matikan buzzer saat startup
// }

// void loop()
// {
//     Blynk.run();
//     timer.run();
//     float temperature = dht.readTemperature();
//     float humidity = dht.readHumidity();

//     if (isnan(temperature) || isnan(humidity))
//     {
//         Serial.println("Failed to read DHT11");
//     }
//     else
//     {
//         Serial.print("Humidity: ");
//         Serial.print(humidity);
//         Serial.print(" %\t");
//         Serial.print("Temperature: ");
//         Serial.print(temperature);
//         Serial.println(" *C");

//         // Kirim data ke Blynk (Menukar V0 dan V1)
//         Blynk.virtualWrite(V1, humidity);  // Kirim kelembaban ke pin virtual V1
//         Blynk.virtualWrite(V0, temperature);  // Kirim suhu ke pin virtual V0

//         // Kontrol buzzer berdasarkan suhu
//         if (temperature > 30.0)
//         {
//             // Suhu panas, nyalakan buzzer dengan suara sangat kencang
//             tone(buzzerPin, 1000, 1000); // Frekuensi 1000 Hz selama 1000 ms (1 detik)
//             Serial.println("PERINGATAN: Suhu sangat panas! Aktifkan kipas angin kandang segera.");
//             Blynk.logEvent("peringatan_suhu_panas", String("PERINGATAN: Suhu sangat panas! Aktifkan kipas angin kandang segera! Temperature: ") + temperature);
//         }
//         else if (temperature > 25.0)
//         {
//             // Suhu hangat, nyalakan buzzer dengan suara sedang
//             tone(buzzerPin, 500, 500); // Frekuensi 500 Hz selama 500 ms (0.5 detik)
//             Serial.println("PERINGATAN: Suhu hangat! Pertimbangkan untuk mengaktifkan kipas angin kandang.");
//             Blynk.logEvent("peringatan_suhu_hangat", String("PERINGATAN: Suhu hangat! Pertimbangkan untuk mengaktifkan kipas angin kandang! Temperature: ") + temperature);
//         }
//         else
//         {
//             // Suhu normal, matikan buzzer
//             noTone(buzzerPin);
//         }

//         delay(3000);
//     }
// }

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6KK3v4pnq"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "T3ZkeLQbq6FiKmdMJnzQlx3CRcKbaQ4s"

#include <Blynk.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

BlynkTimer timer;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "lorem";
char pass[] = "test1234";

#include "DHT.h"
#define DHTPIN 25
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int buzzerPin = 2;// Pin buzzer (contoh: GPIO 14)

void setup()
{
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
    Serial.println("DHT11 Output!");
    dht.begin();
    pinMode(buzzerPin, OUTPUT);
    digitalWrite(buzzerPin, LOW); // Matikan buzzer saat startup
}

void loop()
{
    Blynk.run();
    timer.run();
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity))
    {
        Serial.println("Failed to read DHT11");
    }
    else
    {
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.print(" %\t");
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" *C");

        // Kirim data ke Blynk (Menukar V0 dan V1)
        Blynk.virtualWrite(V1, humidity);  // Kirim kelembaban ke pin virtual V1
        Blynk.virtualWrite(V0, temperature);  // Kirim suhu ke pin virtual V0

        // Kontrol buzzer berdasarkan suhu
        if (temperature > 30.0)
        {
            // Suhu panas, nyalakan buzzer dengan suara sangat kencang
            tone(buzzerPin, 1000, 1000); // Frekuensi 1000 Hz selama 1000 ms (1 detik)
            Serial.println("PERINGATAN: Suhu sangat panas! Aktifkan kipas angin kandang segera.");
            Blynk.logEvent("peringatan_suhu_panas", String("PERINGATAN: Suhu sangat panas! Aktifkan kipas angin kandang segera! Temperature: ") + temperature);
        }
        else if (temperature > 25.0)
        {
            // Suhu hangat, nyalakan buzzer dengan suara sedang
            tone(buzzerPin, 500, 500); // Frekuensi 500 Hz selama 500 ms (0.5 detik)
            Serial.println("PERINGATAN: Suhu hangat! Pertimbangkan untuk mengaktifkan kipas angin kandang.");
            Blynk.logEvent("peringatan_suhu_hangat", String("PERINGATAN: Suhu hangat! Pertimbangkan untuk mengaktifkan kipas angin kandang! Temperature: ") + temperature);
        }
        else
        {
            // Suhu normal, matikan buzzer
            noTone(buzzerPin);
        }

        delay(3000);
    }
}