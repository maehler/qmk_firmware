#include QMK_KEYBOARD_H

enum custom_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define FUNCTION MO(_FUNCTION)

#define FN_ESC LT(FUNCTION, KC_ESC)
#define SFT_ENT MT(MOD_RSFT, KC_ENT)

enum combo_events {
  OE_LC_COMBO,
  OE_UC_COMBO,
  AE_LC_COMBO,
  AE_UC_COMBO,
  AA_LC_COMBO,
  AA_UC_COMBO,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM oe_lc_combo[] = {FN_ESC, KC_SCLN, COMBO_END};
const uint16_t PROGMEM oe_uc_combo[] = {FN_ESC, KC_A, KC_SCLN, COMBO_END};
const uint16_t PROGMEM ae_lc_combo[] = {FN_ESC, KC_QUOT, COMBO_END};
const uint16_t PROGMEM ae_uc_combo[] = {FN_ESC, KC_A, KC_QUOT, COMBO_END};
const uint16_t PROGMEM aa_lc_combo[] = {FN_ESC, KC_LBRC, COMBO_END};
const uint16_t PROGMEM aa_uc_combo[] = {FN_ESC, KC_A, KC_LBRC, COMBO_END};

combo_t key_combos[] = {
  [OE_LC_COMBO] = COMBO_ACTION(oe_lc_combo),
  [OE_UC_COMBO] = COMBO_ACTION(oe_uc_combo),
  [AE_LC_COMBO] = COMBO_ACTION(ae_lc_combo),
  [AE_UC_COMBO] = COMBO_ACTION(ae_uc_combo),
  [AA_LC_COMBO] = COMBO_ACTION(aa_lc_combo),
  [AA_UC_COMBO] = COMBO_ACTION(aa_uc_combo)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mute | Ctrl | Alt  | GUI  |Lower | Bksp |Space |Raise | GUI  | Alt  | Ctrl |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    FN_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
    KC_MUTE, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_BSPC, KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL, _______
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC,
  FN_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT ,
  KC_MUTE, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_BSPC, KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TILD, KC_LT,   KC_GT,   KC_HOME, KC_END,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_NUBS, _______, KC_PGUP, KC_PGDN,
  _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, KC_MPLY
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |  Up  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Left | Down |Right |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_4x12(
    _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______,   _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______,   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12(
  _______, RESET,   DEBUG,   KC_VOLD, KC_MPRV, _______, _______, KC_MNXT, KC_VOLU, KC_MUTE, _______, _______,
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case AA_LC_COMBO:
      if (pressed) {
        register_code(KC_CAPS);
        tap_code(KC_LBRC);
        unregister_code(KC_CAPS);
      }
      break;
    case AA_UC_COMBO:
      if (pressed) {
        register_code(KC_CAPS);
        tap_code16(LSFT(KC_LBRC));
        unregister_code(KC_CAPS);
      }
      break;
    case OE_LC_COMBO:
      if (pressed) {
        register_code(KC_CAPS);
        tap_code(KC_SCLN);
        unregister_code(KC_CAPS);
      }
      break;
    case OE_UC_COMBO:
      if (pressed) {
        register_code(KC_CAPS);
        tap_code16(LSFT(KC_SCLN));
        unregister_code(KC_CAPS);
      }
      break;
    case AE_LC_COMBO:
      if (pressed) {
        register_code(KC_CAPS);
        tap_code(KC_QUOT);
        unregister_code(KC_CAPS);
      }
      break;
    case AE_UC_COMBO:
      if (pressed) {
        register_code(KC_CAPS);
        tap_code16(LSFT(KC_QUOT));
        unregister_code(KC_CAPS);
      }
      break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
  }
  return true;
}
