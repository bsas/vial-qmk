/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2023 Bernardo Silva <@bsas>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MO4,
  _MO5
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_SPC,     KC_ENT,   RAISE, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_MO4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______,  _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_MO5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______,  _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

char layer_misc[7];
char wpm[4];

void oled_render_layer_state(void) {
    oled_write_P(PSTR("\nLayer: "), false);

	sprintf(layer_misc, "<%01d>", get_highest_layer(layer_state));
	oled_write(layer_misc, false);
	
    oled_write_P(PSTR(" | "), false);
    sprintf(wpm, "%03d", get_current_wpm());
    oled_write(wpm, false);
    oled_write_P(PSTR(" wpm"), false);

    oled_write_P(PSTR("\n\n"), false);
	led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("Locks: [CAP|") : PSTR("Locks: [   |"), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR|") : PSTR("   |"), false);
    oled_write_P(led_state.num_lock ? PSTR("NUM]") : PSTR("   ]"), false);
}

void render_bootmagic_status(bool status) {
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

#ifndef QK_MOD_TAP_GET_TAP_KEYCODE
#define QK_MOD_TAP_GET_TAP_KEYCODE(kc) ((kc)&0xFF)
#define IS_QK_MOD_TAP(code) ((code) >= QK_MOD_TAP && (code) <= QK_MOD_TAP_MAX)
#define IS_QK_TAP_DANCE(code) ((code) >= QK_TAP_DANCE && (code) <= QK_TAP_DANCE_MAX)
#define IS_QK_MOMENTARY(code) ((code) >= QK_MOMENTARY && (code) <= QK_MOMENTARY_MAX)
#define QK_MOMENTARY_GET_LAYER(kc) ((kc)&0x1F)
#define IS_QK_LAYER_TAP(code) ((code) >= QK_LAYER_TAP && (code) <= QK_LAYER_TAP_MAX)
#define QK_LAYER_TAP_GET_TAP_KEYCODE(kc) ((kc)&0xFF)
#endif

const char keyicon(const uint8_t layer, const uint8_t row, const uint8_t col) {
	char icon = 0x20;
	int keycode = keymap_key_to_keycode(layer, (keypos_t){.row = row, .col = col});
	
	if (IS_QK_MOMENTARY(keycode)) {
		icon = 0x30 + QK_MOMENTARY_GET_LAYER(keycode);
		keycode = -1;
	} else if (IS_QK_LAYER_TAP(keycode)) {
		keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
	} else if (IS_QK_MOD_TAP(keycode)) {
		keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
	} else if (IS_QK_TAP_DANCE(keycode)) {
		uint8_t idx = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
		vial_tap_dance_entry_t td = { 0 };
		dynamic_keymap_get_tap_dance(idx, &td);
		keycode = td.on_tap;
	}
	
	switch (keycode) {
		// TRNS
		case KC_TRNS: icon=0xB4; break;
		
		// Mods
		case KC_TAB: icon=0x10; break;
		case KC_ESC:
		case QK_GESC: icon=0x1C; break;
		case KC_BACKSPACE: icon=0x11; break;
		case KC_PRINT_SCREEN: icon=0x9E; break;
		case KC_CAPS_LOCK:
		case KC_LEFT_SHIFT:
		case KC_RIGHT_SHIFT: icon=0x1E; break;
		case KC_ENTER: 
		case SC_SENT: icon=0x94; break;
		case KC_SPACE: icon=0x16; break;
		case KC_RGUI:
		case KC_LGUI: icon=0x77; break;
		case KC_RIGHT_ALT:
		case KC_LEFT_ALT: icon=0x61; break;
		case KC_RIGHT_CTRL:
		case KC_LEFT_CTRL: icon=0x63; break;
		
		// Navigation
		case KC_INSERT: icon=0x69; break;
		case KC_DELETE: icon=0x64; break;
		case KC_HOME: icon=0x68; break;
		case KC_END: icon=0x65; break;
		case KC_PAGE_UP: icon=0x1E; break;
		case KC_PAGE_DOWN: icon=0x1F; break;
		
		// Symbols
		case KC_COMMA: icon=0x2C; break;
		case KC_DOT: icon=0x2E; break;
		case KC_SLASH: icon=0x2F; break;
		case KC_BACKSLASH: icon=0x5C; break;
		case KC_SEMICOLON: icon=0x3B; break;
		case KC_MINUS: icon=0x2D; break;
		case KC_QUOTE: icon=0x27; break;
		case KC_EQUAL: icon=0x3D; break;
		case KC_LEFT_BRACKET: icon=0x5B; break;
		case KC_RIGHT_BRACKET: icon=0x5D; break;
		case KC_GRAVE: icon=0x60; break;
		
		// Shifted symbols
		case SC_RCPC:
		case LSFT(KC_0): icon=0x29; break;
		case LSFT(KC_1): icon=0x21; break;
		case LSFT(KC_2): icon=0x40; break;
		case LSFT(KC_3): icon=0x23; break;
		case LSFT(KC_4): icon=0x24; break;
		case LSFT(KC_5): icon=0x25; break;
		case LSFT(KC_6): icon=0x5E; break;
		case LSFT(KC_7): icon=0x26; break;
		case LSFT(KC_8): icon=0x2A; break;
		case SC_LAPO:
		case LSFT(KC_9): icon=0x28; break;
		case LSFT(KC_MINUS): icon=0x5F; break;
		case LSFT(KC_EQUAL): icon=0x2B; break;
		case LSFT(KC_BACKSLASH): icon=0x7C; break;
		case LSFT(KC_LEFT_BRACKET): icon=0x7B; break;
		case LSFT(KC_RIGHT_BRACKET): icon=0x7D; break;
		case LSFT(KC_GRAVE): icon=0x22; break;
		
		// Arrows
		case KC_UP: icon=0x18; break;
		case KC_DOWN: icon=0x19; break;
		case KC_LEFT: icon=0x1B; break;
		case KC_RIGHT: icon=0x1A; break;
		
		// Mouse
		case KC_MS_U: icon=0x18; break;
		case KC_MS_D: icon=0x19; break;
		case KC_MS_L: icon=0x1B; break;
		case KC_MS_R: icon=0x1A; break;
		case KC_BTN1: icon=0xBD; break;
		case KC_BTN2: icon=0x9D; break;
		case KC_WH_U: icon=0x7F; break;
		case KC_WH_D: icon=0x9F; break;
		
		// Media keys
		case KC_VOLU: icon=0xBE; break;
		case KC_VOLD: icon=0xBF; break;
		
		// F keys
		case KC_F1 ... KC_F12: icon=(keycode - KC_F1 + 0xD4); break;
		
		// letters
		case KC_A ... KC_Z: icon=(keycode - KC_A + 0x41); break;
		
		// numbers
		case KC_0: icon=0x30; break;
		case KC_1 ... KC_9: icon=(keycode - KC_1 + 0x31); break;
	}
	
	return icon;
}

void oled_render_logo(void) {
	short unsigned int idx = get_highest_layer(layer_state);
	char lnum = (48 + idx);
	
	// Original Corne logo with layer number
	/*
    char crkbd_logo[] = {
        0x80, lnum, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x93,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb3,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd3,
        0x00};
	*/
	
	// Without thumb cluster + Corne logo with layer number
	/*
	char crkbd_logo[] = {
		0x20, keyicon(idx, 0, 0), keyicon(idx, 0, 1), keyicon(idx, 0, 2), keyicon(idx, 0, 3), keyicon(idx, 0, 4), keyicon(idx, 0, 5),
		0x20, lnum, 0x82, 0x83, 0x84, 0x85,
		0x20, keyicon(idx, 4, 5), keyicon(idx, 4, 4), keyicon(idx, 4, 3), keyicon(idx, 4, 2), keyicon(idx, 4, 1), keyicon(idx, 4, 0), 0x20,
		0x20, keyicon(idx, 1, 0), keyicon(idx, 1, 1), keyicon(idx, 1, 2), keyicon(idx, 1, 3), keyicon(idx, 1, 4), keyicon(idx, 1, 5),
		0x20, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5,
		0x20, keyicon(idx, 5, 5), keyicon(idx, 5, 4), keyicon(idx, 5, 3), keyicon(idx, 5, 2), keyicon(idx, 5, 1), keyicon(idx, 5, 0), 0x20,
		0x20, keyicon(idx, 2, 0), keyicon(idx, 2, 1), keyicon(idx, 2, 2), keyicon(idx, 2, 3), keyicon(idx, 2, 4), keyicon(idx, 2, 5),
		0x20, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5,
		0x20, keyicon(idx, 6, 5), keyicon(idx, 6, 4), keyicon(idx, 6, 3), keyicon(idx, 6, 2), keyicon(idx, 6, 1), keyicon(idx, 6, 0), 0x20,
		0x00};
	*/
	
	// With thumb cluster
	char crkbd_logo[] = {
		0x20, keyicon(idx, 0, 0), keyicon(idx, 0, 1), keyicon(idx, 0, 2), keyicon(idx, 0, 3), keyicon(idx, 0, 4), keyicon(idx, 0, 5),
		0x20, keyicon(idx, 3, 3), 0x20, 0x20, 0x20, keyicon(idx, 7, 3),
		0x20, keyicon(idx, 4, 5), keyicon(idx, 4, 4), keyicon(idx, 4, 3), keyicon(idx, 4, 2), keyicon(idx, 4, 1), keyicon(idx, 4, 0), 0x20,
		0x20, keyicon(idx, 1, 0), keyicon(idx, 1, 1), keyicon(idx, 1, 2), keyicon(idx, 1, 3), keyicon(idx, 1, 4), keyicon(idx, 1, 5),
		0x20, keyicon(idx, 3, 4), 0x20, lnum, 0x20, keyicon(idx, 7, 4), 
		0x20, keyicon(idx, 5, 5), keyicon(idx, 5, 4), keyicon(idx, 5, 3), keyicon(idx, 5, 2), keyicon(idx, 5, 1), keyicon(idx, 5, 0), 0x20,
		0x20, keyicon(idx, 2, 0), keyicon(idx, 2, 1), keyicon(idx, 2, 2), keyicon(idx, 2, 3), keyicon(idx, 2, 4), keyicon(idx, 2, 5),
		0x20, keyicon(idx, 3, 5), 0x20, 0x20, 0x20, keyicon(idx, 7, 5), 
		0x20, keyicon(idx, 6, 5), keyicon(idx, 6, 4), keyicon(idx, 6, 3), keyicon(idx, 6, 2), keyicon(idx, 6, 1), keyicon(idx, 6, 0), 0x20,
		0x00};
	
	oled_write_P(crkbd_logo, false);
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        //oled_render_layer_state();
		oled_render_logo();
    } else {
        //oled_render_logo();
		oled_render_layer_state();
    }
    return false;
}

#endif // OLED_ENABLE

bool should_process_keypress(void) {
	return true;
}
