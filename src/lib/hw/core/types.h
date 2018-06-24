/*
 * types.h
 *
 *  Created on: Jun 20, 2018
 *      Author: ahmed
 */

#ifndef LIB_HW_CORE_TYPES_H_
#define LIB_HW_CORE_TYPES_H_


#include <stdint.h>



#define __IO	volatile


typedef void(*voidPFn_t)(void);

typedef enum {
	ZERO	= 0,
	OFF		= 0,
	LOW		= 0,
	ONE		= 1,
	ON		= 1,
	HIGH	= 1
} bit_t;

#endif /* LIB_HW_CORE_TYPES_H_ */
