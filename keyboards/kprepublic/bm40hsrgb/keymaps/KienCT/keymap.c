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
};

enum custom_keycodes {
    TT = SAFE_RANGE,
    CRY,
    SAD,
    CONFS,
    NEUTRL,
    SSMILE,
    SMILED,
    SMILEV,
    XD,
    LOLOL,
    ANGRY,
    EXPLSS,
    SHAKED,
    STUPID,
    CURRS,
    WOW,
    BLINK,
    TOUNGE,
    SNGLS,
    MEOW
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case TT:  
      if (record -> event.pressed) {
        SEND_STRING("T_T");
      }
      return false;
    case CRY:  
      if (record -> event.pressed) {
        SEND_STRING(":'(");
      }
      return false;
    case SAD:  
      if (record -> event.pressed) {
        SEND_STRING(":(");
      }
      return false;
    case CONFS:  
      if (record -> event.pressed) {
        SEND_STRING(":/");
      }
      return false;
    case NEUTRL:  
      if (record -> event.pressed) {
        SEND_STRING(":|");
      }
      return false;
    case SSMILE:  
      if (record -> event.pressed) {
        SEND_STRING(":)");
      }
      return false;
    case SMILED:  
      if (record -> event.pressed) {
        SEND_STRING(":D");
      }
      return false;
    case SMILEV:  
      if (record -> event.pressed) {
        SEND_STRING(":v");
      }
      return false;
    case XD:  
      if (record -> event.pressed) {
        SEND_STRING("xD");
      }
      return false;
    case LOLOL:  
      if (record -> event.pressed) {
        SEND_STRING("=)))))");
      }
      return false;
    case ANGRY:  
      if (record -> event.pressed) {
        SEND_STRING(">.<");
      }
      return false;
    case EXPLSS:  
      if (record -> event.pressed) {
        SEND_STRING("=_=");
      }
      return false;
    case SHAKED:  
      if (record -> event.pressed) {
        SEND_STRING("@@");
      }
      return false;
    case STUPID:  
      if (record -> event.pressed) {
        SEND_STRING("o_O");
      }
      return false;
    case CURRS:  
      if (record -> event.pressed) {
        SEND_STRING("( ._.)");
      }
      return false;
    case WOW:  
      if (record -> event.pressed) {
        SEND_STRING(":O");
      }
      return false;
    case BLINK:  
      if (record -> event.pressed) {
        SEND_STRING(";)");
      }
      return false;
    case TOUNGE:  
      if (record -> event.pressed) {
        SEND_STRING(":p");
      }
      return false;
    case SNGLS:  
      if (record -> event.pressed) {
        SEND_STRING("B)");
      }
      return false;
    case MEOW:  
      if (record -> event.pressed) {
        SEND_STRING(":3");
      }
      return false;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   '  |   ,  |   .  |   P  |   Y  |  Tab | Bksp |   F  |   G  |   C  |   R  |   L  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   O  |   E  |   U  |   I  | Ctrl | Alt  |   D  |   H  |   T  |   N  |  S   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ;  |   Q  |   J  |   K  |   X  | Shift| Enter|   B  |   M  |   W  |   V  |  Z   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   /  |  =   |  -   | Win  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
        KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_TAB, KC_BSPC, KC_F, KC_G, KC_C, KC_R, KC_L, 
        KC_A, KC_O, KC_E, KC_U, KC_I, KC_LCTL, KC_LALT, KC_D, KC_H, KC_T, KC_N, KC_S, 
        KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_LSFT, KC_ENT, KC_B, KC_M, KC_W, KC_V, KC_Z, 
        KC_SLSH, KC_EQL, KC_MINS, KC_LGUI, MO(1), KC_SPC, MO(2), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   7  |  8   |  9   |   (  |   )  |  Cap |  Del |   &  |   |  |   ~  |  `   |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   4  |  5   |   6  |   [  |  ]   |Layer4|      |   !  |   #  |   @  |   ^  |  $   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   1  |  2   |  3   |  {   |  }   |      | PrSc |RgbTog|RgbMd+| Hue+ | Val+ | Eff+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   0  |   *  |  %   |  esc |      |             |      | Home | PgDn | PgUp |  End |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12_1x2uC(
        KC_7, KC_8, KC_9, KC_LPRN, KC_RPRN, KC_CAPS, KC_DEL, KC_AMPR, KC_PIPE, KC_TILD, KC_GRV,  KC_BSLS, 
        KC_4, KC_5, KC_6, KC_LBRC, KC_RBRC, MO(4), KC_TRNS, KC_EXLM, KC_HASH, KC_AT, KC_CIRC, KC_DLR, 
        KC_1, KC_2, KC_3, KC_LCBR, KC_RCBR, KC_TRNS, KC_PSCR, RGB_TOG, RGB_MOD, RGB_HUI, RGB_VAI, RGB_SPI, 
        KC_0, KC_ASTR, KC_PERC, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   f1 |  f2  |  f3  |  f4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  T_T |  :'( |  :(  |  :/  |  :|  |      |      |  :)  |  :D  |  :v  |  xD  |=)))))|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  >.< |  =_= |  @@  | o_O  |( ._.)|      | Pause| :O   |  ;)  |  :p  |  B)  |  :3  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | undo |  cut | copy | paste|      |             |      | prev | volup| voldn| next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        TT, CRY, SAD, CONFS, NEUTRL, KC_TRNS, KC_TRNS, SSMILE, SMILED, SMILEV, XD, LOLOL, 
        ANGRY, EXPLSS, SHAKED, STUPID, CURRS, KC_TRNS, KC_MPLY, WOW, BLINK, TOUNGE, SNGLS, MEOW, 
        LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

//Dedicated layouts for reset button. Fn1 + Ctrl + Alt + Fn2
[_RESET] = LAYOUT_ortho_4x12_1x2uC(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_RESET1] = LAYOUT_ortho_4x12_1x2uC(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
};
