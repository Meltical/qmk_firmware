// Used with the EurKey layout: https://eurkey.steffen.bruentjen.eu/layout.html
// Exemples for pro micro (Caterina bootloader), see https://github.com/qmk/qmk_firmware/blob/master/docs/config_options.md for all options
// To compile for mac on the left side, use `make crkbd:mel:avrdude-split-left OS=MAC`
// To compile for windows on the right side, use `make crkbd:mel:avrdude-split-right OS=WIN`

#include QMK_KEYBOARD_H
#include "features/swapper.h"
#include "features/achordion.h"
#include "keycodes.h"

enum layers { ALPHA, NAV, SYM, FN, MOUSE };

enum combo_events { COMBO_A_EVENT, COMBO_E_AIG_EVENT, COMBO_E_CIR_EVENT, COMBO_E_GRV_EVENT, COMBO_U_EVENT, COMBO_C_EVENT, COMBO_PARENTHESIS_EVENT };

const uint16_t PROGMEM COMBO_A[]           = {HOME_A, HOME_E, COMBO_END};
const uint16_t PROGMEM COMBO_E_AIG[]       = {HOME_E, HOME_R, COMBO_END};
const uint16_t PROGMEM COMBO_E_CIR[]       = {HOME_E, HOME_S, COMBO_END};
const uint16_t PROGMEM COMBO_E_GRV[]       = {HOME_E, HOME_T, COMBO_END};
const uint16_t PROGMEM COMBO_U[]           = {KC_U, HOME_I, COMBO_END};
const uint16_t PROGMEM COMBO_C[]           = {KC_C, HOME_E, COMBO_END};
const uint16_t PROGMEM COMBO_PARENTHESIS[] = {KC_LPRN, KC_RPRN, COMBO_END};
combo_t                key_combos[]        = {
    [COMBO_A_EVENT] = COMBO(COMBO_A, A_GRV), [COMBO_E_AIG_EVENT] = COMBO(COMBO_E_AIG, E_AIG), [COMBO_E_CIR_EVENT] = COMBO_ACTION(COMBO_E_CIR), [COMBO_E_GRV_EVENT] = COMBO(COMBO_E_GRV, E_GRV), [COMBO_U_EVENT] = COMBO(COMBO_U, U_GRV), [COMBO_C_EVENT] = COMBO(COMBO_C, C_CED), [COMBO_PARENTHESIS_EVENT] = COMBO_ACTION(COMBO_PARENTHESIS),
};

// Override the modded keys
// const key_override_t quot_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_DQUO);
// // This globally defines all key overrides to be used
// const key_override_t** key_overrides = (const key_override_t*[]){
//     &quot_override,
//     NULL // Null terminate the array of overrides!
// };

