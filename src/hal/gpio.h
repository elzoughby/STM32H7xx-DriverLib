/*==============================================================================

 Name        : gpio.h
 Version     : 1.0.0
 Description : General Purpose Input/Output driver for STM32H7xx MCUs

--------------------------------------------------------------------------------

 The MIT License (MIT)
 Copyright (c) 2018 Ahmed Elzoughby

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, ExPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

===============================================================================*/

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_


#include "exti.h"
#include "hw/stm32h7xx.h"


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
	gpioMode_t mode;
	gpioOType_t outputType;
	gpioOSpeed_t outputSpeed;
	gpioPuPd_t pullupPulldown;
	gpioAltFun_t altFunc;
	extITrigger_t interruptTrigger;
} gpioPinConfig_t;


void gpioPinInit(gpioPort_t port, gpioPin_t pin, gpioPinConfig_t* pinConfig);

void gpioPinSet(gpioPort_t port, gpioPin_t pin);

void gpioPinClear(gpioPort_t port, gpioPin_t pin);

void gpioPinWrite(gpioPort_t port, gpioPin_t pin, bit_t val);

bit_t gpioPinRead(gpioPort_t port, gpioPin_t pin);

void gpioPinToggle(gpioPort_t port, gpioPin_t pin);

void gpioPinAttachInterrupt(gpioPort_t port, gpioPin_t pin, void (*handler)(void));

void gpioClearPendingInterrupt(gpioPort_t port, gpioPin_t pin);


#endif /* HAL_GPIO_H_ */
