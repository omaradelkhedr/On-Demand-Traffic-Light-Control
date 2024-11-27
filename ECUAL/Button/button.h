/******************************************************************************
*
* Module: HBTN
*
* File Name: button.h
*
* Description: Interface header file for HAL Button Module
*
* Author: Omar Khedr
******************************************************************************/
#ifndef _HBTN_INTERFACE_H_
#define _HBTN_INTERFACE_H_

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
	BUTTON_OK,
	BUTTON_NOT_OK,
} En_ButtonState_t ;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

En_ButtonState_t HBTN_VOIDInit(uint8_t Copy_U8Port, uint8_t Copy_U8Pin);

#endif
