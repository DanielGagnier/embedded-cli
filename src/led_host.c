#include "led.h"

static int led = 0;

void led_on(void) {
	    led = 1;
}

void led_off(void) {
	    led = 0;
}

int led_get_state(void) {
	    return led;
}
