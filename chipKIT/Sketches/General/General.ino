#include <LIBus.h>
#include <TLC59116_DTWI.h>

DTWI0 dtwi;
TLC59116_DTWI board1(dtwi, 0);
LIBusSlave libus;

typedef enum {
    Absolute,
    Fade,
    Blink,
    Strobe,
    Sync,
    Flicker,
    BlinkFade,
} anim_t;



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

#define MAXSIZE max(sizeof(absolute_t),\
                max(sizeof(fade_t),\
                max(sizeof(blink_t),\
                max(sizeof(strobe_t),\
                sizeof(sync_t)))))

struct LED {
    anim_t mode;
    uint8_t brightness;
    uint32_t param[16];
    uint8_t data[2];
    uint32_t ts;
};

struct LED LEDS[16];

/*
 * Absolute
 *   0 = led
 *   1 = requested value
 *   
 * Fade
 *   0 = led
 *   1 = requested value
 *   2 = ms between steps
 *   
 * Blink
 *   0 = led
 *   1 = mark time
 *   2 = space time
 *   3 = mark brightness
 *   4 = space brightness
 *   
 * Strobe
 *   0 = led
 *   1 = mark time
 *   2 = space time
 *   3 = break time
 *   4 = flash count
 *   5 = mark brightness
 *   6 = space brightness
 *   7 = break brightness
 *   
 * Sync
 *   0 = led
 *   1 = reference LED
 *   
 * Flicker
 *   0 = led
 *   1 = min value
 *   2 = max value
 *   3 = ms
 */
 
void setModeAbsolute(uint8_t *b) {
    uint8_t led = b[0] & 0xF;
    LEDS[led].mode = Absolute;
    LEDS[led].ts = millis();
    LEDS[led].data[0] = 0;
    LEDS[led].data[1] = 0;
    memcpy(LEDS[led].param, b, sizeof(absolute_t));
}

void setModeFade(uint8_t *b) {
    uint8_t led = b[0] & 0xF;
    LEDS[led].mode = Fade;
    LEDS[led].ts = millis();
    LEDS[led].data[0] = 0;
    LEDS[led].data[1] = 0;
    memcpy(LEDS[led].param, b, sizeof(fade_t));
}

void setModeBlink(uint8_t *b) {
    uint8_t led = b[0] & 0xF;
    LEDS[led].mode = Blink;
    LEDS[led].ts = millis();
    LEDS[led].data[0] = 0;
    LEDS[led].data[1] = 0;
    memcpy(LEDS[led].param, b, sizeof(blink_t));
}

void setModeStrobe(uint8_t *b) {
    uint8_t led = b[0] & 0xF;
    LEDS[led].mode = Strobe;
    LEDS[led].ts = millis();
    LEDS[led].data[0] = 0;
    LEDS[led].data[1] = 0;
    memcpy(LEDS[led].param, b, sizeof(strobe_t));
}

void setModeSync(uint8_t *b) {
    uint8_t led = b[0] & 0xF;
    LEDS[led].mode = Sync;
    LEDS[led].ts = millis();
    LEDS[led].data[0] = 0;
    LEDS[led].data[1] = 0;    
    memcpy(LEDS[led].param, b, sizeof(sync_t));
}

void setModeFlicker(uint8_t *b) {
    uint8_t led = b[0] & 0xF;
    LEDS[led].mode = Flicker;
    LEDS[led].ts = millis();
    memcpy(LEDS[led].param, b, sizeof(flicker_t));
    flicker_t *p = (flicker_t *)b;
    LEDS[led].data[0] = random(p->minvalue, p->maxvalue); 
    LEDS[led].data[1] = 0;
}

void setup() {
    memset(LEDS, 0, sizeof(struct LED) * 16);
	board1.begin();
 
	libus.setFunction(0x01, setModeAbsolute, sizeof(absolute_t));
    libus.setFunction(0x02, setModeFade, sizeof(fade_t));
    libus.setFunction(0x03, setModeBlink, sizeof(blink_t));
    libus.setFunction(0x04, setModeStrobe, sizeof(strobe_t));
    libus.setFunction(0x05, setModeSync, sizeof(sync_t));
    libus.setFunction(0x06, setModeFlicker, sizeof(flicker_t));
    
	libus.begin();
}

