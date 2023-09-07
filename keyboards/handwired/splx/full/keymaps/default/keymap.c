// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    PWR,
    NAV,
};

#define SM(K) MT(KC_LSFT, K)
#define CM(K) MT(KC_LCTL, K)
#define AM(K) MT(KC_LALT, K)
#define GM(K) MT(KC_LGUI, K)
#define MM(K) MT(KC_MEH, K)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │MO1│ / │ - │
     * ├───┼───┼───┤
     * │ 1 │ 2 │ 3 │
     * └───┴───┴───┘
     */
    [BASE] = LAYOUT_vertical(
                  KC_SCLN , KC_COMM , KC_DOT  , KC_P     , KC_Y
      , KC_QUES , AM(KC_A), CM(KC_O), SM(KC_E), MM(KC_U) , KC_I
      , KC_LSFT , KC_QUOT , KC_Q    , KC_J    , KC_K     , KC_X
                , KC_LGUI , KC_LALT , KC_LSFT , MO(PWR)  , KC_BSPC , KC_ENTER

                , KC_F    , KC_G    , KC_C    , KC_R    , KC_L
                , CM(KC_D), SM(KC_H), CM(KC_T), AM(KC_N), KC_S    , KC_SLSH
                , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , KC_MINS
      , KC_SPC  , KC_TAB  , MO(NAV), KC_RSFT , KC_RALT , KC_RGUI
    ),
    [PWR] = LAYOUT_vertical(
                  KC_SCLN , KC_COMM , KC_DOT  , KC_P     , KC_Y
      , KC_QUES , AM(KC_A), CM(KC_LBRC), SM(KC_LCBR), MM(KC_LPRN) , KC_I
      , KC_LSFT , KC_7    , KC_5    , KC_3    , KC_1     , KC_9
                , KC_LGUI , KC_LALT , KC_LSFT , KC_LGUI  , KC_BSPC , KC_ENTER

                , KC_F    , KC_G    , KC_C    , KC_R    , KC_L
                , CM(KC_RPRN), SM(KC_RCBR), CM(KC_RBRC), AM(KC_N), KC_S    , KC_SLSH
                , KC_8    , KC_0    , KC_2    , KC_4    , KC_6    , KC_MINS
      , KC_SPC  , KC_TAB  , KC_RGUI , KC_RSFT , KC_RALT , KC_RGUI
    ),
    [NAV] = LAYOUT_vertical(
                  KC_SCLN , KC_COMM , KC_DOT  , KC_P     , KC_Y
      , KC_QUES , AM(KC_A), CM(KC_O), SM(KC_E), MM(KC_U) , KC_I
      , KC_LSFT , KC_QUOT , KC_Q    , KC_J    , KC_K     , KC_X
                , KC_LGUI , KC_LALT , KC_LSFT , KC_LGUI  , KC_BSPC , KC_ENTER

                , KC_F    , KC_G    , KC_C    , KC_R    , KC_L
                , CM(KC_D), SM(KC_H), CM(KC_T), AM(KC_N), KC_S    , KC_SLSH
                , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , KC_MINS
      , KC_SPC  , KC_TAB  , KC_RGUI , KC_RSFT , KC_RALT , KC_RGUI
    )
};
