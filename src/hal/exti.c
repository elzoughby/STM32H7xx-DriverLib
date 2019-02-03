/*==============================================================================

 Name        : exti.c
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

#include "exti.h"



void extIInit() {

	// do nothing for now

}

void extIEnable(extILine_t extILine) {

	// unmask the EXTI line
	if (extILine < 32)
		EXTI->IMR1 |= (1 << (extILine - 0));
	else if (extILine < 64)
		EXTI->IMR2 |= (1 << (extILine - 32));
	else if (extILine < 96)
		EXTI->IMR3 |= (1 << (extILine - 64));

}

void extIDisable(extILine_t extILine) {

	// mask the EXTI line
	if (extILine < 32)
		EXTI->IMR1 &= ~(1 << (extILine - 0));
	else if (extILine < 64)
		EXTI->IMR2 &= ~(1 << (extILine - 32));
	else if (extILine < 96)
		EXTI->IMR3 &= ~(1 << (extILine - 64));

}

void extIClearPending(extILine_t extILine) {

	// clear pending EXTI line
	if (extILine < 32)
		EXTI->PR1 |= (1 << (extILine - 0));
	else if (extILine < 64)
		EXTI->PR2 |= (1 << (extILine - 32));
	else if (extILine < 96)
		EXTI->PR3 |= (1 << (extILine - 64));

}

void extISelTrigger(extILine_t extILine, extITrigger_t interruptTrigger) {

	if (extILine < 32) {
		if (interruptTrigger == EXTI_TRIGGER_RISING) {
			EXTI->RTSR1 |= (1 << (extILine - 0));
			EXTI->FTSR1 &= ~(1 << (extILine - 0));
		} else if (interruptTrigger == EXTI_TRIGGER_FALLING) {
			EXTI->RTSR1 &= ~(1 << (extILine - 0));
			EXTI->FTSR1 |= (1 << (extILine - 0));
		} else if (interruptTrigger == EXTI_TRIGGER_BOTH) {
			EXTI->RTSR1 |= (1 << (extILine - 0));
			EXTI->FTSR1 |= (1 << (extILine - 0));
		}
	} else if (extILine < 64) {
		if (interruptTrigger == EXTI_TRIGGER_RISING) {
			EXTI->RTSR2 |= (1 << (extILine - 0));
			EXTI->FTSR2 &= ~(1 << (extILine - 0));
		} else if (interruptTrigger == EXTI_TRIGGER_FALLING) {
			EXTI->RTSR2 &= ~(1 << (extILine - 0));
			EXTI->FTSR2 |= (1 << (extILine - 0));
		} else if (interruptTrigger == EXTI_TRIGGER_BOTH) {
			EXTI->RTSR2 |= (1 << (extILine - 0));
			EXTI->FTSR2 |= (1 << (extILine - 0));
		}
	} else if (extILine < 96) {
		if (interruptTrigger == EXTI_TRIGGER_RISING) {
			EXTI->RTSR3 |= (1 << (extILine - 0));
			EXTI->FTSR3 &= ~(1 << (extILine - 0));
		} else if (interruptTrigger == EXTI_TRIGGER_FALLING) {
			EXTI->RTSR3 &= ~(1 << (extILine - 0));
			EXTI->FTSR3 |= (1 << (extILine - 0));
		} else if (interruptTrigger == EXTI_TRIGGER_BOTH) {
			EXTI->RTSR3 |= (1 << (extILine - 0));
			EXTI->FTSR3 |= (1 << (extILine - 0));
		}
	}

}


