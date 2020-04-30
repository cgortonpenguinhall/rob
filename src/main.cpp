#include <Arduino.h>
#include <Servo.h>
#include <NewPing.h>

const int leftArmPin = 12;  // blue
const int rightArmPin = 13; // yellow
const int headPin = 11; // green
const int echoPin = 8; //blue 
const int triggerPin = 9; //yellow 
const int maxDistance = 200; 

Servo leftArm;
Servo rightArm;
Servo head;

NewPing sonar (triggerPin, echoPin, maxDistance);

#include <hands.h>
#include <head.h>

void setup() {
  Serial.begin(9600);
  leftArm.attach(leftArmPin);
  rightArm.attach(rightArmPin);
  head.attach(headPin);
}

void loop() {
  int dist = sonar.ping_cm();
  Serial.println(dist);
  delay(100);
    if (dist<=75 && dist>0){
      Serial.println(dist);
      waveHands();
      moveHead();  
      //fiberoptics 
    }

}
