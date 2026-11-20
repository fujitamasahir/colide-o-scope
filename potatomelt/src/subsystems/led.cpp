#include <Arduino.h>
#include <driver/rmt.h>
#include "led.h"
#include "../melty_config.h"

LED::LED() {
}

void LED::init(){
    pinMode(LED_1_PIN, OUTPUT);
    pinMode(LED_2_PIN, OUTPUT);
}

void LED::leds_on_ready() {
    leds_on();
}

void LED::leds_on_low_battery() {
    long now = millis();
        now /= 100;
        if ((now % 10) < 5) {
            leds_on();
        } else {
            leds_off();
        }
}

void LED::leds_on_controller_stale() {
    long now = millis();
        now /= 100;
        if ((now % 10) < 8) {
            leds_on();
        } else {
            leds_off();
        }
}

void LED::leds_on_no_controller() {
    long now = millis();
        now /= 100;
        if ((now % 10) < 2) {
            leds_on();
        } else {
            leds_off();
        }
}

void LED::leds_on_gradient() {
    leds_on();
}

void LED::leds_off() {
    digitalWrite(LED_1_PIN, LOW);
    digitalWrite(LED_2_PIN, LOW);
}

void LED::leds_on() {
    digitalWrite(LED_1_PIN, HIGH);
    digitalWrite(LED_2_PIN, HIGH);
}