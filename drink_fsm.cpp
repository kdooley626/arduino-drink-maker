#include <Arduino.h>
#include "drink_fsm.h"
#include "features.h"


void stop_motor(int pin1, int pin2, int pinSp) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    analogWrite(pinSp, 0);
}

void run_motor(int pin1, int pin2, int pinSp) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    analogWrite(pinSp, 255);
}


bool detect_button(Drink &drink) {
    bool currentState = digitalRead(drink.buttonPin);
    bool pressed = false;
    if (currentState == HIGH && drink.lastButtonState == LOW) {
        pressed = true;
        drink.fsmButtonTrigger = true;
    }
    drink.lastButtonState = currentState;
    return pressed;
}



void make_drink(Drink &drink){
 switch (drink.dispenserState){
    case OFF:
        led_off(drink.ledPin);
        stop_motor(drink.motor1Pin1, drink.motor1Pin2, drink.motor1PinSP);
        stop_motor(drink.motor2Pin1, drink.motor2Pin2, drink.motor2PinSP);

        if (drink.fsmButtonTrigger) {
            drink.timer = millis();          // start timer
            drink.dispenserState = BOTH;     
            drink.fsmButtonTrigger = false;  // consume trigger
        }
        break;
   case BOTH:
     run_motor(drink.motor1Pin1, drink.motor1Pin2, drink.motor1PinSP);
     run_motor(drink.motor2Pin1, drink.motor2Pin2, drink.motor2PinSP);
     led_on(drink.ledPin);
     if (millis()-drink.timer >= drink.bothTime){
       drink.timer = millis();
       drink.dispenserState = MIXER;
     }
     else{
       drink.dispenserState = BOTH;
     }
     break;
   case MIXER:
     stop_motor(drink.motor1Pin1, drink.motor1Pin2, drink.motor1PinSP);
     run_motor(drink.motor2Pin1, drink.motor2Pin2, drink.motor2PinSP);
     blinky_light(drink.ledPin);
     if (millis()-drink.timer >= drink.mixerTime){
       drink.counter++;
       drink.timer = millis();
       if (drink.counter>4){
         drink.dispenserState = OFF;
         drink.counter = 0;
         stop_motor(drink.motor1Pin1, drink.motor1Pin2, drink.motor1PinSP);
         stop_motor(drink.motor2Pin1, drink.motor2Pin2, drink.motor2PinSP);
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


