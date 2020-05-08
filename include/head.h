void moveHead() {
  Serial.println("moveHead()");
  int seconds = 5;

  for(int i= 90; i > 30; i--){ // look from center to left
    head.write(i);
    delay(1000 * seconds / 60);
  }

  for(int i= 30; i < 150; i++){ // look from left to right
    head.write(i);
    delay(1000 * seconds / 120);
  }


  for(int i= 150; i > 90 ; i--){ // look from right to center
    head.write(i);
    delay(1000 * seconds / 60);
  }
  
}