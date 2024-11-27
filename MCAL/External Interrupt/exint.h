/******************************************************************************
*
* Module: MEXINT
*
* File Name: exint.h
*
* Description: Interface header file for MCAL External Interrupt Module
*
* Author: Omar Khedr
******************************************************************************/
#ifndef _EXINT_INTERFACE_H_
#define _EXINT_INTERFACE_H_

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
	EXINT_OK,
	EXINT_NOT_OK
} En_EXINTState_t;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

En_EXINTState_t MEXINT_VOIDGIEEnable (void);
En_EXINTState_t MEXINT_VOIDGIEDisable (void);
En_EXINTState_t MEXINT0_VOIDInit (void);
En_EXINTState_t MEXINT0_VOIDEnableInt (void);
En_EXINTState_t MEXINT0_VOIDDisableInt (void);
En_EXINTState_t MEXINT_VOIDINT0CallBackFunction (void (* Copy_VOIDCallBackPtr) (void));


/*******************************************************************************
 *                      Module Used Macros                                    *
 *******************************************************************************/

/*Used bits inside the registers*/
#define ISC00 (0U)
#define ISC01 (1U)
#define INT0 (6U)
#define I_BIT (7U)
#define INTF0 (6U)

/*******************************************************************************
 *                    		  Module Registers	                               *
 *******************************************************************************/

#define MCUCR_REG *((volatile uint8_t* ) 0x55)
#define SREG_REG *((volatile uint8_t* ) 0x5F)
#define GICR_REG *((volatile uint8_t* ) 0x5B)
#define GIFR_REG *((volatile uint8_t* ) 0x5A)

/*******************************************************************************
 *                    		  Module ISR		                                *
 *******************************************************************************/

void __vector_1 (void) __attribute__((signal));


#endif
