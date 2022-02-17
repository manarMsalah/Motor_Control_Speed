/*
 * adc.c
 *
 *  Created on: Jan 9, 2020
 *      Author: manar
 */

/*--------------------------------------------INCLUDES-----------------------------------------------------*/

#include "adc.h"


/*----------------------------------------FUNCTION DIFINATIONS---------------------------------------------*/

void ADC_init(void)
{
	ADMUX = 0;
	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX=(ADMUX & 0xE0) | (channel_num & 0x07);/*choose channel from 0 to 7*/
	SET_BIT(ADCSRA,ADSC); /*start conversation*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /*polling until ADIF=1*/
	SET_BIT(ADCSRA,ADIF); /*clear ADIF by 1*/
	return ADC; /*ADC VALUE*/
}
