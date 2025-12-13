#include "drink_fsm.h"

int motor1pin1 = 2;
int motor1pin2 = 3;
int motor1sp = 9;

int motor2pin1 = 4;
int motor2pin2 = 5;
int motor2sp = 10;
int button = 8;
int LED = 7;

DispenserState dispenserState = OFF;


void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(motor1sp, OUTPUT);
  pinMode(motor2sp, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

}


void loop() 
{
  detect_button(button);
  // if (get_fsm_on()){
  //   dispenserState = make_drink( motor1pin1,  motor1pin2,  motor2pin1,  motor2pin2,  LED, dispenserState);
  // }
    if (true){
    dispenserState = make_drink( motor1pin1,  motor1pin2,  motor2pin1,  motor2pin2,  LED, dispenserState);
  }
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