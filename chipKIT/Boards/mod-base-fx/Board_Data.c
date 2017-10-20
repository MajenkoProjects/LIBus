#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

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

// Pin  Name        Port    Main Mapping(s)         Additional Mappings
//  0   IO0         RD5     INT1,OC1
//  1   IO1         RF0     INT4,OC4
//  2   IO2         RF1     INT3,OC3
//  3   IO3         RE1     
//  4   IO4         RE2
//  5   IO5         RD4     INT2,OC5

//  6   TX          RB6     U2TX                    U6RX
//  7   RX          RB7     U2RX                    U6TX

//  8   SCL         RD10
//  9   SDA         RD9

// 10   SD_CS       RB8     SS3
// 11   SD_SDO      RB9     SDO3
// 12   SD_SDI      RB10    SDI3
// 13   SD_CLK      RB14    SCK3
// 14   SD_EN       RC13

// 15   AMPEN       RE7

// 16   I2S_DO      RG8     SDO2
// 17   I2S_MCLK    RG7     REFCLKO1
// 18   I2S_BCLK    RG6     SCK2
// 19   I2S_WCLK    RG9     SS2


/* ------------------------------------------------------------ */
/* This table is used to map the digital pin number to the port
** containing that pin.
*/
const uint8_t digital_pin_to_port_PGM[] = {
    _IOPORT_PD,
    _IOPORT_PF,
    _IOPORT_PF,
    _IOPORT_PE,
    _IOPORT_PE,
    _IOPORT_PD,
    _IOPORT_PB,
    _IOPORT_PB,
    _IOPORT_PD,
    _IOPORT_PD,
    _IOPORT_PB,
    _IOPORT_PB,
    _IOPORT_PB,
    _IOPORT_PB,
    _IOPORT_PC,
    _IOPORT_PE,
    _IOPORT_PG,
    _IOPORT_PG,
    _IOPORT_PG,
    _IOPORT_PG
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t digital_pin_to_bit_mask_PGM[] = 
{
    _BV(5), _BV(0), _BV(1), _BV(1),
    _BV(2), _BV(4), _BV(6), _BV(7),
    _BV(10),_BV(9), _BV(8), _BV(9),
    _BV(10),_BV(14),_BV(13),_BV(7),
    _BV(8), _BV(7), _BV(6), _BV(9)
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t digital_pin_to_timer_PGM[] =
{
    _TIMER_OC1,
    _TIMER_OC4,
    _TIMER_OC3,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    _TIMER_OC5,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** analog pin number.
*/
const uint8_t digital_pin_to_analog_PGM[] = {
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN,
    NOT_ANALOG_PIN
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
    _PPS_OUT(_PPS_RPD5R),
    _PPS_OUT(_PPS_RPF0R),
    _PPS_OUT(_PPS_RPF1R),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPD4R),
    _PPS_OUT(_PPS_RPB6R),
    _PPS_OUT(_PPS_RPB7R),
    _PPS_OUT(_PPS_RPD10R),
    _PPS_OUT(_PPS_RPD9R),
    _PPS_OUT(_PPS_RPB8R),
    _PPS_OUT(_PPS_RPB9R),
    _PPS_OUT(_PPS_RPB10R),
    _PPS_OUT(_PPS_RPB14R),
    _PPS_OUT(_PPS_RPC13R),
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPG8R),
    _PPS_OUT(_PPS_RPG7R),
    _PPS_OUT(_PPS_RPG6R),
    _PPS_OUT(_PPS_RPG9R)
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
    _PPS_IN(_PPS_RPD5),
    _PPS_IN(_PPS_RPF0),
    _PPS_IN(_PPS_RPF1),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPD4),
    _PPS_IN(_PPS_RPB6),
    _PPS_IN(_PPS_RPB7),
    _PPS_IN(_PPS_RPD10),
    _PPS_IN(_PPS_RPD9),
    _PPS_IN(_PPS_RPB8),
    _PPS_IN(_PPS_RPB9),
    _PPS_IN(_PPS_RPB10),
    _PPS_IN(_PPS_RPB14),
    _PPS_IN(_PPS_RPC13),
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPG8),
    _PPS_IN(_PPS_RPG7),
    _PPS_IN(_PPS_RPG6),
    _PPS_IN(_PPS_RPG9)
};

/* ------------------------------------------------------------ */
/* This table maps from an output compare number as stored in the
** digital_pin_to_timer_PGM table to the digital pin number of the
** pin that OC is connected to. This table is only required for
** devices that support peripheral pin select (PPS), i.e. PIC32MX1xx/2xx
** devices.
*/

//  0   IO0         RD5     INT1,OC1
//  1   IO1         RF0     INT4,OC4
//  2   IO2         RF1     INT3,OC3
//  3   IO3         RE1     
//  4   IO4         RE2
//  5   IO5         RD4     INT2,OC5


const uint8_t output_compare_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,
    0,
    NOT_PPS_PIN,
    2,
    1,
    5,
    NOT_PPS_PIN,        
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
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
    PIN_INT4,
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
