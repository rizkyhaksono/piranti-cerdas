#define LIGHT_SENSOR_PIN 36

const int buzzerPin = 25;
int switchState = 0;
int ledPin= 21;   

int LDR_Val = 0; 

void setup() {
  Serial.begin(115200);
  // pinMode(sensor, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  LDR_Val = analogRead(LIGHT_SENSOR_PIN);

  // KEGIATAN 1
  // if (LDR_Val < 500 ) {
  //   digitalWrite(ledPin,LOW);
  //   Serial.println("Output : Dark");
  // } else if(LDR_Val > 500 && LDR_Val < 1000){
  //   digitalWrite(ledPin, HIGH); 
  //   delay(1000); 
  //   digitalWrite(ledPin, LOW); 
  //   delay(1000); 
  //   Serial.println("Output : Redup");
  // } else if (LDR_Val >= 1000) {
  //   digitalWrite(ledPin, HIGH); 
  //   Serial.println("Output : Terang");
  // }

  //KEGIATAN 2
  if (LDR_Val == LOW) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}