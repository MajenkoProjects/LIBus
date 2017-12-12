#include <LIBusGeneral.h>

typedef struct {
    uint8_t led;
    uint8_t value;
} __attribute__((packed)) absolute_t;

typedef struct {
    uint8_t led;
    uint8_t value;
    uint16_t ms;
} __attribute__((packed)) fade_t;

typedef struct {
    uint8_t led;
    uint16_t marktime;
    uint16_t spacetime;
    uint8_t markvalue;
    uint8_t spacevalue;
} __attribute__((packed)) blink_t;

typedef struct {
    uint8_t led;
    uint16_t marktime;
    uint16_t spacetime;
    uint16_t breaktime;
    uint8_t blinks;
    uint8_t markvalue;
    uint8_t spacevalue;
    uint8_t breakvalue;
} __attribute__((packed)) strobe_t;

typedef struct {
    uint8_t led;
    uint8_t reference;
} __attribute__((packed)) sync_t;

typedef struct {
    uint8_t led;
    uint8_t minvalue;
    uint8_t maxvalue;
    uint16_t ms;
} __attribute__((packed)) flicker_t;

void LIBusGeneral::absolute(uint8_t led, uint8_t value) {
    absolute_t data;
    data.led = led;
    data.value = value;
    _libus->send(_address, 0x01, (uint8_t *)&data, sizeof(data));
}

void LIBusGeneral::fade(uint8_t led, uint8_t value, uint16_t ms) {
    fade_t data;
    data.led = led;
    data.value = value;
    data.ms = ms;
    _libus->send(_address, 0x02, (uint8_t *)&data, sizeof(data));
}


void LIBusGeneral::blink(uint8_t led, uint16_t marktime, uint16_t spacetime, uint8_t markvalue, uint8_t spacevalue) {
    blink_t data;
    data.led = led;
    data.marktime = marktime;
    data.spacetime = spacetime;
    data.markvalue = markvalue;
    data.spacevalue = spacevalue;
    _libus->send(_address, 0x03, (uint8_t *)&data, sizeof(data));
}

void LIBusGeneral::strobe(uint8_t led, uint16_t marktime, uint16_t spacetime, uint16_t breaktime, uint8_t blinks, uint8_t markvalue, uint8_t spacevalue, uint8_t breakvalue) {
    strobe_t data;
    data.led = led;
    data.marktime = marktime;
    data.spacetime = spacetime;
    data.breaktime = breaktime;
    data.markvalue = markvalue;
    data.spacevalue = spacevalue;
    data.breakvalue = breakvalue;
    data.blinks = blinks;
    _libus->send(_address, 0x04, (uint8_t *)&data, sizeof(data));
}

void LIBusGeneral::sync(uint8_t led, uint8_t reference) {
    sync_t data;
    data.led = led;
    data.reference = reference;
    _libus->send(_address, 0x05, (uint8_t *)&data, sizeof(data));
}

void LIBusGeneral::flicker(uint8_t led, uint8_t minvalue, uint8_t maxvalue, uint16_t ms) {
    flicker_t data;
    data.led = led;
    data.minvalue = minvalue;
    data.maxvalue = maxvalue;
    data.ms = ms;
    _libus->send(_address, 0x06, (uint8_t *)&data, sizeof(data));
}

void LIBusGeneral::waitFor() {
    while (1) {
        if (_libus->areYouThere(_address)) {
            return;
        }
    }
}
