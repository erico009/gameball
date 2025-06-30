// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _CENTER 537
#define _DEAD 150
bool wasdMode = false;
bool arrowMode = false;
#define _DOWN_TRESHOLD (_CENTER+_DEAD)
#define _UP_TRESHOLD (_CENTER-_DEAD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,		KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,		KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
    	KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,		KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F13 ,		KC_ENT , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    	KC_LCTL, KC_LGUI, KC_LALT, MO(1),   KC_SPC,  KC_SPC,  KC_DEL ,		KC_SPC , KC_ENT,  KC_SPC,  KC_LEFT, KC_DOWN, MS_BTN4, MS_BTN5
    ),

    [1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LBRC,		KC_RBRC, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
    	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,		KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
    	KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,		KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F13 ,		KC_ENT , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    	KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_DEL ,		KC_SPC , KC_ENT,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(QK_MOUSE_WHEEL_UP, QK_MOUSE_WHEEL_DOWN)},
    [1] = { ENCODER_CCW_CW(QK_MOUSE_WHEEL_UP, QK_MOUSE_WHEEL_DOWN)},
};
#endif

#if defined(COMBO_ENABLE)
const uint16_t PROGMEM mouse_combo1[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM mouse_combo2[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM mouse_combo3[] = {KC_J, KC_L, COMBO_END};
combo_t key_combos[] = {
    COMBO(mouse_combo1, MS_BTN1),
    COMBO(mouse_combo2, MS_BTN2),
    COMBO(mouse_combo3, MS_BTN3),
};
#endif

#ifdef JOYSTICK_ENABLE
#include "joystick.h"
#include "analog.h"
joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_IN(GP26, 830, 540, 270),
    JOYSTICK_AXIS_IN(GP27, 830, 535, 270),
};
  int16_t xPos = 0;
  int16_t yPos = 0;

  bool yDownHeld = false;
  bool yUpHeld = false;
  bool xLeftHeld = false;
  bool xRightHeld = false;
void matrix_scan_user(void) {
    if (wasdMode) {
      yPos = analogReadPin(GP27);
        if (!yDownHeld && yPos >= _DOWN_TRESHOLD) {
          register_code(KC_W);
          yDownHeld = true;
        } else if (yDownHeld && yPos < _DOWN_TRESHOLD) {
          yDownHeld = false;
          unregister_code(KC_W);
        } else if (!yUpHeld && yPos <= _UP_TRESHOLD) {
          yUpHeld = true;
          register_code(KC_S);
        } else if (yUpHeld && yPos > _UP_TRESHOLD) {
          yUpHeld = false;
          unregister_code(KC_S);
        }
      
      xPos = analogReadPin(GP26);
      if (!xLeftHeld && xPos >= _DOWN_TRESHOLD) {
        register_code(KC_A);
        xLeftHeld = true;
      } else if (xLeftHeld && xPos < _DOWN_TRESHOLD) {
        xLeftHeld = false;
        unregister_code(KC_A);
      } else if (!xRightHeld && xPos <= _UP_TRESHOLD) {
        xRightHeld = true;
        register_code(KC_D);
      } else if (xRightHeld && xPos > _UP_TRESHOLD) {
        xRightHeld = false;
        unregister_code(KC_D);
      }
    }
	else if (arrowMode) {
      yPos = analogReadPin(GP27);
        if (!yDownHeld && yPos >= _DOWN_TRESHOLD) {
          register_code(KC_UP);
          yDownHeld = true;
        } else if (yDownHeld && yPos < _DOWN_TRESHOLD) {
          yDownHeld = false;
          unregister_code(KC_UP);
        } else if (!yUpHeld && yPos <= _UP_TRESHOLD) {
          yUpHeld = true;
          register_code(KC_DOWN);
        } else if (yUpHeld && yPos > _UP_TRESHOLD) {
          yUpHeld = false;
          unregister_code(KC_DOWN);
        }
      
      xPos = analogReadPin(GP26);
      if (!xLeftHeld && xPos >= _DOWN_TRESHOLD) {
        register_code(KC_LEFT);
        xLeftHeld = true;
      } else if (xLeftHeld && xPos < _DOWN_TRESHOLD) {
        xLeftHeld = false;
        unregister_code(KC_LEFT);
      } else if (!xRightHeld && xPos <= _UP_TRESHOLD) {
        xRightHeld = true;
        register_code(KC_RIGHT);
      } else if (xRightHeld && xPos > _UP_TRESHOLD) {
        xRightHeld = false;
        unregister_code(KC_RIGHT);
      }
    }
  }
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == KC_F13 && record->event.pressed) {
    if (!wasdMode && !arrowMode) {
      wasdMode = true;
    } else if (wasdMode){
      wasdMode = false;
	  arrowMode = true;
    } else if (arrowMode){
		arrowMode = false;
	}
  }
  return true;
};