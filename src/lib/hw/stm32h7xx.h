/*
 * stm32h7xx.h
 *
 *  Created on: Jun 16, 2018
 *      Author: ahmed
 */

#ifndef LIB_HW_STM32H7XX_H_
#define LIB_HW_STM32H7XX_H_


#define _VECTOR_TABLE_SIZE	166



#include "core/cortex-m7.h"




#define RCC_BASE		0x58024400
#define EXTI_BASE		0x58000000
#define SYSCFG_BASE		0x58000400
#define PORTA_BASE		0x58020000
#define PORTB_BASE		0x58020400
#define PORTC_BASE		0x58020800
#define PORTD_BASE		0x58020C00
#define PORTE_BASE		0x58021000
#define PORTF_BASE		0x58021400
#define PORTG_BASE		0x58021800
#define PORTH_BASE		0x58021C00
#define PORTI_BASE		0x58022000
#define PORTJ_BASE		0x58022400
#define PORTK_BASE		0x58022800


typedef enum {
/******  Cortex-M Processor Exceptions Numbers *******/
	NonMaskableInt_IRQn         = -14,
	HardFault_IRQn              = -13,
	MemoryManagement_IRQn       = -12,
	BusFault_IRQn               = -11,
	UsageFault_IRQn             = -10,
	SVCall_IRQn                 = -5,
	DebugMonitor_IRQn           = -4,
	PendSV_IRQn                 = -2,
	SysTick_IRQn                = -1,
/*********  STM32 specific Interrupt Numbers *********/
	WWDG_IRQn                   = 0,
	PVD_AVD_IRQn                = 1,
	TAMP_STAMP_IRQn             = 2,
	RTC_WKUP_IRQn               = 3,
	FLASH_IRQn                  = 4,
	RCC_IRQn                    = 5,
	EXTI0_IRQn                  = 6,
	EXTI1_IRQn                  = 7,
	EXTI2_IRQn                  = 8,
	EXTI3_IRQn                  = 9,
	EXTI4_IRQn                  = 10,
	DMA1_Stream0_IRQn           = 11,
	DMA1_Stream1_IRQn           = 12,
	DMA1_Stream2_IRQn           = 13,
	DMA1_Stream3_IRQn           = 14,
	DMA1_Stream4_IRQn           = 15,
	DMA1_Stream5_IRQn           = 16,
	DMA1_Stream6_IRQn           = 17,
	ADC_IRQn                    = 18,
	FDCAN1_IT0_IRQn             = 19,
	FDCAN2_IT0_IRQn             = 20,
	FDCAN1_IT1_IRQn             = 21,
	FDCAN2_IT1_IRQn             = 22,
	EXTI9_5_IRQn                = 23,
	TIM1_BRK_IRQn               = 24,
	TIM1_UP_IRQn                = 25,
	TIM1_TRG_COM_IRQn           = 26,
	TIM1_CC_IRQn                = 27,
	TIM2_IRQn                   = 28,
	TIM3_IRQn                   = 29,
	TIM4_IRQn                   = 30,
	I2C1_EV_IRQn                = 31,
	I2C1_ER_IRQn                = 32,
	I2C2_EV_IRQn                = 33,
	I2C2_ER_IRQn                = 34,
	SPI1_IRQn                   = 35,
	SPI2_IRQn                   = 36,
	USART1_IRQn                 = 37,
	USART2_IRQn                 = 38,
	USART3_IRQn                 = 39,
	EXTI15_10_IRQn              = 40,
	RTC_Alarm_IRQn              = 41,
	TIM8_BRK_TIM12_IRQn         = 43,
	TIM8_UP_TIM13_IRQn          = 44,
	TIM8_TRG_COM_TIM14_IRQn     = 45,
	TIM8_CC_IRQn                = 46,
	DMA1_Stream7_IRQn           = 47,
	FMC_IRQn                    = 48,
	SDMMC1_IRQn                 = 49,
	TIM5_IRQn                   = 50,
	SPI3_IRQn                   = 51,
	UART4_IRQn                  = 52,
	UART5_IRQn                  = 53,
	TIM6_DAC_IRQn               = 54,
	TIM7_IRQn                   = 55,
	DMA2_Stream0_IRQn           = 56,
	DMA2_Stream1_IRQn           = 57,
	DMA2_Stream2_IRQn           = 58,
	DMA2_Stream3_IRQn           = 59,
	DMA2_Stream4_IRQn           = 60,
	ETH_IRQn                    = 61,
	ETH_WKUP_IRQn               = 62,
	FDCAN_CAL_IRQn              = 63,
	DMA2_Stream5_IRQn           = 68,
	DMA2_Stream6_IRQn           = 69,
	DMA2_Stream7_IRQn           = 70,
	USART6_IRQn                 = 71,
	I2C3_EV_IRQn                = 72,
	I2C3_ER_IRQn                = 73,
	OTG_HS_EP1_OUT_IRQn         = 74,
	OTG_HS_EP1_IN_IRQn          = 75,
	OTG_HS_WKUP_IRQn            = 76,
	OTG_HS_IRQn                 = 77,
	DCMI_IRQn                   = 78,
	RNG_IRQn                    = 80,
	FPU_IRQn                    = 81,
	UART7_IRQn                  = 82,
	UART8_IRQn                  = 83,
	SPI4_IRQn                   = 84,
	SPI5_IRQn                   = 85,
	SPI6_IRQn                   = 86,
	SAI1_IRQn                   = 87,
	LTDC_IRQn                   = 88,
	LTDC_ER_IRQn                = 89,
	DMA2D_IRQn                  = 90,
	SAI2_IRQn                   = 91,
	QUADSPI_IRQn                = 92,
	LPTIM1_IRQn                 = 93,
	CEC_IRQn                    = 94,
	I2C4_EV_IRQn                = 95,
	I2C4_ER_IRQn                = 96,
	SPDIF_RX_IRQn               = 97,
	OTG_FS_EP1_OUT_IRQn         = 98,
	OTG_FS_EP1_IN_IRQn          = 99,
	OTG_FS_WKUP_IRQn            = 100,
	OTG_FS_IRQn                 = 101,
	DMAMUX1_OVR_IRQn			= 102,
	HRTIM1_Master_IRQn          = 103,
	HRTIM1_TIMA_IRQn            = 104,
	HRTIM1_TIMB_IRQn            = 105,
	HRTIM1_TIMC_IRQn            = 106,
	HRTIM1_TIMD_IRQn            = 107,
	HRTIM1_TIME_IRQn            = 108,
	HRTIM1_FLT_IRQn             = 109,
	DFSDM1_FLT0_IRQn            = 110,
	DFSDM1_FLT1_IRQn            = 111,
	DFSDM1_FLT2_IRQn            = 112,
	DFSDM1_FLT3_IRQn            = 113,
	SAI3_IRQn                   = 114,
	SWPMI1_IRQn                 = 115,
	TIM15_IRQn                  = 116,
	TIM16_IRQn                  = 117,
	TIM17_IRQn                  = 118,
	MDIOS_WKUP_IRQn             = 119,
	MDIOS_IRQn                  = 120,
	JPEG_IRQn                   = 121,
	MDMA_IRQn                   = 122,
	SDMMC2_IRQn                 = 124,
	HSEM1_IRQn                  = 125,
	ADC3_IRQn                   = 127,
	DMAMUX2_OVR_IRQn            = 128,
	BDMA_Channel0_IRQn          = 129,
	BDMA_Channel1_IRQn          = 130,
	BDMA_Channel2_IRQn          = 131,
	BDMA_Channel3_IRQn          = 132,
	BDMA_Channel4_IRQn          = 133,
	BDMA_Channel5_IRQn          = 134,
	BDMA_Channel6_IRQn          = 135,
	BDMA_Channel7_IRQn          = 136,
	COMP_IRQn                   = 137,
	LPTIM2_IRQn                 = 138,
	LPTIM3_IRQn                 = 139,
	LPTIM4_IRQn                 = 140,
	LPTIM5_IRQn                 = 141,
	LPUART1_IRQn                = 142,
	CRS_IRQn                    = 144,
	SAI4_IRQn                   = 146,
	WAKEUP_PIN_IRQn             = 149,
} interruptSource_t;

