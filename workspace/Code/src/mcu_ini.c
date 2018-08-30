#include "mcu_ini.h"

//------------------------------------------------------------------------------------------------
//Zadayem peremennuy functsiu
//------------------------------------------------------------------------------------------------	
void LEDs_ini(void)
{
	GPIO_InitTypeDef GPIO_Init_LED;
		
		RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE); //vkluchayet tactirovanie na portu B 
		
		
		
		GPIO_Init_LED.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_12 | GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_9 | GPIO_Pin_8;
		GPIO_Init_LED.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_Init_LED.GPIO_Speed =  GPIO_Speed_2MHz;
		GPIO_Init_LED.GPIO_OType = GPIO_OType_PP;
		GPIO_Init_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOB , &GPIO_Init_LED);
}
 
//---------------------------------------------------------------------------------------------------
//inithializiruyem cnopku podkluchayem registry
//---------------------------------------------------------------------------------------------------
void Button_ini (void)
{
	GPIO_InitTypeDef GPIO_Init_Button;
	
	RCC_AHBPeriphClockCmd (RCC_AHBPeriph_GPIOA, ENABLE);
	
	GPIO_Init_Button.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init_Button.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init_Button.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_Button.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Button.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA, &GPIO_Init_Button);
}
	