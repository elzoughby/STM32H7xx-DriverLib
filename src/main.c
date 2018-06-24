/*============================================================================
 Name        : main.c
 Author      : Ahmed Elzoughby
 Version     : 1.0.0
 Copyright   : Copyright (c) 2018 Ahmed Elzoughby
 Description : A demonstration of the independent startup code for STM32H7
 Note        : Tested on Nucleo-H743ZI development board
=============================================================================*/



/*======================= Includes ========================*/
#include "lib/gpio.h"


/*==================== Private macros =====================*/
#define RED_LED_PORT		PORTB
#define RED_LED_PIN			PIN14
#define BLUE_LED_PORT		PORTB
#define BLUE_LED_PIN		PIN7
#define GREEN_LED_PORT		PORTB
#define GREEN_LED_PIN		PIN0
#define USER_BUTTON_PORT	PORTC
#define USER_BUTTON_PIN		PIN13


/*=================== Global variables ====================*/



/*================== function prototypes ==================*/
void delayCountingTo(uint32_t count);
void userButtonHandler(void);
void EXTI15_10_IRQHandler(void);	// for debugging purposes only


/*==================== main function ======================*/
int main(void) {

	gpioPinConfig_t redLED = {RED_LED_PIN, GPIO_MODE_OUTPUT, GPIO_OTYPE_PUSH_PULL,
			GPIO_OSPEED_HIGH, GPIO_PUPD_NO_PULLUP_PULLDOWN, 0, EXTI_DISABLE};
	gpioPinConfig_t blueLED = {BLUE_LED_PIN, GPIO_MODE_OUTPUT, GPIO_OTYPE_PUSH_PULL,
			GPIO_OSPEED_HIGH, GPIO_PUPD_NO_PULLUP_PULLDOWN, 0, EXTI_DISABLE};
	gpioPinConfig_t greenLED = {GREEN_LED_PIN, GPIO_MODE_OUTPUT, GPIO_OTYPE_PUSH_PULL,
			GPIO_OSPEED_HIGH, GPIO_PUPD_NO_PULLUP_PULLDOWN, 0, EXTI_DISABLE};
	gpioPinConfig_t userButton = {USER_BUTTON_PIN, GPIO_MODE_INPUT, GPIO_OTYPE_PUSH_PULL,
			GPIO_OSPEED_LOW, GPIO_PUPD_PULLDOWN, 0, EXTI_TRIGGER_RISING};

	gpioPinInit(RED_LED_PORT, &redLED);
	gpioPinInit(BLUE_LED_PORT, &blueLED);
	gpioPinInit(GREEN_LED_PORT, &greenLED);
	gpioPinInit(USER_BUTTON_PORT, &userButton);
	gpioPinAttachInterrupt(USER_BUTTON_PORT, &userButton, userButtonHandler);


	while (1) {

	}

	return 0;
}


/*================= Function definitions ==================*/
void delayCountingTo(uint32_t count) {

	volatile uint32_t i;
	for (i = 0; i < count; i++);
}

void userButtonHandler() {
	gpioClearPendingInterrupt(USER_BUTTON_PORT, USER_BUTTON_PIN);
	gpioPinToggle(RED_LED_PORT, RED_LED_PIN);
	gpioPinToggle(BLUE_LED_PORT, BLUE_LED_PIN);
	gpioPinToggle(GREEN_LED_PORT, GREEN_LED_PIN);
}

// for debugging purposes only
void EXTI15_10_IRQHandler(void) {
	while (1) {

	}
}


