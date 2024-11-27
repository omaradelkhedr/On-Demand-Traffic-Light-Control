/******************************************************************************
 *
 * Module: HBTN
 *
 * File Name: button.c
 *
 * Description: Program source file for HAL Button Module
 *
 * Author: Omar Khedr
 ******************************************************************************/

/*Include of the module header file*/
#include "button.h"

/************************************************************************************
 * Function Name: HBTN_VOIDInit
 * Parameters (in): uint8_t Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					uint8_t Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_ButtonState_t - the state of the function
 * Description: Function to initialize a specific pin to be input for button
 ************************************************************************************/

En_ButtonState_t HBTN_VOIDInit(uint8_t Copy_U8Port, uint8_t Copy_U8Pin)
{
	En_ButtonState_t LOC_ENState = BUTTON_NOT_OK;
	if (MDIO_VOIDSetPinDirection(Copy_U8Port,Copy_U8Pin,INPUT) == DIO_OK)
	{
		/*Enable Pull up resistance*/
		if (MDIO_VOIDSetPinValue(Copy_U8Port,Copy_U8Pin,HIGH) == DIO_OK)
		{
			LOC_ENState=BUTTON_OK;
		}
		else
		{
			/*Do Nothing*/
			LOC_ENState=BUTTON_NOT_OK;
		}
	}
	else
	{
		/*Do Nothing*/
		LOC_ENState=BUTTON_NOT_OK;
	}
	return LOC_ENState;
}
