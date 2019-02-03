/*==============================================================================

 Name        : led.c
 Version     : 1.0.0
 Description : LED driver for STM32H7xx MCUs

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


#include "led.h"



void ledInit(gpioPort_t port, gpioPin_t pin) {

	gpioPinConfig_t ledPinConfig = {
			GPIO_MODE_OUTPUT,
			GPIO_OTYPE_PUSH_PULL,
			GPIO_OSPEED_MEDIUM,
			GPIO_PUPD_NO_PULLUP_PULLDOWN,
			0,
			EXTI_DISABLE
	};

	gpioPinInit(port, pin, &ledPinConfig);

}

void ledOn(gpioPort_t port, gpioPin_t pin) {

	gpioPinSet(port, pin);

}

void ledOff(gpioPort_t port, gpioPin_t pin) {

	gpioPinClear(port, pin);

}

void ledSetState(gpioPort_t port, gpioPin_t pin, bit_t ledState) {

	gpioPinWrite(port, pin, ledState);

}

bit_t ledGetState(gpioPort_t port, gpioPin_t pin) {

	return gpioPinRead(port, pin);

}


void ledToggle(gpioPort_t port, gpioPin_t pin) {

	if (ledGetState(port, pin))
		ledOff(port, pin);
	else
		ledOn(port, pin);

}
