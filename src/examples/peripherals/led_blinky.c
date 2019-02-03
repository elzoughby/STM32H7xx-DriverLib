/*============================================================================
 Name        : led_blinky.c
 Author      : Ahmed Elzoughby
 Version     : 1.0.0
 Copyright   : Copyright (c) 2018 Ahmed Elzoughby
 Description : A demonstration of the independent startup code for STM32H7
 Note        : Tested on Nucleo-H743ZI development board
=============================================================================*/



/*======================= Includes ========================*/
#include <peripherals/led.h>


/*==================== Private macros =====================*/
#define LED_PORT		PORTB
#define LED_PIN			PIN14


/*=================== Global variables ====================*/



/*================== function prototypes ==================*/
int main(void)							__attribute__((weak));
void delayCountingTo(uint32_t count)	__attribute__((weak));


/*==================== main function ======================*/
int main(void) {

	ledInit(LED_PORT, LED_PIN);

	while (1) {

		ledToggle(LED_PORT, LED_PIN);
		delayCountingTo(1000000);

	}

	return 0;
}


/*================= Function definitions ==================*/
void delayCountingTo(uint32_t count) {

	volatile uint32_t i;
	for (i = 0; i < count; i++);
}

