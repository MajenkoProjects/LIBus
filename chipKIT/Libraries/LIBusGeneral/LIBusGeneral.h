#ifndef _LIBUS_GENERAL_H
#define _LIBUS_GENERAL_H

#include <Arduino.h>
#include <LIBus.h>

class LIBusGeneral {
    private:
        LIBusMaster *_libus;
        uint32_t _address;

    public:
        LIBusGeneral(LIBusMaster &libus, uint32_t address) : _libus(&libus), _address(address) {}
        LIBusGeneral(LIBusMaster *libus, uint32_t address) : _libus(libus), _address(address) {}


        void absolute(uint8_t led, uint8_t value);
        void fade(uint8_t led, uint8_t value, uint16_t ms);
        void blink(uint8_t led, uint16_t marktime, uint16_t spacetime, uint8_t markvalue, uint8_t spacevalue);
        void strobe(uint8_t led, uint16_t marktime, uint16_t spacetime, uint16_t breaktime, uint8_t blinks, uint8_t markvalue, uint8_t spacevalue, uint8_t breakvalue);
        void sync(uint8_t led, uint8_t reference);
        void flicker(uint8_t led, uint8_t minvalue, uint8_t maxvalue, uint16_t ms);

        void waitFor();



};
 
#endif
