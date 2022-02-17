/*
 * pwm.h
 *
 *  Created on: Jan 9, 2020
 *      Author: manar
 */

#ifndef PWM_TIMER0_H_
#define PWM_TIMER0_H_

/*--------------------------------------------INCLUDES-----------------------------------------------------*/

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

/*-------------------------------------------FUNCTION DECLARATIONS------------------------------------------*/

void PWM_Timer0_Init(uint8 set_duty_cycle);

#endif /* PWM_TIMER0_H_ */
