#include <Servo.h>

Servo gateServo;

const int trigPin = 9;
const int echoPin = 10;

const int servoPin = 6;
const int greenLED = 3;
const int redLED = 4;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  gateServo.attach(servoPin);
  gateServo.write(0); // Gate closed position

  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Vehicle detected
  if (distance < 20) {
    gateServo.write(90);       // Open gate
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);

    Serial.println("Vehicle Detected - Gate Open");
  }

  // No vehicle
  else {
    gateServo.write(0);        // Close gate
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

    Serial.println("No Vehicle - Gate Closed");
  }

  delay(500);
}
