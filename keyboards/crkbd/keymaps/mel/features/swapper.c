#include "keycodes.h"
#include "swapper.h"
#include "../keycodes.h"

#define NEXT HOME_N
#define PREV HOME_T

void handle_cmdish(bool register_key, uint16_t cmdish, uint16_t cmdish_2) {
    if (register_key) {
        register_code(cmdish);
        if (cmdish_2 != 0) {
            register_code(cmdish_2);
        }
    } else {
        unregister_code(cmdish);
        if (cmdish_2 != 0) {
            unregister_code(cmdish_2);
        }
    }
}

void handle_position(bool next, keyrecord_t *record, uint16_t tabish) {
    if (record->event.pressed) {
        if (next) {
            tap_code(tabish);
        } else {
            register_code(KC_LSFT);
            tap_code(tabish);
            unregister_code(KC_LSFT);
        }
    }
}

bool update_swapper(bool *active, uint16_t cmdish, uint16_t cmdish_2, uint16_t tabish, uint16_t trigger, uint16_t keycode, keyrecord_t *record) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                handle_cmdish(true, cmdish, cmdish_2);
            }
            register_code(tabish);
        } else {
            unregister_code(tabish); // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (*active) {
        bool isNext = keycode == NEXT;
        bool isPrev = keycode == PREV;
        if (isNext || isPrev) {
            handle_position(isNext, record, tabish);
            return true;
        }
        handle_cmdish(false, cmdish, cmdish_2);
        *active = false;
        return true;
    }
    return false;
}
