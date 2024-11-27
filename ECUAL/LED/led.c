/******************************************************************************
 *
 * Module: HLED
 *
 * File Name: led.c
 *
 * Description: Program source file for HAL LED Module
 *
 * Author: Omar Khedr
 ******************************************************************************/

/*Include of the module header file*/
#include "led.h"

/************************************************************************************
 * Function Name: HLED_VOIDInit
 * Parameters (in): uint8_t Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					uint8_t Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_LEDState_t - the state of the function
 * Description: Function to initialize a specific pin to be output for LED
 ************************************************************************************/

En_LEDState_t HLED_VOIDInit(uint8_t Copy_U8Port, uint8_t Copy_U8Pin)
{
	/*Variable to store the state of the function*/
	En_LEDState_t LOC_ENState = LED_NOT_OK;
	if(MDIO_VOIDSetPinDirection(Copy_U8Port,Copy_U8Pin,HIGH) == DIO_OK)
	{
		LOC_ENState = LED_OK;
	}
	else
	{
		/*Do Nothing*/
		LOC_ENState = LED_NOT_OK;
	}
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: HLED_VOIDON
 * Parameters (in): uint8_t Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					uint8_t Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_LEDState_t - the state of the function
 * Description: Function to set the LED ON
 ************************************************************************************/

En_LEDState_t HLED_VOIDON(uint8_t Copy_U8Port, uint8_t Copy_U8Pin)
{
	/*Variable to store the state of the function*/
	En_LEDState_t LOC_ENState = LED_NOT_OK;
	if (MDIO_VOIDSetPinValue(Copy_U8Port,Copy_U8Pin,HIGH) == DIO_OK)
	{
		LOC_ENState = LED_OK;
	}
	else
	{
		/*Do Nothing*/
		LOC_ENState = LED_NOT_OK;
	}
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: HLED_VOIDOFF
 * Parameters (in): uint8_t Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					uint8_t Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_LEDState_t - the state of the function
 * Description: Function to set the LED OFF
 ************************************************************************************/

En_LEDState_t HLED_VOIDOFF(uint8_t Copy_U8Port, uint8_t Copy_U8Pin)
{
	/*Variable to store the state of the function*/
	En_LEDState_t LOC_ENState = LED_NOT_OK;
	if (MDIO_VOIDSetPinValue(Copy_U8Port,Copy_U8Pin,LOW) == DIO_OK)
	{
		LOC_ENState = LED_OK;
	}
	else
	{
		/*Do Nothing*/
		LOC_ENState = LED_NOT_OK;
	}
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: HLED_VOIDToggle
 * Parameters (in): uint8_t Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					uint8_t Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_LEDState_t - the state of the function
 * Description: Function to toggle the LED
 ************************************************************************************/

En_LEDState_t HLED_VOIDToggle(uint8_t Copy_U8Port, uint8_t Copy_U8Pin)
{
	/*Variable to store the state of the function*/
	En_LEDState_t LOC_ENState = LED_NOT_OK;
	if (MDIO_VOIDTogglePinValue(Copy_U8Port,Copy_U8Pin) == DIO_OK)
	{
		LOC_ENState = LED_OK;
	}
	else
	{
		/*Do Nothing*/
		LOC_ENState = LED_NOT_OK;
	}
	return LOC_ENState;
}

