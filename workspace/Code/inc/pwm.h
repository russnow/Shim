#ifndef PWM_H
#define PWM_H

#include "stm32f30x.h"
#include "main.h"

void Systick_PWM(void);
void PWM_LED_Off(void);
void PWM_LED_On(void);

void LED_On(void);
void LED_Off(void);
#endif
