#include QMK_KEYBOARD_H
#include "features/swapper.h"
#include "features/achordion.h"
#include "keymap_french.h"

#define HOME KC_HOME 
#define END KC_END

#define LA_NAV LT(NAV, KC_SPC)
#define LA_SYM LT(SYM, KC_BSPC)
#define LA_FN LT(FN, KC_ENT)

#define REDO C(FR_Y)
#define UNDO C(FR_Z)
#define CUT C(FR_X)
#define COPY C(FR_C)
#define PASTE C(FR_V)
#define SLCTALL C(FR_A)

#define PREV C(KC_LEFT)
#define NEXT C(KC_RGHT)

// Left-hand home row mods
#define HOME_A LGUI_T(FR_A)
#define HOME_R LALT_T(FR_R)
#define HOME_S LCTL_T(FR_S)
#define HOME_T LSFT_T(FR_T)

// Right-hand home row mods
#define HOME_N RSFT_T(FR_N)
#define HOME_E RCTL_T(FR_E)
#define HOME_I LALT_T(FR_I)
#define HOME_O RGUI_T(FR_O)

enum layers { ALPHA, NAV, SYM, FN, MOUSE };

enum combo_events {
  COMBO_E_2_EVENT
};
const uint16_t PROGMEM COMBO_A[] = {HOME_A, HOME_E, COMBO_END}; // à
const uint16_t PROGMEM COMBO_E_1[] = {HOME_E, HOME_R, COMBO_END}; // é
const uint16_t PROGMEM COMBO_E_2[] = {HOME_E, HOME_S, COMBO_END}; // ê
const uint16_t PROGMEM COMBO_E_3[] = {HOME_E, HOME_T, COMBO_END}; // è
const uint16_t PROGMEM COMBO_U[] = {FR_U, HOME_I, COMBO_END}; // ù
const uint16_t PROGMEM COMBO_C[] = {FR_C, HOME_E, COMBO_END}; // ç
combo_t key_combos[] = {
    [COMBO_E_2_EVENT] = COMBO_ACTION(COMBO_E_2),
    COMBO(COMBO_A, FR_AGRV),
    COMBO(COMBO_E_1, FR_EACU),
    COMBO(COMBO_E_3, FR_EGRV),
    COMBO(COMBO_U, FR_UGRV),
    COMBO(COMBO_C, FR_CCED)
};

const key_override_t quot_override = ko_make_basic(MOD_MASK_SHIFT, FR_QUOT, FR_DQUO);
const key_override_t slsh_override = ko_make_basic(MOD_MASK_SHIFT, FR_SLSH, FR_QUES);
const key_override_t scln_override = ko_make_basic(MOD_MASK_SHIFT, FR_SCLN, FR_COLN);
const key_override_t dot_override  = ko_make_basic(MOD_MASK_SHIFT, FR_DOT, FR_RABK);
const key_override_t comm_override = ko_make_basic(MOD_MASK_SHIFT, FR_COMM, FR_LABK);

// This globally defines all key overrides to be used
const key_override_t** key_overrides = (const key_override_t*[]){
    &quot_override,
    &slsh_override,
    &scln_override,
    &dot_override,
    &comm_override,
    NULL // Null terminate the array of overrides!
};

enum swithers {
    SW_WIN = SAFE_RANGE, // Switch to next window
    SW_LANG,             // Switch to next input language
    SW_CTL,              // CTL+TAB, often used for switching tabs
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ALPHA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    FR_Q,    FR_W,    FR_F,    FR_P,    FR_B,                         FR_J,    FR_L,    FR_U,    FR_Y,  FR_GRV,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,  HOME_A,  HOME_R,  HOME_S,  HOME_T,    KC_G,                         FR_M,  HOME_N,  HOME_E,  HOME_I,  HOME_O, FR_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CW_TOGG,    FR_Z,    FR_X,    FR_C,    FR_D,    FR_V,                         FR_K,    FR_H, FR_COMM,  FR_DOT, FR_SCLN, FR_SLSH,
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
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, FR_HASH,   FR_AT, FR_ASTR, FR_BSLS, FR_EURO,                      FR_DLR,  FR_SLSH, FR_EQL, FR_CIRC, FR_TILD,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, FR_LABK, FR_LBRC, FR_LPRN, FR_LCBR, FR_PLUS,                      FR_MINS, FR_RCBR, FR_RPRN, FR_RBRC, FR_RABK, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, FR_QUOT, FR_EXLM, FR_AMPR, FR_PERC,                      FR_UNDS, FR_PIPE, FR_QUES, FR_DQUO, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [FN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                      FR_SLSH,    FR_7,    FR_8,    FR_9, FR_ASTR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, SW_LANG,                      FR_MINS,    FR_4,    FR_5,    FR_6, FR_PLUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,                         FR_0,    FR_1,    FR_2,    FR_3, FR_COMM,  FR_DOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
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
    switch (combo_index) {
        case COMBO_E_2_EVENT:
            if (pressed) {
                tap_code(FR_CIRC);
                tap_code(FR_E);
            }
            break;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_L:
        case KC_SCLN: // M
        case KC_N ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case FR_1 ... FR_0:
        case KC_BSPC:
        case KC_DEL:
        case FR_UNDS:
        case FR_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// TODOs:
// - COMBOS (Add `()` + go one left)
// - Review thumb clusters