int ldrPin = A0;
int ledPin = 8;

int lightValue;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(ldrPin);

  Serial.println(lightValue);

  if (lightValue < 500) {   // Dark
    digitalWrite(ledPin, HIGH);
  } 
  else {                    // Bright
    digitalWrite(ledPin, LOW);
  }

  delay(200);
}
