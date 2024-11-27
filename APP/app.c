/******************************************************************************
 *
 * Module: APP
 *
 * File Name: app.c
 *
 * Description: Program source file for the Application
 *
 * Author: Omar Khedr
 ******************************************************************************/

/*Include of the module header file*/
#include "app.h"

/*Global Variable to check which colour indicator is on in the present time*/
static EN_APPColour_t GLOB_ENColour=START;

/************************************************************************************
 * Function Name: APP_VOIDInit
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: EN_APPState_t - to store the state of the function
 * Description: Function to initialize all modules used in the application
 ************************************************************************************/

EN_APPState_t APP_VOIDInit(void)
{
	/*Variable to store the state of the function*/
	EN_APPState_t LOC_ENState = APP_NOT_OK;
	/*Initialize external interrupt on INT0 -> Rising edge*/
	if(MEXINT_VOIDINT0CallBackFunction(APP_VOIDPedestrianMode) == EXINT_OK)
	{
		/*Enable the external interrupt*/
		if(MEXINT0_VOIDInit() == EXINT_OK)
		{
			/*Store the address of the pedestrian mode*/
			if (MEXINT0_VOIDEnableInt() == EXINT_OK)
			{
				/*Initialize Timer in CTC mode*/
				if (MTMR0_VOIDCTCInit() == TIMER_OK)
				{
					/*Initialize the button at INT0 Pin -> Port D, Pin 2*/
					if (HBTN_VOIDInit(PORTD,PIN2) == BUTTON_OK)
					{
						/*Initialize LEDs
						 *Car LEDs: Green, Yellow, and Red, connected on Port A, Pins: 0, 1, and 2
						 *Pedestrian LEDs: Green, Yellow, and Red, connected on Port B, Pins: 0, 1, and 2
						 */
						if (HLED_VOIDInit(PORTA,PIN0)==LED_OK)
						{
							if (HLED_VOIDInit(PORTA,PIN1)==LED_OK)
							{
								if (HLED_VOIDInit(PORTA,PIN2)==LED_OK)
								{
									if (HLED_VOIDInit(PORTB,PIN0)==LED_OK)
									{
										if (HLED_VOIDInit(PORTB,PIN1)==LED_OK)
										{
											if (HLED_VOIDInit(PORTB,PIN2)==LED_OK)
											{
												LOC_ENState = APP_OK;
											}
											else
											{
												LOC_ENState=APP_NOT_OK;
											}
										}
										else
										{
											LOC_ENState=APP_NOT_OK;
										}

									}
									else
									{
										LOC_ENState=APP_NOT_OK;
									}

								}
								else
								{
									LOC_ENState=APP_NOT_OK;
								}
							}
							else
							{
								LOC_ENState=APP_NOT_OK;
							}
						}
						else
						{
							LOC_ENState=APP_NOT_OK;
						}
					}
					else
					{
						LOC_ENState = APP_NOT_OK;
					}
				}
				else
				{
					LOC_ENState = APP_NOT_OK;
				}
			}
			else
			{
				LOC_ENState = APP_NOT_OK;
			}
		}
		else
		{
			LOC_ENState = APP_NOT_OK;
		}
	}
	else
	{
		LOC_ENState = APP_NOT_OK;
	}
	return LOC_ENState;
}

/************************************************************************************
 * Function Name: APP_VOIDNormalMode
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to implement the normal mode
 ************************************************************************************/