typedef enum {
	EXTI0						= 0,
	EXTI1						= 1,
	EXTI2						= 2,
	EXTI3						= 3,
	EXTI4						= 4,
	EXTI5						= 5,
	EXTI6						= 6,
	EXTI7						= 7,
	EXTI8						= 8,
	EXTI9						= 9,
	EXTI10						= 10,
	EXTI11						= 11,
	EXTI12						= 12,
	EXTI13						= 13,
	EXTI14						= 14,
	EXTI15						= 15,
	PVD							= 16,
	AVD							= 16,
	RTC_ALARMS					= 17,
	RTC_TAMPER					= 18,
	RTC_TIMESTAMP				= 18,
	RCC_LSECSS					= 18,
	RTC_WAKEUP_TIMER			= 19,
	COMP1						= 20,
	COMP2						= 21,
	I2C1_WAKEUP					= 22,
	I2C2_WAKEUP					= 23,
	I2C3_WAKEUP					= 24,
	I2C4_WAKEUP					= 25,
	USART1_WAKEUP				= 26,
	USART2_WAKEUP				= 27,
	USART3_WAKEUP				= 28,
	USART6_WAKEUP				= 29,
	USART4_WAKEUP				= 30,
	USART5_WAKEUP				= 31,
	USART7_WAKEUP				= 32,
	USART8_WAKEUP				= 33,
	LPUART1_RX_WAKEUP			= 34,
	LPUART1_TX_WAKEUP			= 35,
	SPI1_WAKEUP					= 36,
	SPI2_WAKEUP					= 37,
	SPI3_WAKEUP					= 38,
	SPI4_WAKEUP					= 39,
	SPI5_WAKEUP					= 40,
	SPI6_WAKEUP					= 41,
	MDIO_WAKEUP					= 42,
	USB1_WAKEUP					= 43,
	USB2_WAKEUP					= 44,
	LPTIM1_WAKEUP				= 47,
	LPTIM2_WAKEUP				= 48,
	LPTIM2_OUTPUT				= 49,
	LPTIM3_WAKEUP				= 50,
	LPTIM3_OUTPUT				= 51,
	LPTIM4_WAKEUP				= 52,
	LPTIM5_WAKEUP				= 53,
	SWPMI_WAKEUP				= 54,
	WKUP1						= 55,
	WKUP2						= 56,
	WKUP3						= 57,
	WKUP4						= 58,
	WKUP5						= 59,
	WKUP6						= 60,
	RCC_INTERRUPT				= 61,
	I2C4_EVENT_INTERRUPT		= 62,
	I2C4_ERROR_INTERRUPT		= 63,
	LPUART1_GLOBAL_INTERRUPT	= 64,
	SPI6_INTERRUPT				= 65,
	BDMA_CH0_INTERRUPT			= 66,
	BDMA_CH1_INTERRUPT			= 67,
	BDMA_CH2_INTERRUPT			= 68,
	BDMA_CH3_INTERRUPT			= 69,
	BDMA_CH4_INTERRUPT			= 70,
	BDMA_CH5_INTERRUPT			= 71,
	BDMA_CH6_INTERRUPT			= 72,
	BDMA_CH7_INTERRUPT			= 73,
	DMAMUX2_INTERRUPT			= 74,
	ADC3_INTERRUPT				= 75,
	SAI4_INTERRUPT				= 76,
	HDMI_CEC_WAKEUP				= 85,
	ETHERNET_WAKEUP				= 86,
	HSECSS_INTERRUPT			= 87
} extILine_t;


