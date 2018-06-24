/*
 * gpio.c
 *
 *  Created on: Jun 16, 2018
 *      Author: ahmed
 */


#include "gpio.h"


static uint8_t getPortNum(gpioPort_t port);

static interruptSource_t getExtIInterruptSource(extILine_t extILine);

static void selectExtILinePort(gpioPort_t port, gpioPin_t pin);



void gpioPinInit(gpioPort_t port, gpioPinConfig_t* pinConfig) {

	gpioPin_t pin = pinConfig->pin;

	uint8_t portNum = getPortNum(port);
	RCC->AHB4ENR |= (1 << portNum);

	port->MODER &= ~(0x03U << (pin * 2));
	port->MODER |= (pinConfig->mode << (pin * 2));
	port->OTYPER &= ~(0x01U << pin);
	port->OTYPER |= (pinConfig->outputType << pin);
	port->OSPEEDR &= ~(0x03U << (pin * 2));
	port->OSPEEDR |= (pinConfig->outputSpeed << (pin * 2));
	port->PUPDR &= ~(0x03U << (pin * 2));
	port->PUPDR |= (pinConfig->pullupPulldown << (pin * 2));
	if (pin <= 7) {
		port->AFRL &= ~(0x0FU << (pin * 4));
		port->AFRL |= (pinConfig->altFunc << (pin * 4));
	} else {
		port->AFRH &= ~(0x0FU << ((pin - 8) * 4));
		port->AFRH |= (pinConfig->altFunc << ((pin - 8) * 4));
	}

}

void gpioPinSet(gpioPort_t port, gpioPin_t pin) {

	port->BSR = (1 << pin);

}

void gpioPinClear(gpioPort_t port, gpioPin_t pin) {

	port->BRR = (1 << pin);

}

void gpioPinWrite(gpioPort_t port, gpioPin_t pin, bit_t val) {

	if(val == 1) {
		gpioPinSet(port, pin);
	} else if(val == 0) {
		gpioPinClear(port, pin);
	}

}

bit_t gpioPinRead(gpioPort_t port, gpioPin_t pin) {

	return (port->IDR & (1 << pin))? 1 : 0;

}

void gpioPinToggle(gpioPort_t port, gpioPin_t pin) {

	if(gpioPinRead(port, pin))
		gpioPinClear(port, pin);
	else
		gpioPinSet(port, pin);

}

void gpioPinAttachInterrupt(gpioPort_t port, gpioPinConfig_t* pinConfig, void (*handler)(void)) {

	// get EXTI Line
	extILine_t extILine = pinConfig->pin;

	// get Interrupt IRQ number
	interruptSource_t interruptSource = getExtIInterruptSource(extILine);

	extIInit();
	extISelTrigger(extILine, pinConfig->interruptTrigger);
	selectExtILinePort(port, pinConfig->pin);
	extIEnable(extILine);
	interruptInit();
	interruptHandlerInstall(interruptSource, handler);
	interruptEnable(interruptSource);

}

void gpioClearPendingInterrupt(gpioPort_t port, gpioPin_t pin) {

	// get EXTI Line
	extILine_t extILine = pin;

	extIClearPending(extILine);

}



static uint8_t getPortNum(gpioPort_t port) {

	uint8_t portNum;

	if (port == PORTA)
		portNum = 0;
	else if (port == PORTB)
		portNum = 1;
	else if (port == PORTC)
		portNum = 2;
	else if (port == PORTD)
		portNum = 3;
	else if (port == PORTE)
		portNum = 4;
	else if (port == PORTF)
		portNum = 5;
	else if (port == PORTG)
		portNum = 6;
	else if (port == PORTH)
		portNum = 7;
	else if (port == PORTI)
		portNum = 8;
	else if (port == PORTJ)
		portNum = 9;
	else if (port == PORTK)
		portNum = 10;

	return portNum;
}

static interruptSource_t getExtIInterruptSource(extILine_t extILine) {

	interruptSource_t interruptSource;
	if (extILine < 5)
		interruptSource = EXTI0_IRQn + extILine;
	else if (extILine < 10)
		interruptSource = EXTI9_5_IRQn;
	else if (extILine < 16)
		interruptSource = EXTI15_10_IRQn;

	return interruptSource;
}

static void selectExtILinePort(gpioPort_t port, gpioPin_t pin) {

	// enable clock for SYSCFG
	RCC->APB4ENR |= RCC_APB4ENR_SYSCFGEN;

	// get the port number
	uint8_t portNum = getPortNum(port);

	// select the EXTI line source port in SYSCFG
	SYSCFG->EXTICR[pin/4] &= ~(0xF << ((pin % 4) * 4));
	SYSCFG->EXTICR[pin/4] |= (portNum << ((pin % 4) * 4));

}

