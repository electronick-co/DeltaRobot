/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include "./include/OctopusBot.h"
#include <asf.h>

ISR(USARTD0_RXC_vect)
{
	int data = usart_getchar(BLUETOOTH);
	switch(data)
	{
		case '1':
			ioport_toggle_pin_level(LED1);
		break;
		case '2':
			ioport_toggle_pin_level(LED2);
		break;
		case '3':
			ioport_toggle_pin_level(LED3);
		break;
		case '4':
			ioport_toggle_pin_level(LED4);
		break;
		case '5':
			ioport_toggle_pin_level(LED5);
		break;
		case '6':
			ioport_toggle_pin_level(LED6);
		break;
	}
}

#define INIT_MAX 100
void initial_animation(void)
{
	volatile int i;
	for(i = 50;i<INIT_MAX;i+=15)
	{
		ioport_set_pin_level(LED1,1);
		delay_ms(i);
		ioport_set_pin_level(LED2,1);
		delay_ms(i);
		ioport_set_pin_level(LED3,1);
		delay_ms(i);
		ioport_set_pin_level(LED4,1);
		delay_ms(i);
		ioport_set_pin_level(LED5,1);
		delay_ms(i);
		ioport_set_pin_level(LED6,1);
		delay_ms(i);
		
		ioport_set_pin_level(LED1,0);
		delay_ms(i);
		ioport_set_pin_level(LED2,0);
		delay_ms(i);
		ioport_set_pin_level(LED3,0);
		delay_ms(i);
		ioport_set_pin_level(LED4,0);
		delay_ms(i);
		ioport_set_pin_level(LED5,0);
		delay_ms(i);
		ioport_set_pin_level(LED6,0);
		delay_ms(i);
	}
}

int main (void)
{
	init_octopus();
	// Insert application code here, after the board has been initialized.
	initial_animation();
	
	
	
	for (;;)
	{
		if(ioport_get_pin_level(SW1) == 0)
		{
			ioport_set_pin_level(LED1,1);
			delay_ms(200);
			ioport_set_pin_level(LED2,1);
			delay_ms(200);
			ioport_set_pin_level(LED3,1);
			delay_ms(200);
			ioport_set_pin_level(LED4,1);
			delay_ms(200);
			ioport_set_pin_level(LED5,1);
			delay_ms(200);
			ioport_set_pin_level(LED6,1);
			delay_ms(200);
		}
		if(ioport_get_pin_level(SW2) == 0)
		{
			ioport_set_pin_level(LED1,0);
			delay_ms(200);
			ioport_set_pin_level(LED2,0);
			delay_ms(200);
			ioport_set_pin_level(LED3,0);
			delay_ms(200);
			ioport_set_pin_level(LED4,0);
			delay_ms(200);
			ioport_set_pin_level(LED5,0);
			delay_ms(200);
			ioport_set_pin_level(LED6,0);
			delay_ms(200);
		}			
	}
}
