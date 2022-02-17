/*
 * pwm.c
 *
 *  Created on: Jan 9, 2020
 *      Author: manar
 */

/*--------------------------------------------INCLUDES-----------------------------------------------------*/

#include "pwm_timer0.h"

/*----------------------------------------FUNCTION DIFINATIONS---------------------------------------------*/

void PWM_Timer0_Init(unsigned char set_duty_cycle)
{
/* initial timer value. */
	TCNT0 = 0; 

	OCR0  = set_duty_cycle;
/* set OC0 as output pin. */
	SET_BIT(DDRB,PB3); 

/* Configure timer control register. */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
