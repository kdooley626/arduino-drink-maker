
int motor1pin1 = 2;
int motor1pin2 = 3;
int motor1sp = 9;

int motor2pin1 = 4;
int motor2pin2 = 5;
int motor2sp = 10;
int button = 8;
int LED = 7;
enum {
OFF,
BOTH,
MIXER
};
unsigned char dispenserState = OFF;
const unsigned long bothTime = 500;
const unsigned long mixerTime = 500;
unsigned long timer = 0;
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
void blinkyLED(){
  const unsigned int blinkTime = 200;
  unsigned long nextblinkTime = 0;
  bool lastlightState = false;
  if (nextblinkTime <= millis()){
    lastlightState = ~lastlightState;
    if (lastlightState){
      digitalWrite(LED, HIGH);
    }
    else{
      digitalWrite(LED,LOW);
    }
    nextblinkTime = nextblinkTime + blinkTime;
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

//  static int counter = 0;
//
//  switch (dispenserState){
//    case OFF:
//      Serial.println("OFF");

//      digitalWrite(motor1pin1, LOW);
//      digitalWrite(motor2pin1, LOW);
//      if (button){
//        digitalWrite(LED,HIGH);
//        timer = millis();
//        dispenserState = BOTH;
//      }
//  
//    case BOTH:
//      Serial.println("BOTH");
//      digitalWrite(motor1pin1, HIGH);
//      digitalWrite(motor1pin2, LOW);
//      digitalWrite(motor2pin1, HIGH);
//      digitalWrite(motor2pin2, LOW);
//      if (millis()-timer >= bothTime){
//        Serial.print(timer);
//        Serial.println("LEAVING BOTH");
//        digitalWrite(LED,LOW);
//        timer = millis();
//        dispenserState = MIXER;
//      }
//      else{
//        dispenserState = BOTH;
//      }
//  
//    case MIXER:
//      Serial.println("MIXER");
//      digitalWrite(motor1pin1, LOW);
//      counter++;
//      if (millis()-timer >= mixerTime){
//        timer = millis();
//        if (counter>4){
//          dispenserState = OFF;
//          digitalWrite(LED, LOW);
//          counter = 0;
//      }
//        else{
//          dispenserState = BOTH;
//        }
//
//      }
//      else{
//        dispenserState = MIXER;
//      }
//
//  
//    }
//  
}

bool buttonState;
void loop() {
  if (digitalRead(button)==HIGH) {
    digitalWrite(LED, HIGH);
    makeDrink1(buttonState);
    digitalWrite(LED,LOW);
    }
  // put your main code here, to run repeatedly:
  
}
