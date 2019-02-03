/*==============================================================================

 Name        : interrupt.h
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


#ifndef HAL_INTERRUPT_H_
#define HAL_INTERRUPT_H_


#include "hw/stm32h7xx.h"


/* install the interrupt vector table */
void interruptInit();

/* enable IRQ in the NVIC */
void interruptEnable(interruptSource_t interruptSource);

/* disable IRQ in the NVIC */
void interruptDisable(interruptSource_t interruptSource);

/* install the interrupt handler for an IRQ */
void interruptHandlerInstall(interruptSource_t interruptSource, pVFn_t handler);



#endif /* HAL_INTERRUPT_H_ */
