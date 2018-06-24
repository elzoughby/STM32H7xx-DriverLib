/*
 * interrupt.h
 *
 *  Created on: Jun 18, 2018
 *      Author: ahmed
 */

#ifndef LIB_INTERRUPT_H_
#define LIB_INTERRUPT_H_


#include "hw/stm32h7xx.h"


// install the interrupt vector table
void interruptInit();

// enable IRQ in the NVIC
void interruptEnable(interruptSource_t interruptSource);

// disable IRQ in the NVIC
void interruptDisable(interruptSource_t interruptSource);

// install the interrupt handler for an IRQ
void interruptHandlerInstall(interruptSource_t interruptSource, void (*handler)(void));



#endif /* LIB_INTERRUPT_H_ */
