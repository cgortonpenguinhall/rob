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
  someFunction();
}

void loop() {
  // put your main code here, to run repeatedly:
  leftArm.write(45);
  delay(1000);
  leftArm.write(120);
  delay(1000);
  rightArm.write(45);
  delay(1000);
  rightArm.write(120);
  delay(1000);
}
