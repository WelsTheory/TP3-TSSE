#include "leds.h"

#define ALL_LEDS_OFF    0x0000
#define LED_ON          1
#define LED_OFF         0
#define LED_OFFSET      1
#define LED_MIN         0
#define LED_MAX         16
#define ERROR           0

static uint16_t * puerto;

uint16_t led_to_bit(uint8_t led)
{
    return (LED_ON << (led - LED_OFFSET));
}

void Leds_Create(uint16_t * puntero)
{
    puerto = puntero;
    Led_TurnOffAll();
}

void Led_TurnOn(uint8_t led)
{
    *puerto |= led_to_bit(led);
}

void Led_TurnOff(uint8_t led)
{
    *puerto &= ~led_to_bit(led);
}

void Led_TurnOnAll(void)
{
    *puerto = ~ALL_LEDS_OFF;
}

void Led_TurnOffAll(void)
{
    *puerto = ALL_LEDS_OFF;
}

bool Led_State(uint8_t led)
{
    return (*puerto & led_to_bit(led)) != LED_OFF;
}

