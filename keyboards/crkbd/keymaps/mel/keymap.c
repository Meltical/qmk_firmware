// Used with the EurKey layout: https://eurkey.steffen.bruentjen.eu/layout.html

#include QMK_KEYBOARD_H
#include "features/swapper.h"
#include "features/achordion.h"

//EurKey
#define EURO RALT(KC_5) //€
#define A_GRV RALT(KC_Z) //à
#define E_AIG RALT(KC_G) //é
#define E_GRV RALT(KC_F) //è
#define U_GRV RALT(KC_H) //ù
#define C_CED RALT(KC_C) //ç
#define D_CIR RALT(KC_6) //dead ^

#define HOME KC_HOME 
#define END KC_END

#define LA_NAV LT(NAV, KC_SPC)
#define LA_SYM LT(SYM, KC_BSPC)
#define LA_FN LT(FN, KC_ENT)

#define REDO C(KC_Y)
#define UNDO C(KC_Z)
#define CUT C(KC_X)
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define SLCTALL C(KC_A)

#define PREV C(KC_LEFT)
#define NEXT C(KC_RGHT)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LSFT_T(KC_T)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

enum layers { ALPHA, NAV, SYM, FN, MOUSE };

enum combo_events {
  COMBO_A_EVENT,
  COMBO_E_AIG_EVENT,
  COMBO_E_CIR_EVENT,
  COMBO_E_GRV_EVENT,
  COMBO_U_EVENT,
  COMBO_C_EVENT
};

const uint16_t PROGMEM COMBO_A[] = {HOME_A, HOME_E, COMBO_END};
const uint16_t PROGMEM COMBO_E_AIG[] = {HOME_E, HOME_R, COMBO_END};
const uint16_t PROGMEM COMBO_E_CIR[] = {HOME_E, HOME_S, COMBO_END};
const uint16_t PROGMEM COMBO_E_GRV[] = {HOME_E, HOME_T, COMBO_END};
const uint16_t PROGMEM COMBO_U[] = {KC_U, HOME_I, COMBO_END};
const uint16_t PROGMEM COMBO_C[] = {KC_C, HOME_E, COMBO_END};
combo_t key_combos[] = {
    [COMBO_A_EVENT] = COMBO(COMBO_A, A_GRV),
    [COMBO_E_AIG_EVENT] = COMBO(COMBO_E_AIG, E_AIG),
    [COMBO_E_CIR_EVENT] = COMBO_ACTION(COMBO_E_CIR),
    [COMBO_E_GRV_EVENT] = COMBO(COMBO_E_GRV, E_GRV),
    [COMBO_U_EVENT] = COMBO(COMBO_U, U_GRV),
    [COMBO_C_EVENT] = COMBO(COMBO_C, C_CED)
};

// Override the modded keys
// const key_override_t quot_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_DQUO);
// // This globally defines all key overrides to be used
// const key_override_t** key_overrides = (const key_override_t*[]){
//     &quot_override,
//     NULL // Null terminate the array of overrides!
// };

enum custom_keycodes {
    //Switchers
    SW_WIN = SAFE_RANGE, // Switch to next window
    SW_LANG,             // Switch to next input language
    SW_CTL,              // CTL+TAB, often used for switching tabs
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ALPHA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_GRV,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,  HOME_A,  HOME_R,  HOME_S,  HOME_T,    KC_G,                         KC_M,  HOME_N,  HOME_E,  HOME_I,  HOME_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CW_TOGG,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SCLN, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           SW_WIN,  LA_NAV, XXXXXXX,      LA_FN,  LA_SYM,  SW_CTL
                                      //`--------------------------'  `--------------------------'

  ),
    [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,    REDO,    UNDO,  KC_SPC, XXXXXXX,                      KC_WH_U, KC_PGUP,   KC_UP, KC_PGDN, KC_WH_D, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, SLCTALL, XXXXXXX, XXXXXXX, KC_LSFT, XXXXXXX,                         HOME,    PREV, KC_DOWN,    NEXT,     END, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,     CUT,    COPY,   PASTE, XXXXXXX,                      KC_BTN4, KC_LEFT, XXXXXXX, KC_RGHT, KC_BTN5, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,   KC_ENTER, KC_BSPC, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_HASH,   KC_AT, KC_ASTR, KC_BSLS,    EURO,                      KC_DLR,  KC_SLSH, KC_EQL, KC_CIRC, KC_TILD,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LABK, KC_LBRC, KC_LPRN, KC_LCBR, KC_PLUS,                      KC_MINS, KC_RCBR, KC_RPRN, KC_RBRC, KC_RABK, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_QUOT, KC_EXLM, KC_AMPR, KC_PERC,                      KC_UNDS, KC_PIPE, KC_QUES, KC_DQUO, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  KC_SPC, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [FN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                      KC_SLSH,    KC_7,    KC_8,    KC_9, KC_ASTR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, SW_LANG,                      KC_MINS,    KC_4,    KC_5,    KC_6, KC_PLUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,                         KC_0,    KC_1,    KC_2,    KC_3, KC_COMM,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  KC_SPC, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BTN3, KC_BTN1, KC_BTN2,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

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
    update_swapper(&sw_win_active, KC_LALT, KC_TAB, SW_WIN, keycode, record);
    update_swapper(&sw_lang_active, KC_LGUI, KC_SPC, SW_LANG, keycode, record);
    update_swapper(&sw_ctl_active, KC_LCTL, KC_TAB, SW_CTL, keycode, record);
    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    // Allow thumb keys
    if (tap_hold_record->event.key.row == 3 || tap_hold_record->event.key.row == 7) {
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
    if(!pressed) {
        return;
    }
    switch (combo_index) {
        case COMBO_E_CIR_EVENT:
            tap_code16(D_CIR);
            tap_code(KC_E);
            break;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// TODOs:
// - COMBOS (Add `()` + go one left)
// - Review thumb clusters
// - Add combos for unusual accent characters and uppercase versions