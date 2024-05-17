#include QMK_KEYBOARD_H
#include "features/swapper.h"
#include "features/achordion.h"
#include "keymap_us_international.h"

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

// Layers
enum layers { ALPHA, NAV, SYM, FN, MOUSE };

// Combos
const uint16_t PROGMEM test_combo1[] = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END};
combo_t                key_combos[]  = {COMBO(test_combo1, KC_ESC), COMBO(test_combo2, KC_Q)};

enum keycodes {
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
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_HASH,   KC_AT, KC_ASTR, KC_BSLS, US_EURO,                      KC_DLR,  KC_SLSH, KC_EQL, KC_CIRC, KC_TILD,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, KC_PLUS,                      KC_MINS, KC_RCBR, KC_RPRN, KC_RBRC,   KC_GT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_QUOT, KC_EXLM, KC_AMPR, KC_PERC,                      KC_UNDS, KC_PIPE, KC_QUES, KC_DQUO, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [FN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                      KC_SLSH,    KC_7,    KC_8,    KC_9, KC_ASTR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,                      KC_MINS,    KC_4,    KC_5,    KC_6, KC_PLUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,                         KC_0,    KC_1,    KC_2,    KC_3, KC_COMM,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    [MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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

