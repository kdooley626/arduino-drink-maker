#include <Arduino.h>

enum DispenserState {
OFF,
BOTH,
MIXER
};

void stop_motor(int pin1, int pin2);
void run_motor(int pin1, int pin2);

typedef struct {
    int motor1Pin1;
    int motor1Pin2;
    int motor1PinSP;
    int motor2Pin1;
    int motor2Pin2;
    int motor2PinSP;
    int ledPin;
    int buttonPin;
    DispenserState dispenserState;
    unsigned long timer;
    int counter;
    const unsigned long bothTime;
    const unsigned long mixerTime;
    bool lastButtonState;
    bool fsmButtonTrigger;
} Drink;

void make_drink(Drink &drink);
bool detect_button(Drink &drink);
// bool get_fsm_on();