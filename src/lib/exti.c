/*
 * exti.c
 *
 *  Created on: Jun 19, 2018
 *      Author: ahmed
 */

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


