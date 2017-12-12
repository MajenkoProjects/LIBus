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

        void waitFor();
};
 
#endif
