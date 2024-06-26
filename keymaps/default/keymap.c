// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

//ENCODER
#include QMK_KEYBOARD_H
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  }
};
#endif

//KEYMAP
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,KC_GRV,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINS,KC_EQL,KC_BSPC,KC_F9,
        KC_F1,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS,KC_F10,
        KC_F2,KC_CAPS,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_ENT,KC_F11,
        KC_F3,KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,KC_UP,KC_F12,
        KC_F4,KC_LCTL,MO(1),KC_LWIN,KC_LALT,KC_SPC,KC_SPC,KC_SPC,KC_SPC,KC_RALT,MO(1),KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT
    ),
    [1] = LAYOUT(
        KC_ESC,KC_GRV,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINS,KC_EQL,KC_BSPC,KC_F9,
        KC_F1,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS,KC_F10,
        KC_F2,KC_CAPS,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_ENT,KC_F11,
        KC_F3,KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,KC_UP,KC_F12,
        KC_F4,KC_LCTL,KC_NO,KC_LWIN,KC_LALT,KC_SPC,KC_SPC,KC_SPC,KC_SPC,KC_RALT,KC_NO,KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT
    )
};
/*
// RGB
led_config_t g_led_config = { {
  // Key Matrix to LED Index
{35,34,33,32,31,30,29,28,NO_LED},
{21,22,23,24,25,26,27,NO_LED,NO_LED},
{20,19,18,17,16,15,14,NO_LED,NO_LED},
{7,8,9,10,11,12,13,NO_LED,NO_LED},
{6,5,4,3,2,1,0,NO_LED,NO_LED},
{70,71,72,73,74,75,NO_LED,76,77},
{69,68,67,66,65,64,63,62,61},
{53,54,55,56,57,58,NO_LED,59,60},
{52,51,50,49,48,47,46,45,44},
{36,37,NO_LED,38,39,40,41,42,43}
}, 
{
  {94, 64},{82, 64},{69, 64},{54, 64},{40, 64},{24, 64},{5, 64},
  {5, 48},{30, 48},{49, 48},{61, 48},{73, 48},{84, 48},{96, 48},
  {91, 32},{80, 32},{68, 32},{56, 32},{44, 32},{28, 32},{5, 32},
  {5, 16},{25, 16},{41, 16},{53, 16},{64, 16},{76, 16},{88, 16},
  {94, 0},{82, 0},{70, 0},{58, 0},{47, 0},{35, 0},{23, 0},{5, 0},
  {112, 64},{123, 64},{139, 64},{155, 64},{169, 64},{192, 64},{203, 64},
  {218, 48},{203, 48},{183, 48},{168, 48},{156, 48},{145, 48},{133, 48},{121, 48},{109, 48},
  {114, 32},{126, 32},{137, 32},{149, 32},{161, 32},{173, 32},{193, 32},{218, 32},
  {218, 16},{196, 16},{182, 16},{170, 16},{159, 16},{147, 16},{135, 16},{123, 16},{112, 16},
  {117, 0},{129, 0},{141, 0},{153, 0},{165, 0},{176, 0},{194, 0},{218, 0}
}, {
  4,4,1,4,4,1,4,
  4,1,4,4,4,4,4,
  4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,
  4,4,4,1,1,4,4,4,
  4,4,1,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4
} 
};
*/