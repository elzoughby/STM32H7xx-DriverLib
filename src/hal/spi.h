/*==============================================================================

 Name        : spi.h
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

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, ExPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

===============================================================================*/


#ifndef HAL_SPI_H_
#define HAL_SPI_H_


#include "hw/stm32h7xx.h"



typedef enum {
	SPI_MODE_MASTER	= 0x00,
	SPI_MODE_SLAVE	= 0x01
} spiMode_t;

typedef enum {
	SPI_CLK_DIV_BY_2	= 0x00,
	SPI_CLK_DIV_BY_4	= 0x01,
	SPI_CLK_DIV_BY_8	= 0x02,
	SPI_CLK_DIV_BY_16	= 0x03,
	SPI_CLK_DIV_BY_32	= 0x04,
	SPI_CLK_DIV_BY_64	= 0x05,
	SPI_CLK_DIV_BY_128	= 0x06,
	SPI_CLK_DIV_BY_256	= 0x07,
} spiClkDiv_t;

typedef enum {
	SPI_CRC_DISABLE		= 0x00,
	SPI_CRC_4BITS		= 0x03,
	SPI_CRC_5BITS		= 0x04,
	SPI_CRC_6BITS		= 0x05,
	SPI_CRC_7BITS		= 0x06,
	SPI_CRC_8BITS		= 0x07,
	SPI_CRC_9BITS		= 0x08,
	SPI_CRC_10BITS		= 0x09,
	SPI_CRC_11BITS		= 0x0A,
	SPI_CRC_12BITS		= 0x0B,
	SPI_CRC_13BITS		= 0x0C,
	SPI_CRC_14BITS		= 0x0D,
	SPI_CRC_15BITS		= 0x0E,
	SPI_CRC_16BITS		= 0x0F,
	SPI_CRC_17BITS		= 0x10,
	SPI_CRC_18BITS		= 0x11,
	SPI_CRC_19BITS		= 0x12,
	SPI_CRC_20BITS		= 0x13,
	SPI_CRC_21BITS		= 0x14,
	SPI_CRC_22BITS		= 0x15,
	SPI_CRC_23BITS		= 0x16,
	SPI_CRC_24BITS		= 0x17,
	SPI_CRC_25BITS		= 0x18,
	SPI_CRC_26BITS		= 0x19,
	SPI_CRC_27BITS		= 0x1A,
	SPI_CRC_28BITS		= 0x1B,
	SPI_CRC_29BITS		= 0x1C,
	SPI_CRC_30BITS		= 0x1D,
	SPI_CRC_31BITS		= 0x1E,
	SPI_CRC_32BITS		= 0x1F,
} spiCRC_t;

typedef enum {
	SPI_FIFO_1DATA		= 0x00,
	SPI_FIFO_2DATA		= 0x01,
	SPI_FIFO_3DATA		= 0x02,
	SPI_FIFO_4DATA		= 0x03,
	SPI_FIFO_5DATA		= 0x04,
	SPI_FIFO_6DATA		= 0x05,
	SPI_FIFO_7DATA		= 0x06,
	SPI_FIFO_8DATA		= 0x07,
	SPI_FIFO_9DATA		= 0x08,
	SPI_FIFO_10DATA		= 0x09,
	SPI_FIFO_11DATA		= 0x0A,
	SPI_FIFO_12DATA		= 0x0B,
	SPI_FIFO_13DATA		= 0x0C,
	SPI_FIFO_14DATA		= 0x0D,
	SPI_FIFO_15DATA		= 0x0E,
	SPI_FIFO_16DATA		= 0x0F,
} spiFIFOLevel_t;

typedef enum {
	SPI_FRAME_4BITS		= 0x03,
	SPI_FRAME_5BITS		= 0x04,
	SPI_FRAME_6BITS		= 0x05,
	SPI_FRAME_7BITS		= 0x06,
	SPI_FRAME_8BITS		= 0x07,
	SPI_FRAME_9BITS		= 0x08,
	SPI_FRAME_10BITS	= 0x09,
	SPI_FRAME_11BITS	= 0x0A,
	SPI_FRAME_12BITS	= 0x0B,
	SPI_FRAME_13BITS	= 0x0C,
	SPI_FRAME_14BITS	= 0x0D,
	SPI_FRAME_15BITS	= 0x0E,
	SPI_FRAME_16BITS	= 0x0F,
	SPI_FRAME_17BITS	= 0x10,
	SPI_FRAME_18BITS	= 0x11,
	SPI_FRAME_19BITS	= 0x12,
	SPI_FRAME_20BITS	= 0x13,
	SPI_FRAME_21BITS	= 0x14,
	SPI_FRAME_22BITS	= 0x15,
	SPI_FRAME_23BITS	= 0x16,
	SPI_FRAME_24BITS	= 0x17,
	SPI_FRAME_25BITS	= 0x18,
	SPI_FRAME_26BITS	= 0x19,
	SPI_FRAME_27BITS	= 0x1A,
	SPI_FRAME_28BITS	= 0x1B,
	SPI_FRAME_29BITS	= 0x1C,
	SPI_FRAME_30BITS	= 0x1D,
	SPI_FRAME_31BITS	= 0x1E,
	SPI_FRAME_32BITS	= 0x1F,
} spiFrameSize_t;

typedef enum {
	SPI_CLK_MODE0 = 0x00,
	SPI_CLK_MODE1 = 0x01,
	SPI_CLK_MODE2 = 0x02,
	SPI_CLK_MODE3 = 0x03
} spiClkMode_t;

typedef enum {
	SPI_MSB_FIRST	= 0x00,
	SPI_LSB_FIRST	= 0x01
} spiBitOrder_t;

typedef enum {
	SPI_PROTOCOL_MOTOROLA	= 0x00,
	SPI_PROTOCOL_TI			= 0x01
} spiProtocol_t;

typedef enum {
	SPI_COMM_FULL_DUPLEX			= 0x00,
	SPI_COMM_SIMPLEX_TRANSMITTER	= 0x01,
	SPI_COMM_SIMPLEX_RECEIVER		= 0x02,
	SPI_COMM_HALF_DUPLEX			= 0x03
} spiCommMode_t;


typedef struct {
	spiMode_t		mode;
	spiClkDiv_t		clockDivider;
	spiCRC_t		crcConfig;
	spiFIFOLevel_t	fifoLevel;
	spiFrameSize_t	frameSize;
	spiClkMode_t	clkMode;
	spiBitOrder_t	bitOrder;
	spiProtocol_t	protocol;
	spiCommMode_t	commMode;
} spiConfig_t;


/* initialize the SPI configuration registers */
void spiInit(spiInterface_t spiInterface, spiConfig_t* spiConfig);

/* enable the SPI Interface in control register */
void spiEnable(spiInterface_t spiInterface);

/* disable the SPI Interface in control register */
void spiDisable(spiInterface_t spiInterface);


void spiTransmitByte(spiInterface_t spiInterface, uint8_t txData);

void spiTransmitHalfWord(spiInterface_t spiInterface, uint16_t txData);

void spiTransmitWord(spiInterface_t spiInterface, uint32_t txData);

void spiTransmit(spiInterface_t spiInterface, void* txBuffer, uint32_t bufferWidth, uint32_t bufferSize);

uint8_t spiReceiveByte(spiInterface_t spiInterface);

uint16_t spiReceiveHalfWord(spiInterface_t spiInterface);

uint32_t spiReceiveWord(spiInterface_t spiInterface);

void* spiReceive(spiInterface_t spiInterface, void* rxBuffer, uint32_t bufferWidth, uint32_t bufferSize);


#endif /* HAL_SPI_H_ */
