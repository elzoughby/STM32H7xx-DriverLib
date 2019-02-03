/*==============================================================================

 Name        : exti.h
 Version     : 1.0.0
 Description : External Interrupt driver for STM32H7xx MCUs

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

#ifndef HAL_EXTI_H_
#define HAL_EXTI_H_


#include "hw/stm32h7xx.h"
#include "interrupt.h"


typedef enum {
	EXTI_DISABLE			= 0x00,
	EXTI_TRIGGER_DISABLE	= 0x00,
	EXTI_TRIGGER_RISING		= 0x01,
	EXTI_TRIGGER_FALLING	= 0x02,
	EXTI_TRIGGER_BOTH		= 0x03
} extITrigger_t;



void extIInit();

void extIEnable(extILine_t extILine);

void extIDisable(extILine_t extILine);

void extIClearPending(extILine_t extILine);

void extISelTrigger(extILine_t extILine, extITrigger_t interruptTrigger);


#endif /* HAL_EXTI_H_ */
