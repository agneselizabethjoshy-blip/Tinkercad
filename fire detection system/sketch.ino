// Pin definitions
const int flameSensor = 2;
const int redLED = 8;
const int greenLED = 9;
const int buzzer = 10;

void setup() {
  pinMode(flameSensor, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int flame = digitalRead(flameSensor);

  // Most flame sensors output LOW when fire is detected
  if (flame == LOW) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, HIGH);

    Serial.println("Fire Detected!");
  }
  else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, LOW);

    Serial.println("No Fire");
  }

  delay(200);
}
