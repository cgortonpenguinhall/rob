#include <Arduino.h>
#include <NewPing.h>
#include <Servo.h>

const int leftArmPin = 12;     // blue
const int rightArmPin = 13;    // yellow
const int headPin = 11;        // green
const int echoPin = 8;         // blue
const int triggerPin = 9;      // yellow
const int fiberOpticsPin = 7;  // red
const int maxDistance = 200;

Servo leftArm;
Servo rightArm;
Servo head;

NewPing sonar(triggerPin, echoPin, maxDistance);

#include <hair.h>
#include <hands.h>
#include <head.h>

void setup() {
  pinMode(fiberOpticsPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Starting");

  leftArm.attach(leftArmPin);
  rightArm.attach(rightArmPin);
  head.attach(headPin);
}

void loop() {
  int dist = sonar.ping_cm();
  delay(100);
  if (dist <= 75 && dist > 0) {
    Serial.println(dist);
    digitalWrite(fiberOpticsPin, HIGH);
    waveHands();
    moveHead();
  }
  fiberOpticBlink();
}
