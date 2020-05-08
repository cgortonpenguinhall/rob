#include <Arduino.h>
#include <NewPing.h>
#include <SD.h>
#include <SPI.h>
#include <Servo.h>
#include <TMRpcm.h>

const int leftArmPin = 12;     // blue
const int rightArmPin = 13;    // yellow
const int headPin = 11;        // green
const int echoPin = 8;         // blue
const int triggerPin = 9;      // yellow
const int fiberOpticsPin = 7;  // red
const int maxDistance = 200;
const int SD_ChipSelectPin = 53;  // yellow
const int speakerPin = 46;        // brown

Servo leftArm;
Servo rightArm;
Servo head;

NewPing sonar(triggerPin, echoPin, maxDistance);

TMRpcm audio;

#include <hair.h>
#include <hands.h>
#include <head.h>

void setup() {
  pinMode(fiberOpticsPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Starting");

  leftArm.attach(leftArmPin);
  rightArm.attach(rightArmPin);
  head.attach(headPin);

  audio.speakerPin = speakerPin;
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }
}

void loop() {
  int dist = sonar.ping_cm();
  delay(100);
  if (dist <= 75 && dist > 0) {
    Serial.println(dist);
    digitalWrite(fiberOpticsPin, HIGH);
    //waveHands();
    Serial.println("playing audio");
    audio.setVolume(5);
    audio.play("APHrob.wav");
    delay(4000);
    audio.stopPlayback();
    // digitalWrite(speakerPin, LOW);
    // Serial.println("disabling audio");
    // audio.disable();
    delay(250);
    moveHead();
  }
  fiberOpticBlink();
}
