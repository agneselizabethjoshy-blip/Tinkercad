const int trigPin = 9;
const int echoPin = 10;
const int motorPin = 8;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Measure echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2;

  Serial.print("Water level distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  // Pump control
  // Larger distance = low water level
  if (distance > 15) {
    digitalWrite(motorPin, HIGH);   // Turn ON pump
    Serial.println("Pump ON");
  }
  else {
    digitalWrite(motorPin, LOW);    // Turn OFF pump
    Serial.println("Pump OFF");
  }

  delay(1000);
}
