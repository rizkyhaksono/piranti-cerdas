// const int switchPin = 15;
// const int ledPin = 14;

// int switchState = 0;

// void setup() {
//   Serial.begin(115200);
//   pinMode(switchPin, INPUT);
//   pinMode(ledPin, OUTPUT);
// }

// void loop() {
//   switchState = digitalRead(switchPin);
//   if (switchState == HIGH){
//     digitalWrite(ledPin, HIGH);
//   } else {
//     digitalWrite(ledPin, LOW);
//   }
// }

const int switchPin = 15;
const int ledPin = 14;

int switchState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  switchState = digitalRead(switchPin);
  if (switchState == HIGH){
    // digitalWrite(ledPin, HIGH);
    // delay(1000); // Turn on the LED for 1 second
    // digitalWrite(ledPin, LOW);
    // delay(1000); // Turn off the LED for 1 second

    digitalWrite(ledPin, HIGH);
    delay(500); // Turn on the LED for 0.5 second
    digitalWrite(ledPin, LOW);
    delay(500); // Turn off the LED for 0.5 second
    digitalWrite(ledPin, HIGH);
    delay(200); // Turn on the LED for 0.2 second
    digitalWrite(ledPin, LOW);
    delay(200); // Turn off the LED for 0.2 second
  }
}