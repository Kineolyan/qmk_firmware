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
  KGR_U,
};

typedef enum {
    NONE,
    SFT_QM, // `MO(SHFN)` on held, `?` when tapped
    MAJI_I // `I` on held, `i` when tapped
} td_keycodes_t;

// Enable gboard combos, as described here: https://docs.qmk.fm/features/combo
// To import after defining custom keycodes, to be able to use them from combos
#include "g/keymap_combo.h"

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
} td_state_t;

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
      , TD(SFT_QM)  , ALT_T(KC_A) , CTL_T(KC_O) , SFT_T(KC_E) , MEH_T(KC_U) , TD(MAJI_I)
      , KC_UNDS     , KC_QUOT     , KC_Q        , KC_J        , KC_K        , KC_X
                    , TG(SHFN)    , XXXXXXX     , OSM(MOD_LSFT) , MO(PWR)     , KC_ENTER   , LT(WM, KC_BSPC)

                    , KC_F        , KC_G        , KC_C        , KC_R        , KC_L
                    , GUI_T(KC_D) , MEH_T(KC_H) , SFT_T(KC_T) , CTL_T(KC_N) , ALT_T(KC_S), KC_SLSH
                    , KC_B        , KC_M        , KC_W        , KC_V        , KC_Z       , KC_MINS
      , LT(CSP, KC_TAB), KC_SPC   , MO(NAV)     , OSL(CSP)     , XXXXXXX     , KC_RGUI
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
      , _______ , KC_LALT , KC_LCTL , KC_LSFT , MEH_T(KC_MPLY), GUI_T(KC_MSTP)
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
      , QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    , KC_ESC
                , _______ , XXXXXXX , XXXXXXX , XXXXXXX    , KC_ENTER    , KC_SPC

                  , XXXXXXX   , KC_F1       , KC_F2        , KC_F3         , KC_F4
                  , XXXXXXX   , KC_F5       , KC_F6        , KC_F7         , KC_F8      , XXXXXXX
                  , XXXXXXX   , KC_F9       , KC_F10       , KC_F11        , KC_F12     , XXXXXXX
      , C(KC_LSFT), KC_LSFT   , KC_MEH      , A(KC_LSFT)   , _______       , _______
    )
};

typedef struct {
    td_state_t state;
    td_keycodes_t key;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state) {
    // Source
    // https://github.com/qmk/qmk_firmware/blob/9f76541b29056150cf57d69569a14a59e13995c7/docs/features/tap_dance.md#L222-L248
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }
    return TD_UNKNOWN;
}

// Handle the possible states for each tapdance keycode you define:
void gen_finished(tap_dance_state_t *state, void *user_data) {
    td_tap_t* tap_state = (td_tap_t*) user_data;
    tap_state->state = cur_dance(state);
    switch (tap_state->key) {
        case MAJI_I:
            switch (tap_state->state) {
                // Last case is for fast typing. Assuming your key is `f`:
                // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
                // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
                case TD_DOUBLE_SINGLE_TAP: tap_code(KC_I); // fallthrough
                case TD_SINGLE_TAP: register_code(KC_I); break;

                case TD_DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_I); break;

                // Assuming tap then hold
                case TD_DOUBLE_HOLD: tap_code(KC_I); // fallthrough
                case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
                default: break;
            }
            break;
        case SFT_QM:
            switch (tap_state->state) {
                case TD_SINGLE_TAP: register_code16(KC_QUES); break;
                case TD_SINGLE_HOLD: layer_on(SHFN); break;
                default: break;
            }
            break;
        case NONE: break;
    }
}

void gen_reset(tap_dance_state_t *state, void *user_data) {
    td_tap_t* tap_state = (td_tap_t*) user_data;
    switch (tap_state->key) {
        case MAJI_I:
            switch (tap_state->state) {
                case TD_DOUBLE_SINGLE_TAP:
                case TD_SINGLE_TAP: unregister_code(KC_I); break;

                case TD_DOUBLE_TAP: unregister_code(KC_I); unregister_code(KC_LSFT); break;

                case TD_SINGLE_HOLD:
                case TD_DOUBLE_HOLD: unregister_code(KC_LGUI); break;
                default: break;
            }
            break;
        case SFT_QM:
            switch (tap_state->state) {
                case TD_SINGLE_TAP: unregister_code16(KC_QUES); break;
                case TD_SINGLE_HOLD: layer_off(SHFN); break;
                default: break;
            }
        case NONE: break;
    }
    tap_state->state = TD_NONE;
}

#define TD_WITH_KEY(tap_code) ((td_tap_t) { .state = TD_NONE, .key = tap_code, })

#define ACTION_TAP_DANCE(state) \
    { .fn = {NULL, gen_finished, gen_reset}, .user_data = &state, }

tap_dance_action_t tap_dance_actions[] = {
    [SFT_QM] = ACTION_TAP_DANCE(TD_WITH_KEY(SFT_QM)),
    [MAJI_I] = ACTION_TAP_DANCE(TD_WITH_KEY(MAJI_I)),
};
