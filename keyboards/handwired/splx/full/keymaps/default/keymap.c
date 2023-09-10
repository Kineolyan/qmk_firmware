// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    PWR,
    NAV,
    WM,
};

const int prTap = QK_DYNAMIC_TAPPING_TERM_PRINT;
const int tapUp = QK_DYNAMIC_TAPPING_TERM_UP;
const int tapDw = QK_DYNAMIC_TAPPING_TERM_DOWN;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │MO1│ / │ - │
     * ├───┼───┼───┤
     * │ 1 │ 2 │ 3 │
     * └───┴───┴───┘
     */
    [BASE] = LAYOUT_vertical(
                      KC_SCLN     , KC_COMM     , KC_DOT      , KC_P        , KC_Y
      , KC_QUES     , ALT_T(KC_A) , CTL_T(KC_O) , SFT_T(KC_E) , MEH_T(KC_U) , GUI_T(KC_I)
      , KC_LSFT     , KC_QUOT     , KC_Q        , KC_J        , KC_K        , KC_X
                    , KC_LGUI     , KC_LALT     , KC_ESC      , MO(PWR)     , KC_ENTER   , LT(WM, KC_BSPC)

                    , KC_F        , KC_G        , KC_C        , KC_R        , KC_L
                    , GUI_T(KC_D) , MEH_T(KC_H) , SFT_T(KC_T) , CTL_T(KC_N) , ALT_T(KC_S), KC_SLSH
                    , KC_B        , KC_M        , KC_W        , KC_V        , KC_Z       , KC_MINS
      , KC_TAB      , KC_SPC      , MO(NAV)     , KC_ESC      , KC_RALT     , KC_RGUI
    ),
    [PWR] = LAYOUT_vertical(
                  KC_BSLS    , KC_PERC    , KC_LT      , KC_DLR     , KC_AMPR
      , KC_EQL  , ALT_T(KC_TILD), CTL_T(KC_LBRC), SFT_T(KC_LCBR), MEH_T(KC_LPRN), GUI_T(KC_ASTR)
      , KC_DOT  , KC_7       , KC_5       , KC_3       , KC_1       , KC_9
                , _______    , _______    , _______    , _______    , _______ , _______

                , KC_AT     , KC_GRAVE   , KC_GT      , KC_HASH    , KC_CIRC
                , GUI_T(KC_PLUS) , CTL_T(KC_RPRN), SFT_T(KC_RCBR), CTL_T(KC_RBRC), ALT_T(KC_PIPE) , KC_EXLM
                , KC_8      , KC_0       , KC_2       , KC_4       , KC_6    , KC_COMM
      , _______  , _______  , _______ , _______ , _______ , _______
    ),
    [NAV] = LAYOUT_vertical(
                  _______ , _______ , KC_MPRV , KC_MNXT    , _______
      , QK_BOOT , KC_LALT , KC_LCTL , KC_LSFT , MEH_T(KC_MPLY), GUI_T(KC_MSTP)
      , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    , XXXXXXX
                , prTap   , tapUp   , tapDw   , _______    , _______ , _______

                , RCS(KC_C), C(KC_C)    , C(KC_X) , _______ , _______
                , KC_HOME  , KC_LEFT    , KC_DOWN , KC_UP   , KC_RGHT , KC_END
                , RCS(KC_V), C(KC_V)    , XXXXXXX , XXXXXXX , XXXXXXX , _______
      , _______ , _______  , _______    , _______ , _______ , _______
    ),
    [WM] = LAYOUT_vertical(
                  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    , XXXXXXX
      , XXXXXXX , G(KC_1) , G(KC_2) , G(KC_3) , G(KC_4)    , G(KC_5)
      , XXXXXXX , KC_LALT , KC_LCTL , KC_LSFT , XXXXXXX    , XXXXXXX
                , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    , XXXXXXX , XXXXXXX

                , XXXXXXX  , G(KC_LEFT) , G(KC_DOWN), G(KC_UP), G(KC_RGHT)
                , G(KC_6)  , G(KC_7)    , G(KC_8)   , G(KC_9) , G(KC_0) , XXXXXXX
                , XXXXXXX  , XXXXXXX    , KC_LSFT   , KC_LCTL , KC_LALT , XXXXXXX
      , XXXXXXX , XXXXXXX  , XXXXXXX    , XXXXXXX   , XXXXXXX , XXXXXXX
    )
};
