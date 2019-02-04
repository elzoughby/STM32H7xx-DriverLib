/*==============================================================================

 Name        : interrupt.c
 Version     : 1.0.0
 Description : An interrupt driver for STM32H7xx MCUs

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

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

===============================================================================*/


#include "interrupt.h"


/* the new vector table copy on SRAM */
static __IO pVFn_t newVectorTable[_VECTOR_TABLE_SIZE] __attribute__ ((section(".sram_d1")));


void interruptInit() {

	/* ensure that it could be called just once */
	static bit_t _firstCall = TRUE;

	if(_firstCall) {
		__IO pVFn_t* origVectorTable = (pVFn_t*) SCB->VTOR;
		/* copy the content of the original vector table into the new vector table */
		for(uint32_t i = 0; i < _VECTOR_TABLE_SIZE; i++)
		newVectorTable[i] = origVectorTable[i];

		/* install the new interrupt vector table */
		SCB->VTOR = (uint32_t) &newVectorTable;

		/* it shouldn't be called again */
		_firstCall = FALSE;
	} else {
		/* Do nothing */
	}

}

void interruptEnable(interruptSource_t interruptSource) {

	NVIC->ISER[interruptSource/32] |= (1 << (interruptSource % 32));

}

void interruptDisable(interruptSource_t interruptSource) {

	NVIC->ICER[interruptSource/32] |= (1 << (interruptSource % 32));

}

void interruptHandlerInstall(interruptSource_t interruptSource, pVFn_t handler) {

	/* install interrupt handler bypassing the 16 system exceptions */
	newVectorTable[interruptSource + 16] = handler;

}

