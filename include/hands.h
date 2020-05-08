void waveHands() {
    Serial.println("waveHands()");
    leftArm.write(45);  // up
    rightArm.write(120); // up
    delay (1000);
    leftArm.write(120); // down
    rightArm.write(120); // up
    delay (1000);
    leftArm.write(45);  // up
    rightArm.write(45); // down
    delay (1000);
    leftArm.write(120); // down
    rightArm.write(120); // up
    delay(1000);
    leftArm.write(120);  // down
    rightArm.write(45); // down
    delay(1000);
    leftArm.write(90);  // straight
    rightArm.write(90); // striaght
    delay(1000);
}

