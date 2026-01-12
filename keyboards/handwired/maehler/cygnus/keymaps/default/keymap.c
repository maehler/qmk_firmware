/* Copyright 2026 maehler
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum cygnus_layers {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _ADJUST,
};

enum cygnus_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCTION MO(_FUNCTION)
#define SFT_ENT MT(MOD_RSFT, KC_ENT)
#define FN_ESC LT(_FUNCTION, KC_ESC)

// QWERTY home row mods
#define A_LSFT LSFT_T(KC_A)
#define S_LALT LALT_T(KC_S)
#define D_LGUI LGUI_T(KC_D)
#define F_LCTL LCTL_T(KC_F)
#define J_RCTL RCTL_T(KC_J)
#define K_RGUI RGUI_T(KC_K)
#define L_RALT RALT_T(KC_L)
#define SCLN_RSFT RSFT_T(KC_SCLN)

// COLEMAK home row mods
#define R_LALT LALT_T(KC_R)
#define S_LGUI LGUI_T(KC_S)
#define T_LCTL LCTL_T(KC_T)
#define N_RCTL RCTL_T(KC_N)
#define E_RGUI RGUI_T(KC_E)
#define I_RALT RALT_T(KC_I)
#define O_RSFT RSFT_T(KC_O)

// Lower/raise left side
#define F2_LALT LALT_T(KC_F2)
#define F3_LGUI LGUI_T(KC_F3)
#define F4_LCTL LCTL_T(KC_F4)

// Raise right side
#define MINS_RCTL RCTL_T(KC_MINS)
#define EQL_RGUI RGUI_T(KC_EQL)
#define LBRC_RALT RALT_T(KC_LBRC)
#define RBRC_RSFT RSFT_T(KC_RBRC)

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',
    '*', '*', '*', 'L', 'L', 'L', 'R', 'R', 'R', '*', '*', '*'
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
      KC_TAB, KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,    KC_Y,   KC_U,   KC_I,     KC_O,    KC_P,      XXXXXXX,
      FN_ESC, A_LSFT,  S_LALT,  D_LGUI,   F_LCTL, KC_G,    KC_H,   J_RCTL, K_RGUI,   L_RALT,  SCLN_RSFT, KC_QUOT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,    KC_N,   KC_M,   KC_COMM,  KC_DOT,  KC_SLSH,   SFT_ENT,
     XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,  LOWER,  KC_BSPC, KC_SPC, RAISE,  KC_MPLY,  XXXXXXX, XXXXXXX,   XXXXXXX
  ),

[_COLEMAK] = LAYOUT(
      KC_TAB, KC_Q,    KC_W,    KC_F,     KC_P,   KC_G,    KC_J,   KC_L,   KC_U,     KC_Y,    KC_SCLN, XXXXXXX,
      FN_ESC, A_LSFT,  R_LALT,  S_LGUI,   T_LCTL, KC_D,    KC_H,   N_RCTL, E_RGUI,   I_RALT,  O_RSFT,  KC_QUOT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,    KC_K,   KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, SFT_ENT,
     XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,  LOWER,  KC_BSPC, KC_SPC, RAISE,  KC_MPLY,  XXXXXXX, XXXXXXX, XXXXXXX
  ),

[_LOWER] = LAYOUT(
     _______, KC_EXLM,   KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
     _______, KC_F1,     F2_LALT, F3_LGUI, F4_LCTL, KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
     _______, KC_F7,     KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TILD, KC_LT,   KC_GT,   KC_HOME, KC_END,
     _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

[_RAISE] = LAYOUT(
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,      KC_8,     KC_9,      KC_0,      _______,
     _______, KC_F1,   F2_LALT, F3_LGUI, F4_LCTL, KC_F5,  KC_F6,   MINS_RCTL, EQL_RGUI, LBRC_RALT, RBRC_RSFT, KC_BSLS,
     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,  _______,   KC_NUBS,  _______,   KC_PGUP,   KC_PGDN,
     _______, _______, _______, _______, _______, KC_DEL, _______, _______,   _______,  _______,   _______,   _______
  ),

[_FUNCTION] = LAYOUT(
     _______, _______, _______,   KC_UP, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

[_ADJUST] = LAYOUT(
     _______, _______, _______, KC_VOLD, _______, _______, _______, _______, KC_VOLU, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, QWERTY,  COLEMAK, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case A_LSFT:
        //     return 100;
        // case O_RSFT:
        //     return 100;
        // case SCLN_RSFT:
        //     return 100;
        default:
            return TAPPING_TERM;
    }
}