typedef struct {
	__IO uint32_t CR;
	__IO uint32_t ICSCR;
	__IO uint32_t CRRCR;
	uint32_t RESERVED0;
	__IO uint32_t CFGR;
	uint32_t RESERVED1;
	__IO uint32_t D1CFGR;
	__IO uint32_t D2CFGR;
	__IO uint32_t D3CFGR;
	uint32_t RESERVED2;
	__IO uint32_t PLLCKSELR;
	__IO uint32_t PLLCFGR;
	__IO uint32_t PLL1DIVR;
	__IO uint32_t PLL1FRACR;
	__IO uint32_t PLL2DIVR;
	__IO uint32_t PLL2FRACR;
	__IO uint32_t PLL3DIVR;
	__IO uint32_t PLL3FRACR;
	uint32_t RESERVED3;
	__IO uint32_t D1CCIPR;
	__IO uint32_t D2CCIP1R;
	__IO uint32_t D2CCIP2R;
	__IO uint32_t D3CCIPR;
	uint32_t RESERVED4;
	__IO uint32_t CIER;
	__IO uint32_t CIFR;
	__IO uint32_t CICR;
	uint32_t RESERVED5;
	__IO uint32_t BDCR;
	__IO uint32_t CSR;
	uint32_t RESERVED6;
	__IO uint32_t AHB3RSTR;
	__IO uint32_t AHB1RSTR;
	__IO uint32_t AHB2RSTR;
	__IO uint32_t AHB4RSTR;
	__IO uint32_t APB3RSTR;
	__IO uint32_t APB1LRSTR;
	__IO uint32_t APB1HRSTR;
	__IO uint32_t APB2RSTR;
	__IO uint32_t APB4RSTR;
	__IO uint32_t GCR;
	uint32_t RESERVED7;
	__IO uint32_t D3AMR;
	uint32_t RESERVED8[9];
	__IO uint32_t RSR;
	__IO uint32_t AHB3ENR;
	__IO uint32_t AHB1ENR;
	__IO uint32_t AHB2ENR;
	__IO uint32_t AHB4ENR;
	__IO uint32_t APB3ENR;
	__IO uint32_t APB1LENR;
	__IO uint32_t APB1HENR;
	__IO uint32_t APB2ENR;
	__IO uint32_t APB4ENR;
	uint32_t RESERVED9;
	__IO uint32_t AHB3LPENR;
	__IO uint32_t AHB1LPENR;
	__IO uint32_t AHB2LPENR;
	__IO uint32_t AHB4LPENR;
	__IO uint32_t APB3LPENR;
	__IO uint32_t APB1LLPENR;
	__IO uint32_t APB1HLPENR;
	__IO uint32_t APB2LPENR;
	__IO uint32_t APB4LPENR;
	uint32_t RESERVED10[4];
} rccStruct;

