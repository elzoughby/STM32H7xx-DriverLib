/*==============================================================================

 Name        : spi.c
 Version     : 1.0.0
 Description : Serial Peripheral Interface driver for STM32H7xx MCUs

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


#include "spi.h"
#include "gpio.h"


static void spiClockEnable(spiInterface_t spiInterface) {

	if (spiInterface == SPI1_I2S1)
		RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	else if (spiInterface == SPI2_I2S2)
		RCC->APB1LENR |= RCC_APB1LENR_SPI2EN;
	else if (spiInterface == SPI3_I2S3)
		RCC->APB1LENR |= RCC_APB1LENR_SPI3EN;
	else if (spiInterface == SPI4)
		RCC->APB2ENR |= RCC_APB2ENR_SPI4EN;
	else if (spiInterface == SPI5)
		RCC->APB2ENR |= RCC_APB2ENR_SPI5EN;
	else if (spiInterface == SPI6)
		RCC->APB4ENR |= RCC_APB4ENR_SPI6EN;

}

/* initialize the SPI configuration registers */
void spiInit(spiInterface_t spiInterface, spiConfig_t* spiConfig) {

	/* disable SPI */
	spiDisable(spiInterface);

	/* enable clock for SPI interface port */
	spiClockEnable(spiInterface);

	/* set GPIO alternative function as SPI */
	//spiInterface->CFG2 |= (1U << 31);

	/* initialize SPI */
	spiInterface->CFG2 |= (spiConfig->mode << 22);
	spiInterface->CFG1 |= (spiConfig->clockDivider << 28);
	if (spiConfig->crcConfig == SPI_CRC_DISABLE) {
		spiInterface->CFG1 &= ~(0U << 22);
	} else {
		spiInterface->CFG1 |= (1U << 22);
		spiInterface->CFG1 |= (spiConfig->crcConfig << 16);
	}
	spiInterface->CFG1 |= (spiConfig->fifoLevel << 5);
	spiInterface->CFG1 |= (spiConfig->frameSize << 0);
	spiInterface->CFG2 |= (spiConfig->clkMode << 24);
	spiInterface->CFG2 |= (spiConfig->bitOrder << 23);
	spiInterface->CFG2 |= (spiConfig->protocol << 19);
	spiInterface->CFG2 |= (spiConfig->commMode << 17);

	/* enable SPI */
	spiEnable(spiInterface);

}

/* enable the SPI Interface in control register */
void spiEnable(spiInterface_t spiInterface) {

	spiInterface->CR1 |= (1U << 0);

}

/* disable the SPI Interface in control register */
void spiDisable(spiInterface_t spiInterface) {

	spiInterface->CR1 &= ~(1U << 0);

}


void spiTransmitByte(spiInterface_t spiInterface, uint8_t txData) {

	spiInterface->TXDR = txData;

}

void spiTransmitHalfWord(spiInterface_t spiInterface, uint16_t txData) {

	spiInterface->TXDR = txData;

}

void spiTransmitWord(spiInterface_t spiInterface, uint32_t txData) {

	spiInterface->TXDR = txData;

}

void spiTransmit(spiInterface_t spiInterface, void* txBuffer, uint32_t bufferWidth, uint32_t bufferSize) {

	uint32_t i, alignment = bufferWidth / 8;

	for(i = 0; i < bufferSize; i += alignment) {
		if (bufferWidth == 8)
			spiInterface->TXDR =  *((uint8_t*)(txBuffer + i));
		else if (bufferWidth == 16)
			spiInterface->TXDR =  *((uint16_t*)(txBuffer + i));
		else if (bufferWidth  == 32)
			spiInterface->TXDR =  *((uint32_t*)(txBuffer + i));
	}

}

uint8_t spiReceiveByte(spiInterface_t spiInterface) {

	return spiInterface->RXDR;

}

uint16_t spiReceiveHalfWord(spiInterface_t spiInterface) {

	return spiInterface->RXDR;

}

uint32_t spiReceiveWord(spiInterface_t spiInterface) {

	return spiInterface->RXDR;

}

void* spiReceive(spiInterface_t spiInterface, void* rxBuffer, uint32_t bufferWidth, uint32_t bufferSize) {

	uint32_t i, alignment = bufferWidth / 8;

	for(i = 0; i < bufferSize; i += alignment) {
		if (bufferWidth == 8)
			*((uint8_t*)(rxBuffer + i)) = spiInterface->RXDR;
		else if (bufferWidth == 16)
			*((uint16_t*)(rxBuffer + i)) = spiInterface->RXDR;
		else if (bufferWidth  == 32)
			*((uint32_t*)(rxBuffer + i)) = spiInterface->RXDR;
	}

	return rxBuffer;
}


