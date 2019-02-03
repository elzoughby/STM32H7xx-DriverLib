/*============================================================================
 Name        : gpio_interrupt.c
 Author      : Ahmed Elzoughby
 Version     : 1.0.0
 Copyright   : Copyright (c) 2018 Ahmed Elzoughby
 Description : A demonstration of the independent startup code for STM32H7
 Note        : Tested on Nucleo-H743ZI development board
=============================================================================*/



/*======================= Includes ========================*/
#include <hal/gpio.h>


/*==================== Private macros =====================*/
#define LED_PORT		PORTB
#define LED_PIN			PIN14
#define BUTTON_PORT		PORTC
#define BUTTON_PIN		PIN13


/*=================== Global variables ====================*/



/*================== function prototypes ==================*/
int main(void)							__attribute__((weak));
void delayCountingTo(uint32_t count)	__attribute__((weak));
void buttonHandler(void)				__attribute__((weak));


/*==================== main function ======================*/
int main(void) {

	gpioPinConfig_t ledPinConfig = {
			GPIO_MODE_OUTPUT,
			GPIO_OTYPE_PUSH_PULL,
			GPIO_OSPEED_HIGH,
			GPIO_PUPD_NO_PULLUP_PULLDOWN,
			0,
			EXTI_DISABLE
	};

	gpioPinConfig_t buttonPinConfig = {
			GPIO_MODE_INPUT,
			GPIO_OTYPE_PUSH_PULL,
			GPIO_OSPEED_LOW,
			GPIO_PUPD_PULLDOWN,
			0,
			EXTI_TRIGGER_RISING
	};

	gpioPinInit(LED_PORT, LED_PIN, &ledPinConfig);
	gpioPinInit(BUTTON_PORT, BUTTON_PIN, &buttonPinConfig);
	gpioPinAttachInterrupt(BUTTON_PORT, BUTTON_PIN, buttonHandler);


	while (1) {

	}

	return 0;
}


/*================= Function definitions ==================*/
void delayCountingTo(uint32_t count) {

	volatile uint32_t i;
	for (i = 0; i < count; i++);
}

void buttonHandler() {

	gpioClearPendingInterrupt(BUTTON_PORT, BUTTON_PIN);
	gpioPinToggle(LED_PORT, LED_PIN);
}


