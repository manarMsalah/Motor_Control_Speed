/*
 * control_motor_speed.c
 *
 *  Created on: Jan 9, 2020
 *      Author: manar
 */


#include "lcd.h"
#include "adc.h"
#include "pwm_timer0.h"

/* global variable to store flag value whenever interrupt accur. */
volatile uint8 Interrupt_flag=0;

ISR(INT1_vect)
{
	Interrupt_flag=1;
}

void INT1_Init(void)
{
	/ *configure pins 3 of PORTD as output pin. */
	CLEAR_BIT(DDRD,PD3);

	/* configure INT1 registers. */
	SET_BIT(GICR,INT1);
	SET_BIT(MCUCR,ISC11);
	SET_BIT(MCUCR,ISC10);
}


int main()
{
/* local varible to store adc value. */
	uint16 res_value;

/* set global interrupt. */
    SET_BIT(SREG,7);

/* configure pins 0 and 1 of PORTB as output pins. */
	SET_BIT(DDRB,PB0);
	SET_BIT(DDRB,PB1);



	INT1_Init();
	LCD_init();
	ADC_init();
	LCD_clearScreen();
	LCD_displayString("ADC Value = ");

/* rotate the motor. */
	SET_BIT(PORTB,PB0);
	CLEAR_BIT(PORTB,PB1);

	  while(1)
	    {

			LCD_goToRowColumn(0,12);
			/* read adc value from channel 0 and put it in res_value. */
			res_value = ADC_readChannel(0); 
			/* send the adc value to lcd. */
			LCD_intgerToString(res_value);
			/* send the adc value to timer0 as compare to control the motor speed. */
			PWM_Timer0_Init(res_value/4);

			if(Interrupt_flag==1)
			{
				/*reverse the direction of the motor*/
				TOGGLE_BIT(PORTB,PB0);
				TOGGLE_BIT(PORTB,PB1);
				Interrupt_flag=0;

			}


	    }


}
