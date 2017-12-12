#include <TLC59116_DTWI.h>
#include <LIBus.h>

extern uint8_t sin8(int angle);

LIBusSlave libus;

DTWI0 dtwi;

enum {
    PARM_SPEED,
    PARM_MULT,
    PARM_RED,
    PARM_GREEN,
    PARM_DIR,
    PARM_FLASHEN
};

struct ledspec {
    int redchip;
    int redport;
    int greenchip;
    int greenport;
    int bluechip;
    int blueport;
};

struct ledspec leds[12] = {
    {1,12, 1,11, 1,10}, // 0/12
    {1, 5, 1, 4, 1, 3}, // 1
    {1, 2, 1, 1, 1, 0}, // 2
    {2,11, 2,10, 2, 9}, // 3
    {2, 8, 2, 7, 2, 6}, // 4
    {2, 5, 2, 4, 2, 3}, // 5
    {2, 2, 2, 1, 2, 0}, // 6
    {0,11, 0,10, 0, 9}, // 7
    {0, 8, 0, 7, 0, 6}, // 8
    {0, 5, 0, 4, 0, 3}, // 9
    {0, 2, 0, 1, 0, 0}, // 10
    {1,15, 1,14, 1,13}, // 11
};

class Spinner {
    private:
        TLC59116_DTWI chip0;
        TLC59116_DTWI chip1;
        TLC59116_DTWI chip2;


    public:
        static const int RED = 0;
        static const int GREEN = 1;
        static const int BLUE = 2;

        Spinner(DTWI *dtwi) : chip0(dtwi, 0), chip1(dtwi, 1), chip2(dtwi, 2) {}
        void begin() {
            chip0.begin();
            chip1.begin();
            chip2.begin();
        }

        void setLedColor(int led, int col, int bright) {
            if (bright < 0) bright = 0;
            if (bright > 255) bright = 255;
            int cno = 0;
            int pno = 0;
            switch (col) {
                case RED:
                    cno = leds[led].redchip;
                    pno = leds[led].redport;
                    break;
                case GREEN:
                    cno = leds[led].greenchip;
                    pno = leds[led].greenport;
                    break;
                case BLUE:
                    cno = leds[led].bluechip;
                    pno = leds[led].blueport;
                    break;
            }

            switch (cno) {
                case 0: chip0.analogWrite(pno, bright); break;
                case 1: chip1.analogWrite(pno, bright); break;
                case 2: chip2.analogWrite(pno, bright); break;
            }
        }

        void setColor(int pos, uint32_t col) {
            setLedColor(pos, RED, (col >> 16) & 0xFF);
            setLedColor(pos, GREEN, (col >> 8) & 0xFF);
            setLedColor(pos, BLUE, col & 0xFF);
        }
};

Spinner spinner(&dtwi);

void setup() {
    libus.begin();
    libus.setParameter(PARM_SPEED, 0);
    libus.setParameter(PARM_MULT, 3);
    libus.setParameter(PARM_RED, 0);
    libus.setParameter(PARM_GREEN, 0);
    libus.setParameter(PARM_DIR, 0);
    libus.setParameter(PARM_FLASHEN, 0);
    spinner.begin();

    for (int i = 0; i < 12; i++) {
        spinner.setColor(i, 0);
    }
    
}

void loop() {
    static int progno = 1;

    switch (progno) {
        case 0: // Nothing.
            break;
        case 1: // Normal spinning
            program_0();
            break;
    }
}

void program_0() {

    static uint32_t flashts = millis();
    static uint32_t flashstate = 0;
    static uint32_t flashtime = 0;

    if (libus.getParameter(PARM_FLASHEN) > 0) {
        if (flashtime == 0) {
            flashtime = rand() & 5000 + 1;
            flashstate = 0;
        }

        if (millis() - flashts >= flashtime) {
            flashts = millis();
            if (flashstate == 0) { // It was off
                flashtime = 20; // 20ms flash
                int led = rand() % 12;
                spinner.setLedColor(led, Spinner::BLUE, 255);
                flashstate = 1;                
            } else {
                flashtime = rand() & 5000 + 1;
                flashstate = 0;
                for (int i = 0; i < 12; i++) {
                    spinner.setLedColor(i, Spinner::BLUE, 0);
                }
            }
        }
    }
    
    static float phase = 0;
    static uint32_t ts = millis();
    if (millis() - ts > 1) {
        ts = millis();    
        for (int i = 0; i < 12; i++) {
            int b = sin8(phase + (i*30) * libus.getParameter(PARM_MULT));
            
            spinner.setLedColor(i, Spinner::RED, b * libus.getParameter(PARM_RED) / 255);
            spinner.setLedColor(i, Spinner::GREEN, b * libus.getParameter(PARM_GREEN) / 255);
        }
        if (libus.getParameter(PARM_DIR) == 0) {
            phase -= (libus.getParameter(PARM_SPEED)/10.0);
            if (phase <= 0) phase += 360;
        } else {            
            phase += (libus.getParameter(PARM_SPEED)/10.0);
            if (phase >= 360) phase -= 360;
        }
    }
}
