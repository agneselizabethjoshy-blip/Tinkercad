int pirSensor = 2;
int led = 8;

void setup() {
  pinMode(pirSensor, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int motion = digitalRead(pirSensor);

  if (motion == HIGH) {
    digitalWrite(led, HIGH);
    Serial.println("Motion detected!");
  }
  else {
    digitalWrite(led, LOW);
    Serial.println("No motion");
  }

  delay(200);
}
