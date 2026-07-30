int tempPin = A0;
int buzzer = 8;

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int reading = analogRead(tempPin);

  float voltage = reading * 5.0 / 1023.0;

  float temperature = (voltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if (temperature > 30) {
    tone(buzzer, 1000);
  }
  else {
    noTone(buzzer);
  }

  delay(500);
}
