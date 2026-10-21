#include <msp432p401r.h>
#include "led.h"

#define LED_PIN BIT0

static int initialized = 0;

static void led_init(void)
{
    /* Select GPIO functionality for P1.0 */
    P1SEL0 &= ~LED_PIN;
    P1SEL1 &= ~LED_PIN;

    /* Configure P1.0 as an output */
    P1DIR |= LED_PIN;

    /* Start with the LED off */
    P1OUT &= ~LED_PIN;

    /* Enable GPIO pins on the MSP432 */
    PM5CTL0 &= ~LOCKLPM5;

    initialized = 1;
}

void led_on(void)
{
    if (!initialized) {
        led_init();
    }

    P1OUT |= LED_PIN;
}

void led_off(void)
{
    if (!initialized) {
        led_init();
    }

    P1OUT &= ~LED_PIN;
}

int led_get_state(void)
{
    if (!initialized) {
        led_init();
    }

    return (P1OUT & LED_PIN) ? 1 : 0;
}
