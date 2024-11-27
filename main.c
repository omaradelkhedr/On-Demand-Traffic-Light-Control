/******************************************************************************
 *
 * Module: Main File
 *
 * File Name: main.c
 *
 * Description: Source file for the Main
 *
 * Author: Omar Khedr
 ******************************************************************************/

/*Inclusion of the app.h file*/
#include "APP/app.h"

int main (void)
{
	/*Initialize the application*/
	EN_APPState_t LOC_ENState ;
	if (APP_VOIDInit() == APP_OK)
	{
		LOC_ENState = APP_OK;
	}
	else
	{
		LOC_ENState = APP_NOT_OK;
	}


	while (1)
	{
		if(LOC_ENState == APP_OK)
		{
			APP_VOIDStart();
		}
		else
		{
			/*Do Nothing*/
		}
	}
	return 0;
}
