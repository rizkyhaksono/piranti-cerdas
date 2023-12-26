#define RELAY_PIN 2

// int RELAY_PIN = 22

void setup() 
{
  Serial.begin(9600);
  //pinMode(sensorPin, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() 
{
    digitalWrite(RELAY_PIN, HIGH);
    delay(2000);
    digitalWrite(RELAY_PIN, LOW);
    delay(2000);
}
