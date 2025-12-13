#include <Arduino.h>
#include "drink_fsm.h"
#include "features.h"

// static int counter = 0;
// const unsigned long bothTime = 4000;
// const unsigned long mixerTime = 15000;
static bool lastButtonState = LOW;
static bool fsmButtonTrigger = false; 



bool detect_button(int buttonPin){
  bool currentState = digitalRead(buttonPin);
  bool pressed = false;
  if (currentState == HIGH && lastButtonState == LOW){
    pressed = true;
    fsmButtonTrigger = true;
    lastButtonState = HIGH;
  }
  return pressed;
}

bool get_fsm_on(){
  return fsmButtonTrigger;
}

void make_drink(Drink &drink){
  
 switch (drink.dispenserState){
   case OFF:
     led_off(drink.ledPin);
     analogWrite(drink.motor1PinSP, 255);
     analogWrite(drink.motor2PinSP, 255);
     digitalWrite(drink.motor1Pin1, LOW);
     digitalWrite(drink.motor2Pin1, LOW);
     if (fsmButtonTrigger){
       drink.timer = millis();
       drink.dispenserState = BOTH;
     }
     break;
 
   case BOTH:
     digitalWrite(drink.motor1Pin1, HIGH);
     digitalWrite(drink.motor1Pin2, LOW);
     digitalWrite(drink.motor2Pin1, HIGH);
     digitalWrite(drink.motor2Pin2, LOW);
     led_on(drink.ledPin);
     if (millis()-drink.timer >= drink.bothTime){
       Serial.print(drink.timer);
       drink.timer = millis();
       drink.dispenserState = MIXER;
     }
     else{
       drink.dispenserState = BOTH;
     }
     break;
   case MIXER:
     digitalWrite(drink.motor1Pin1, LOW);
     blinky_light(drink.ledPin);
     if (millis()-drink.timer >= drink.mixerTime){
       drink.counter++;
       drink.timer = millis();
       if (drink.counter>4){
         fsmButtonTrigger = false;
         lastButtonState = LOW;
         drink.dispenserState = OFF;
         drink.counter = 0;
     }
       else{
         drink.dispenserState = BOTH;
       }

     }
     else{
       drink.dispenserState = MIXER;
     }
     break;
 
   }
    Serial.print("State: "); 
    Serial.print(drink.dispenserState);
    Serial.print(", counter: ");
    Serial.print(drink.counter);
    Serial.print(", timer: ");
    Serial.println(drink.timer);
}


