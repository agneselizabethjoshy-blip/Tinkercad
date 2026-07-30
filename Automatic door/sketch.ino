#include <Servo.h>

Servo doorServo;

int trigPin = 9;
int echoPin = 10;

long duration;
int distance;

void setup() {
  doorServo.attach(6);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

  doorServo.write(0); // Door closed
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.println(distance);

  if (distance < 20) {
    doorServo.write(90);   // Open door
    delay(3000);
  }
  else {
    doorServo.write(0);    // Close door
  }

  delay(200);
}
