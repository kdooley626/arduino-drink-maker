#include <Arduino.h>

enum DispenserState {
OFF,
BOTH,
MIXER
};

typedef struct {
    int motor1Pin1;
    int motor1Pin2;
    int motor1PinSP;
    int motor2Pin1;
    int motor2Pin2;
    int motor2PinSP;
    int ledPin;
    DispenserState dispenserState;
    unsigned long timer;
    int counter;
    const unsigned long bothTime;
    const unsigned long mixerTime;
} Drink;

void make_drink(Drink &drink);
bool detect_button(int buttonPin);
bool get_fsm_on();