#include "pwm.h"

uint8_t PWM_Counter=0; 	//schetchik kotoryy bydet sravnivat
uint8_t PWM_A=1, PWM_B=20;	//A - opredelyaet period, B - skvazhnost period v ms

uint8_t PWM_LED_On_Counter=0; 	//scheetik plavnogo vkl LED
uint8_t PWM_LED_Off_Counter=0; //schetchik planogo vykl LED

uint8_t PWM_LED_On_flag=0;	 //flag o tom chto mozhno vkluchat svetodiod, kogda Led vkl flag sbrasyvaetsya
uint8_t PWM_LED_Off_flag=0;	//flag o tom chto mozhno vykluchit svetodiod, kogda Led vykl flag sbrasyvaetsya 

//--------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------

void Systick_PWM(void) //podcluchaem cherez systick
{
	if (PWM_Counter >= PWM_B) //zachita ot ne izvestnyh oshibok
	{
		PWM_Counter = 0; //chetchik sbroshen vkl LED
		GREEN_LD6_ON ();
	}
	
	else if (PWM_Counter == PWM_A)
	{
		PWM_Counter++;
		GREEN_LD6_OFF(); //kak tolko pwm dostygayet A chetchick zapyskaetsya
	}
	
	else 
	{
	PWM_Counter++;
	}
}

//----------------------------------------------------------------------------
// Plavnoe vkluchenie i vyklucheniye svetodiodov 
//----------------------------------------------------------------------------

void PWM_LED_On(void)
{
	if (PWM_LED_On_flag == 1)
	{
		
	
			if (PWM_LED_On_Counter >= 20)
			{
				PWM_LED_On_Counter = 0;
				if (PWM_A < PWM_B)
				{
					PWM_A++;
				}
				
				else 
					{
					PWM_LED_On_flag = 0;
					}
			}
			
			else 
			{
				PWM_LED_On_Counter++;
			}
	}
}

//-----------------------------------------------------------------------------------
//Plavnoye vykluchenie LED
//-----------------------------------------------------------------------------------

void PWM_LED_Off(void)
{
	if (PWM_LED_Off_flag == 1)
	{
		if (PWM_LED_Off_Counter >=20)
		{
			PWM_LED_Off_Counter = 0;
			if (PWM_A > 0)
			{
				PWM_A--;
			}
			else
			{
				PWM_LED_Off_flag = 0;
			}
		}
			else
			{
				PWM_LED_Off_Counter++;
			}
	}
	
}

//-------------------------------------------------------------------------------------
//vkluchenie flagov
//--------------------------------------------------------------------------------------
void LED_On(void)
{
	PWM_LED_On_flag = 1;
}

void LED_Off(void)
{
	PWM_LED_Off_flag = 1;
}
