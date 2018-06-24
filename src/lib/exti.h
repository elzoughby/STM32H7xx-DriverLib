/*
 * exti.h
 *
 *  Created on: Jun 19, 2018
 *      Author: ahmed
 */

#ifndef LIB_EXTI_H_
#define LIB_EXTI_H_


#include "hw/stm32h7xx.h"
#include "interrupt.h"


typedef enum {
	EXTI_DISABLE			= 0x00,
	EXTI_TRIGGER_RISING		= 0x01,
	EXTI_TRIGGER_FALLING	= 0x02,
	EXTI_TRIGGER_BOTH		= 0x03
} extITrigger_t;



void extIInit();

void extIEnable(extILine_t extILine);

void extIDisable(extILine_t extILine);

void extIClearPending(extILine_t extILine);

void extISelTrigger(extILine_t extILine, extITrigger_t interruptTrigger);


#endif /* LIB_EXTI_H_ */