void APP_VOIDNormalMode(void)
{
	if (GLOB_ENColour == START)
	{
		/*The default pedestrian lights: Red on, yellow/green off */
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_GREEN);
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_RED);
		/*Turn off both red and yellow lights*/
		HLED_VOIDOFF(CAR_PORT,CAR_YELLOW);
		HLED_VOIDOFF(CAR_PORT,CAR_RED);
		/*Turn on the green light*/
		HLED_VOIDON(CAR_PORT,CAR_GREEN);
		GLOB_ENColour = GREEN;
		/*wait for 5 seconds*/
		MTMR0_VOIDCTCStart(FIVE_SECOND);

	}
	if (GLOB_ENColour == GREEN)
	{
		/*Turn off both red and green lights*/
		HLED_VOIDOFF(CAR_PORT,CAR_GREEN);
		HLED_VOIDOFF(CAR_PORT,CAR_RED);
		/*Blink the yellow light for 5 seconds*/
		HLED_VOIDON(CAR_PORT,CAR_YELLOW);
		GLOB_ENColour = YELLOW_1;
	}
	else
	{
		/*Do Nothing*/
	}
	if (GLOB_ENColour == RED)
	{
		/*Turn off both red and green lights*/
		HLED_VOIDOFF(CAR_PORT,CAR_GREEN);
		HLED_VOIDOFF(CAR_PORT,CAR_RED);
		/*Blink the yellow light for 5 seconds*/
		HLED_VOIDON(CAR_PORT,CAR_YELLOW);
		GLOB_ENColour = YELLOW_2;
	}
	else
	{
		/*Do Nothing*/
	}
	if(GLOB_ENColour == YELLOW_1)
	{
		for (uint8_t LOC_U8Iterator = ZERO ; LOC_U8Iterator<FIVE_SECOND ;LOC_U8Iterator++)
		{
			HLED_VOIDToggle(CAR_PORT,CAR_YELLOW);
			MTMR0_VOIDCTCStart(ONE_SECOND);
		}
		/*Turn off both yellow and green lights*/
		HLED_VOIDOFF(CAR_PORT,CAR_GREEN);
		HLED_VOIDOFF(CAR_PORT,CAR_YELLOW);
		/*Turn on the red light*/
		HLED_VOIDON(CAR_PORT,CAR_RED);
		GLOB_ENColour = RED;
		/*wait for 5 seconds*/
		MTMR0_VOIDCTCStart(FIVE_SECOND);
	}
	else
	{
		/*Do Nothing*/
	}
	if(GLOB_ENColour == YELLOW_2)
	{
		for (uint8_t LOC_U8Iterator = ZERO ; LOC_U8Iterator<FIVE_SECOND ;LOC_U8Iterator++)
		{
			HLED_VOIDToggle(CAR_PORT,CAR_YELLOW);
			MTMR0_VOIDCTCStart(ONE_SECOND);
		}
		/*Turn off both yellow and red lights*/
		HLED_VOIDOFF(CAR_PORT,CAR_RED);
		HLED_VOIDOFF(CAR_PORT,CAR_YELLOW);
		/*Turn on the green light*/
		HLED_VOIDON(CAR_PORT,CAR_GREEN);
		GLOB_ENColour = GREEN;
		/*wait for 5 seconds*/
		MTMR0_VOIDCTCStart(FIVE_SECOND);
	}
	else
	{
		/*Do Nothing*/
	}
}

/************************************************************************************
 * Function Name: APP_VOIDNormalMode
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to implement the pedestrian mode
 ************************************************************************************/

