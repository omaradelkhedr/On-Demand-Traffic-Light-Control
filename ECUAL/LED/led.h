/******************************************************************************
*
* Module: HLED
*
* File Name: led.h
*
* Description: Interface header file for HAL LED Module
*
* Author: Omar Khedr
******************************************************************************/
#ifndef _HLED_INTERFACE_H_
#define _HLED_INTERFACE_H_

/*******************************************************************************
*                              Module Inclusions                               *
*******************************************************************************/

/*Include of Standard types header file */
#include "../../LIB/STD_TYPES.h"
/*Include of Bit Math header file*/
#include "../../LIB/BIT_MATH.h"
/*Include of MCAL DIO header file*/
#include "../../MCAL/DIO/dio.h"

/*******************************************************************************
 *                      Module Definitions                                     *
 *******************************************************************************/

/*Enumeration to define module states*/
typedef enum
{
	LED_OK,
	LED_NOT_OK
} En_LEDState_t ;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

En_LEDState_t HLED_VOIDInit(uint8_t Copy_U8Port, uint8_t Copy_U8Pin);
En_LEDState_t HLED_VOIDON(uint8_t Copy_U8Port, uint8_t Copy_U8Pin);
En_LEDState_t HLED_VOIDOFF(uint8_t Copy_U8Port, uint8_t Copy_U8Pin);
En_LEDState_t HLED_VOIDToggle(uint8_t Copy_U8Port, uint8_t Copy_U8Pin);


#endif
