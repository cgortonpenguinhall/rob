#include <Arduino.h>
#include <Servo.h>
#include <someFunctions.h>

const int leftArmPin = 12;  //blue
const int rightArmPin = 13; // yellow

Servo leftArm;
Servo rightArm;

void setup() {
  Serial.begin(9600);
  leftArm.attach(leftArmPin);
  rightArm.attach(rightArmPin);
  waveHands();
}

void loop() {


}
