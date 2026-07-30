const int moisturePin = A0;
const int motorPin = 9;

int moistureValue;
int threshold = 600;   // Adjust based on calibration

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  moistureValue = analogRead(moisturePin);

  Serial.print("Moisture Value: ");
  Serial.println(moistureValue);

  if (moistureValue > threshold) {
    digitalWrite(motorPin, HIGH);   // Pump ON
  } else {
    digitalWrite(motorPin, LOW);    // Pump OFF
  }

  delay(500);
}
