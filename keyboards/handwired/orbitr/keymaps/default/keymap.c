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
    [BASE] = LAYOUT(
                  KC_SCLN , KC_COMM , KC_DOT  , KC_P    , KC_Y    ,
        KC_EQL  , KC_A    , KC_O    , KC_E    , KC_U    , KC_I    ,
        KC_SLSH , KC_QUOT , KC_Q    , KC_J    , KC_K    , KC_X    ,
                  KC_LCTL , KC_LALT , KC_LSFT , KC_LGUI , KC_SPC  , KC_ENTER
    ),

    /*
     * ┌───┬───┬───┐
     * │MO1│ / │   │
     * ├───┼───┼───┤
     * │ a │ b │ c │
     * └───┴───┴───┘
     */
    [UP] = LAYOUT(
                  KC_SCLN , KC_COMM , KC_DOT  , KC_P    , KC_Y    ,
        KC_EQL  , KC_A    , KC_O    , KC_E    , KC_U    , KC_I    ,
        KC_SLSH , KC_QUOT , KC_Q    , KC_J    , KC_K    , KC_X    ,
                  KC_LCTL , KC_LALT , KC_LSFT , KC_LGUI , KC_SPC  , KC_ENTER
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
