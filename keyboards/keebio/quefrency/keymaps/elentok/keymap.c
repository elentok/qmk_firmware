// Copyright 2022 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layer {
    _BASE,
    _FN1,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_F1,                 KC_ESC,   QK_GESC, KC_1,         KC_2,         KC_3,         KC_4,           KC_5,             KC_6,     KC_7,           KC_8,         KC_9,         KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_HOME,
    KC_MEDIA_PLAY_PAUSE,   KC_VOLU,  KC_TAB,  KC_Q,         KC_W,         KC_E,         KC_R,           KC_T,             KC_Y,     KC_U,           KC_I,         KC_O,         KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    KC_F5,                 KC_VOLD,  KC_LCTL, LCTL_T(KC_A), LGUI_T(KC_S), LSFT_T(KC_D), LT(_FN1, KC_F), KC_G,             KC_H,     LT(_FN1, KC_J), RSFT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN),  KC_QUOT, KC_ENT,  KC_PGUP,
    KC_F7,                 KC_F8,    KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,           KC_B,             KC_N,     KC_M,           KC_COMM,      KC_DOT,       KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    KC_F9,                 KC_F10,   KC_LCTL, MO(_FN1),KC_LALT, KC_LGUI, KC_SPC,        _______,        LT(_FN1, KC_SPC), MO(_FN1), KC_RCTL,        _______,       KC_LEFT,      KC_DOWN, KC_RGHT
  ),

  [_FN1] = LAYOUT_65_with_macro(
    _______,               _______, QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______,
    _______,               _______, RGB_TOG, RGB_MOD, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,               _______, _______, _______, KC_LPRN, KC_RPRN, _______, KC_TAB, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______, _______, _______, _______,
    _______,               _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,               _______, KC_TILD, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
