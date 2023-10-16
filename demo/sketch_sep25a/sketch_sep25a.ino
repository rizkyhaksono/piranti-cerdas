const int switchPin = 15;
const int ledPin = 14;  
const int ledPin2 = 27;
const int speakerPin = 12;
int LDR_Val = 0;     /*Variable to store photoresistor value*/
int sensor =34;      /*Analogue Input for photoresistor*/
int led= 25;   


// const int ldrPin = A0; // Analog pin for LDR

int switchState = 0;

void setup() {
  Serial.begin(19200);
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // switchState = digitalRead(switchPin);
  
  // Serial.println("ihuihi");
  // if (switchState == HIGH) {
  //   digitalWrite(ledPin, HIGH);
  //   tone(speakerPin, 1000); // Play a 1000 Hz tone
  //   delay(500); // Turn on the LED and play the tone for 0.5 second
  //   digitalWrite(ledPin, LOW);
  //   noTone(speakerPin); // Turn off the tone
  //   delay(500); // Turn off the LED for 0.5 second

  //   digitalWrite(ledPin, HIGH);
  //   tone(speakerPin, 3000); // Play a 2000 Hz tone
  //   delay(200); // Turn on the LED and play the tone for 0.2 second
  //   digitalWrite(ledPin, LOW);
  //   noTone(speakerPin); // Turn off the tone
  //   delay(200); // Turn off the LED for 0.2 second

  //   digitalWrite(ledPin2, HIGH);
  //   tone(speakerPin, 1500); // Play a 1500 Hz tone
  //   delay(500); // Turn on the LED and play the tone for 0.5 second
  //   digitalWrite(ledPin2, LOW);
  //   noTone(speakerPin); // Turn off the tone
  //   delay(500); // Turn off the LED for 0.5 second

  //   digitalWrite(ledPin2, HIGH);
  //   tone(speakerPin, 2500); // Play a 2500 Hz tone
  //   delay(200); // Turn on the LED and play the tone for 0.2 second
  //   digitalWrite(ledPin2, LOW);
  //   noTone(speakerPin); // Turn off the tone
  //   delay(200); // Turn off the LED for 0.2 second
  // }

//test ldr
  // LDR_Val = analogRead(sensor);   /*Analog read LDR value*/
  //   Serial.print("LDR Output Value: ");
  //   Serial.println(LDR_Val);   /*Display LDR Output Val on serial monitor*/
  //   if(LDR_Val > 100) {       /*If light intensity is HIGH*/
  //       Serial.println(" High intensity ");
  //       digitalWrite(led,LOW); /*LED Remains OFF*/
  //   }
  //   else {
  //    /*Else if Light intensity is LOW LED will Remain ON*/
  //       Serial.println("LOW Intensity ");
  //       digitalWrite(led,HIGH);  /* LED Turn ON LDR value is less than 100*/
  //   }
  //   delay(1000);

  int analogValue = analogRead(sensor)
}
