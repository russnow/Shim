#include "pwm.h"

uint8_t PWM_Counter=0;
uint8_t PWM_A=1, PWM_B=20;

uint8_t PWM_LED_On_Counter=0;
uint8_t PWM_LED_Off_Counter=0;

uint8_t PWM_LED_On_flag=0;
uint8_t PWM_LED_Off_flag=0;


void Systick_PWM(void)
{
	if (PWM_Counter >= PWM_B)
	{
		PWM_Counter = 0;
		GREEN_LD6_ON ();
	}
	
	else if (PWM_Counter == PWM_A)
	{
		PWM_Counter++;
		GREEN_LD6_OFF();
	}
	
	else 
	{
	PWM_Counter++;
	}
}

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

void LED_On(void)
{
	PWM_LED_On_flag = 1;
}

void LED_Off(void)
{
	PWM_LED_Off_flag = 1;
}
