#include <Arduino.h>
#include <Servo.h>

const int leftArmPin = 12;  //blue
const int rightArmPin = 13; // yellow
const int headPin = 11; // green

Servo leftArm;
Servo rightArm;
Servo head; 

#include <hands.h>
#include <head.h>

void setup() {
  Serial.begin(9600);
  leftArm.attach(leftArmPin);
  rightArm.attach(rightArmPin);
  head.attach(headPin);
  waveHands();
  moveHead();
}

void loop() {


}
