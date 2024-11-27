/******************************************************************************
 *
 * Module: MXINT
 *
 * File Name: exint.c
 *
 * Description: Program source file for MCAL External Interrupt Module
 *
 * Author: Omar Khedr
 ******************************************************************************/

/*Include of the module header file*/
#include "exint.h"

/*Callback pointer to be used in the callback function*/
static void (* GLOB_VOIDINT0CallBackPtr) (void);

/************************************************************************************
 * Function Name: MEXINT_VOIDGIEEnable
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_EXINTState_t - The state of the function
 * Description: Function to enable the general interrupts
 ************************************************************************************/

En_EXINTState_t MEXINT_VOIDGIEEnable (void)
{
	/*Local variable to store the state of the function*/
	En_EXINTState_t LOC_ENState = EXINT_NOT_OK;
	/*Set the I-Bit (Bit: 7) in SREG register to 1 to enable General Interrupts*/
	SET_BIT(SREG_REG,I_BIT);
	LOC_ENState = EXINT_OK;
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: MEXINT_VOIDGIEDisable
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_EXINTState_t - The state of the function
 * Description: Function to disable the general interrupts
 ************************************************************************************/

En_EXINTState_t MEXINT_VOIDGIEDisable (void)
{
	/*Local variable to store the state of the function*/
	En_EXINTState_t LOC_ENState = EXINT_NOT_OK;
	/*Clear the I-Bit (Bit: 7) in SREG register to 1 to disable General Interrupts*/
	CLR_BIT(SREG_REG,I_BIT);
	LOC_ENState = EXINT_OK;
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: MEXINT0_VOIDInit
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_EXINTState_t - The state of the function
 * Description: Function to initialize the interrupts on INT0
 ************************************************************************************/

En_EXINTState_t MEXINT0_VOIDInit (void)
{
	/*Local variable to store the state of the function*/
	En_EXINTState_t LOC_ENState = EXINT_NOT_OK;
	/*Setting ISC01 ISC00 bits to 11 to enable the interrupt sense on the rising edge*/
	SET_BIT(MCUCR_REG,ISC01);
	SET_BIT(MCUCR_REG,ISC00);
	LOC_ENState = EXINT_OK;
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: MEXINT0_VOIDEnableInt
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_EXINTState_t - The state of the function
 * Description: Function to enable the interrupt on INT0
 ************************************************************************************/

En_EXINTState_t MEXINT0_VOIDEnableInt (void)
{
	/*Local variable to store the state of the function*/
	En_EXINTState_t LOC_ENState = EXINT_NOT_OK;
	/*Enable the General Interrupts*/
	MEXINT_VOIDGIEEnable();
	/*Enable interrupt on INT0 by setting the INT0 bit in GICR register*/
	SET_BIT(GICR_REG,INT0);
	LOC_ENState = EXINT_OK;
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: MEXINT0_VOIDDisableInt
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_EXINTState_t - The state of the function
 * Description: Function to disable the interrupt on INT0
 ************************************************************************************/

En_EXINTState_t MEXINT0_VOIDDisableInt (void)
{
	/*Local variable to store the state of the function*/
	En_EXINTState_t LOC_ENState = EXINT_NOT_OK;
	/*Enable the General Interrupts*/
	MEXINT_VOIDGIEDisable();
	/*Disable interrupt on INT0 by clearing the INT0 bit in GICR register*/
	CLR_BIT(GICR_REG,INT0);
	LOC_ENState = EXINT_OK;
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: MEXINT0_VOIDDisableInt
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: ISR of INT0
 ************************************************************************************/

void __vector_1 (void)
{
	/*Calling the function through the callback pointer*/
	GLOB_VOIDINT0CallBackPtr();
}

/************************************************************************************
 * Function Name: MEXINT0_VOIDDisableInt
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: ISR of INT0
 ************************************************************************************/

En_EXINTState_t MEXINT_VOIDINT0CallBackFunction (void (* Copy_VOIDCallBackPtr) (void))
{
	En_EXINTState_t LOC_ENState = EXINT_NOT_OK;
	/*Storing the value of the passed function in the Call Back Pointer*/
	 GLOB_VOIDINT0CallBackPtr = Copy_VOIDCallBackPtr;
	 LOC_ENState= EXINT_OK;
	 return LOC_ENState;
}

