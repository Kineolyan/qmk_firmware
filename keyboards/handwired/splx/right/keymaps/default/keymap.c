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
     *     ┌───┬───┬───┬───┬───┐
     *     │ / │ - │ - │ - │ - │
     *     ├───┼───┼───┼───┼───┼───┐
     *     │ 2 │ 3 │ 3 │ 3 │ 3 │ 3 │
     *     ├───┼───┼───┼───┼───┼───┤
     *     │ 2 │ 3 │ 3 │ 3 │ 3 │ 3 │
     * ┌───┼───┼───┼───┼───┼───┼───┘
     * │ 1 │ 2 │ 3 │ 3 │ 3 │ 3 │
     * └───┴───┴───┴───┴───┴───┘
     */
    [BASE] = LAYOUT(
                  KC_F    , KC_G    , KC_C    , KC_R    , KC_L    ,
                  KC_D    , KC_H    , KC_T    , KC_N    , KC_S    , KC_MINS   ,
                  KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , S(KC_EQL) ,
        KC_SPC  , KC_TAB  , MO(UP)  , KC_RSFT , KC_RALT , KC_RCTL
    ),

    /*
     * ┌───┬───┬───┐
     * │MO1│ / │   │
     * ├───┼───┼───┤
     * │ a │ b │ c │
     * └───┴───┴───┘
     */
    [UP] = LAYOUT(
                  XXXXXXX , KC_1    , KC_2    , KC_3    , KC_DOT  ,
                  XXXXXXX , KC_4    , KC_5    , KC_6    , KC_0    , KC_SLASH  ,
                  XXXXXXX , KC_7    , KC_8    , KC_9    , KC_COMM , XXXXXXX   ,
        XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX
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
