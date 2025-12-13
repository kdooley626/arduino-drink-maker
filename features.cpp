#include <Arduino.h>

void blinky_light(int ledPin){
  const unsigned int blinkTime = 200;
  unsigned long nextblinkTime = 0;
  bool lastlightState = false;
  if (nextblinkTime <= millis()){
    lastlightState = ~lastlightState;
    if (lastlightState){
      digitalWrite(ledPin, HIGH);
    }
    else{
      digitalWrite(ledPin,LOW);
    }
    nextblinkTime = nextblinkTime + blinkTime;
  }
  
  
}
