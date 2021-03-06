/*
 * light weight WS2812 lib - ARM Cortex M0/M0+ version
 *
 * Created: 07.07.2013
 *  Author: Tim (cpldcpu@gmail.com)
 */

#ifndef LIGHT_WS2812_H_
#define LIGHT_WS2812_H_
#include <stdint.h>
#include "stm32f4xx.h"

///////////////////////////////////////////////////////////////////////
// User defined area: CPU specific CMSIS include
///////////////////////////////////////////////////////////////////////

//#include "LPC8XX.h"			// Change this to the include for your MCU


///////////////////////////////////////////////////////////////////////
// User defined area: Define I/O pin
///////////////////////////////////////////////////////////////////////

// Data port and pin definition for your CPU. Depending on the way
// port access is implemented in your Cortex CPU, the set and clr
// mask and addresses may be the same. This example is for the
// NXP LPC81X
#ifdef  USE_HAL_DRIVER
#define PORTB_SET ((uint32_t*)&GPIOB->BSRR)
#define PORTB_CLR ((uint32_t*)(&GPIOB->BSRR + 2))
#else
#define PORTB_SET ((uint32_t*)&GPIOB->BSRRL)
#define PORTB_CLR ((uint32_t*)&GPIOB->BSRRH)
#endif

#define ws2812_port_set PORTB_SET	// Address of the data port register to set the pin
#define ws2812_port_clr	PORTB_CLR	// Address of the data port register to clear the pin

#define ws2812_mask_set  (1<<0)		// Bitmask to set the data out pin
#define ws2812_mask_clr  (1<<0)		// Bitmask to clear the data out pin

#define ws2812_port_set1 PORTB_SET	// Address of the data port register to set the pin
#define ws2812_port_clr1 PORTB_CLR	// Address of the data port register to clear the pin

#define ws2812_mask_set1  (1<<1)		// Bitmask to set the data out pin
#define ws2812_mask_clr1  (1<<1)		// Bitmask to clear the data out pin

#define ws2812_port_set2 PORTB_SET	// Address of the data port register to set the pin
#define ws2812_port_clr2 PORTB_CLR	// Address of the data port register to clear the pin

#define ws2812_mask_set2  (1<<2)		// Bitmask to set the data out pin
#define ws2812_mask_clr2  (1<<2)		// Bitmask to clear the data out pin

#define ws2812_port_set3 PORTB_SET	// Address of the data port register to set the pin
#define ws2812_port_clr3 PORTB_CLR	// Address of the data port register to clear the pin

#define ws2812_mask_set3  (1<<3)		// Bitmask to set the data out pin
#define ws2812_mask_clr3  (1<<3)		// Bitmask to clear the data out pin

#define ws2812_port_set4 PORTB_SET	// Address of the data port register to set the pin
#define ws2812_port_clr4 PORTB_CLR	// Address of the data port register to clear the pin

#define ws2812_mask_set4  (1<<4)		// Bitmask to set the data out pin
#define ws2812_mask_clr4  (1<<4)		// Bitmask to clear the data out pin

#define ws2812_port_set5 PORTB_SET	// Address of the data port register to set the pin
#define ws2812_port_clr5 PORTB_CLR	// Address of the data port register to clear the pin

#define ws2812_mask_set5  (1<<5)		// Bitmask to set the data out pin
#define ws2812_mask_clr5  (1<<5)		// Bitmask to clear the data out pin

///////////////////////////////////////////////////////////////////////
// User defined area: Define CPU clock speed
//
// The current implementation of the sendarray routine uses cycle accurate
// active waiting. The routine is automatically adjusted according to
// the clockspeed defined below. Only values between 8 Mhz and 60 Mhz
// are allowable.
//
// Important: The timing calculation assumes that there are no waitstates
// for code memory access. If there are waitstates you may have to reduce
// the value below until you get acceptable timing. It is highly recommended
// to use this library only on devices without flash waitstates and
// predictable code execution timing.
//
///////////////////////////////////////////////////////////////////////

#define ws2812_cpuclk 168000000

///////////////////////////////////////////////////////////////////////
// End user defined area
///////////////////////////////////////////////////////////////////////

//#if (ws2812_cpuclk<8000000)
//	#error "Minimum clockspeed for ARM ws2812 library is 8 Mhz!"
//#endif

//#if (ws2812_cpuclk>60000000)
//	#error "Maximum clockspeed for ARM ws2812 library is 60 Mhz!"
//#endif


///////////////////////////////////////////////////////////////////////
// Main function call
//
// Call with address to led color array (order is Green-Red-Blue)
// Numer of bytes to be transmitted is leds*3
///////////////////////////////////////////////////////////////////////
void ws2812_sendarray_armcc(uint8_t *data,int datlen);
void ws2812_config_gpio(void);


#endif /* LIGHT_WS2812_H_ */
