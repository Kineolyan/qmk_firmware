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

enum td_keycodes {
    SFT_QM // `MO(SHFN)` on held, `?` when tapped
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
} td_state_t;

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void sftqm_finished(tap_dance_state_t *state, void *user_data);
void sftqm_reset(tap_dance_state_t *state, void *user_data);

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

enum combos {
  KM_ESC,
};

const uint16_t PROGMEM km_combo[] = {KC_K, KC_M, COMBO_END};

combo_t key_combos[] = {
  [KM_ESC] = COMBO(km_combo, KC_ESC),
};


td_state_t cur_dance(tap_dance_state_t *state) {
    return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:
// static td_state_t td_state;

void sftqm_finished(tap_dance_state_t *state, void *user_data) {
}

void sftqm_reset(tap_dance_state_t *state, void *user_data) {
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
    [SFT_QM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sftqm_finished, sftqm_reset)
};
