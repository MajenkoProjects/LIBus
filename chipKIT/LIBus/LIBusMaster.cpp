#include <LIBus.h>

#ifdef _LIBUS_CAN_MASTER

void LIBusMaster::begin() {
    mapPps(LIBUSM_TX, LIBUSM_TX_PPS);
    mapPps(LIBUSM_RX, LIBUSM_RX_PPS);
    setIntVector(LIBUSM_VECTOR, ISR);
    setIntPriority(LIBUSM_VECTOR, 4, 0);
    clearIntFlag(LIBUSM_IRQ);
    clearIntFlag(LIBUSM_IRQ + 1);
    clearIntFlag(LIBUSM_IRQ + 2);
// ERR            setIntEnable(LIBUS_IRQ);
//            setIntEnable(LIBUS_IRQ + 1); // RX - only when needed
// TX            setIntEnable(LIBUS_IRQ + 2);
    LIBUSM_MODE.UEN = 0b00;
    LIBUSM_MODE.PDSEL = 0b11;
    LIBUSM_MODE.BRGH = 0;
    LIBUSM_MODE.STSEL = 0;
    LIBUSM_STA.ADM_EN = 0;
    LIBUSM_STA.URXEN = 0;
    LIBUSM_STA.UTXEN = 1;
    LIBUSM_STA.URXISEL = 0b00;
    LIBUSM_STA.ADDEN = 0;
    LIBUSM_BRG = (getPeripheralClock() / (16 * 2400)) - 1;
    pinMode(LIBUSM_RX, INPUT_PULLUP);
    LIBUSM_MODE.ON = 1;
}

void LIBusMaster::write(uint16_t b) {
    while (LIBUSM_STA.UTXBF);
    LIBUSM_TXREG = b;
}

void LIBusMaster::handleInterrupt() {
    
}

void LIBusMaster::send(uint32_t address, uint8_t cmd, uint8_t *data, uint32_t len) {
    write(0x100 | ((address >> 16) & 0xFF));
    write((address >> 8) & 0xFF);
    write(address & 0xFF);
    write(cmd);
    for (int i = 0; i < len; i++) {
        write(data[i]);
    }
}

bool LIBusMaster::areYouThere(uint32_t address) {
    send(address, 0x90, NULL, 0);
    uint32_t t = pulseIn(LIBUSM_RX, LOW, 3000);
    return (t > 0);
}

LIBusMaster *LIBusMaster::_this;

#endif
