#include "main.h"

uint16_t delay_count=0;
uint8_t Mode=0;
uint16_t Mode_count=0;
uint8_t Mode_new=0;

uint8_t Button_count=0; // ubirAYEM DREBEZG
uint8_t Button_state=0;

//------------------------------------------------------------------------------------------------
//Functsiu budet vyzyvat kazduy 1ms
//------------------------------------------------------------------------------------------------
void SysTick_Handler(void)
{
						if (delay_count > 0)
						{
							delay_count--;
						}
						//--------------------
						if (Mode_count > 0)
						{
							Mode_count--;
						}
						
						//--------------------------
								Systick_PWM();
								PWM_LED_On();
								PWM_LED_Off();
}

//------------------------------------------------------------------------------------------------
//gdem poka delay count ne stanet raven nulyu
//------------------------------------------------------------------------------------------------
void delay_ms(uint16_t delay_temp)
{
	delay_count = delay_temp;
	while(delay_count) //gdem poka delay count ne stanet raven nulyu
	{
		
	}
}

//------------------------------------------------------------------------------------------------
//Podklyutchaem peremennuy i initsializiruyem systemnyi timer //1ms
//------------------------------------------------------------------------------------------------
int main (void)
	{
		
		LEDs_ini();
		//Button_ini();
		SysTick_Config(SystemCoreClock/1000); //initsializiruyem systemnyi timer //1ms	
		//Mode_count = DELAY;
		//Mode=MODE_GREEN_LD6;
		//-------------------------------------------------------------------------------
		//vkluchenie i vykluchenie zelenogo dioda
		//---------------------------------------------------------------------------------
		while(1)
			{ 
				LED_On();
				delay_ms(1000);
				LED_Off();
				delay_ms(1000);
			}
	}
