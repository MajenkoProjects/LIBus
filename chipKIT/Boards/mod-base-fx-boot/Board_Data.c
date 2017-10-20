/************************************************************************/
/*                                                                      */
/*    Board_Data.c -- Board Customization Data for Digilent chipKIT WF32*/
/*                                                                      */
/************************************************************************/
/*    Author: Gene Apperson                                             */
/*    Copyright 2011, Digilent. All rights reserved                     */
/************************************************************************/
/*  File Description:                                                   */
/*                                                                      */
/* This file contains the board specific declartions and data structure */
/* to customize the chipKIT MPIDE for use with the Digilent chipKIT     */
/* Uno32 board.                                                         */
/*                                                                      */
/* This code is based on earlier work:                                  */
/*        Copyright (c) 2010, 2011 by Mark Sproul                       */
/*        Copyright (c) 2005, 2006 by David A. Mellis                   */
/*                                                                       */
/************************************************************************/
/*  Revision History:                                                   */
/*                                                                      */
/*    11/28/2011(GeneA): Created by splitting data out of Board_Defs.h  */
//*	Feb 17, 2012	<KeithV> Added PPS support for MZ devices
/*                                                                      */
/************************************************************************/
//*    This library is free software; you can redistribute it and/or
//*    modify it under the terms of the GNU Lesser General Public
//*    License as published by the Free Software Foundation; either
//*    version 2.1 of the License, or (at your option) any later version.
//*    
//*    This library is distributed in the hope that it will be useful,
//*    but WITHOUT ANY WARRANTY; without even the implied warranty of
//*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*    Lesser General Public License for more details.
//*    
//*    You should have received a copy of the GNU Lesser General
//*    Public License along with this library; if not, write to the
//*    Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*    Boston, MA  02111-1307  USA
/************************************************************************/

#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*                    Data Tables                               */
/* ------------------------------------------------------------ */
/* The following declarations define data used in pin mapping.  */
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_DATA)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t port_to_tris_PGM[] = {
    NOT_A_PORT,                //index value 0 is not used

//#if defined(_PORTA)
//    (uint32_t)&TRISA,
//#else
    NOT_A_PORT,
//#endif

#if defined(_PORTB)
    (uint32_t)&TRISB,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTC)
    (uint32_t)&TRISC,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTD)
    (uint32_t)&TRISD,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTE)
    (uint32_t)&TRISE,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTF)
    (uint32_t)&TRISF,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTG)
    (uint32_t)&TRISG,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTH)
    (uint32_t)&TRISH,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTJ)
    (uint32_t)&TRISJ,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTK)
    (uint32_t)&TRISK,
#else
    NOT_A_PORT,
#endif

    NOT_A_PORT,
};