void loop() {
    for (int i = 0; i < 16; i++) {
        switch (LEDS[i].mode) {
            case Absolute: {
                absolute_t *param = (absolute_t *)LEDS[i].param;
                if (LEDS[i].brightness != param->value) {
                    board1.analogWrite(i, param->value);
                    LEDS[i].brightness = param->value;
                }
            }
            break;

            case Fade: {
                fade_t *param = (fade_t *)LEDS[i].param;
                if (millis() - LEDS[i].ts >= param->ms) {
                    if (LEDS[i].brightness > param->value) {
                        LEDS[i].brightness--;
                    } else if (LEDS[i].brightness < param->value) {
                        LEDS[i].brightness++;
                    } else { // revert to absolute
                        LEDS[i].mode = Absolute;
                    }
                    LEDS[i].ts = millis();
                    board1.analogWrite(i, LEDS[i].brightness);
                }
            }
            break;

            case Blink: {
                blink_t *param = (blink_t *)LEDS[i].param;
                if (LEDS[i].data[0] == 0) { // in space
                    if (millis() - LEDS[i].ts >= param->spacetime) {
                        LEDS[i].ts = millis();
                        LEDS[i].brightness = param->markvalue;
                        LEDS[i].data[0] = 1;
                        board1.analogWrite(i, LEDS[i].brightness);                        
                    }
                } else { // in mark
                    if (millis() - LEDS[i].ts >= param->marktime) {
                        LEDS[i].ts = millis();
                        LEDS[i].brightness = param->spacevalue;
                        LEDS[i].data[0] = 0;
                        board1.analogWrite(i, LEDS[i].brightness);
                    }
                }
            }
            break;

            case Strobe: {
                strobe_t *param = (strobe_t *)LEDS[i].param;
                if (LEDS[i].data[0] == 0) { // in space
                    if (millis() - LEDS[i].ts >= param->spacetime) {
                        LEDS[i].ts = millis();
                        LEDS[i].brightness = param->markvalue;
                        LEDS[i].data[0] = 1;
                        board1.analogWrite(i, LEDS[i].brightness);                        
                    }
                } else if (LEDS[i].data[0] == 1) { // in mark
                    if (millis() - LEDS[i].ts >= param->marktime) {
                        LEDS[i].ts = millis();
                        LEDS[i].data[1]++;
                        if (LEDS[i].data[1] >= param->blinks) {
                            LEDS[i].brightness = param->breakvalue;
                            LEDS[i].data[0] = 2;
                        } else {
                            LEDS[i].brightness = param->spacevalue;
                            LEDS[i].data[0] = 0;
                        }
                        board1.analogWrite(i, LEDS[i].brightness);
                    }
                } else { // in break
                    if (millis() - LEDS[i].ts >= param->breaktime) {
                        LEDS[i].ts = millis();
                        LEDS[i].brightness = param->markvalue;
                        LEDS[i].data[0] = 1; // Go to mark next
                        LEDS[i].data[1] = 0;
                        board1.analogWrite(i, LEDS[i].brightness);                        
                    }
                }
            }
            break;

            case Sync: {
                sync_t *param = (sync_t *)LEDS[i].param;
                int ref = param->reference & 0xF;
                if (LEDS[i].brightness != LEDS[ref].brightness) {
                    board1.analogWrite(i, LEDS[ref].brightness);
                    LEDS[i].brightness = LEDS[ref].brightness;
                }
            }
            break;

            case Flicker: {
                flicker_t *param = (flicker_t *)LEDS[i].param;
                if (millis() - LEDS[i].ts >= param->ms) {
                    if (LEDS[i].brightness > LEDS[i].data[0]) {
                        LEDS[i].brightness--;
                    } else if (LEDS[i].brightness < LEDS[i].data[0]) {
                        LEDS[i].brightness++;
                    } else { // revert to absolute
                        LEDS[i].data[0] = random(param->minvalue, param->maxvalue); 
                    }
                    LEDS[i].ts = millis();
                    board1.analogWrite(i, LEDS[i].brightness);
                }
            }
            break;
        }
    }
}
