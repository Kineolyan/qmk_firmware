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
        MO(UP), KC_SLASH, KC_MINUS,
        KC_1  , KC_2    , KC_3
    ),

    /*
     * ┌───┬───┬───┐
     * │MO1│ / │   │
     * ├───┼───┼───┤
     * │ a │ b │ c │
     * └───┴───┴───┘
     */
    [UP] = LAYOUT(
        _______, KC_EQL , XXXXXXX,
        KC_A   , KC_B   , KC_C
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
