#include <Servo.h>

Servo myServo;

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

const int openAngle = 90;
const int closeAngle = 0;
const int threshold = 30;
const int moveDelay = 15;
const int checkDelay = 200;

bool isOpen = false;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.write(closeAngle);
}

long readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000);
  long distance = duration * 0.034 / 2;
  return distance;
}

void openGate() {
  for (int pos = closeAngle; pos <= openAngle; pos += 2) {
    myServo.write(pos);
    delay(moveDelay);
  }
  isOpen = true;
}

void closeGate() {
  for (int pos = openAngle; pos >= closeAngle; pos -= 2) {
    myServo.write(pos);
    delay(moveDelay);
  }
  isOpen = false;
}

void loop() {
  long distance = readDistance();
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < threshold && !isOpen) {
    Serial.println("Ada benda -> membuka portal...");
    openGate();
  } 
  else if ((distance >= threshold || distance == 0) && isOpen) {
    Serial.println("Tidak ada benda -> menutup portal...");
    closeGate();
  }

  delay(checkDelay);
}
