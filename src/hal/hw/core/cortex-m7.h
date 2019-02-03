/*==============================================================================

 Name        : cortex-m7.h
 Version     : 1.0.0
 Description : Core registers definition for all ARM cortex-m7 MCUs

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

#ifndef LIB_HW_CORTEX_M7_H_
#define LIB_HW_CORTEX_M7_H_


#include "types.h"


#define NVIC_BASE	0xE000E100
#define SCB_BASE	0xE000ED00


typedef struct
{
  __IO uint32_t ISER[8U];
        uint32_t RESERVED0[24U];
  __IO uint32_t ICER[8U];
        uint32_t RSERVED1[24U];
  __IO uint32_t ISPR[8U];
        uint32_t RESERVED2[24U];
  __IO uint32_t ICPR[8U];
        uint32_t RESERVED3[24U];
  __IO uint32_t IABR[8U];
        uint32_t RESERVED4[56U];
  __IO uint8_t  IP[240U];
        uint32_t RESERVED5[644U];
  __IO  uint32_t STIR;
}  nvicStruct;


typedef struct
{
	__IO const uint32_t CPUID;
	__IO uint32_t ICSR;
	__IO uint32_t VTOR;
	__IO uint32_t AIRCR;
	__IO uint32_t SCR;
	__IO uint32_t CCR;
	__IO uint8_t  SHPR[12U];
	__IO uint32_t SHCSR;
	__IO uint8_t MMFSR;
	__IO uint8_t BFSR;
	__IO uint16_t UFSR;
	__IO uint32_t HFSR;
	__IO uint32_t DFSR;
	__IO uint32_t MMFAR;
	__IO uint32_t BFAR;
	__IO uint32_t AFSR;
} scbStruct;


#define NVIC	((nvicStruct*) NVIC_BASE)
#define SCB		((scbStruct*) SCB_BASE)


#endif /* LIB_HW_CORTEX_M7_H_ */
