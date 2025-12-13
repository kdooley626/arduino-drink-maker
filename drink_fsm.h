#include <Arduino.h>

enum DispenserState {
OFF,
BOTH,
MIXER
};
int make_drink(int motor1pin1, int motor1pin2, int motor2pin1, int motor2pin2, int LED,  DispenserState dispenserState);
bool detect_button(int buttonPin);
bool get_fsm_on();