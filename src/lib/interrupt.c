/*
 * interrupt.c
 *
 *  Created on: Jun 18, 2018
 *      Author: ahmed
 */


#include "interrupt.h"


static __IO voidPFn_t newVectorTable[_VECTOR_TABLE_SIZE] __attribute__ ((section(".itcmram")));


void interruptInit() {

	__IO voidPFn_t* origVectorTable = (voidPFn_t*) SCB->VTOR;
	// copy the content of the original vector table into the new vector table
	for(uint32_t i = 0; i < _VECTOR_TABLE_SIZE; i++)
		newVectorTable[i] = origVectorTable[i];

	// install the new interrupt vector table
	SCB->VTOR = (uint32_t) &newVectorTable;

}

void interruptEnable(interruptSource_t interruptSource) {

	NVIC->ISER[interruptSource/32] |= (1 << (interruptSource % 32));

}

void interruptDisable(interruptSource_t interruptSource) {

	NVIC->ICER[interruptSource/32] |= (1 << (interruptSource % 32));

}

void interruptHandlerInstall(interruptSource_t interruptSource, void (*handler)(void)) {

	// install interrupt handler function
	newVectorTable[interruptSource] = handler;

}

