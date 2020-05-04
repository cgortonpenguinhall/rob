void fiberOpticBlink() {
  int evenOdd = millis() / 1000;
  if (evenOdd % 2 == 0) {
    digitalWrite(fiberOpticsPin, HIGH);
  } else {
    digitalWrite(fiberOpticsPin, LOW);
  }
}