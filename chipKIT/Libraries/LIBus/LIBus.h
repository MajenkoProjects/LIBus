#ifndef _LIBUS_H
#define _LIBUS_H

#include <Arduino.h>

#ifdef _LIBUS_CAN_SLAVE
class LIBusSlave {
private:
    uint32_t _address;
    volatile uint8_t _parameters[256];
    static LIBusSlave *_this;
    uint32_t _bpos = 0;
    uint8_t _buffer[128];
    bool _rxen;
    uint8_t _phase;
    uint8_t _command;

    void (*_functions[0x80])(uint8_t *);
    uint8_t _lengths[0x80];

public:

    // General control functions
    static const uint8_t CMD_SET_PARAMETER = 0x80;
    static const uint8_t CMD_GET_PARAMETER = 0x81;

    // System control functions
    static const uint8_t CMD_ARE_YOU_THERE = 0x90;

    LIBusSlave(uint32_t address) : _address(address) {
        _this = this;
    }

    LIBusSlave() : _address(LIBUS_BOARD_TYPE) {
        _this = this;
    }

    static __USER_ISR void ISR() {
        _this->handleInterrupt();
    }


    void setFunction(uint8_t id, void (*func)(uint8_t *buf), uint8_t len);
    uint8_t getParameter(uint8_t p);
    void setParameter(uint8_t p, uint8_t v);
    void begin();
    void handleInterrupt();
    void write(uint16_t b);
    void reply(uint8_t *data, uint8_t len);
};
#endif

#ifdef _LIBUS_CAN_MASTER
class LIBusMaster {
    private:
        static LIBusMaster *_this;
        static const uint8_t CMD_SET_PARAMETER = 0x80;
        static const uint8_t CMD_GET_PARAMETER = 0x81;

    public:
        LIBusMaster() {
            _this = this;
        }

        static __USER_ISR void ISR() {
            _this->handleInterrupt();
        }

        void begin();
        void write(uint16_t b);
        void handleInterrupt();
        void send(uint32_t address, uint8_t cmd, const uint8_t *data, uint32_t len);
        bool areYouThere(uint32_t address);
        void setParameter(uint32_t address, uint8_t parameter, uint8_t val);
};
#endif

#endif
