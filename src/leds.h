#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

uint16_t led_to_bit(uint8_t led);

void Leds_Create(uint16_t * puntero);

void Led_TurnOn(uint8_t led);

void Led_TurnOff(uint8_t led);

void Led_TurnOnAll(void);

void Led_TurnOffAll(void);

bool Led_State(uint8_t led);