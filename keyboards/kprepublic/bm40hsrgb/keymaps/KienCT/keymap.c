/* Copyright 2024 Tamkien Cao
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

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _RESET,
 _RESET1,
 _RESET2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  esc | Alt  |Lower |    Space    |Raise | /    | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_ENT, 
        KC_LCTL, KC_LGUI, KC_ESC, KC_LALT, MO(1), KC_SPC, MO(2), KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  | Prsc |   Up |CtAltL|  ins | home | pgup |   7  |   8  |   9  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | to(0)| left | down | right| del  | end  | pgdn |   4  |   5  |   6  |   -  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | shift| mute | vol +|vol - |play  |prev  |next  |   1  |   2  |   3  |  +   |enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | esc  |rgbtog|      |      |      |             |      |  0   |      |  [   |  ]   |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12_1x2uC(
        KC_GRV, KC_PSCR, KC_UP, LCA(KC_L), KC_INS, KC_HOME, KC_PGUP, KC_7, KC_8, KC_9, KC_ASTR, KC_BSPC, 
        TO(0), KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_END, KC_PGDN, KC_4, KC_5, KC_6, KC_MINS, KC_BSLS, 
        KC_LSFT, KC_MUTE, KC_VOLU, KC_VOLD, KC_MPLY, KC_MPRV, KC_MNXT, KC_1, KC_2, KC_3, KC_PLUS, KC_ENT, 
        KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, MO(3), KC_LBRC, KC_RBRC
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   f1 |  f2  |  f3  |  f4  |bl tog|rgbvai|   &  |  *   |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F5  |  F6  |  F7  |  F8  |blstep|rgbhui|   $  |  %   |   ^  |   -  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |rgbsai|  !   |  @   |  #   |  =   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |rgbmod|      |      |      |             |      |  ?   |Reset |  {   |  }   |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
        KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, BL_TOGG, RGB_VAI, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, 
        TO(1), KC_F5, KC_F6, KC_F7, KC_F8, BL_STEP, RGB_HUI, KC_DLR, KC_PERC, KC_CIRC, KC_UNDS, KC_PIPE, 
        KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, RGB_SAI, KC_EXLM, KC_AT, KC_HASH, KC_EQL, KC_ENT, 
        KC_TRNS, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_QUES, QK_BOOT, KC_LCBR, KC_RCBR
),

//Dedicated layouts for reset button. Lower + Left Arrow + R + 0,0 + 0,12
[_RESET] = LAYOUT_ortho_4x12_1x2uC(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_RESET1] = LAYOUT_ortho_4x12_1x2uC(
        MO(5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_RESET2] = LAYOUT_ortho_4x12_1x2uC(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

};

