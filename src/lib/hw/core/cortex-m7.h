/*
 * cortexm7.h
 *
 *  Created on: Jun 18, 2018
 *      Author: ahmed
 */

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
