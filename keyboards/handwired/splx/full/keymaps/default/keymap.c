// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    PWR,
    NAV,
    WM,
    CSP,
    SHFN,
};

enum custom_keycodes {
  KCR_A = SAFE_RANGE,
  KCR_E,
  KCR_I,
  KCR_O,
  KCR_U,
  KGR_A,
  KGR_E,
  KGR_U
};

// void send_grave(char* const key) {
//     SEND_STRING(SS_RALT("^") key);
// }
#define SEND_CIRC(key) SEND_STRING(SS_RALT("6") key);
#define SEND_GRAVE(key) SEND_STRING(SS_RALT("`") key);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case KCR_A:
            SEND_CIRC("a");
            break;
        case KCR_E:
            SEND_CIRC("e");
            break;
        case KCR_I:
            SEND_CIRC("i");
            break;
        case KCR_O:
            SEND_CIRC("o");
            break;
        case KCR_U:
            SEND_CIRC("u");
            break;
        case KGR_A:
            SEND_GRAVE("a");
            break;
        case KGR_E:
            SEND_GRAVE("e");
            break;
        case KGR_U:
            SEND_GRAVE("u");
            break;
        }
    }
    return true;
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
      , KC_UNDS     , KC_QUOT     , KC_Q        , KC_J        , KC_K        , KC_X
                    , MO(SHFN)    , XXXXXXX     , OSM(MOD_LSFT) , MO(PWR)     , KC_ENTER   , LT(WM, KC_BSPC)

                    , KC_F        , KC_G        , KC_C        , KC_R        , KC_L
                    , GUI_T(KC_D) , MEH_T(KC_H) , SFT_T(KC_T) , CTL_T(KC_N) , ALT_T(KC_S), KC_SLSH
                    , KC_B        , KC_M        , KC_W        , KC_V        , KC_Z       , KC_MINS
      , LT(CSP, KC_TAB), KC_SPC   , MO(NAV)     , MO(CSP)     , XXXXXXX     , KC_RGUI
    ),
    // Do not use tap-hold mode in this layer, using a lot of shifted keys
    [PWR] = LAYOUT_vertical(
                  KC_BSLS    , KC_PERC    , KC_LT      , KC_DLR     , KC_AMPR
      , KC_EQL  , KC_TILD    , KC_LBRC    , KC_LCBR    , KC_LPRN    , KC_ASTR
      , KC_DOT  , KC_7       , KC_5       , KC_3       , KC_1       , KC_9
                , KC_LALT    , KC_LCTL    , KC_LSFT    , KC_LGUI    , _______ , _______

                , KC_AT     , KC_GRAVE   , KC_GT      , KC_HASH    , KC_CIRC
                , KC_PLUS   , KC_RPRN    , KC_RCBR    , KC_RBRC    , KC_PIPE , KC_EXLM
                , KC_8      , KC_0       , KC_2       , KC_4       , KC_6    , KC_COMM
      , _______ , _______   , KC_RGUI    , KC_RSFT    , KC_RCTL    , KC_RALT
    ),
    [NAV] = LAYOUT_vertical(
                  _______ , _______ , KC_MPRV , KC_MNXT    , _______
      , QK_BOOT , KC_LALT , KC_LCTL , KC_LSFT , MEH_T(KC_MPLY), GUI_T(KC_MSTP)
      , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    , XXXXXXX
                , prTap   , tapUp   , tapDw   , _______    , _______ , _______

                , XXXXXXX  , RCS(KC_C), C(KC_C)   , C(KC_X) , _______
                , KC_HOME  , KC_LEFT    , KC_DOWN , KC_UP   , KC_RGHT , KC_END
                , XXXXXXX  , RCS(KC_V), C(KC_V)   , XXXXXXX , XXXXXXX , _______
      , _______ , _______  , _______    , _______ , _______ , _______
    ),
    [WM] = LAYOUT_vertical(
                     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    , XXXXXXX
      , XXXXXXX    , G(KC_1) , G(KC_2) , G(KC_3) , G(KC_4)    , G(KC_5)
      , XXXXXXX    , KC_LALT , KC_LCTL , KC_LSFT , G(KC_K)    , XXXXXXX
                   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    , XXXXXXX , XXXXXXX

                   , XXXXXXX  , G(KC_LEFT)  , G(KC_DOWN), G(KC_UP), G(KC_RGHT)
                   , G(KC_6)  , G(KC_7)     , G(KC_8)   , G(KC_9) , G(KC_0) , XXXXXXX
                   , XXXXXXX  , XXXXXXX     , KC_LSFT   , KC_LCTL , KC_LALT , XXXXXXX
      , G(KC_ENTER), XXXXXXX  , LSG(KC_SCLN), XXXXXXX   , XXXXXXX , XXXXXXX
    ),
    [CSP] = LAYOUT_vertical(
                  KCR_A        , KCR_O      , KCR_E      , KCR_U      , KCR_I
      , KC_BSLS , KGR_A        , XXXXXXX    , RALT(KC_E) , KGR_U      , RALT(KC_J)
      , KC_LSFT , RALT(KC_COMM), XXXXXXX    , KGR_E      , RALT(KC_Y) , RALT(KC_COMM)
                , _______      , _______    , _______    , _______    , _______       , _______

                , XXXXXXX   , UC(0x2026)  , UC(0xB7)     , UC(0xD7)      , UC(0xB1)
                , XXXXXXX   , RSA(KC_QUOT), RALT(KC_QUOT), RALT(KC_GRAVE), RALT(KC_6) , XXXXXXX
                , XXXXXXX   , RALT(KC_5)  , XXXXXXX      , XXXXXXX       , XXXXXXX    , KC_RSFT
      , _______ , _______   , _______     , _______      , _______       , _______
    ),
    [SHFN] = LAYOUT_vertical(
                  XXXXXXX , XXXXXXX , C(KC_Z) , C(KC_Y)    , KC_BSPC
      , _______ , XXXXXXX , C(KC_X) , C(KC_C) , C(KC_V)    , KC_DEL
      , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    , KC_ESC
                , KC_LALT , KC_LCTL , KC_LSFT , KC_LGUI    , KC_ENTER, KC_SPC

                , XXXXXXX   , KC_F1       , KC_F2        , KC_F3         , KC_F4
                , XXXXXXX   , KC_F5       , KC_F6        , KC_F7         , KC_F8      , XXXXXXX
                , XXXXXXX   , KC_F9       , KC_F10       , KC_F11        , KC_F12     , XXXXXXX
      , _______ , _______   , _______     , _______      , _______       , _______
    )
};

