#ifndef _LIBUS_SPINNER_H
#define _LIBUS_SPINNER_H

#include <Arduino.h>
#include <LIBus.h>

class LIBusSpinner {
    private:
        LIBusMaster *_libus;
        uint32_t _address;

    public:
        LIBusSpinner(LIBusMaster &libus, uint32_t address) : _libus(&libus), _address(address) {}
        LIBusSpinner(LIBusMaster *libus, uint32_t address) : _libus(libus), _address(address) {}

        void setSpeed(uint8_t s) { _libus->setParameter(_address, 0, s); }
        void setMultiple(uint8_t s) { _libus->setParameter(_address, 1, s); }
        void setRed(uint8_t s) { _libus->setParameter(_address, 2, s); }
        void setGreen(uint8_t s) { _libus->setParameter(_address, 3, s); }
        void setDirection(uint8_t s) { _libus->setParameter(_address, 4, s); }
        void setFlash(uint8_t s) { _libus->setParameter(_address, 5, s); }

        void absolute(uint8_t led, uint8_t value);
        void fade(uint8_t led, uint8_t value, uint16_t ms);
        void blink(uint8_t led, uint16_t marktime, uint16_t spacetime, uint8_t markvalue, uint8_t spacevalue);
        void strobe(uint8_t led, uint16_t marktime, uint16_t spacetime, uint16_t breaktime, uint8_t blinks, uint8_t markvalue, uint8_t spacevalue, uint8_t breakvalue);
        void sync(uint8_t led, uint8_t reference);
        void flicker(uint8_t led, uint8_t minvalue, uint8_t maxvalue, uint16_t ms);

        void setMode(uint8_t mode);

        void waitFor();
};
 
#endif
