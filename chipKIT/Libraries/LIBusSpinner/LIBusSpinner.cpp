#include <LIBusSpinner.h>

void LIBusSpinner::waitFor() {
    while (1) {
        if (_libus->areYouThere(_address)) {
            return;
        }
    }
}
