/*
 * OctopusBot.c
 *
 * Created: 3/30/2013 6:38:02 PM
 *  Author: Nick
 */ 

#include "./../include/OctopusBot.h"
#include <asf.h>

const struct pwm_config pwm_mot1;
const struct pwm_config pwm_mot2;
const struct pwm_config pwm_mot3;
const struct pwm_config pwm_mot4;


void init_octopus(void)
{
	sysclk_init();
	
	ioport_init();
	
	ioport_set_pin_dir(LED1, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(LED2, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(LED3, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(LED4, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(LED5, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(LED6, IOPORT_DIR_OUTPUT);
	
	ioport_set_pin_dir(SW1, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(SW2, IOPORT_DIR_INPUT);
	
// 	ioport_set_pin_dir(MOTOR1_A, IOPORT_DIR_OUTPUT);
// 	ioport_set_pin_dir(MOTOR1_B, IOPORT_DIR_OUTPUT);
// 	ioport_set_pin_dir(MOTOR2_A, IOPORT_DIR_OUTPUT);
// 	ioport_set_pin_dir(MOTOR2_B, IOPORT_DIR_OUTPUT);
// 	ioport_set_pin_dir(MOTOR3_A, IOPORT_DIR_OUTPUT);
// 	ioport_set_pin_dir(MOTOR3_B, IOPORT_DIR_OUTPUT);
// 	ioport_set_pin_dir(MOTOR4_A, IOPORT_DIR_OUTPUT);
// 	ioport_set_pin_dir(MOTOR4_B, IOPORT_DIR_OUTPUT);
	
	ioport_set_pin_dir(PWM0,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(PWM1,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(PWM2,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(PWM3,IOPORT_DIR_OUTPUT);
	
	
	//init_motors();
	init_servo();
	//init_bluetooth();
	//init_bluetooth_interrupt();
	init_virtual_comm();
}

void init_bluetooth(void)
{
	ioport_set_pin_dir(BT_TX,IOPORT_DIR_OUTPUT);
	
	static usart_serial_options_t usart_options = {
		.baudrate = 19200,
		.charlength = USART_CHSIZE_8BIT_gc,
		.paritytype = USART_PMODE_DISABLED_gc,
		.stopbits = false
	};
	usart_serial_init(BLUETOOTH, &usart_options);
}

void init_bluetooth_interrupt(void)
{
	 
	 pmic_init();
	 pmic_set_scheduling(PMIC_SCH_ROUND_ROBIN);
	 USARTD0.CTRLA = USART_RXCINTLVL_HI_gc;
	 cpu_irq_enable();
}

const struct pwm_config pwm_servo0;
const struct pwm_config pwm_servo1;
const struct pwm_config pwm_servo2;
const struct pwm_config pwm_servo3;

void init_servo(int servo_num)
{
	switch(servo_num)
	{
		case 0:
			pwm_init(&pwm_servo0, PWM_TCD0, PWM_CH_A, 50);
			pwm_start(&pwm_servo0, 7.5);
		break;
		case 1:
			pwm_init(&pwm_servo1, PWM_TCD0, PWM_CH_B, 50);
			pwm_start(&pwm_servo1, 7.5);
		break;
		case 2:
			pwm_init(&pwm_servo2, PWM_TCD1, PWM_CH_A, 50);
			pwm_start(&pwm_servo2, 7.5);
		break;
		case 3:
			pwm_init(&pwm_servo3, PWM_TCD1, PWM_CH_A, 50);
			pwm_start(&pwm_servo3, 7.5);
		break;
	}

}

void update_servo(int servo_num,double duty)
{
	switch(servo_num)
	{
		case 0:
			tc_write_cc_buffer(pwm_servo0.tc, pwm_servo0.channel,
			(uint16_t)(((double)pwm_servo0.period *
			(double)duty) / 100));
		break;
		case 1:
			tc_write_cc_buffer(pwm_servo1.tc, pwm_servo1.channel,
			(uint16_t)(((double)pwm_servo1.period *
			(double)duty) / 100));
		break;
		case 2:
			tc_write_cc_buffer(pwm_servo2.tc, pwm_servo2.channel,
			(uint16_t)(((double)pwm_servo2.period *
			(double)duty) / 100));
		break;
		case 3:
			tc_write_cc_buffer(pwm_servo3.tc, pwm_servo3.channel,
			(uint16_t)(((double)pwm_servo3.period *
			(double)duty) / 100));
		break;
	}
	//pwm_start(&pwm_servo0, duty);
	
}

void init_motors(void)
{
	 
}

void init_virtual_comm(void)
{
	irq_initialize_vectors();
	cpu_irq_enable();
	udc_start();
	udc_attach();
}	

void move_motor_1(int dir, int vel)
{
	if(dir == FORWARD)
	{
		ioport_set_pin_level(MOTOR1_B,OFF);
		pwm_start(&pwm_mot1, vel);
	}
	else
	{
		ioport_set_pin_level(MOTOR1_B,ON);
		pwm_start(&pwm_mot1, 100-vel);
	}
	
}

void blink(void){
	ioport_set_pin_level(LED1,ON);
	ioport_set_pin_level(LED2,ON);
	delay_s(1);
	ioport_set_pin_level(LED1,OFF);
	ioport_set_pin_level(LED2,OFF);
	delay_s(1);
}

void forward(void)
{
	ioport_set_pin_level(MOTOR1_A,ON);
 	ioport_set_pin_level(MOTOR2_A,ON);
	ioport_set_pin_level(MOTOR3_A,ON);
 	ioport_set_pin_level(MOTOR4_A,ON);
	
	ioport_set_pin_level(MOTOR1_B,OFF);
 	ioport_set_pin_level(MOTOR2_B,OFF);
	ioport_set_pin_level(MOTOR3_B,OFF);
 	ioport_set_pin_level(MOTOR4_B,OFF);
}

#define DELAYGO_1 2
#define DELAYSTOP_1 13 

#define DELAYGO_2 5
#define DELAYSTOP_2 10

#define DELAYGO_3 7
#define DELAYSTOP_3 7

#define DELAYGO_4 10
#define DELAYSTOP_4 5

#define DELAYGO_5 14
#define DELAYSTOP_5 1

void forward_1(void)
{
	forward();
	delay_ms(DELAYGO_1);
	stop();
	delay_ms(DELAYSTOP_1);
	forward();
}

void forward_2(void)
{
	forward();
	delay_ms(DELAYGO_2);
	stop();
	delay_ms(DELAYSTOP_2);
	forward();
}

void forward_3(void)
{
	forward();
	delay_ms(DELAYGO_3);
	stop();
	delay_ms(DELAYSTOP_3);
	forward();
}
void forward_4(void)
{
	forward();
	delay_ms(DELAYGO_4);
	stop();
	delay_ms(DELAYSTOP_4);
	forward();
}
void forward_5(void)
{
	forward();
	delay_ms(DELAYGO_5);
	stop();
	delay_ms(DELAYSTOP_5);
	forward();
}

void backward_1(void)
{
	backward();
	delay_ms(DELAYGO_1);
	stop();
	delay_ms(DELAYSTOP_1);
	backward();
}

void backward_2(void)
{
	backward();
	delay_ms(DELAYGO_2);
	stop();
	delay_ms(DELAYSTOP_2);
	backward();
}

void backward_3(void)
{
	backward();
	delay_ms(DELAYGO_3);
	stop();
	delay_ms(DELAYSTOP_3);
	backward();
}
void backward_4(void)
{
	backward();
	delay_ms(DELAYGO_4);
	stop();
	delay_ms(DELAYSTOP_4);
	backward();
}
void backward_5(void)
{
	backward();
	delay_ms(DELAYGO_5);
	stop();
	delay_ms(DELAYSTOP_5);
	backward();
}

void turn_left_1(void)
{
	turn_left();
	delay_ms(DELAYGO_1);
	stop();
	delay_ms(DELAYSTOP_1);
	turn_left();
}

void turn_left_2(void)
{
	turn_left();
	delay_ms(DELAYGO_2);
	stop();
	delay_ms(DELAYSTOP_2);
	turn_left();
}

void turn_left_3(void)
{
	turn_left();
	delay_ms(DELAYGO_3);
	stop();
	delay_ms(DELAYSTOP_3);
	turn_left();
}

void turn_left_4(void)
{
	turn_left();
	delay_ms(DELAYGO_4);
	stop();
	delay_ms(DELAYSTOP_4);
	turn_left();
}

void turn_left_5(void)
{
	turn_left();
	delay_ms(DELAYGO_5);
	stop();
	delay_ms(DELAYSTOP_5);
	turn_left();
}

void turn_right_1(void)
{
	turn_right();
	delay_ms(DELAYGO_1);
	stop();
	delay_ms(DELAYSTOP_1);
	turn_right();
}

void turn_right_2(void)
{
	turn_right();
	delay_ms(DELAYGO_2);
	stop();
	delay_ms(DELAYSTOP_2);
	turn_right();
}

void turn_right_3(void)
{
	turn_right();
	delay_ms(DELAYGO_3);
	stop();
	delay_ms(DELAYSTOP_3);
	turn_right();
}

void turn_right_4(void)
{
	turn_right();
	delay_ms(DELAYGO_4);
	stop();
	delay_ms(DELAYSTOP_4);
	turn_right();
}

void turn_right_5(void)
{
	turn_right();
	delay_ms(DELAYGO_5);
	stop();
	delay_ms(DELAYSTOP_5);
	turn_right();
}


void backward(void)
{
	ioport_set_pin_level(MOTOR1_A,OFF);
	ioport_set_pin_level(MOTOR2_A,OFF);
	ioport_set_pin_level(MOTOR3_A,OFF);
	ioport_set_pin_level(MOTOR4_A,OFF);
	
	ioport_set_pin_level(MOTOR1_B,ON);
	ioport_set_pin_level(MOTOR2_B,ON);
	ioport_set_pin_level(MOTOR3_B,ON);
	ioport_set_pin_level(MOTOR4_B,ON);
}



void turn_left(void)
{
	ioport_set_pin_level(MOTOR1_A,OFF);
	ioport_set_pin_level(MOTOR2_A,ON);
	ioport_set_pin_level(MOTOR3_A,OFF);
	ioport_set_pin_level(MOTOR4_A,ON);
	
	ioport_set_pin_level(MOTOR1_B,ON);
	ioport_set_pin_level(MOTOR2_B,OFF);
	ioport_set_pin_level(MOTOR3_B,ON);
	ioport_set_pin_level(MOTOR4_B,OFF);
}
void turn_right(void)
{
	ioport_set_pin_level(MOTOR1_A,ON);
	ioport_set_pin_level(MOTOR2_A,OFF);
	ioport_set_pin_level(MOTOR3_A,ON);
	ioport_set_pin_level(MOTOR4_A,OFF);
	
	ioport_set_pin_level(MOTOR1_B,OFF);
	ioport_set_pin_level(MOTOR2_B,ON);
	ioport_set_pin_level(MOTOR3_B,OFF);
	ioport_set_pin_level(MOTOR4_B,ON);
}

void stop(void)
{
	ioport_set_pin_level(MOTOR1_A,OFF);
	ioport_set_pin_level(MOTOR2_A,OFF);
	ioport_set_pin_level(MOTOR3_A,OFF);
	ioport_set_pin_level(MOTOR4_A,OFF);
	
	ioport_set_pin_level(MOTOR1_B,OFF);
	ioport_set_pin_level(MOTOR2_B,OFF);
	ioport_set_pin_level(MOTOR3_B,OFF);
	ioport_set_pin_level(MOTOR4_B,OFF);
}
