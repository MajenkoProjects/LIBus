/************************************************************************/
/*																		*/
/*	Board_Defs.h --	Board Customization for Digilent chipKIT Uno32		*/
/*																		*/
/************************************************************************/
/*	Author: Gene Apperson												*/
/*	Copyright 2011, Digilent. All rights reserved						*/
/************************************************************************/
/*  File Description:													*/
/*																		*/
/* This file contains the board specific declartions and data structure	*/
/* to customize the chipKIT MPIDE for use with the Digilent chipKIT		*/
/* Uno32 board.															*/
/*																		*/
/* This code is based on earlier work:									*/
/*		Copyright (c) 2010, 2011 by Mark Sproul							*/
/*		Copyright (c) 2005, 2006 by David A. Mellis						*/
/*																		*/
/************************************************************************/
/*  Revision History:													*/
/*																		*/
/*	10/06/2011(GeneA): Created											*/
/*	11/28/2011(GeneA): Moved data definitions and configuration			*/
/*		functions to Board_Data.c										*/
/*	11/29/2011(GeneA): Moved int priority definitions to System_Defs.h	*/
/*	Feb 17, 2012	<KeithV> Added PPS support for MZ devices           */
/*																		*/
/************************************************************************/
//*	This library is free software; you can redistribute it and/or
//*	modify it under the terms of the GNU Lesser General Public
//*	License as published by the Free Software Foundation; either
//*	version 2.1 of the License, or (at your option) any later version.
//*	
//*	This library is distributed in the hope that it will be useful,
//*	but WITHOUT ANY WARRANTY; without even the implied warranty of
//*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*	Lesser General Public License for more details.
//*	
//*	You should have received a copy of the GNU Lesser General
//*	Public License along with this library; if not, write to the
//*	Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*	Boston, MA  02111-1307  USA
/************************************************************************/

#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>

#define _USB

//    #define  _OCMP1_BASE_ADDRESS ((uint32_t) &OC1CON)
    #define  _TIMER_1_IRQ _TIMER_1_VECTOR

/* ------------------------------------------------------------ */
/*				Public Board Declarations						*/
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to periperhals on the board generically.
*/

#define	_BOARD_NAME_	"Modular FX Base Board"

/* Define the Microcontroller peripherals available on the board.
*/
#define	NUM_DIGITAL_PINS	20
#define	NUM_ANALOG_PINS		0
#define NUM_OC_PINS			0
#define	NUM_IC_PINS			0
#define	NUM_TCK_PINS		0
#define	NUM_INT_PINS		4

#define	NUM_SERIAL_PORTS	1   
#define	NUM_SPI_PORTS		1   
#define	NUM_I2C_PORTS		1   

#define NUM_DSPI_PORTS		1
#define	NUM_DTWI_PORTS		1

#define _LIBUS_CAN_MASTER
#define LIBUSM_RX            7
#define LIBUSM_TX            6
#define LIBUSM_IRQ           _UART2_FAULT_VECTOR
#define LIBUSM_VECTOR        _UART2_FAULT_VECTOR
#define LIBUSM_TX_PPS        PPS_OUT_U2TX
#define LIBUSM_RX_PPS        PPS_IN_U2RX
#define LIBUSM_MODE          U2MODEbits
#define LIBUSM_STA           U2STAbits
#define LIBUSM_BRG           U2BRG
#define LIBUSM_RXREG         U2RXREG
#define LIBUSM_TXREG         U2TXREG

//#define _LIBUS_CAN_SLAVE
//#define LIBUS_RX            7
//#define LIBUS_TX            6
//#define LIBUS_IRQ           _UART6_FAULT_VECTOR
//#define LIBUS_VECTOR        _UART6_FAULT_VECTOR
//#define LIBUS_TX_PPS        PPS_OUT_U6TX
//#define LIBUS_RX_PPS        PPS_IN_U6RX
//#define LIBUS_MODE          U6MODEbits
//#define LIBUS_STA           U6STAbits
//#define LIBUS_BRG           U6BRG
//#define LIBUS_RXREG         U6RXREG
//#define LIBUS_TXREG         U6TXREG


/* Define I/O devices on the board.
*/
#define	NUM_LED				0
#define NUM_BTN				0
#define	NUM_SWT				0
#define NUM_SERVO			0

/* Define the number of pins including extended i/o pins.
** These are pins that are not native to the microcontroller, such
** as implemented via an i/o expander or external A/D or D/A.
** This board doesn't have any.
*/
#define	NUM_DIGITAL_PINS_EXTENDED	NUM_DIGITAL_PINS
#define	NUM_ANALOG_PINS_EXTENDED	NUM_ANALOG_PINS

