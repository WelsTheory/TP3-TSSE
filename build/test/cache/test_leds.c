#include "src/leds.h"
#include "/home/wels/.rbenv/versions/2.5.0/lib/ruby/gems/2.5.0/gems/ceedling-0.31.0/vendor/unity/src/unity.h"














uint16_t ledsVirtuales;



void setUp(void)

{

    Leds_Create(&ledsVirtuales);

}



void tearDown(void)

{



}





void test_LedsOffAfterCreate(void)

{

    ledsVirtuales = 0xFFFF;

    Leds_Create(&ledsVirtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnLedOne(void)

{

    Led_TurnOn(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1<<(5 -1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOffOneLed(void)

{

    Led_TurnOn(5);

    Led_TurnOff(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnAndOffManyLeds(void)

{

    Led_TurnOn(3);

    Led_TurnOn(5);

    Led_TurnOff(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << (5 -1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnAllLeds(void)

{

    Led_TurnOnAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOffAllLeds(void)

{

    Led_TurnOn(3);

    Led_TurnOn(5);

    Led_TurnOffAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_HEX16);

}





void test_StateLedOff(void)

{

    Led_TurnOn(5);

    Led_TurnOff(5);

    do {if (!(Led_State(5))) {} else {UnityFail( ((("LED ON "))), (UNITY_UINT)((UNITY_UINT)(75)));}} while(0);

}





void test_StateLed(void)

{

    Led_TurnOn(5);

    do {if ((Led_State(5))) {} else {UnityFail( ((("LED OFF "))), (UNITY_UINT)((UNITY_UINT)(82)));}} while(0);

}





void test_ParamLed(void){

    Led_TurnOffAll();

    Led_TurnOn(5);

    Led_TurnOn(6);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0030)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_HEX16);

}
