#include <Arduino.h>

void led_off(int ledPin){
    digitalWrite(ledPin, LOW);
}

void blinky_light(int ledPin){
  static const unsigned int blinkTime = 200;
  static unsigned long nextblinkTime = 0;
  static bool lastlightState = false;
  if (nextblinkTime <= millis()){
    lastlightState = !lastlightState;
    if (lastlightState){
      digitalWrite(ledPin, HIGH);
    }
    else{
      digitalWrite(ledPin,LOW);
    }
    nextblinkTime = millis() + blinkTime;
  }
  
  
}