typedef struct
{
	__IO uint32_t RTSR1;
	__IO uint32_t FTSR1;
	__IO uint32_t SWIER1;
	__IO uint32_t D3PMR1;
	__IO uint32_t D3PCR1L;
	__IO uint32_t D3PCR1H;
	uint32_t      RESERVED1;
	uint32_t      RESERVED2;
	__IO uint32_t RTSR2;
	__IO uint32_t FTSR2;
	__IO uint32_t SWIER2;
	__IO uint32_t D3PMR2;
	__IO uint32_t D3PCR2L;
	__IO uint32_t D3PCR2H;
	uint32_t      RESERVED3;
	uint32_t      RESERVED4;
	__IO uint32_t RTSR3;
	__IO uint32_t FTSR3;
	__IO uint32_t SWIER3;
	__IO uint32_t D3PMR3;
	__IO uint32_t D3PCR3L;
	__IO uint32_t D3PCR3H;
	uint32_t RESERVED5[10];
	__IO uint32_t IMR1;
	__IO uint32_t EMR1;
	__IO uint32_t PR1;
	uint32_t      RESERVED6;
	__IO uint32_t IMR2;
	__IO uint32_t EMR2;
	__IO uint32_t PR2;
	uint32_t      RESERVED7;
	__IO uint32_t IMR3;
	__IO uint32_t EMR3;
	__IO uint32_t PR3;
} extIStruct;

typedef struct
{
	uint32_t RESERVED1;
	__IO uint32_t PMCR;
	__IO uint32_t EXTICR[4];
	uint32_t RESERVED2[2];
	__IO uint32_t CCCSR;
	__IO uint32_t CCVR;
	__IO uint32_t CCCR;
	uint32_t     RESERVED3[62];
	__IO uint32_t PKGR;
	uint32_t     RESERVED4[118];
	__IO uint32_t UR0;
	__IO uint32_t UR1;
	__IO uint32_t UR2;
	__IO uint32_t UR3;
	__IO uint32_t UR4;
	__IO uint32_t UR5;
	__IO uint32_t UR6;
	__IO uint32_t UR7;
	__IO uint32_t UR8;
	__IO uint32_t UR9;
	__IO uint32_t UR10;
	__IO uint32_t UR11;
	__IO uint32_t UR12;
	__IO uint32_t UR13;
	__IO uint32_t UR14;
	__IO uint32_t UR15;
	__IO uint32_t UR16;
	__IO uint32_t UR17;
} sysCfgStruct;

