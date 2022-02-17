/*
 * adc.h
 *
 *  Created on: Jan 9, 2020
 *      Author: manar
 */

#ifndef ADC_H_
#define ADC_H_

/*--------------------------------------------INCLUDES-----------------------------------------------------*/

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

/*-------------------------------------------FUNCTION DECLARATIONS------------------------------------------*/


void ADC_init(void);

uint16 ADC_readChannel(uint8 channel_num);


#endif /* ADC_H_ */
