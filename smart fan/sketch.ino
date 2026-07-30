int tempSensor = A0;
int motor = 9;

void setup() {
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int value = analogRead(tempSensor);

  float voltage = value * 5.0 / 1023.0;
  float temperature = (voltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if (temperature > 30) {
    analogWrite(motor, 255);  // Fan ON
  }
  else {
    analogWrite(motor, 0);    // Fan OFF
  }

  delay(500);
}
