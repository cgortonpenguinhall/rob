#include <Arduino.h>
#include <Servo.h>
#include <someFunctions.h>

Servo leftArm;
Servo rightArm;

void setup() {
  Serial.begin(9600);
  leftArm.attach(12); 
  rightArm.attach(13);
  someFunction();
}

void loop() {
  // put your main code here, to run repeatedly:
  leftArm.write(45);
  delay(1000);
  leftArm.write(75);
  delay(1000);

}
