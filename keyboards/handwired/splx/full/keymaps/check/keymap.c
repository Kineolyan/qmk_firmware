// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    KC_P00 = SAFE_RANGE
};

enum layers {
    BASE,
    UP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │MO1│ / │ - │
     * ├───┼───┼───┤
     * │ 1 │ 2 │ 3 │
     * └───┴───┴───┘
     */
    [BASE] = LAYOUT_flat(
                  KC_SCLN , KC_COMM , KC_DOT  , KC_P    , KC_Y                        , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    ,
        KC_EQL  , KC_A    , KC_O    , KC_E    , KC_U    , KC_I                        , KC_D    , KC_H    , KC_T    , KC_N    , KC_S    , KC_MINS   ,
        KC_SLSH , KC_QUOT , KC_Q    , KC_J    , KC_K    , KC_X                        , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , S(KC_EQL) ,
                  KC_LCTL , KC_LALT , KC_LSFT , KC_LGUI , KC_BSPC , KC_ENTER, KC_SPC  , KC_TAB  , KC_RGUI , KC_RSFT , KC_RALT , KC_RCTL
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case KC_P00:
                tap_code(KC_P0);
                tap_code(KC_P0);
                return false;
        }
    }
    return true;
}
