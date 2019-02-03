/*==============================================================================

 Name        : led.h
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

#ifndef PERIPHERALS_LED_H_
#define PERIPHERALS_LED_H_


#include "hal/gpio.h"


#define ledSourcingOn(port, pin)	ledOn(port, pin)
#define ledSourcingOff(port, pin)	ledOff(port, pin)
#define ledSinkingOn(port, pin)		ledOff(port, pin)
#define ledSinkingOff(port, pin)	ledOn(port, pin)



void ledInit(gpioPort_t port, gpioPin_t pin);

void ledOn(gpioPort_t port, gpioPin_t pin);

void ledOff(gpioPort_t port, gpioPin_t pin);

void ledSetState(gpioPort_t port, gpioPin_t pin, bit_t ledState);

bit_t ledGetState(gpioPort_t port, gpioPin_t pin);

void ledToggle(gpioPort_t port, gpioPin_t pin);


#endif /* PERIPHERALS_LED_H_ */
