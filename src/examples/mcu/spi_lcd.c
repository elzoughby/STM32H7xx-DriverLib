/*============================================================================
 Name        : spi_lcd.c
 Author      : Ahmed Elzoughby
 Version     : 1.0.0
 Copyright   : Copyright (c) 2018 Ahmed Elzoughby
 Description : A demonstration of the independent startup code for STM32H7
 Note        : Tested on Nucleo-H743ZI development board
=============================================================================*/



/*======================= Includes ========================*/
#include "hal/gpio.h"
#include "hal/spi.h"


/*==================== Private macros =====================*/
#define SPI3_SCK_PORT	PORTC
#define SPI3_SCK_PIN	PIN10
#define SPI3_MISO_PORT	PORTC
#define SPI3_MISO_PIN	PIN11
#define SPI3_MOSI_PORT	PORTC
#define SPI3_MOSI_PIN	PIN12
#define SPI3_NSS_PORT	PORTA
#define SPI3_NSS_PIN	PIN4

#define LCD_CE_PORT		SPI3_NSS_PORT
#define LCD_CE_PIN		SPI3_NSS_PIN
#define LCD_DC_PORT		SPI3_MISO_PORT
#define LCD_DC_PIN		SPI3_MISO_PIN
#define LCD_RST_PORT	PORTD
#define LCD_RST_PIN		PIN2


/*=================== Global variables ====================*/



/*================== function prototypes ==================*/
int main(void)							__attribute__((weak));
void delayCountingTo(uint32_t count)	__attribute__((weak));


/*==================== main function ======================*/
int main(void) {

	spiConfig_t spi3Config = {
			SPI_MODE_MASTER,
			SPI_CLK_DIV_BY_32,
			SPI_CRC_DISABLE,
			SPI_FIFO_1DATA,
			SPI_FRAME_8BITS,
			SPI_CLK_MODE3,
			SPI_MSB_FIRST,
			SPI_PROTOCOL_MOTOROLA,
			SPI_COMM_SIMPLEX_TRANSMITTER
	};

	gpioPinConfig_t spi3PinConfig = {
			GPIO_MODE_ALT_FUNC,
			GPIO_OTYPE_PUSH_PULL,
			GPIO_OSPEED_MEDIUM,
			GPIO_PUPD_NO_PULLUP_PULLDOWN,
			GPIO_AF6_SPI3,
			EXTI_DISABLE
	};

	gpioPinConfig_t dioPinConfig = {
			GPIO_MODE_OUTPUT,
			GPIO_OTYPE_PUSH_PULL,
			GPIO_OSPEED_MEDIUM,
			GPIO_PUPD_NO_PULLUP_PULLDOWN,
			DIO,
			EXTI_DISABLE
	};

	gpioPinInit(SPI3_SCK_PORT, SPI3_SCK_PIN, &spi3PinConfig);
	gpioPinInit(SPI3_MOSI_PORT, SPI3_MOSI_PIN, &spi3PinConfig);
	gpioPinInit(LCD_CE_PORT, LCD_CE_PIN, &dioPinConfig);
	gpioPinInit(LCD_DC_PORT, LCD_DC_PIN, &dioPinConfig);
	gpioPinInit(LCD_RST_PORT, LCD_RST_PIN, &dioPinConfig);
	spiInit(SPI3_I2S3, &spi3Config);

	gpioPinSet(LCD_CE_PORT, LCD_CE_PIN);
	gpioPinClear(LCD_RST_PORT, LCD_RST_PIN);
	delayCountingTo(100000);
	gpioPinSet(LCD_RST_PORT, LCD_RST_PIN);

	gpioPinClear(LCD_CE_PORT, LCD_CE_PIN);
	gpioPinClear(LCD_DC_PORT, LCD_DC_PIN);

	spiTransmitByte(SPI3_I2S3, 0x21);
	delayCountingTo(100000);
	gpioPinSet(LCD_CE_PORT, LCD_CE_PIN);
	delayCountingTo(100000);
	gpioPinClear(LCD_CE_PORT, LCD_CE_PIN);

	spiTransmitByte(SPI3_I2S3, 0xc6);
	delayCountingTo(10000);
	gpioPinSet(LCD_CE_PORT, LCD_CE_PIN);
	delayCountingTo(100000);
	gpioPinClear(LCD_CE_PORT, LCD_CE_PIN);

	spiTransmitByte(SPI3_I2S3, 0x13);
	delayCountingTo(10000);
	gpioPinSet(LCD_CE_PORT, LCD_CE_PIN);
	delayCountingTo(100000);
	gpioPinClear(LCD_CE_PORT, LCD_CE_PIN);

	spiTransmitByte(SPI3_I2S3, 0x06);
	delayCountingTo(10000);
	gpioPinSet(LCD_CE_PORT, LCD_CE_PIN);
	delayCountingTo(100000);
	gpioPinClear(LCD_CE_PORT, LCD_CE_PIN);

	spiTransmitByte(SPI3_I2S3, 0x20);
	delayCountingTo(10000);
	gpioPinSet(LCD_CE_PORT, LCD_CE_PIN);
	delayCountingTo(100000);
	gpioPinClear(LCD_CE_PORT, LCD_CE_PIN);

	spiTransmitByte(SPI3_I2S3, 0x0C);
	delayCountingTo(10000);
	gpioPinSet(LCD_CE_PORT, LCD_CE_PIN);
	delayCountingTo(100000);
	gpioPinClear(LCD_CE_PORT, LCD_CE_PIN);

	spiTransmitByte(SPI3_I2S3, 0x80);
	delayCountingTo(10000);
	gpioPinSet(LCD_CE_PORT, LCD_CE_PIN);
	delayCountingTo(100000);
	gpioPinClear(LCD_CE_PORT, LCD_CE_PIN);

	spiTransmitByte(SPI3_I2S3, 0x40);
	delayCountingTo(10000);

	gpioPinSet(LCD_CE_PORT, LCD_CE_PIN);
	delayCountingTo(100000);
	gpioPinSet(LCD_DC_PORT, LCD_DC_PIN);
	gpioPinClear(LCD_CE_PORT, LCD_CE_PIN);


	spiTransmitByte(SPI3_I2S3, 0x1F);
	delayCountingTo(10000);
	gpioPinSet(LCD_CE_PORT, LCD_CE_PIN);
	delayCountingTo(100000);
	gpioPinClear(LCD_CE_PORT, LCD_CE_PIN);

	spiTransmitByte(SPI3_I2S3, 0x05);
	delayCountingTo(10000);
	gpioPinSet(LCD_CE_PORT, LCD_CE_PIN);
	delayCountingTo(100000);
	gpioPinClear(LCD_CE_PORT, LCD_CE_PIN);

	spiTransmitByte(SPI3_I2S3, 0x07);
	delayCountingTo(10000);
	gpioPinSet(LCD_CE_PORT, LCD_CE_PIN);


	while (1) {

	}

	return 0;
}


/*================= Function definitions ==================*/
void delayCountingTo(uint32_t count) {

	volatile uint32_t i;
	for (i = 0; i < count; i++);
}

