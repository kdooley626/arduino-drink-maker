#include <Arduino.h>
struct Timer{
    unsigned long interval;
    unsigned long nextTime;
    bool state;
};
void blinky_light(int ledPin);
void led_off(int ledPin);