void APP_VOIDPedestrianMode(void)
{
	if (GLOB_ENColour == RED)
	{
		/*Car's red light is on*/
		HLED_VOIDON(CAR_PORT,CAR_RED);
		GLOB_ENColour = RED;
		/*Pedestrian's red light is off*/
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_RED);
		/*Pedestrian's green light is on*/
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_GREEN);
		/*Wait for five seconds*/
		MTMR0_VOIDCTCStart(FIVE_SECOND);
		/*Car's red light off*/
		HLED_VOIDOFF(CAR_PORT,CAR_RED);
		/*Blink both yellow lights for 5 seconds*/
		HLED_VOIDON(CAR_PORT,CAR_YELLOW);
		GLOB_ENColour =YELLOW_2;
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		for (uint8_t LOC_U8Iterator = ZERO ; LOC_U8Iterator<FIVE_SECOND ;LOC_U8Iterator++)
		{
			HLED_VOIDToggle(CAR_PORT,CAR_YELLOW);
			HLED_VOIDToggle(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
			MTMR0_VOIDCTCStart(ONE_SECOND);
		}
		/*Prepare to return to the normal mode*/
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_GREEN);
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_RED);
		HLED_VOIDOFF(CAR_PORT,CAR_RED);
		HLED_VOIDOFF(CAR_PORT,CAR_YELLOW);
		HLED_VOIDON(CAR_PORT,CAR_GREEN);
		GLOB_ENColour =GREEN;
	}
	else if (GLOB_ENColour == GREEN)
	{
		/*Pedestrian's green/yellow is off*/
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_GREEN);
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		/*Pedestrian's red light is on*/
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_RED);
		/*Car's green/red lights are off*/
		HLED_VOIDOFF(CAR_PORT,CAR_GREEN);
		HLED_VOIDOFF(CAR_PORT,CAR_RED);
		/*Blink both yellow lights for 5 seconds*/
		HLED_VOIDON(CAR_PORT,CAR_YELLOW);
		GLOB_ENColour=YELLOW_1;
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		for (uint8_t LOC_U8Iterator = ZERO ; LOC_U8Iterator<5 ;LOC_U8Iterator++)
		{
			HLED_VOIDToggle(CAR_PORT,CAR_YELLOW);
			HLED_VOIDToggle(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
			MTMR0_VOIDCTCStart(ONE_SECOND);
		}
		/*Car's red light is on,Car's green/yellow light is off*/
		HLED_VOIDOFF(CAR_PORT,CAR_YELLOW);
		HLED_VOIDOFF(CAR_PORT,CAR_GREEN);
		HLED_VOIDON(CAR_PORT,CAR_RED);
		GLOB_ENColour=RED;
		/*Pedestrian's red/yellow light is off,Pedestrian's green light is on*/
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_RED);
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_GREEN);
		/*Wait for 5 seconds*/
		MTMR0_VOIDCTCStart(FIVE_SECOND);
		/*Blink both yellow lights for 5 seconds*/
		HLED_VOIDON(CAR_PORT,CAR_YELLOW);
		GLOB_ENColour =YELLOW_2;
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		for (uint8_t LOC_U8Iterator = ZERO ; LOC_U8Iterator<FIVE_SECOND ;LOC_U8Iterator++)
		{
			HLED_VOIDToggle(CAR_PORT,CAR_YELLOW);
			HLED_VOIDToggle(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
			MTMR0_VOIDCTCStart(ONE_SECOND);
		}
		/*Prepare to return to the normal mode*/
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_GREEN);
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_RED);
		HLED_VOIDOFF(CAR_PORT,CAR_RED);
		HLED_VOIDOFF(CAR_PORT,CAR_YELLOW);
		HLED_VOIDON(CAR_PORT,CAR_GREEN);
		GLOB_ENColour =GREEN;
	}
	else if (GLOB_ENColour == YELLOW_1)
	{
		/*Pedestrian's green/yellow is off*/
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_GREEN);
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		/*Pedestrian's red light is on*/
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_RED);
		/*Car's green/red lights are off*/
		HLED_VOIDOFF(CAR_PORT,CAR_GREEN);
		HLED_VOIDOFF(CAR_PORT,CAR_RED);
		/*Blink both yellow lights for 5 seconds*/
		HLED_VOIDON(CAR_PORT,CAR_YELLOW);
		GLOB_ENColour=YELLOW_1;
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		for (uint8_t LOC_U8Iterator = ZERO ; LOC_U8Iterator<5 ;LOC_U8Iterator++)
		{
			HLED_VOIDToggle(CAR_PORT,CAR_YELLOW);
			HLED_VOIDToggle(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
			MTMR0_VOIDCTCStart(ONE_SECOND);
		}
		/*Car's red light is on,Car's green/yellow light is off*/
		HLED_VOIDOFF(CAR_PORT,CAR_YELLOW);
		HLED_VOIDOFF(CAR_PORT,CAR_GREEN);
		HLED_VOIDON(CAR_PORT,CAR_RED);
		GLOB_ENColour=RED;
		/*Pedestrian's red/yellow light is off,Pedestrian's green light is on*/
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_RED);
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_GREEN);
		/*Wait for 5 seconds*/
		MTMR0_VOIDCTCStart(FIVE_SECOND);
		/*Blink both yellow lights for 5 seconds*/
		HLED_VOIDON(CAR_PORT,CAR_YELLOW);
		GLOB_ENColour =YELLOW_2;
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		for (uint8_t LOC_U8Iterator = ZERO ; LOC_U8Iterator<FIVE_SECOND ;LOC_U8Iterator++)
		{
			HLED_VOIDToggle(CAR_PORT,CAR_YELLOW);
			HLED_VOIDToggle(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
			MTMR0_VOIDCTCStart(ONE_SECOND);
		}
		/*Prepare to return to the normal mode*/
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_GREEN);
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_RED);
		HLED_VOIDOFF(CAR_PORT,CAR_RED);
		HLED_VOIDOFF(CAR_PORT,CAR_YELLOW);
		HLED_VOIDON(CAR_PORT,CAR_GREEN);
		GLOB_ENColour =GREEN;
		/*Wait for 5 seconds*/
		MTMR0_VOIDCTCStart(FIVE_SECOND);
		/*Car's green light is off*/
		HLED_VOIDOFF(CAR_PORT,CAR_GREEN);
	}
	else if (GLOB_ENColour == YELLOW_2)
	{
		/*Pedestrian's green/yellow is off*/
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_GREEN);
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		/*Pedestrian's red light is on*/
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_RED);
		/*Car's green/red lights are off*/
		HLED_VOIDOFF(CAR_PORT,CAR_GREEN);
		HLED_VOIDOFF(CAR_PORT,CAR_RED);
		/*Blink both yellow lights for 5 seconds*/
		HLED_VOIDON(CAR_PORT,CAR_YELLOW);
		GLOB_ENColour=YELLOW_1;
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		for (uint8_t LOC_U8Iterator = ZERO ; LOC_U8Iterator<5 ;LOC_U8Iterator++)
		{
			HLED_VOIDToggle(CAR_PORT,CAR_YELLOW);
			HLED_VOIDToggle(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
			MTMR0_VOIDCTCStart(ONE_SECOND);
		}
		/*Car's red light is on,Car's green/yellow light is off*/
		HLED_VOIDOFF(CAR_PORT,CAR_YELLOW);
		HLED_VOIDOFF(CAR_PORT,CAR_GREEN);
		HLED_VOIDON(CAR_PORT,CAR_RED);
		GLOB_ENColour=RED;
		/*Pedestrian's red/yellow light is off,Pedestrian's green light is on*/
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_RED);
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_GREEN);
		/*Wait for 5 seconds*/
		MTMR0_VOIDCTCStart(FIVE_SECOND);
		/*Blink both yellow lights for 5 seconds*/
		HLED_VOIDON(CAR_PORT,CAR_YELLOW);
		GLOB_ENColour =YELLOW_2;
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		for (uint8_t LOC_U8Iterator = ZERO ; LOC_U8Iterator<FIVE_SECOND ;LOC_U8Iterator++)
		{
			HLED_VOIDToggle(CAR_PORT,CAR_YELLOW);
			HLED_VOIDToggle(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
			MTMR0_VOIDCTCStart(ONE_SECOND);
		}
		/*Prepare to return to the normal mode*/
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_GREEN);
		HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
		HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_RED);
		/*Car's red light is off*/
		HLED_VOIDOFF(CAR_PORT,CAR_RED);
		GLOB_ENColour =GREEN;
	}
	else
	{
		/*Do Nothing*/
	}
}

/************************************************************************************
 * Function Name: APP_VOIDStart
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: EN_APPState_t - to store the state of the function
 * Description: Function to start the On-Demand Traffic Lights Control application
 ************************************************************************************/

EN_APPState_t APP_VOIDStart(void)
{
	/*Variable to store the state of the function*/
	EN_APPState_t LOC_ENState = APP_NOT_OK;
	/*Prepare Normal Mode*/
	HLED_VOIDON(PEDESTRIAN_PORT,PEDESTRIAN_RED);
	HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_GREEN);
	HLED_VOIDOFF(PEDESTRIAN_PORT,PEDESTRIAN_YELLOW);
	/*Run the normal mode, pedestrian mode will be activated when the button is released
	 * as i configured the external interrupt INT0 on rising edge and connected the button with
	 * a pull up configuration
	 */
	APP_VOIDNormalMode();
	LOC_ENState = APP_OK;
	return LOC_ENState;
}
