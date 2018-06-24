/*
 * gpio.h
 *
 *  Created on: Jun 16, 2018
 *      Author: ahmed
 */

#ifndef LIB_GPIO_H_
#define LIB_GPIO_H_

#include "hw/stm32h7xx.h"
#include "exti.h"


typedef enum {
	GPIO_MODE_INPUT		= 0x00,
	GPIO_MODE_OUTPUT	= 0x01,
	GPIO_MODE_ALT_FUNC	= 0x02,
	GPIO_MODE_ANALOG	= 0x03
} gpioMode_t;

typedef enum {
	GPIO_OTYPE_PUSH_PULL	= 0x00,
	GPIO_OTYPE_OPEN_DRAIN	= 0x01
} gpioOType_t;

typedef enum {
	GPIO_OSPEED_LOW			= 0x00,
	GPIO_OSPEED_MEDIUM		= 0x01,
	GPIO_OSPEED_HIGH		= 0x02,
	GPIO_OSPEED_VERY_HIGH	= 0x03
} gpioOSpeed_t;

typedef enum {
	GPIO_PUPD_NO_PULLUP_PULLDOWN	= 0x00,
	GPIO_PUPD_PULLUP				= 0x01,
	GPIO_PUPD_PULLDOWN				= 0x02
} gpioPuPd_t;


typedef struct {
	gpioPin_t pin;
	gpioMode_t mode;
	gpioOType_t outputType;
	gpioOSpeed_t outputSpeed;
	gpioPuPd_t pullupPulldown;
	gpioAltFun_t altFunc;
	extITrigger_t interruptTrigger;
} gpioPinConfig_t;


void gpioPinInit(gpioPort_t port, gpioPinConfig_t* pinConfig);

void gpioPinSet(gpioPort_t port, gpioPin_t pin);

void gpioPinClear(gpioPort_t port, gpioPin_t pin);

void gpioPinWrite(gpioPort_t port, gpioPin_t pin, bit_t val);

bit_t gpioPinRead(gpioPort_t port, gpioPin_t pin);

void gpioPinToggle(gpioPort_t port, gpioPin_t pin);

void gpioPinAttachInterrupt(gpioPort_t port, gpioPinConfig_t* pinConfig, void (*handler)(void));

void gpioClearPendingInterrupt(gpioPort_t port, gpioPin_t pin);


#endif /* LIB_GPIO_H_ */