#define PIN_IO0         0
#define PIN_IO1         1
#define PIN_IO2         2
#define PIN_IO3         3
#define PIN_IO4         4
#define PIN_IO5         5
#define PIN_TX          6
#define PIN_RX          7
#define PIN_SCL         8
#define PIN_SDA         9
#define PIN_SCK         10
#define PIN_SDO         11
#define PIN_SDI         12
#define PIN_AMP_EN      13
#define PIN_SD_CS       14
#define PIN_SD_EN       15



#define	PIN_INT0	255
#define	PIN_INT1	0
#define PIN_INT2	5
#define	PIN_INT3	2
#define	PIN_INT4	1

#define PIN_AMP     15

#define PIN_BCLK    18
#define PIN_MCLK    17
#define PIN_DO      16
#define PIN_WCLK    19


/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h
*/
static const uint8_t SS   = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 12;
static const uint8_t SCK  = 13;

/* The Digilent DSPI library uses these ports.
*/
#define	PIN_DSPI0_SS	10

#define	PIN_CN0		0
#define	PIN_CN1		1
#define	PIN_CN2		2      
#define	PIN_CN3		3      
#define	PIN_CN4		4
#define	PIN_CN5		5
#define	PIN_CN6		6
#define	PIN_CN7		7
#define	PIN_CN8		8
#define	PIN_CN9		9
#define	PIN_CN10	10
#define	PIN_CN11	11
#define	PIN_CN12	12
#define	PIN_CN13	13
#define	PIN_CN14	14      
#define	PIN_CN15	15
#define	PIN_CN16	16
#define	PIN_CN17	17      
#define	PIN_CN18	18      
#define	PIN_CN19	19
#define	PIN_CN20	20
#define	PIN_CN21	21
#define	PIN_CN22	22
#define	PIN_CN23	23      
#define	PIN_CN24	24
#define	PIN_CN25	25
#define	PIN_CN26	26      
#define	PIN_CN27	27      
#define	PIN_CN28	28      
#define	PIN_CN29	29      
#define	PIN_CN30	30
#define	PIN_CN31	31
#define	PIN_CN32	32
#define	PIN_CN33	33
#define	PIN_CN34	34      
#define	PIN_CN35	35
#define	PIN_CN36	36
#define	PIN_CN37	37      
#define	PIN_CN38	38      
#define	PIN_CN39	39
#define	PIN_CN40	40
#define	PIN_CN41	41

/* ------------------------------------------------------------ */
/*					Pin Mapping Macros							*/
/* ------------------------------------------------------------ */
/* This section contains the definitions for pin mapping macros that
** are being redefined for this board variant.
*/

// NUM_ANALOG_PINS == 14, the first analog pin as represented as a digital pin is also 14
// if the analog pin is less than 14, then you can put in the analog number 
// if the pin is greater than 14, it must be a digital pin number.

#undef digitalPinToAnalog
//#define	digitalPinToAnalog(P) (digital_pin_to_analog_PGM[P])
#define digitalPinToAnalog(P) (((P) < NUM_ANALOG_PINS) ? (P) : (digital_pin_to_analog_PGM[P]))

#undef analogInPinToChannel
#define analogInPinToChannel(P) (analog_pin_to_channel_PGM[P])


/* ------------------------------------------------------------ */
/*					Data Declarations							*/
/* ------------------------------------------------------------ */

/* The following declare externals to access the pin mapping
** tables. These tables are defined in Board_Data.c.
*/

#if !defined(OPT_BOARD_DATA)

extern const uint32_t	port_to_tris_PGM[];
extern const uint8_t	digital_pin_to_port_PGM[];
extern const uint16_t	digital_pin_to_bit_mask_PGM[];
extern const uint16_t	digital_pin_to_timer_PGM[];

extern const uint8_t	output_compare_to_digital_pin_PGM[];
extern const uint8_t	external_int_to_digital_pin_PGM[];

extern const uint8_t	analog_pin_to_channel_PGM[];
extern const uint8_t 	digital_pin_to_analog_PGM[];

extern const uint8_t	digital_pin_to_pps_out_PGM[];
extern const uint8_t	digital_pin_to_pps_in_PGM[];

#endif

/* ------------------------------------------------------------ */
/*				Internal Declarations							*/
/* ------------------------------------------------------------ */
/* The following declarations are used to map peripherals for	*/
/* the core and libraries and to provide configuration options	*/
/* for the core. They are not normally needed by a user sketch.	*/
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_INTERNAL)

