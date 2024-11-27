/******************************************************************************
*
* Module: APP
*
* File Name: app.h
*
* Description: Interface header file for the Application
*
* Author: Omar Khedr
******************************************************************************/
#ifndef _APP_INTERFACE_H_
#define _APP_INTERFACE_H_

/*******************************************************************************
*                              Module Inclusions                               *
*******************************************************************************/

/*Include of Standard types header file */
#include "../LIB/STD_TYPES.h"
/*Include of Bit Math header file*/
#include "../LIB/BIT_MATH.h"
/*Include of HAL LED module*/
#include "../ECUAL/LED/led.h"
/*Include of HAL Button module*/
#include "../ECUAL/Button/button.h"
/*Include of MCAL DIO module*/
#include "../MCAL/DIO/dio.h"
/*Include of MCAL External Interrupt module*/
#include "../MCAL/External Interrupt/exint.h"
/*Include of MCAL Timer module*/
#include "../MCAL/Timer/timer.h"

/*******************************************************************************
 *                      Module Definitions                                     *
 *******************************************************************************/

/*Enumeration to define module states*/
typedef enum
{
	APP_OK,
	APP_NOT_OK
} EN_APPState_t;

/*Enumeration to check which light is on*/
typedef enum
{
	START,
	RED,
	YELLOW_1, /*from green to red*/
	YELLOW_2, /*from red to green*/
	GREEN
} EN_APPColour_t;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

EN_APPState_t APP_VOIDInit(void);
EN_APPState_t APP_VOIDStart(void);
void APP_VOIDNormalMode(void);
void APP_VOIDPedestrianMode(void);

/*******************************************************************************
 *                      Module Used Macros                                    *
 *******************************************************************************/

#define ONE_SECOND (1U)
#define FIVE_SECOND (5U)
#define CAR_RED PIN2
#define CAR_YELLOW PIN1
#define CAR_GREEN PIN0
#define PEDESTRIAN_RED PIN2
#define PEDESTRIAN_YELLOW PIN1
#define PEDESTRIAN_GREEN PIN0
#define CAR_PORT PORTA
#define PEDESTRIAN_PORT PORTB

#endif