/* ------------------------------------------------------------ */
/* This table is used to map the digital pin number to the port
** containing that pin.
*/
const uint8_t digital_pin_to_port_PGM[] = {
    // IO
    _IOPORT_PD,         //  0   RD04    IO0
    _IOPORT_PD,         //  1   RD05    IO1
    _IOPORT_PF,         //  2   RF00    IO2
    _IOPORT_PF,         //  3   RF01    IO3
    _IOPORT_PE,         //  4   RE01    IO4

    // Expansion Port
    _IOPORT_PB,         //  5   RB04    GPIO0
    _IOPORT_PB,         //  6   RB03    GPIO1
    _IOPORT_PB,         //  7   RB02    GPIO2
    _IOPORT_PB,         //  8   RB01    GPIO3
    _IOPORT_PB,         //  9   RB00    GPIO4
    _IOPORT_PB,         //  10  RB06    TX
    _IOPORT_PB,         //  11  RB07    RX
    _IOPORT_PD,         //  12  RD03    SCL
    _IOPORT_PD,         //  13  RD02    SDA
    _IOPORT_PD,         //  14  RD01    SCK
    _IOPORT_PC,         //  15  RC14    SDO
    _IOPORT_PF,         //  16  RF04    SDI

    // Audio I2S
    _IOPORT_PE,         //  17  RE07    AMP_EN
    _IOPORT_PG,         //  18  RG06    BCLK
    _IOPORT_PG,         //  19  RG07    MCLK
    _IOPORT_PG,         //  20  RG08    DO
    _IOPORT_PG,         //  21  RG09    WCLK

    // SD Card SPI
    _IOPORT_PB,         //  22  RB10    SDI
    _IOPORT_PB,         //  23  RB09    SDO
    _IOPORT_PB,         //  24  RB14    SCK
    _IOPORT_PB,         //  25  RB08    CS
    _IOPORT_PC,         //  26  RC13    SD_EN

    // Internal I2C
    _IOPORT_PD,         //  27  RD10    SCL
    _IOPORT_PD,         //  28  RD09    SDA
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t digital_pin_to_bit_mask_PGM[] = 
{
    // IO
    _BV(4),             //  0   RD04    IO0
    _BV(5),             //  1   RD05    IO1
    _BV(0),             //  2   RF00    IO2
    _BV(1),             //  3   RF01    IO3
    _BV(1),             //  4   RE01    IO4

    // Expansion Port
    _BV(4),             //  5   RB04    GPIO0
    _BV(3),             //  6   RB03    GPIO1
    _BV(2),             //  7   RB02    GPIO2
    _BV(1),             //  8   RB01    GPIO3
    _BV(0),             //  9   RB00    GPIO4
    _BV(6),             //  10  RB06    TX
    _BV(7),             //  11  RB07    RX
    _BV(3),             //  12  RD03    SCL
    _BV(2),             //  13  RD02    SDA
    _BV(1),             //  14  RD01    SCK
    _BV(14),            //  15  RC14    SDO
    _BV(4),             //  16  RF04    SDI

    // Audio I2S
    _BV(7),             //  17  RE07    AMP_EN
    _BV(6),             //  18  RG06    BCLK
    _BV(7),             //  19  RG07    MCLK
    _BV(8),             //  20  RG08    DO
    _BV(9),             //  21  RG09    WCLK

    // SD Card SPI
    _BV(10),            //  22  RB10    SDI
    _BV(9),             //  23  RB09    SDO
    _BV(14),            //  24  RB14    SCK
    _BV(8),             //  25  RB08    CS
    _BV(13),            //  26  RC13    SD_EN

    // Internal I2C
    _BV(10),            //  27  RD10    SCL
    _BV(9),             //  28  RD09    SDA
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t digital_pin_to_timer_PGM[] =
{
    // IO
    NOT_ON_TIMER,      //  0   RD04    IO0
    NOT_ON_TIMER,      //  1   RD05    IO1
    NOT_ON_TIMER,      //  2   RF00    IO2
    NOT_ON_TIMER,      //  3   RF01    IO3
    NOT_ON_TIMER,      //  4   RE01    IO4

    // Expansion Port
    NOT_ON_TIMER,      //  5   RB04    GPIO0
    NOT_ON_TIMER,      //  6   RB03    GPIO1
    NOT_ON_TIMER,      //  7   RB02    GPIO2
    NOT_ON_TIMER,      //  8   RB01    GPIO3
    NOT_ON_TIMER,      //  9   RB00    GPIO4
    NOT_ON_TIMER,      //  10  RB06    TX
    NOT_ON_TIMER,      //  11  RB07    RX
    NOT_ON_TIMER,      //  12  RD03    SCL
    NOT_ON_TIMER,      //  13  RD02    SDA
    NOT_ON_TIMER,      //  14  RD01    SCK
    NOT_ON_TIMER,      //  15  RC14    SDO
    NOT_ON_TIMER,      //  16  RF04    SDI

    // Audio I2S
    NOT_ON_TIMER,      //  17  RE07    AMP_EN
    NOT_ON_TIMER,      //  18  RG06    BCLK
    NOT_ON_TIMER,      //  19  RG07    MCLK
    NOT_ON_TIMER,      //  20  RG08    DO
    NOT_ON_TIMER,      //  21  RG09    WCLK

    // SD Card SPI
    NOT_ON_TIMER,      //  22  RB10    SDI
    NOT_ON_TIMER,      //  23  RB09    SDO
    NOT_ON_TIMER,      //  24  RB14    SCK
    NOT_ON_TIMER,      //  25  RB08    CS
    NOT_ON_TIMER,      //  26  RC13    SD_EN

    // Internal I2C
    NOT_ON_TIMER,      //  27  RD10    SCL
    NOT_ON_TIMER,      //  28  RD09    SDA
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** analog pin number.
*/
const uint8_t digital_pin_to_analog_PGM[] = {
    // IO
    NOT_ANALOG_PIN,    //  0   RD04    IO0
    NOT_ANALOG_PIN,    //  1   RD05    IO1
    NOT_ANALOG_PIN,    //  2   RF00    IO2
    NOT_ANALOG_PIN,    //  3   RF01    IO3
    NOT_ANALOG_PIN,    //  4   RE01    IO4

    // Expansion Port
    NOT_ANALOG_PIN,    //  5   RB04    GPIO0
    NOT_ANALOG_PIN,    //  6   RB03    GPIO1
    NOT_ANALOG_PIN,    //  7   RB02    GPIO2
    NOT_ANALOG_PIN,    //  8   RB01    GPIO3
    NOT_ANALOG_PIN,    //  9   RB00    GPIO4
    NOT_ANALOG_PIN,    //  10  RB06    TX
    NOT_ANALOG_PIN,    //  11  RB07    RX
    NOT_ANALOG_PIN,    //  12  RD03    SCL
    NOT_ANALOG_PIN,    //  13  RD02    SDA
    NOT_ANALOG_PIN,    //  14  RD01    SCK
    NOT_ANALOG_PIN,    //  15  RC14    SDO
    NOT_ANALOG_PIN,    //  16  RF04    SDI

    // Audio I2S
    NOT_ANALOG_PIN,    //  17  RE07    AMP_EN
    NOT_ANALOG_PIN,    //  18  RG06    BCLK
    NOT_ANALOG_PIN,    //  19  RG07    MCLK
    NOT_ANALOG_PIN,    //  20  RG08    DO
    NOT_ANALOG_PIN,    //  21  RG09    WCLK

    // SD Card SPI
    NOT_ANALOG_PIN,    //  22  RB10    SDI
    NOT_ANALOG_PIN,    //  23  RB09    SDO
    NOT_ANALOG_PIN,    //  24  RB14    SCK
    NOT_ANALOG_PIN,    //  25  RB08    CS
    NOT_ANALOG_PIN,    //  26  RC13    SD_EN

    // Internal I2C
    NOT_ANALOG_PIN,    //  27  RD10    SCL
    NOT_ANALOG_PIN,    //  28  RD09    SDA
};


/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
*/
const uint8_t analog_pin_to_channel_PGM[] =
{
                //*    chipKIT Pin        PIC32 Analog channel
    23,         //*    A0                       AN45
    34,         //*    A1                       AN49
    21,         //*    A2                       AN21
    10,         //*    A3                       AN10
    13,         //*    A4                       AN13
    12,         //*    A5                       AN12
    3,          //*    A6                       AN3
    2,          //*    A7                       AN2
    4,          //*    A8                       AN4
    1,          //*    A9                       AN1
    48,         //*    A10                      AN48
    0,          //*    A11                      AN00
    8,          //*    A12                      AN8
    7,          //*    A13                      AN7
};


/* ------------------------------------------------------------ */
/*                PPS Mappings                                    */
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** PPS register. This register is used to select the peripheral output
** connected to the pin. The register is set to 0 to disconnedt the
** pin from any peripheral so it can be used as GPIO.
** For PIC32MX1xx/2xx series devices, the PPS output select registers
** are arranged as a contiguous series of 32 bit registers. This table
** treats these registers as an array of DWORDs an stores the index
** to the register.
*/
const uint8_t digital_pin_to_pps_out_PGM[] = {
    // IO
    _PPS_OUT(_PPS_RPD4R),   //  0   RD04    IO0
    _PPS_OUT(_PPS_RPD5R),   //  1   RD05    IO1
    _PPS_OUT(_PPS_RPF0R),   //  2   RF00    IO2
    _PPS_OUT(_PPS_RPF1R),   //  3   RF01    IO3
    NOT_PPS_PIN,            //  4   RE01    IO4

    // Expansion Port
    NOT_PPS_PIN,            //  5   RB04    GPIO0
    _PPS_OUT(_PPS_RPB3R),   //  6   RB03    GPIO1
    _PPS_OUT(_PPS_RPB2R),   //  7   RB02    GPIO2
    _PPS_OUT(_PPS_RPB1R),   //  8   RB01    GPIO3
    _PPS_OUT(_PPS_RPB0R),   //  9   RB00    GPIO4
    _PPS_OUT(_PPS_RPB6R),   //  10  RB06    TX
    _PPS_OUT(_PPS_RPB7R),   //  11  RB07    RX
    _PPS_OUT(_PPS_RPD3R),   //  12  RD03    SCL
    _PPS_OUT(_PPS_RPD2R),   //  13  RD02    SDA
    _PPS_OUT(_PPS_RPD1R),   //  14  RD01    SCK
    _PPS_OUT(_PPS_RPC14R),  //  15  RC14    SDO
    _PPS_OUT(_PPS_RPF4R),   //  16  RF04    SDI

    // Audio I2S
    NOT_PPS_PIN,            //  17  RE07    AMP_EN
    _PPS_OUT(_PPS_RPG6R),   //  18  RG06    BCLK
    _PPS_OUT(_PPS_RPG7R),   //  19  RG07    MCLK
    _PPS_OUT(_PPS_RPG8R),   //  20  RG08    DO
    _PPS_OUT(_PPS_RPG9R),   //  21  RG09    WCLK

    // SD Card SPI
    _PPS_OUT(_PPS_RPB10R),  //  22  RB10    SDI
    _PPS_OUT(_PPS_RPB9R),   //  23  RB09    SDO
    _PPS_OUT(_PPS_RPB14R),  //  24  RB14    SCK
    _PPS_OUT(_PPS_RPB8R),   //  25  RB08    CS
    _PPS_OUT(_PPS_RPC13R),  //  26  RC13    SD_EN

    // Internal I2C
    _PPS_OUT(_PPS_RPD10R),  //  27  RD10    SCL
    _PPS_OUT(_PPS_RPD9R),   //  28  RD09    SDA
 };

/* ------------------------------------------------------------ */
/* This table maps from the digital pin number to the value to be
** loaded into a PPS input select register to select that pin.
** It also maps from digital pin number to input/output pin set to 
** which the pin belongs. The set mask is in the high four bits,
** the select value is in the low four bits.
** Note: if the PIC32 device has more than four pin sets, or more than
** 16 pin mapping choices per input function, then this table will have
** to be redefined as a table of uint16_t values and the macros used to
** access the table redefined as well.
*/
const uint8_t digital_pin_to_pps_in_PGM[] = {
    // IO
    _PPS_IN(_PPS_RPD4),   //  0   RD04    IO0
    _PPS_IN(_PPS_RPD5),   //  1   RD05    IO1
    _PPS_IN(_PPS_RPF0),   //  2   RF00    IO2
    _PPS_IN(_PPS_RPF1),   //  3   RF01    IO3
    NOT_PPS_PIN,          //  4   RE01    IO4

    // Expansion Port
    NOT_PPS_PIN,          //  5   RB04    GPIO0
    _PPS_IN(_PPS_RPB3),   //  6   RB03    GPIO1
    _PPS_IN(_PPS_RPB2),   //  7   RB02    GPIO2
    _PPS_IN(_PPS_RPB1),   //  8   RB01    GPIO3
    _PPS_IN(_PPS_RPB0),   //  9   RB00    GPIO4
    _PPS_IN(_PPS_RPB6),   //  10  RB06    TX
    _PPS_IN(_PPS_RPB7),   //  11  RB07    RX
    _PPS_IN(_PPS_RPD3),   //  12  RD03    SCL
    _PPS_IN(_PPS_RPD2),   //  13  RD02    SDA
    _PPS_IN(_PPS_RPD1),   //  14  RD01    SCK
    _PPS_IN(_PPS_RPC14),  //  15  RC14    SDO
    _PPS_IN(_PPS_RPF4),   //  16  RF04    SDI

    // Audio I2S
    NOT_PPS_PIN,          //  17  RE07    AMP_EN
    _PPS_IN(_PPS_RPG6),   //  18  RG06    BCLK
    _PPS_IN(_PPS_RPG7),   //  19  RG07    MCLK
    _PPS_IN(_PPS_RPG8),   //  20  RG08    DO
    _PPS_IN(_PPS_RPG9),   //  21  RG09    WCLK

    // SD Card SPI
    _PPS_IN(_PPS_RPB10),  //  22  RB10    SDI
    _PPS_IN(_PPS_RPB9),   //  23  RB09    SDO
    _PPS_IN(_PPS_RPB14),  //  24  RB14    SCK
    _PPS_IN(_PPS_RPB8),   //  25  RB08    CS
    _PPS_IN(_PPS_RPC13),  //  26  RC13    SD_EN

    // Internal I2C
    _PPS_IN(_PPS_RPD10),  //  27  RD10    SCL
    _PPS_IN(_PPS_RPD9),   //  28  RD09    SDA
};

/* ------------------------------------------------------------ */
/* This table maps from an output compare number as stored in the
** digital_pin_to_timer_PGM table to the digital pin number of the
** pin that OC is connected to. This table is only required for
** devices that support peripheral pin select (PPS), i.e. PIC32MX1xx/2xx
** devices.
*/

const uint8_t output_compare_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,
    NOT_PPS_PIN,              
    NOT_PPS_PIN,        
    NOT_PPS_PIN,        
    NOT_PPS_PIN,        
    NOT_PPS_PIN,        
    NOT_PPS_PIN,        
    PIN_OC7,
    PIN_OC8,
    PIN_OC9,
};

/* ------------------------------------------------------------ */
/* This table maps from an external interrupt number to the digital
** pin for that interrupt.
*/

const uint8_t external_int_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,        
    PIN_INT1,            
    PIN_INT2,            
    PIN_INT3,            
    PIN_INT4            
};



/* ------------------------------------------------------------ */
/*                Board Customization Functions                    */
/* ------------------------------------------------------------ */
/*                                                                */
/* The following can be used to customize the behavior of some    */
/* of the core API functions. These provide hooks that can be    */
/* used to extend or replace the default behavior of the core    */
/* functions. To use one of these functions, add the desired    */
/* code to the function skeleton below and then set the value    */
/* of the appropriate compile switch above to 1. This will        */
/* cause the hook function to be compiled into the build and    */
/* to cause the code to call the hook function to be compiled    */
/* into the appropriate core function.                            */
/*                                                                */
/* ------------------------------------------------------------ */
/***    _board_init
**
**    Parameters:
**        none
**
**    Return Value:
**        none
**
**    Errors:
**        none
**
**    Description:
**        This function is called from the core init() function.
**        This can be used to perform any board specific init
**        that needs to be done when the processor comes out of
**        reset and before the user sketch is run.
*/
#if    (OPT_BOARD_INIT != 0)

void _board_init(void) {
    
}

#endif

/* ------------------------------------------------------------ */
/***    _board_pinMode
**
**    Parameters:
**        pin        - digital pin number to configure
**        mode    - mode to which the pin should be configured
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the pinMode
**        function. It can perform any special processing needed
**        when setting the pin mode. If this function returns zero,
**        control will pass through the normal pinMode code. If
**        it returns a non-zero value the normal pinMode code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_pinMode(uint8_t pin, uint8_t mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_getPinMode
**
**    Parameters:
**        pin        - digital pin number
**        mode    - pointer to variable to receive mode value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the getPinMode
**        function. It can perform any special processing needed
**        when getting the pin mode. If this function returns zero,
**        control will pass through the normal getPinMode code. If
**        it returns a non-zero value the normal getPinMode code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_getPinMode(uint8_t pin, uint8_t * mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalWrite
**
**    Parameters:
**        pin        - digital pin number
**        val        - value to write to the pin
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the digitalWrite
**        function. It can perform any special processing needed
**        in writing to the pin. If this function returns zero,
**        control will pass through the normal digitalWrite code. If
**        it returns a non-zero value the normal digitalWrite code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalWrite(uint8_t pin, uint8_t val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalRead
**
**    Parameters:
**        pin        - digital pin number
**        val        - pointer to variable to receive pin value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the digitalRead
**        function. It can perform any special processing needed
**        in reading from the pin. If this function returns zero,
**        control will pass through the normal digitalRead code. If
**        it returns a non-zero value the normal digitalRead code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalRead(uint8_t pin, uint8_t * val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogRead
**
**    Parameters:
**        pin        - analog channel number
**        val        - pointer to variable to receive analog value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogRead
**        function. It can perform any special processing needed
**        in reading from the pin. If this function returns zero,
**        control will pass through the normal analogRead code. If
**        it returns a non-zero value the normal analogRead code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogRead(uint8_t pin, int * val) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogReference
**
**    Parameters:
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogReference
**        function. It can perform any special processing needed
**        to set the reference voltage. If this function returns zero,
**        control will pass through the normal analogReference code. If
**        it returns a non-zero value the normal analogReference code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogReference(uint8_t mode) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogWrite
**
**    Parameters:
**        pin        - pin number
**        val        - analog value to write
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogWrite
**        function. It can perform any special processing needed
**        in writing to the pin. If this function returns zero,
**        control will pass through the normal analogWrite code. If
**        it returns a non-zero value the normal analogWrite code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_WRITE != 0)

int    _board_analogWrite(uint8_t pin, int val) {

    return 0;

}

#endif

#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif    // BOARD_DATA_C

/************************************************************************/
