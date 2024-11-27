/******************************************************************************
*
* Module: MTMR
*
* File Name: timer.h
*
* Description: Interface header file for MCAL Timer Module
*
* Author: Omar Khedr
******************************************************************************/
#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_

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

/*Enumeration that contains module states*/
typedef enum
{
	TIMER_OK,
	TIMER_NOT_OK,
	TIMER_COMPLETE,
	TIMER_NOT_COMPLETE
} En_TIMERState_t;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

En_TIMERState_t MTMR0_VOIDCTCInit (void);
En_TIMERState_t MTMR0_VOIDCTCStart (uint16_t Copy_U16Second);

/*******************************************************************************
 *                      Module Used Macros                                    *
 *******************************************************************************/

/*Used bits inside the registers*/
#define WGM01 (6U)
#define WGM00 (3U)
#define COMM01 (5U)
#define COMM00 (4U)
#define CS02 (2U)
#define CS01 (1U)
#define CS00 (0U)
#define OCIE0 (1U)
#define TOIE (0U)
#define OCF0 (1U)
#define TOV0 (0U)
/*Used macros inside module functions*/
#define ZERO (0U)
#define MAXIMUM_SECONDS_NUMBER (262U)
#define OCR0_REG_VALUE (125U)
#define COUNTER_VALUE (125U)

/*******************************************************************************
 *                    		  Module Registers	                               *
 *******************************************************************************/

#define TCCR0_REG *((volatile uint8_t *) 0X53)
#define TCNT0_REG *((volatile uint8_t *) 0X52)
#define OCR0_REG *((volatile uint8_t *) 0X5C)
#define TIMSK_REG *((volatile uint8_t *) 0X59)
#define TIFR_REG *((volatile uint8_t *) 0X58)

#endif
