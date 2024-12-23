// Copyright 2023 Olivier Peyrusse (@Kineolyan)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
#define UNICODE_KEY_LNX LCTL(LSFT(KC_U))
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
#define SPLIT_HAND_MATRIX_GRID_LOW_IS_LEFT
#define COMBO_VARIABLE_LEN
