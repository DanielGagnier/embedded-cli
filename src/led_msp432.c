#include <msp432p401r.h>
#include "led.h"

#define LED_PIN BIT0

static int initialized = 0;

static void led_init(void)
{
    P1->SEL0 &= (uint8_t)~LED_PIN;
    P1->SEL1 &= (uint8_t)~LED_PIN;

    P1->DIR |= LED_PIN;

    P1->OUT &= (uint8_t)~LED_PIN;

    initialized = 1;
}

void led_on(void)
{
    if (!initialized) {
        led_init();
    }

    P1->OUT |= LED_PIN;
}

void led_off(void)
{
    if (!initialized) {
        led_init();
    }

    P1->OUT &= (uint8_t)~LED_PIN;
}

int led_get_state(void)
{
    if (!initialized) {
        led_init();
    }

    return (P1->OUT & LED_PIN) ? 1 : 0;
}
