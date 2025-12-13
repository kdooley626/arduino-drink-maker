#include "drink_fsm.h"

Drink rumncoke = {
    2,   // motor1pin1
    3,   // motor1pin2
    9,   // motor1pinSP
    4,   // motor2pin1
    5,   // motor2pin2
    10,   //motor2pinsp
    7,   // LED
    OFF, // initial state
    0,   // initial timer
    0,   // initial counter
    4000, // bothTime 
    15000 // mixerTime
};


int button = 8;



void setup() {
  // put your setup code here, to run once:
  pinMode(rumncoke.motor1Pin1, OUTPUT);
  pinMode(rumncoke.motor1Pin2, OUTPUT);
  pinMode(rumncoke.motor2Pin1, OUTPUT);
  pinMode(rumncoke.motor2Pin2, OUTPUT);

  pinMode(rumncoke.motor1PinSP, OUTPUT);
  pinMode(rumncoke.motor2PinSP, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(rumncoke.ledPin, OUTPUT);

  rumncoke.dispenserState = OFF;

  Serial.begin(9600);

}


void loop() 
{
  detect_button(button);
  // if (get_fsm_on()){
  //   dispenserState = make_drink( motor1pin1,  motor1pin2,  motor2pin1,  motor2pin2,  LED, dispenserState);
  // }
  if (true){
      make_drink(rumncoke);
  }
}

// void makeDrink1(bool button) {
//   analogWrite(motor1sp, 255);
//   analogWrite(motor2sp, 255);
//   for (int i = 0; i<5; ++i){
//       digitalWrite(motor1pin1, HIGH);
//       digitalWrite(motor1pin2, LOW);
//       digitalWrite(motor2pin1, HIGH);
//       digitalWrite(motor2pin2, LOW);
//       delay(4000);
//       digitalWrite(motor1pin1, LOW);
//       delay(15000);

//   }
//   digitalWrite(motor2pin1, LOW);
//   digitalWrite(motor1pin1, LOW);
// }