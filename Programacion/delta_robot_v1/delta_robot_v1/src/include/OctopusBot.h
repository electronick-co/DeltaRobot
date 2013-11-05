/*
 * OctopusBot.h
 *
 * Created: 3/30/2013 5:49:54 PM
 *  Author: Nick
 */ 


#ifndef OCTOPUSBOT_H_
#define OCTOPUSBOT_H_

/* For default Dir A of every motor is set. If the motor supose to go forward but go backwars, 
the corresponding motor_dir should be change to dir B */ 
#define MOTOR_1_DIR_A
//#define MOTOR_1_DIR_B
//#define MOTOR_2_DIR_A
#define MOTOR_2_DIR_B
//#define MOTOR_3_DIR_A
#define MOTOR_3_DIR_B
//#define MOTOR_4_DIR_A
#define MOTOR_4_DIR_B

#ifdef MOTOR_1_DIR_A 
	//#define MOTOR_1_PWM_INIT pwm_init(&pwm_mot1, PWM_TCE0, PWM_CH_C, MOTOR_FREQUENCY);
	#define MOTOR1_A IOPORT_CREATE_PIN(PORTE, 2)
	#define MOTOR1_B IOPORT_CREATE_PIN(PORTE, 3)
#endif /*MOTOR_1_DIR_A*/ 

#ifdef MOTOR_1_DIR_B
	#define MOTOR1_B IOPORT_CREATE_PIN(PORTE, 2)
	#define MOTOR1_A IOPORT_CREATE_PIN(PORTE, 3)
#endif /*MOTOR_1_DIR_B*/

#ifdef MOTOR_2_DIR_A
	#define MOTOR2_A IOPORT_CREATE_PIN(PORTE, 1)
	#define MOTOR2_B IOPORT_CREATE_PIN(PORTE, 0)
#endif /*MOTOR_2_DIR_A*/

#ifdef MOTOR_2_DIR_B
	#define MOTOR2_B IOPORT_CREATE_PIN(PORTE, 1)
	#define MOTOR2_A IOPORT_CREATE_PIN(PORTE, 0)
#endif /*MOTOR_2_DIR_B*/

#ifdef MOTOR_3_DIR_A
	#define MOTOR3_A IOPORT_CREATE_PIN(PORTA, 6)
	#define MOTOR3_B IOPORT_CREATE_PIN(PORTA, 7)
#endif /*MOTOR_3_DIR_A*/

#ifdef MOTOR_3_DIR_B
	#define MOTOR3_B IOPORT_CREATE_PIN(PORTA, 6)
	#define MOTOR3_A IOPORT_CREATE_PIN(PORTA, 7)
#endif /*MOTOR_3_DIR_B*/

#ifdef MOTOR_4_DIR_A
	#define MOTOR4_A IOPORT_CREATE_PIN(PORTA, 5)
	#define MOTOR4_B IOPORT_CREATE_PIN(PORTA, 4)
#endif /*MOTOR_4_DIR_A*/

#ifdef MOTOR_4_DIR_B
	#define MOTOR4_B IOPORT_CREATE_PIN(PORTA, 5)
	#define MOTOR4_A IOPORT_CREATE_PIN(PORTA, 4)
#endif /*MOTOR_4_DIR_B*/

#define ON 1
#define OFF 0

#define FORWARD 1
#define BACKWARD 2

#define MOTOR_FREQUENCY 1000

#define SW1 IOPORT_CREATE_PIN(PORTC, 2)
#define SW2 IOPORT_CREATE_PIN(PORTC, 3)

#define LED1 IOPORT_CREATE_PIN(PORTC, 4)
#define LED2 IOPORT_CREATE_PIN(PORTC, 5)
#define LED6 IOPORT_CREATE_PIN(PORTC, 6)
#define LED3 IOPORT_CREATE_PIN(PORTC, 7)
#define LED4 IOPORT_CREATE_PIN(PORTR, 1)
#define LED5 IOPORT_CREATE_PIN(PORTR, 0)

#define IO_1 IOPORT_CREATE_PIN(PORTA, 0)
#define IO_2 IOPORT_CREATE_PIN(PORTA, 1)
#define IO_3 IOPORT_CREATE_PIN(PORTA, 2)
#define IO_4 IOPORT_CREATE_PIN(PORTA, 3)
#define IO_5 IOPORT_CREATE_PIN(PORTB, 0)
#define IO_6 IOPORT_CREATE_PIN(PORTB, 1)
#define IO_7 IOPORT_CREATE_PIN(PORTB, 2)
#define IO_8 IOPORT_CREATE_PIN(PORTB, 3)

#define PWM0 IOPORT_CREATE_PIN(PORTD, 0)
#define PWM1 IOPORT_CREATE_PIN(PORTD, 1)
#define PWM2 IOPORT_CREATE_PIN(PORTD, 4)
#define PWM3 IOPORT_CREATE_PIN(PORTD, 5)

// Definifiones antiguas. Con la nueva configuración se puede cambiar la direccion de los motores
// #define MOTOR1_A IOPORT_CREATE_PIN(PORTE, 2)
// #define MOTOR1_B IOPORT_CREATE_PIN(PORTE, 3)
// #define MOTOR2_A IOPORT_CREATE_PIN(PORTE, 1)
// #define MOTOR2_B IOPORT_CREATE_PIN(PORTE, 0)
// #define MOTOR3_A IOPORT_CREATE_PIN(PORTA, 6)
// #define MOTOR3_B IOPORT_CREATE_PIN(PORTA, 7)
// #define MOTOR4_A IOPORT_CREATE_PIN(PORTA, 5)
// #define MOTOR4_B IOPORT_CREATE_PIN(PORTA, 4)

#define BT_RX IOPORT_CREATE_PIN(PORTD, 2)
#define BT_TX IOPORT_CREATE_PIN(PORTD, 3)

#define BLUETOOTH &USARTD0

void blink(void);
void forward(void);

void forward_1(void);
void forward_2(void);
void forward_3(void);
void forward_4(void);
void forward_5(void);

void backward_1(void);
void backward_2(void);
void backward_3(void);
void backward_4(void);
void backward_5(void);

void turn_right_1(void);
void turn_right_2(void);
void turn_right_3(void);
void turn_right_4(void);
void turn_right_5(void);

void turn_left_1(void);
void turn_left_2(void);
void turn_left_3(void);
void turn_left_4(void);
void turn_left_5(void);

void turn_left(void);
void turn_right(void);
void backward(void);
void move_motor_1(int dir, int vel);
void init_motors(void);

void init_servo(int servo_num);
void update_servo(int servo_num,double duty);

void init_bluetooth(void);
void init_virtual_comm(void);
void init_bluetooth_interrupt(void);
void init_octopus(void);
void stop(void);

#endif /* OCTOPUSBOT_H_ */