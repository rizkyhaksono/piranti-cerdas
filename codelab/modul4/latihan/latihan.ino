int LDR_VAL = 0;
int SENSOR = 34;
int LED = 25;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  LDR_VAL = analogRead(SENSOR);
  Serial.print("LDR Output :");
  Serial.print(LDR_VAL);

  if(LDR_VAL > 100) {
    Serial.println("Cahaya Terang");
    digitalWrite(LED, LOW);
  } else {
    Serial.println("Cahaya Gelap");
    digitalWrite(LED, HIGH);
  }

  delay(1000);
}