enum combos {
  KM_ESC,
  GC_EQL,
  CR_AT,
  DTP_EXLM,
  GR_ACUTE,
  HR_AGRAVE,
  MR_ACIRC,
  FR_ADIAR,
};

const uint16_t PROGMEM km_combo[] = {KC_K, KC_M, COMBO_END};
const uint16_t PROGMEM gc_combo[] = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM cr_combo[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM ltp_combo[] = {KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM gr_combo[] = {KC_G, KC_R, COMBO_END};
const uint16_t PROGMEM hr_combo[] = {KC_H, KC_R, COMBO_END};
const uint16_t PROGMEM mr_combo[] = {KC_M, KC_R, COMBO_END};
const uint16_t PROGMEM fr_combo[] = {KC_F, KC_R, COMBO_END};

combo_t key_combos[] = {
  [KM_ESC] = COMBO(km_combo, KC_ESC),
  [GC_EQL] = COMBO(gc_combo, KC_EQL),
  [CR_AT] = COMBO(cr_combo, KC_AT),
  [DTP_EXLM] = COMBO(ltp_combo, KC_EXLM),
  [GR_ACUTE] = COMBO(gr_combo, RALT(KC_QUOT)),
  [HR_AGRAVE] = COMBO(hr_combo, RALT(KC_GRAVE)),
  [MR_ACIRC] = COMBO(mr_combo, RALT(KC_6)),
  [FR_ADIAR] = COMBO(fr_combo, RSA(KC_QUOT)),
};
