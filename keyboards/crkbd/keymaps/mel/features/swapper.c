#include "swapper.h"

bool update_swapper(bool *active, uint16_t cmdish, uint16_t cmdish_2, uint16_t tabish, uint16_t trigger, uint16_t keycode, keyrecord_t *record) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
                if (cmdish_2 != 0) {
                    register_code(cmdish_2);
                }
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
        return true;
    } else if (*active) {
        unregister_code(cmdish);
        if (cmdish_2 != 0) {
            unregister_code(cmdish_2);
        }
        *active = false;
        return true;
    }
    return false;
}