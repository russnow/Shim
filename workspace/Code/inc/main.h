#ifndef MAIN_H
#define MAIN_H

#include "mcu_ini.h"


#define GREEN_LD6_ON()			GPIO_SetBits(GPIOE, GPIO_Pin_15)
#define GREEN_LD6_OFF()			GPIO_ResetBits (GPIOE, GPIO_Pin_15)

#define ORANGE_LD8_ON()			GPIO_SetBits(GPIOE, GPIO_Pin_14)
#define ORANGE_LD8_OFF()		GPIO_ResetBits (GPIOE, GPIO_Pin_14)

#define RED_LD10_ON()				GPIO_SetBits(GPIOE, GPIO_Pin_13)
#define RED_LD10_OFF()			GPIO_ResetBits(GPIOE, GPIO_Pin_13)

#define BLUE_LD9_ON()				GPIO_SetBits(GPIOE, GPIO_Pin_12)
#define BLUE_LD9_OFF()			GPIO_ResetBits(GPIOE, GPIO_Pin_12)

#define GREEN_LD7_ON()			GPIO_SetBits(GPIOE, GPIO_Pin_11)
#define GREEN_LD7_OFF()			GPIO_ResetBits(GPIOE, GPIO_Pin_11)

#define ORANGE_LD5_ON()			GPIO_SetBits(GPIOE, GPIO_Pin_10)
#define ORANGE_LD5_OFF()		GPIO_ResetBits(GPIOE, GPIO_Pin_10)

#define RED_LD3_ON()				GPIO_SetBits(GPIOE, GPIO_Pin_9)
#define RED_LD3_OFF()				GPIO_ResetBits(GPIOE, GPIO_Pin_9)

#define BLUE_LD4_ON()				GPIO_SetBits(GPIOE, GPIO_Pin_8)
#define BLUE_LD4_OFF()			GPIO_ResetBits(GPIOE, GPIO_Pin_8)

#define DELAY						100 

//-------------------------------------------------------------
// Propisyvayem rezhimy miganiya diodov
//-------------------------------------------------------------

#define MODE_GREEN_LD6	0
#define MODE_ORANGE_LD8	1
#define MODE_RED_LD10		2
#define MODE_BLUE_LD9		3
#define MODE_GREEN_LD7  4
#define MODE_ORANGE_LD5 5
#define MODE_RED_LD3		6
#define MODE_BLUE_LD4		7

//-------------------------------------------------------------
//Zadayom funkthiyu chteniya
//-------------------------------------------------------------

#define BUTTON_READ()			GPIO_ReadInputDataBit (GPIOA, GPIO_Pin_0)

#endif

