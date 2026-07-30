#include <Servo.h>

Servo windowServo;

int rainSensor = A0;
int rainValue;

void setup() {
  windowServo.attach(9);
  windowServo.write(0);   // Window open position

  Serial.begin(9600);
}

void loop() {
  rainValue = analogRead(rainSensor);

  Serial.println(rainValue);

  if (rainValue < 500) {  
    // Rain detected
    windowServo.write(90);   // Close window
  } 
  else {
    // No rain
    windowServo.write(0);    // Open window
  }

  delay(500);
}
