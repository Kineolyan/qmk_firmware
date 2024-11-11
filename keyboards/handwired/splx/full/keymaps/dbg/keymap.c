// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
// Debug mapping with only two keys (thumbs)

#include QMK_KEYBOARD_H

enum custom_keycodes {
    KC_P00 = SAFE_RANGE
};

enum layers {
    BASE,
};

enum td_keycodes {
    SFT_QM // `MO(SHFN)` on held, `?` when tapped
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
} td_state_t;

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void sftqm_finished(tap_dance_state_t *state, void *user_data);
void sftqm_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_dbg(KC_L, KC_R)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
