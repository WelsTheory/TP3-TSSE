/*
* TP3 WILLIAMS LIMONCHI
*/

#include "unity.h"
#include "leds.h"

#define LED 5

uint16_t ledsVirtuales;

void setUp(void) 
{
    Leds_Create(&ledsVirtuales);
}

void tearDown(void)
{

}

// Después de la inicialización 
void test_LedsOffAfterCreate(void) 
{
    ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// Encender Leds forma individual
void test_TurnOnLedOne(void) 
{
    Led_TurnOn(LED);
    TEST_ASSERT_EQUAL_HEX16(1<<(LED-1), ledsVirtuales);
}

// Se puede apagar un LED individual
void test_TurnOffOneLed(void)
{
    Led_TurnOn(LED);
    Led_TurnOff(LED);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

//
void test_TurnOnAndOffManyLeds(void)
{
    Led_TurnOn(3);
    Led_TurnOn(LED);
    Led_TurnOff(3);
    TEST_ASSERT_EQUAL_HEX16(1 << (LED-1), ledsVirtuales);
}

// Se pueden prender todos los LEDs de una vez
void test_TurnOnAllLeds(void)
{
    Led_TurnOnAll();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

// Se pueden apagar todos los LEDs de una vez.
void test_TurnOffAllLeds(void)
{
    Led_TurnOnAll();
    Led_TurnOffAll();
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// Se puede consultar el estado de un LED apagado.
void test_StateLedOff(void)
{
    Led_TurnOn(LED);
    Led_TurnOff(LED);
    TEST_ASSERT_FALSE_MESSAGE(Led_State(LED), "LED ON ");
}

// Se puede consultar el estado de un LED
void test_StateLed(void)
{
    Led_TurnOn(LED);
    TEST_ASSERT_TRUE_MESSAGE(Led_State(LED), "LED OFF ");
}

// Revisar limites de los parametros.
void test_ParamLed(void){ 
    Led_TurnOffAll();
    Led_TurnOn(LED);
    Led_TurnOn(6);
    TEST_ASSERT_EQUAL_HEX16(0x0030,ledsVirtuales);
}





