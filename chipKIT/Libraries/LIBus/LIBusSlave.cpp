#include <LIBus.h>

#ifdef _LIBUS_CAN_SLAVE

void LIBusSlave::setFunction(uint8_t id, void (*func)(uint8_t *buf), uint8_t len) {
    id &= 0x7F;
    _functions[id] = func;
    _lengths[id] = len;
}

uint8_t LIBusSlave::getParameter(uint8_t p) {
    return _parameters[p];
}

void LIBusSlave::setParameter(uint8_t p, uint8_t v) {
    _parameters[p] = v;
}

void LIBusSlave::begin() {

    if (_address < 0x10000) { // It's only a type - get the rest from the USERID
        _address <<= 16;
        if (DEVCFG3bits.USERID == 0xFFFF) { // No ID has been set!!!
            _address |= (rand() & 0xFFFF);
        } else {
            _address |= (DEVCFG3bits.USERID & 0xFFFF);
        }
    }
    mapPps(LIBUS_TX, LIBUS_TX_PPS);
    mapPps(LIBUS_RX, LIBUS_RX_PPS);
    setIntVector(LIBUS_VECTOR, ISR);
    setIntPriority(LIBUS_VECTOR, 1, 0);
    clearIntFlag(LIBUS_RX_IRQ);
    setIntEnable(LIBUS_RX_IRQ);
    LIBUS_MODE.UEN = 0b00;
    LIBUS_MODE.PDSEL = 0b11;
    LIBUS_MODE.BRGH = 0;
    LIBUS_MODE.STSEL = 0;
    LIBUS_STA.ADM_EN = 0;
//            LIBUS_STA.ADDR = 0x000 | ((_address >> 16) & 0xFF);
    LIBUS_STA.URXEN = 1;
    LIBUS_STA.UTXEN = 0;
    LIBUS_STA.URXISEL = 0b00;
//            LIBUS_STA.ADDEN = 1;
    LIBUS_BRG = (getPeripheralClock() / (16 * 2400)) - 1;
    pinMode(LIBUS_TX, INPUT_PULLUP);
    LIBUS_MODE.ON = 1;
}

void LIBusSlave::handleInterrupt() {
    if (getIntFlag(LIBUS_RX_IRQ)) {
        int val = LIBUS_RXREG;

        if (val & 0x100) { // Reset on address bit
            _rxen = ((val & 0xFF) == ((_address >> 16) & 0xFF));
            _bpos = 0;
            _phase = 0;
        } else {
            if (_rxen) {
                switch (_phase) {
                    case 0: { // Second address byte
                            if (val != ((_address >> 8) & 0xFF)) {
                                if (val != 0xFF) {
                                    _rxen = false;
                                }
                            }

                            _phase++;
                        }
                        break;

                    case 1: { // Third address byte
                            if (val != (_address & 0xFF)) {
                                if (val != 0xFF) {
                                    _rxen = false;
                                }
                            }

                            _phase++;
                        }
                        break;

                    case 2: { // Command byte
                            _command = val;
                            _phase++;
                            _bpos = 0;

                            switch (_command) {
                                case CMD_ARE_YOU_THERE:
                                    pinMode(LIBUS_TX, OUTPUT);
                                    digitalWrite(LIBUS_TX, LOW);
                                    delay(1);
                                    digitalWrite(LIBUS_TX, HIGH);
                                    pinMode(LIBUS_TX, INPUT_PULLUP);
                                    break;

                                default:
                                    if ((_command < 0x80) && (_lengths[_command] == 0)) {
                                        if (_functions[_command]) {
                                            _functions[_command](_buffer);
                                        }

                                        _rxen = false;
                                    }

                                    break;
                            }
                        }
                        break;

                    case 3: { // Data
                            uint8_t length = 0;

                            switch (_command) {
                                    write(_command);

                                case CMD_SET_PARAMETER:
                                    length = 2;
                                    break;

                                case CMD_GET_PARAMETER:
                                    length = 1;
                                    break;

                                default:
                                    length = _lengths[_command];
                                    break;
                            }

                            _buffer[_bpos++] = val;

                            if (_bpos == length) {
                                _rxen = false;

                                switch (_command) {
                                    case CMD_SET_PARAMETER: {
                                            _parameters[_buffer[0]] = _buffer[1];
                                        }
                                        break;

                                    case CMD_GET_PARAMETER: {
                                            uint8_t buf[1];
                                            buf[0] = _parameters[_buffer[0]];
                                            reply(buf, 1);
                                        }
                                        break;

                                    case CMD_ARE_YOU_THERE: {
                                            pinMode(LIBUS_TX, OUTPUT);
                                            digitalWrite(LIBUS_TX, LOW);
                                            delay(1);
                                            digitalWrite(LIBUS_TX, HIGH);
                                            pinMode(LIBUS_TX, INPUT_PULLUP);
                                        }
                                        break;

                                    default: {
                                            if (_functions[_command]) {
                                                _functions[_command](_buffer);
                                            }

                                        }
                                        break;
                                }
                            }
                        }
                        break;
                }
            }
        }

        clearIntFlag(LIBUS_RX_IRQ);
    }
}

void LIBusSlave::write(uint16_t b) {
    while (LIBUS_STA.UTXBF);

    LIBUS_TXREG = b;
}

void LIBusSlave::reply(uint8_t *data, uint8_t len) {
    LIBUS_STA.UTXEN = 1;

    for (int i = 0; i < len; i++) {
        write(data[i]);
    }

    while (LIBUS_STA.TRMT == 0);

    LIBUS_STA.UTXEN = 0;
}

LIBusSlave *LIBusSlave::_this;

#endif