enum custom_keycodes {
    // Switchers
    SW_WIN = SAFE_RANGE, // Switch to next window
    SW_LANG,             // Switch to next input language
    SW_APP,              // CTL+TAB, often used for switching tabs
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[ALPHA] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_GRV, KC_DEL,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  KC_TAB, HOME_A, HOME_R, HOME_S, HOME_T, KC_G, KC_M, HOME_N, HOME_E, HOME_I, HOME_O, KC_ENT,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  CW_TOGG, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SCLN, KC_QUOT,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  SW_WIN, LA_NAV, KC_LSFT, LA_FN, LA_SYM, SW_APP
                                                                  //`--------------------------'  `--------------------------'

                                                                  ),
                                                              [NAV] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  _______, XXXXXXX, REDO, UNDO, KC_SPC, XXXXXXX, KC_WH_U, KC_PGUP, KC_UP, KC_PGDN, KC_WH_D, _______,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  _______, SLCTALL, KC_LALT, SAVE, KC_LSFT, XXXXXXX, HOME, PREV_W, KC_DOWN, NEXT_W, END, _______,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, CUT, COPY, PASTE, XXXXXXX, KC_BTN4, KC_LEFT, XXXXXXX, KC_RGHT, KC_BTN5, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT, KC_BSPC, XXXXXXX
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),
                                                              [SYM] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  _______, KC_HASH, KC_AT, KC_ASTR, KC_BSLS, EURO, KC_DLR, KC_SLSH, KC_EQL, KC_CIRC, KC_TILD, _______,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  _______, KC_LABK, KC_LBRC, KC_LPRN, KC_LCBR, KC_PLUS, KC_MINS, KC_RCBR, KC_RPRN, KC_RBRC, KC_RABK, _______,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, KC_QUOT, KC_EXLM, KC_AMPR, KC_PERC, KC_UNDS, KC_PIPE, KC_QUES, KC_DQUO, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),
                                                              [FN] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  _______, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, KC_SLSH, KC_7, KC_8, KC_9, KC_MINS, _______,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  _______, KC_F11, KC_F4, KC_F5, KC_F6, SW_LANG, KC_ASTR, KC_4, KC_5, KC_6, KC_PLUS, _______,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, KC_F10, KC_F1, KC_F2, KC_F3, XXXXXXX, KC_COMM, KC_1, KC_2, KC_3, KC_DOT, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, KC_SPC, KC_0, XXXXXXX, XXXXXXX, XXXXXXX
                                                                  //`--------------------------'  `--------------------------'
                                                                  ),
                                                              [MOUSE] = LAYOUT_split_3x6_3(
                                                                  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                                                  KC_ESC, XXXXXXX, KC_WH_U, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, OS_GUI, KC_LALT, OS_CTL, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                                                  XXXXXXX, XXXXXXX, CUT, COPY, PASTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                  KC_BTN3, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX
                                                                  //`--------------------------'  `--------------------------'
                                                                  )};

void pointing_device_init_user(void) {
    set_auto_mouse_layer(MOUSE);
    set_auto_mouse_enable(true);
}

bool sw_win_active  = false;
bool sw_lang_active = false;
bool sw_ctl_active  = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
#ifdef MAC
    if (update_swapper(&sw_win_active, KC_LGUI, 0, KC_TAB, SW_WIN, keycode, record)) {
        return false;
    }
    if (update_swapper(&sw_lang_active, KC_LCTL, KC_LALT, KC_SPC, SW_LANG, keycode, record)) {
        return false;
    }
#else
    if (update_swapper(&sw_win_active, KC_LALT, 0, KC_TAB, SW_WIN, keycode, record)) {
        return false;
    }
    if (update_swapper(&sw_lang_active, KC_LGUI, 0, KC_SPC, SW_LANG, keycode, record)) {
        return false;
    }
#endif
    if (update_swapper(&sw_ctl_active, KC_LCTL, 0, KC_TAB, SW_APP, keycode, record)) {
        return false;
    }

    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    // Allow thumb keys
    if (tap_hold_record->event.key.row == 3 || tap_hold_record->event.key.row == 7 || other_record->event.key.row == 3 || other_record->event.key.row == 7) {
        return true;
    }

    switch (other_keycode) {
        case KC_TAB:
            return true;
    }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    // If you quickly hold a tap-hold key after tapping it, the tap action is
    // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
    // lead to missed triggers in fast typing. Here, returning 0 means we
    // instead want to "force hold" and disable key repeating.
    switch (keycode) {
        case HOME_N:
            // Repeating is useful for Vim navigation keys.
            return QUICK_TAP_TERM; // Enable key repeating.
        default:
            return 0; // Otherwise, force hold and disable key repeating.
    }
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) {
        return;
    }
    switch (combo_index) {
        case COMBO_E_CIR_EVENT:
            tap_code16(D_CIR);
            tap_code(KC_E);
            break;
        case COMBO_PARENTHESIS_EVENT:
            tap_code16(KC_LPRN);
            tap_code16(KC_RPRN);
            tap_code(KC_LEFT);
            break;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

// TODOs:
// - Fix combo when from base layer triggering from a different layer
// - COMBOS (Add `()` + go one left)
// - Review thumb clusters
// - Add combos for unusual accent characters and uppercase versions
// - Add go to beginning/end of file for mac/win
// - Fix swapper for mac (Allow multiple cmdish)