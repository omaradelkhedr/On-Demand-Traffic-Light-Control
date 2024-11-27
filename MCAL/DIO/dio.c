/******************************************************************************
 *
 * Module: MDIO
 *
 * File Name: MDIO_Program.c
 *
 * Description: Program source file for MCAL Digital Input Output (DIO) Module
 *
 * Author: Omar Khedr
 ******************************************************************************/

/*Include of the module header file*/
#include "dio.h"

/************************************************************************************
 * Function Name: MDIO_VOIDSetPinDirection
 * Parameters (in): uint8_t Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					uint8_t Copy_U8Pin - to store the value of the desired Pin (0->7)
 * 					uint8_t Copy_U8Direction - to store the value of the desired Direction (0/1)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_DIOState_t - The state of the function
 * Description: Function to set the direction of a specific pin inside a specific port
 ************************************************************************************/

En_DIOState_t MDIO_VOIDSetPinDirection (uint8_t Copy_U8Port, uint8_t Copy_U8Pin, uint8_t Copy_U8Direction)
{
	/*Local Variable to return the state of the function*/
	En_DIOState_t LOC_ENState= DIO_NOT_OK;
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*If condition inside each case to get the direction and storing the direction into the DDR register*/
	case PORTA:
		if (LOW == Copy_U8Direction)
		{
			CLR_BIT(DDRA_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else if(HIGH == Copy_U8Direction)
		{
			SET_BIT(DDRA_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else
		{
			/*Do Nothing*/
			LOC_ENState = DIO_NOT_OK;
		}
		break;
	case PORTB:
		if (LOW == Copy_U8Direction)
		{
			CLR_BIT(DDRB_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else if(HIGH == Copy_U8Direction)
		{
			SET_BIT(DDRB_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else
		{
			/*Do Nothing*/
			LOC_ENState = DIO_NOT_OK;
		}
		break;
	case PORTC:
		if (LOW == Copy_U8Direction)
		{
			CLR_BIT(DDRC_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else if(HIGH == Copy_U8Direction)
		{
			SET_BIT(DDRC_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else
		{
			/*Do Nothing*/
			LOC_ENState = DIO_NOT_OK;
		}
		break;
	case PORTD:
		if (LOW == Copy_U8Direction)
		{
			CLR_BIT(DDRD_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else if(HIGH == Copy_U8Direction)
		{
			SET_BIT(DDRD_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else
		{
			/*Do Nothing*/
			LOC_ENState = DIO_NOT_OK;
		}
		break;
	default: break;
	}
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: MDIO_VOIDSetPortDirection
 * Parameters (in): uint8_t Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					uint8_t Copy_U8Direction - to store the value of the desired Direction (0/1)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_DIOState_t - The state of the function
 * Description: Function to set the direction of a specific port
 ************************************************************************************/

En_DIOState_t MDIO_VOIDSetPortDirection (uint8_t Copy_U8Port, uint8_t Copy_U8Direction)
{
	/*Local Variable to return the state of the function*/
	En_DIOState_t LOC_ENState=DIO_NOT_OK;
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*Storing the value of the direction into the DDR register*/
	case PORTA:
		DDRA_REG=Copy_U8Direction;
		LOC_ENState = DIO_OK;
		break;
	case PORTB:
		DDRB_REG=Copy_U8Direction;
		LOC_ENState = DIO_OK;
		break;
	case PORTC:
		DDRC_REG=Copy_U8Direction;
		LOC_ENState = DIO_OK;
		break;
	case PORTD:
		DDRD_REG=Copy_U8Direction;
		LOC_ENState = DIO_OK;
		break;
	default: break;
	}
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: MDIO_VOIDSetPinValue
 * Parameters (in): uint8_t Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					uint8_t Copy_U8Pin - to store the value of the desired Pin (0->7)
 * 					uint8_t Copy_U8Value - to store the desired value (0/1)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_DIOState_t - The state of the function
 * Description: Function to set the value of a specific pin inside a specific port
 ************************************************************************************/

En_DIOState_t MDIO_VOIDSetPinValue (uint8_t Copy_U8Port, uint8_t Copy_U8Pin, uint8_t Copy_U8Value)
{
	/*Local Variable to return the state of the function*/
	En_DIOState_t LOC_ENState=DIO_NOT_OK;
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*If condition inside each case to get the value then storing the value into the pin*/
	case PORTA:
		if (LOW == Copy_U8Value)
		{
			CLR_BIT(PORTA_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else if(HIGH == Copy_U8Value)
		{
			SET_BIT(PORTA_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else
		{
			/*Do Nothing*/
			LOC_ENState = DIO_NOT_OK;
		}
		break;
	case PORTB:
		if (LOW == Copy_U8Value)
		{
			CLR_BIT(PORTB_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else if(HIGH == Copy_U8Value)
		{
			SET_BIT(PORTB_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else
		{
			/*Do Nothing*/
			LOC_ENState = DIO_NOT_OK;
		}
		break;
	case PORTC:
		if (LOW == Copy_U8Value)
		{
			CLR_BIT(PORTC_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else if(HIGH == Copy_U8Value)
		{
			SET_BIT(PORTC_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else
		{
			/*Do Nothing*/
			LOC_ENState = DIO_NOT_OK;
		}
		break;
	case PORTD:
		if (LOW == Copy_U8Value)
		{
			CLR_BIT(PORTD_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else if(HIGH == Copy_U8Value)
		{
			SET_BIT(PORTD_REG,Copy_U8Pin);
			LOC_ENState = DIO_OK;
		}
		else
		{
			/*Do Nothing*/
			LOC_ENState = DIO_NOT_OK;
		}
		break;
	default: break;
	}
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: MDIO_VOIDSetPortValue
 * Parameters (in): uint8_t Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					uint8_t Copy_U8Value - to store the desired 8-bit value
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_DIOState_t - The state of the function
 * Description: Function to store a value inside a specific port
 ************************************************************************************/

En_DIOState_t MDIO_VOIDSetPortValue (uint8_t Copy_U8Port, uint8_t Copy_U8Value)
{
	/*Local Variable to return the state of the function*/
	En_DIOState_t LOC_ENState=DIO_NOT_OK;
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*Storing the value of the port into the PORT register*/
	case PORTA:
		PORTA_REG=Copy_U8Value;
		LOC_ENState = DIO_OK;
		break;
	case PORTB:
		PORTB_REG=Copy_U8Value;
		LOC_ENState = DIO_OK;
		break;
	case PORTC:
		PORTC_REG=Copy_U8Value;
		LOC_ENState = DIO_OK;
		break;
	case PORTD:
		PORTD_REG=Copy_U8Value;
		LOC_ENState = DIO_OK;
		break;
	default: break;
	}
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: MDIO_VOIDTogglePinValue
 * Parameters (in): uint8_t Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					uint8_t Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_DIOState_t - The state of the function
 * Description: Function to complement the value of a specific pin inside a specific port
 ************************************************************************************/

En_DIOState_t MDIO_VOIDTogglePinValue (uint8_t Copy_U8Port, uint8_t Copy_U8Pin)
{
	/*Local Variable to return the state of the function*/
	En_DIOState_t LOC_ENState=DIO_NOT_OK;
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*Complementing the value of the bit*/
	case PORTA:
		TOGGLE_BIT(PORTA_REG,Copy_U8Pin);
		LOC_ENState = DIO_OK;
		break;
	case PORTB:
		TOGGLE_BIT(PORTB_REG,Copy_U8Pin);
		LOC_ENState = DIO_OK;
		break;
	case PORTC:
		TOGGLE_BIT(PORTC_REG,Copy_U8Pin);
		LOC_ENState = DIO_OK;
		break;
	case PORTD:
		TOGGLE_BIT(PORTD_REG,Copy_U8Pin);
		LOC_ENState = DIO_OK;
		break;
	default: break;
	}
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: MDIO_U8GetPinValue
 * Parameters (in): uint8_t Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					uint8_t Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_DIOState_t - The state of the function
 * Description: Function to return the value of a specific pin inside a specific port
 ************************************************************************************/

En_DIOState_t MDIO_U8GetPinValue (uint8_t Copy_U8Port, uint8_t Copy_U8Pin)
{
	/*Variable to store the value of the pin into then returning it*/
	uint8_t LOC_U8RetVal;
	/*Variable to store the state of the function*/
	En_DIOState_t LOC_ENState=DIO_NOT_OK;
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*Storing the value of the bit*/
	case PORTA:
		LOC_U8RetVal=GET_BIT(PINA_REG,Copy_U8Pin);
		if (LOC_U8RetVal == HIGH)
		{
			LOC_ENState=DIO_HIGH;
		}
		else if (LOC_U8RetVal == LOW)
		{
			LOC_ENState=DIO_LOW;
		}
		else
		{
			LOC_ENState=DIO_NOT_OK;
		}
		break;
	case PORTB:
		LOC_U8RetVal=GET_BIT(PINB_REG,Copy_U8Pin);
		if (LOC_U8RetVal == HIGH)
		{
			LOC_ENState=DIO_HIGH;
		}
		else if (LOC_U8RetVal == LOW)
		{
			LOC_ENState=DIO_LOW;
		}
		else
		{
			LOC_ENState=DIO_NOT_OK;
		}
		break;
	case PORTC:
		LOC_U8RetVal=GET_BIT(PINC_REG,Copy_U8Pin);
		if (LOC_U8RetVal == HIGH)
		{
			LOC_ENState=DIO_HIGH;
		}
		else if (LOC_U8RetVal == LOW)
		{
			LOC_ENState=DIO_LOW;
		}
		else
		{
			LOC_ENState=DIO_NOT_OK;
		}
		break;
	case PORTD:
		LOC_U8RetVal=GET_BIT(PIND_REG,Copy_U8Pin);
		if (LOC_U8RetVal == HIGH)
		{
			LOC_ENState=DIO_HIGH;
		}
		else if (LOC_U8RetVal == LOW)
		{
			LOC_ENState=DIO_LOW;
		}
		else
		{
			LOC_ENState=DIO_NOT_OK;
		}
		break;
	default: break;
	}
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: MDIO_U8GetPortValue
 * Parameters (in): uint8_t Copy_U8Port - to store the desired Port (A/B/C/D)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: uint8_t LOC_U8RetVal - to store the value of the port
 * Description: Function to return the value of a specific port
 ************************************************************************************/

uint8_t MDIO_U8GetPortValue (uint8_t Copy_U8Port)
{
	/*Variable to store the value of the port into then returning it*/
	uint8_t LOC_U8RetVal;
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*Storing the value of the port*/
	case PORTA:
		LOC_U8RetVal=PINA_REG;
		break;
	case PORTB:
		LOC_U8RetVal=PINB_REG;
		break;
	case PORTC:
		LOC_U8RetVal=PINC_REG;
		break;
	case PORTD:
		LOC_U8RetVal=PIND_REG;
		break;
	default: break;
	}
	return LOC_U8RetVal;
}