/* ------------------------------------------------------------ */
/*				Core Configuration Declarations					*/
/* ------------------------------------------------------------ */
/*																*/
/* These are conditional compilation switches that control the	*/
/* board core configuration functions. These functions provide	*/
/* hooks that can call from some of the core functions into		*/
/* functions defined below that can be used to extend or		*/
/* replace the default behavior of the core function. To use	*/
/* this, enter the appropriate code into the appropriate		*/
/* function skeleton below and then set the appropriate switch	*/
/* value to 1. This will cause the configuration function to be	*/
/* compiled into the build and will cause the code to call the	*/
/* hook function to be compiled into the core function.			*/
/*																*/
/* ------------------------------------------------------------ */

#define	OPT_BOARD_INIT			0	//board needs no special init code
#define	OPT_BOARD_DIGITAL_IO	0	//board does not extend digital i/o functions
#define	OPT_BOARD_ANALOG_READ	0	//board does not extend analogRead
#define	OPT_BOARD_ANALOG_WRITE	0	//board does not extend analogWrite

/* ------------------------------------------------------------ */
/*					Serial Port Declarations					*/
/* ------------------------------------------------------------ */

/* Serial port 0 uses UART1
*/
#define	_SER0_BASE      _UART2_BASE_ADDRESS
#define	_SER0_IRQ       _UART2_FAULT_VECTOR
#define	_SER0_VECTOR    _UART2_FAULT_VECTOR
#define	_SER0_IPL_ISR   IPL2SRS
#define	_SER0_IPL       2
#define	_SER0_SPL       0
#define _SER0_TX_OUT    PPS_OUT_U2TX 
#define _SER0_TX_PIN    6
#define _SER0_RX_IN     PPS_IN_U2RX 
#define _SER0_RX_PIN    7       


/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

/* The Digilent DSPI and standard SPI libraries uses these ports.
*/

// Expansion Port
#define	_DSPI0_BASE			_SPI3_BASE_ADDRESS
#define	_DSPI0_ERR_IRQ		_SPI3_FAULT_VECTOR
#define	_DSPI0_RX_IRQ		_SPI3_RX_VECTOR
#define	_DSPI0_TX_IRQ		_SPI3_TX_VECTOR
#define	_DSPI0_VECTOR		_SPI3_FAULT_VECTOR
#define _DSPI0_IPL_ISR		IPL3SRS
#define	_DSPI0_IPL			3
#define	_DSPI0_SPL			0

#define _DSPI0_MISO_IN		PPS_IN_SDI3
#define _DSPI0_MISO_PIN		PIN_SDI
#define _DSPI0_MOSI_OUT		PPS_OUT_SDO3
#define _DSPI0_MOSI_PIN		PIN_SDO


/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

// Off-board I2C

#define	_DTWI0_BASE		_I2C1_BASE_ADDRESS
#define	_DTWI0_BUS_IRQ	_I2C1_BUS_VECTOR
#define	_DTWI0_VECTOR	_I2C1_BUS_VECTOR
#define	_DTWI0_IPL_ISR	IPL3SRS 
#define	_DTWI0_IPL		3
#define	_DTWI0_SPL		0
#define _DTWI0_SCL_PIN  PIN_SCL
#define _DTWI0_SDA_PIN  PIN_SDA

/* ------------------------------------------------------------ */
/*  On MZ parts, ports are defined                              */
/* ------------------------------------------------------------ */

#define _PORTA
#define _PORTB
#define _PORTC
#define _PORTD
#define _PORTE
#define _PORTF
#define _PORTG

/* ------------------------------------------------------------ */
/*  JTAG Support, set to 1 if you want JTAG enabled             */
/*  otherwise JTAG will be disabled                             */
/* ------------------------------------------------------------ */
#define _JTAG 0

/* ------------------------------------------------------------ */

#endif	// OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */
#define ADCRANGE        4096ul              // analog read will return a max number of ADCRANGE-1
#define ADCTADFREQ      25000000ul          // How fast to run the TAD ADC clock
#define ADCTADSH        68ul                // How many TADs the Sample and Hold will charge
#define __ALT_ADC_IMPL__
extern void initADC(void);
extern int convertADC(uint8_t channelNumber);

/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*					Defines for the On Board uSD				*/
/* ------------------------------------------------------------ */

#define _uSD_SPI_CONFIG_

#define SD_CS_PIN 10

#define DefineSDSPI(spi) DSPI0 spi
#define DefineDSDVOL(vol, spi) DSDVOL vol(spi, 10)     // Create an DSDVOL object

/* ------------------------------------------------------------ */
/*					Defines for the On Board MRF24				*/
/* ------------------------------------------------------------ */



#endif	// BOARD_DEFS_H

/************************************************************************/
