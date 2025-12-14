#include "drink_fsm.h"

Drink rumncoke = {
    1,   // motor1pin1
    2,   // motor1pin2
    3,   // motor1pinSP
    4,   // motor2pin1
    5,   // motor2pin2
    6,   //motor2pinsp
    7,   // LED
    A0,  // button
    OFF, // initial state
    0,   // initial timer
    0,   // initial counter
    4000, // bothTime 
    15000, // mixerTime
    LOW,    // lastButtonState;
    false    // fsmButtonTrigger;
};

Drink gintonic = {
    8,   // motor1pin1
    10,   // motor1pin2
    9,   // motor1pinSP
    12,   // motor2pin1
    13,   // motor2pin2
    11,   //motor2pinsp
    A1,   // LED
    A2, //button
    OFF, // initial state
    0,   // initial timer
    0,   // initial counter
    4000, // bothTime 
    15000, // mixerTime
    HIGH,    // lastButtonState;
    false    // fsmButtonTrigger;
};






void setup() {
  // put your setup code here, to run once:
  pinMode(rumncoke.motor1Pin1, OUTPUT);
  pinMode(rumncoke.motor1Pin2, OUTPUT);
  pinMode(rumncoke.motor2Pin1, OUTPUT);
  pinMode(rumncoke.motor2Pin2, OUTPUT);

  pinMode(rumncoke.motor1PinSP, OUTPUT);
  pinMode(rumncoke.motor2PinSP, OUTPUT);
  pinMode(rumncoke.buttonPin, INPUT_PULLUP);
  pinMode(rumncoke.ledPin, OUTPUT);

  rumncoke.dispenserState = OFF;
  analogWrite(rumncoke.motor1PinSP, 255);
  analogWrite(rumncoke.motor2PinSP, 255);  

  Serial.begin(9600);

}


void loop() 
{
  detect_button(rumncoke);
  make_drink(rumncoke);

}