typedef struct {
	__IO uint32_t MODER;
	__IO uint32_t OTYPER;
	__IO uint32_t OSPEEDR;
	__IO uint32_t PUPDR;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint16_t BSR;
	__IO uint16_t BRR;
	__IO uint32_t LCKR;
	__IO uint32_t AFRL;
	__IO uint32_t AFRH;
} gpioStruct;

typedef enum {
	PIN0 = 0x0,
	PIN1 = 0x1,
	PIN2 = 0x2,
	PIN3 = 0x3,
	PIN4 = 0x4,
	PIN5 = 0x5,
	PIN6 = 0x6,
	PIN7 = 0x7,
	PIN8 = 0x8,
	PIN9 = 0x9,
	PIN10 = 0xA,
	PIN11 = 0xB,
	PIN12 = 0xC,
	PIN13 = 0xD,
	PIN14 = 0xE,
	PIN15 = 0xF
} gpioPin_t;

typedef enum {
	GPIO
} gpioAltFun_t;

typedef gpioStruct* gpioPort_t;



#define RCC			((rccStruct*) RCC_BASE)
#define EXTI		((extIStruct*) EXTI_BASE)
#define SYSCFG		((sysCfgStruct*) SYSCFG_BASE)
#define PORTA		((gpioStruct*) PORTA_BASE)
#define PORTB		((gpioStruct*) PORTB_BASE)
#define PORTC		((gpioStruct*) PORTC_BASE)
#define PORTD		((gpioStruct*) PORTD_BASE)
#define PORTE		((gpioStruct*) PORTE_BASE)
#define PORTF		((gpioStruct*) PORTF_BASE)
#define PORTG		((gpioStruct*) PORTG_BASE)
#define PORTH		((gpioStruct*) PORTH_BASE)
#define PORTI		((gpioStruct*) PORTI_BASE)
#define PORTJ		((gpioStruct*) PORTJ_BASE)
#define PORTK		((gpioStruct*) PORTK_BASE)


/********************  Bit definition for RCC_AHB4ENR register  ******************/
#define RCC_AHB4ENR_GPIOAEN		(0x1U << 0)
#define RCC_AHB4ENR_GPIOBEN		(0x1U << 1)
#define RCC_AHB4ENR_GPIOCEN		(0x1U << 2)
#define RCC_AHB4ENR_GPIODEN		(0x1U << 3)
#define RCC_AHB4ENR_GPIOEEN		(0x1U << 4)
#define RCC_AHB4ENR_GPIOFEN		(0x1U << 5)
#define RCC_AHB4ENR_GPIOGEN		(0x1U << 6)
#define RCC_AHB4ENR_GPIOHEN		(0x1U << 7)
#define RCC_AHB4ENR_GPIOIEN		(0x1U << 8)
#define RCC_AHB4ENR_GPIOJEN		(0x1U << 9)
#define RCC_AHB4ENR_GPIOKEN		(0x1U << 10)
#define RCC_AHB4ENR_CRCEN		(0x1U << 19)
#define RCC_AHB4ENR_BDMAEN		(0x1U << 21)
#define RCC_AHB4ENR_ADC3EN		(0x1U << 24)
#define RCC_AHB4ENR_HSEMEN		(0x1U << 25)
#define RCC_AHB4ENR_BKPRAMEN	(0x1U << 28)

/********************  Bit definition for RCC_APB4ENR register  ******************/
#define RCC_APB4ENR_SYSCFGEN	(0x1U << 1)
#define RCC_APB4ENR_LPUART1EN	(0x1U << 3)
#define RCC_APB4ENR_SPI6EN		(0x1U << 5)
#define RCC_APB4ENR_I2C4EN		(0x1U << 7)
#define RCC_APB4ENR_LPTIM2EN	(0x1U << 9)
#define RCC_APB4ENR_LPTIM3EN	(0x1U << 10)
#define RCC_APB4ENR_LPTIM4EN	(0x1U << 11)
#define RCC_APB4ENR_LPTIM5EN	(0x1U << 12)
#define RCC_APB4ENR_COMP12EN	(0x1U << 14)
#define RCC_APB4ENR_VREFEN		(0x1U << 15)
#define RCC_APB4ENR_RTCAPBEN	(0x1U << 16)
#define RCC_APB4ENR_SAI4EN		(0x1U << 21)


#endif /* LIB_HW_STM32H7XX_H_ */
