/******************************************************************************
*
* Module: MDIO
*
* File Name: MDIO_Interface.h
*
* Description: Interface header file for MCAL Digital Input Output (DIO) Module
*
* Author: Omar Khedr
******************************************************************************/
#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

/*******************************************************************************
*                              Module Inclusions                               *
*******************************************************************************/

/*Include of Standard types header file */
#include "../../LIB/STD_TYPES.h"
/*Include of Bit Math header file*/
#include "../../LIB/BIT_MATH.h"

/*******************************************************************************
 *                      Module Definitions                                     *
 *******************************************************************************/

/*Enumeration to define module states*/
typedef enum
{
	DIO_OK,
	DIO_NOT_OK,
	DIO_HIGH,
	DIO_LOW
} En_DIOState_t ;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

En_DIOState_t MDIO_VOIDSetPinDirection (uint8_t Copy_U8Port, uint8_t Copy_U8Pin, uint8_t Copy_U8Direction);
En_DIOState_t MDIO_VOIDSetPortDirection (uint8_t Copy_U8Port, uint8_t Copy_U8Direction);
En_DIOState_t MDIO_VOIDSetPinValue (uint8_t Copy_U8Port, uint8_t Copy_U8Pin, uint8_t Copy_U8Value);
En_DIOState_t MDIO_VOIDSetPortValue (uint8_t Copy_U8Port, uint8_t Copy_U8Value);
En_DIOState_t MDIO_VOIDTogglePinValue (uint8_t Copy_U8Port, uint8_t Copy_U8Pin);
En_DIOState_t MDIO_U8GetPinValue (uint8_t Copy_U8Port, uint8_t Copy_U8Pin);
uint8_t MDIO_U8GetPortValue (uint8_t Copy_U8Port);


/*******************************************************************************
 *                      Module Used Macros                                    *
 *******************************************************************************/

#define LOW		(0U)
#define HIGH	(1U)
#define PORTA	(0U)
#define PORTB	(1U)
#define PORTC	(2U)
#define PORTD	(3U)
#define ALL_ZERO (0U)
#define ALL_ONE	(0b11111111)
#define PIN0	(0U)
#define PIN1	(1U)
#define PIN2	(2U)
#define PIN3	(3U)
#define PIN4	(4U)
#define PIN5	(5U)
#define PIN6	(6U)
#define PIN7	(7U)
#define INPUT	(0U)
#define OUTPUT	(1U)

/*******************************************************************************
 *                    		  Module Registers	                               *
 *******************************************************************************/\

#define PORTA_REG		*((volatile uint8_t*) 0x3B)
#define DDRA_REG		*((volatile uint8_t*) 0x3A)
#define PINA_REG		*((volatile uint8_t*) 0x39)

#define PORTB_REG		*((volatile uint8_t*) 0x38)
#define DDRB_REG		*((volatile uint8_t*) 0x37)
#define PINB_REG		*((volatile uint8_t*) 0x36)

#define PORTC_REG		*((volatile uint8_t*) 0x35)
#define DDRC_REG		*((volatile uint8_t*) 0x34)
#define PINC_REG		*((volatile uint8_t*) 0x33)

#define PORTD_REG		*((volatile uint8_t*) 0x32)
#define DDRD_REG		*((volatile uint8_t*) 0x31)
#define PIND_REG		*((volatile uint8_t*) 0x30)


#endif
