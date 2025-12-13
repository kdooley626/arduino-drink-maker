#include <Arduino.h>
#include "drink_fsm.h"

static int counter = 0;
const unsigned long bothTime = 500;
const unsigned long mixerTime = 500;
static bool lastButtonState = LOW;
static bool fsmButtonTrigger = false; 

bool detect_button(int buttonPin){
  bool currentState = digitalRead(buttonPin);
  bool pressed = false;
  if (currentState = HIGH && lastButtonState = LOW){
    pressed = true;
    fsmButtonTrigger = true;
    lastButtonState = HIGH;
  }
  return pressed;
}

bool get_fsm_on(){
  return fsmButtonTrigger;
}

int make_drink(int motor1pin1, int motor1pin2, int motor2pin1, int motor2pin2, int LED, DispenserState dispenserState){
 static unsigned long timer = 0;
 switch (dispenserState){
   case OFF:
     Serial.println("OFF");

     digitalWrite(motor1pin1, LOW);
     digitalWrite(motor2pin1, LOW);
     if (fsmButtonTrigger){
       digitalWrite(LED,HIGH);
       timer = millis();
       dispenserState = BOTH;
     }
     break;
 
   case BOTH:
     Serial.println("BOTH");
     digitalWrite(motor1pin1, HIGH);
     digitalWrite(motor1pin2, LOW);
     digitalWrite(motor2pin1, HIGH);
     digitalWrite(motor2pin2, LOW);
     if (millis()-timer >= bothTime){
       Serial.print(timer);
       Serial.println("LEAVING BOTH");
       digitalWrite(LED,LOW);
       timer = millis();
       dispenserState = MIXER;
     }
     else{
       dispenserState = BOTH;
     }
     break;
   case MIXER:
     Serial.println("MIXER");
     digitalWrite(motor1pin1, LOW);

     if (millis()-timer >= mixerTime){
       counter++;
       timer = millis();
       if (counter>4){
         fsmButtonTrigger = false;
         lastButtonState = LOW;
         dispenserState = OFF;
         digitalWrite(LED, LOW);
         counter = 0;
     }
       else{
         dispenserState = BOTH;
       }

     }
     else{
       dispenserState = MIXER;
     }
     break;
 
   }
    Serial.print("State: "); 
    Serial.print(dispenserState);
    Serial.print(", counter: ");
    Serial.print(counter);
    Serial.print(", timer: ");
    Serial.println(timer);
   return dispenserState;
}

void makeDrink1(bool button) {
  analogWrite(motor1sp, 255);
  analogWrite(motor2sp, 255);
  for (int i = 0; i<5; ++i){
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
      delay(4000);
      digitalWrite(motor1pin1, LOW);
      delay(15000);

  }
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor1pin1, LOW);
}
