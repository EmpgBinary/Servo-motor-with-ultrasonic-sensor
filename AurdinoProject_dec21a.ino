#include <Servo.h>

Servo myServo;

const int trigPin = 6;
const int echoPin = 7;
const int ledPin = 12;


void setup() {
  Serial.begin(9600);
  myServo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration / 2) / 29.1;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  if (distance < 10){
    digitalWrite(ledPin, HIGH);
  }else {
    digitalWrite(ledPin, LOW);
  }

  int angle = map(distance, 5, 30, 0, 180);

  myServo.write(angle);

  delay(500);

}
