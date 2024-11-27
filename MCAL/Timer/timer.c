/******************************************************************************
 *
 * Module: MTMR
 *
 * File Name: tiemr.c
 *
 * Description: Program source file for MCAL Timer Module
 *
 * Author: Omar Khedr
 ******************************************************************************/

/*Include of the module header file*/
#include "timer.h"

/************************************************************************************
 * Function Name: MTMR0_VOIDCTCInit
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_TIMERState_t - The state of the function
 * Description: Function to initialize timer 0 in CTC mode
 ************************************************************************************/

En_TIMERState_t MTMR0_VOIDCTCInit (void)
{
	En_TIMERState_t LOC_ENState= TIMER_NOT_OK;
	/*Select CTC mode*/
	SET_BIT(TCCR0_REG,WGM01);
	CLR_BIT(TCCR0_REG,WGM00);
	/*Select Normal port operation mode*/
	CLR_BIT(TCCR0_REG,COMM01);
	CLR_BIT(TCCR0_REG,COMM00);
	LOC_ENState = TIMER_OK;
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: MTMR0_VOIDCTCStart
 * Parameters (in): uint16_t Copy_U16Second - to store the required number of seconds
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: En_TIMERState_t - The state of the function
 * Description: Function to start the timer is complete, maximum number of seconds = 262s
 ************************************************************************************/

En_TIMERState_t MTMR0_VOIDCTCStart (uint16_t Copy_U16Time)
{
	/*Variable to store the state of the function*/
		En_TIMERState_t LOC_ENState= TIMER_NOT_OK;
		if (Copy_U16Time > MAXIMUM_SECONDS_NUMBER)
		{
			LOC_ENState = TIMER_NOT_OK;
		}
		else
		{
			/*Variable to iterate on*/
			uint16_t LOC_U16Complete=ZERO;
			/*Calculation:
			 *Tov = ( 125 * 256 )/(8000000) = 4ms
			 *as the Required time = Copy_U8Second sec -> Counter * 2= Copy_U8Second/(4ms)= Copy_U8Second * 250
			 *Complete_VALUE = Copy_U8Second * 125
			 *Exit when we reach the required time
			 */
			/*Selecting the value 125 to be compared with the timer counter*/
			OCR0_REG = OCR0_REG_VALUE;
			/*Select pre-scaler value = /256  --> Timer Start Counting*/
			SET_BIT(TCCR0_REG,CS02);
			CLR_BIT(TCCR0_REG,CS01);
			CLR_BIT(TCCR0_REG,CS00);
			while (LOC_U16Complete != (COUNTER_VALUE * Copy_U16Time))
			{
				while (GET_BIT(TIFR_REG,OCF0) == ZERO)
				{
					/*Do Nothing -> wait for the compare match*/
				}
				/*Clear the flag manually*/
				SET_BIT(TIFR_REG,OCF0);
				LOC_U16Complete++;
			}
			if (LOC_U16Complete == (COUNTER_VALUE * Copy_U16Time))
			{
				LOC_ENState=TIMER_COMPLETE;
			}
			else
			{
				LOC_ENState = TIMER_NOT_COMPLETE;
			}
		}
		return LOC_ENState;
}

