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
						//----------------------
						//Nazhatie i othatie cnopki
						//----------------------
					if (BUTTON_READ()==1)
						{
												if (Button_count <5)
												{
													Button_count++;
												}
												
													else
														if (Button_state ==0)
													{
														Button_state=1;
														//GPIO_ToggleBits(GPIOB, GPIO_Pin_6);//vkluchaem svetodiod
														Mode=MODE_GREEN_LD6;
														Mode_new =1;
														ORANGE_LD8_OFF();
														RED_LD10_OFF();
														BLUE_LD9_OFF();
														GREEN_LD7_OFF();
														ORANGE_LD5_OFF();
														RED_LD3_OFF();
														BLUE_LD4_OFF();
														
													}
						}
						//---------------------------
								else
								{
										if (Button_count>0)
										{
											Button_count--;
										}
									
									else
										{
											Button_state=0;
										}
								}
						//--------------------------
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
		Button_ini();
		SysTick_Config(SystemCoreClock/1000); //initsializiruyem systemnyi timer //1ms	
		Mode_count = DELAY;
		Mode=MODE_GREEN_LD6;
		//-------------------------------------------------------------------------------
		//vkluchenie i vykluchenie zelenogo dioda
		//---------------------------------------------------------------------------------
		while(1)
			{

				if (Mode == MODE_GREEN_LD6)
							{
								if (Mode_new ==1)
									{
										Mode_count = DELAY;
										Mode_new = 0;
										GREEN_LD6_ON();
									}

								if (Mode_count == 0)
									{
						
										GREEN_LD6_OFF();
										if (Button_state ==0)
										{
										Mode = MODE_ORANGE_LD8; // vkl rezhima 
										}
										Mode_new =1;
									}
							}
//-----------------------------------------------------------
//	vkluchenie i vykluchenie golubogo dioda						
//-------------------------------------------------------------							
				else if (Mode == MODE_ORANGE_LD8)
				{
					if (Mode_new ==1)
					{
						Mode_count = DELAY;
						Mode_new = 0;
						ORANGE_LD8_ON();
					}
					
					if (Mode_count == 0)
					{
						ORANGE_LD8_OFF();
						Mode = MODE_RED_LD10 ;
						Mode_new = 1;
					}
				}
//------------------------------------------------------------------------
//vkluchenie i vykluchenie nizhnego zelenogo dioda
//------------------------------------------------------------------------
								else if (Mode == MODE_RED_LD10)
				{
					if (Mode_new ==1)
					{
						Mode_count = DELAY;
						Mode_new = 0;
						RED_LD10_ON();
					}
					
					if (Mode_count == 0)
					{
						RED_LD10_OFF();
						Mode = MODE_BLUE_LD9 ;
						Mode_new = 1;
					}
				}
//------------------------------------------------------------------------
//vkluchenie i vykluchenie nizhnego zelenogo dioda
//------------------------------------------------------------------------
				else if (Mode == MODE_BLUE_LD9)
				{
					if (Mode_new ==1)
					{
						Mode_count = DELAY;
						Mode_new=0;
						BLUE_LD9_ON();
					}
					
					if (Mode_count == 0)
					{
						BLUE_LD9_OFF();
						Mode = MODE_GREEN_LD7;
						Mode_new = 1;
					}
				}
				
//--------------------------------------------------------------------------------
//vkluchenie i vykluchenie verkhnego dioda
//--------------------------------------------------------------------------------
				else if (Mode == MODE_GREEN_LD7)
				{
					if (Mode_new ==1)
					{
						Mode_count = DELAY;
						Mode_new = 0;
						GREEN_LD7_ON();
					}
					
					if (Mode_count == 0)
					{	
						GREEN_LD7_OFF();
						Mode = MODE_ORANGE_LD5;
						Mode_new = 1;
					}
				}
	//--------------------------------------------------------------------------------
//vkluchenie i vykluchenie verkhnego dioda
//--------------------------------------------------------------------------------			
				else if (Mode == MODE_ORANGE_LD5)
				{
					if (Mode_new == 1)
					{
						Mode_count=DELAY;
						Mode_new=0;
						ORANGE_LD5_ON();
					}
					
					if (Mode_count ==0)
					{
						ORANGE_LD5_OFF();
						Mode = MODE_RED_LD3;
						Mode_new =1;
					}
				}
//--------------------------------------------------------------------------------
//vkluchenie i vykluchenie verkhnego dioda
//--------------------------------------------------------------------------------				
				else if (Mode == MODE_RED_LD3)
				{
					if (Mode_new ==1)
					{
						Mode_count =DELAY;
						Mode_new=0;
						RED_LD3_ON();
					}
					
					if (Mode_count == 0)
					{
						RED_LD3_OFF();
						Mode = MODE_BLUE_LD4;
						Mode_new=1;
					}
				}
	//--------------------------------------------------------------------------------
//vkluchenie i vykluchenie verkhnego dioda
//--------------------------------------------------------------------------------			
				else if (Mode == MODE_BLUE_LD4)
				{
					if (Mode_new==1)
					{
						Mode_count=DELAY;
						Mode_new=0;
						BLUE_LD4_ON();
					}
					
					if (Mode_count==0)
					{
						BLUE_LD4_OFF();
						Mode_new =1;
						Mode= MODE_GREEN_LD6;
					}
				}
	//--------------------------------------------------------------------------------
//vkluchenie i vykluchenie verkhnego dioda
//--------------------------------------------------------------------------------			
			}
	}
