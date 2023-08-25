// keyboards/splitkb/kyria/keymaps/maartenq/keymap.c

#include QMK_KEYBOARD_H

enum combos {
  FJ_CTL_B,
  ASCLN_CTL_BS
};

const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM ascln_combo[] = {KC_A, KC_SCLN, COMBO_END};

combo_t key_combos[] = {
  [FJ_CTL_B] = COMBO(fj_combo, LCTL(KC_B)),
  [ASCLN_CTL_BS] = COMBO(ascln_combo, KC_BSLS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer 0

  ,----------------------------------.                ,----------------------------------.
  |      |      |      |      |      |                |      |      |      |      |      |
  |   Q  |   W  |   E  |   R  |   T  |                |  Y   |  U   |  I   |  O   |  P   |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |      |      |                |      |      |      |      |  :   |
  |   A  |   S  |   D  |   F  |   G  |                |  H   |  J   |  K   |  L   |  ;   |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |   ⌥  |   ⌘  |                |  ⌘   |  ⌥   |  <   |  >   |  ?   |
  |   Z  |   X  |   C  |   V  |   B  |                |  N   |  M   |  ,   |  .   |  /   |
  `-------------+------+------+------+------.  ,------+------+------+------+------+------'
                              |      |      |  |      |  ⌥⎈⇧ |
                              |  L1  |   ⎈  |  |  ⇧   |   ␣  |
                              `-------------'  `-------------'
*/
   [0] = LAYOUT(
        XXXXXXX, KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_Y, KC_U, KC_I, KC_O, KC_P, XXXXXXX,
        XXXXXXX, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_H, KC_J, KC_K, KC_L, KC_SCLN, XXXXXXX,
        XXXXXXX, KC_Z, KC_X, KC_C, MT(MOD_LALT,KC_V), MT(MOD_LGUI,KC_B),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        MT(MOD_RGUI,KC_N), MT(MOD_RALT,KC_M), KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
        XXXXXXX, XXXXXXX, OSL(1),OSM(MOD_LCTL), XXXXXXX,
        XXXXXXX, OSM(MOD_RSFT), MEH_T(KC_SPC), XXXXXXX, XXXXXXX
  ),

/* Layer 1

  ,----------------------------------.                ,----------------------------------.
  |      |      |      |      |      |                |      |      |      |      |      |
  |   !  |   @  |   #  |  $   |  %   |                |   ^  |   &  |   *  |   ⎋  |  ⌫   |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |      |      |                |      |      |      |      |      |
  | TAB  |   _  |   -  |  +   |  =   |                |   \  |   (  |   )  |   |  |  ↵   |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |  ⌥   |   ⌘  |                |  ⌘   |   ⌥  |      |      |  ?   |
  |   ~  |   €  |  `   |  '   |   "  |                |  [   |   {  |   }  |   ]  |  /   |
  `-------------+------+------+------+------.  ,------+------+------+------+------+------'
                              |      |      |  |      |      |
                              |  L2  |   ⎈  |  |  ⇧   |  L0  |
                              `-------------'  `-------------'
*/
  [1] = LAYOUT(
        XXXXXXX, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,
        KC_CIRC, KC_AMPR, KC_ASTR, KC_ESC, KC_BSPC, XXXXXXX,
        XXXXXXX, KC_TAB, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,
        KC_BSLS, KC_LPRN, KC_RPRN, KC_PIPE, KC_ENT, XXXXXXX,
        XXXXXXX, KC_TILDE, LSA(KC_2), KC_GRV, MT(MOD_LALT, KC_QUOT), MT(MOD_LGUI, KC_DQT),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        MT(MOD_RGUI, KC_LBRC), MT(MOD_RALT, KC_LCBR), KC_RCBR, KC_RBRC, KC_SLSH, XXXXXXX,
        XXXXXXX, XXXXXXX, TO(2), _______, XXXXXXX,
        XXXXXXX, _______, TO(0), XXXXXXX, XXXXXXX
  ),

/* Layer 2

  ,----------------------------------.                ,----------------------------------.
  |      |      |      |      |      |                |      |      |      |      |      |
  |   !  |   @  |   #  |  $   |  %   |                |   ^  |   7  |   8  |   9  |  ⌫   |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |      |      |                |      |      |      |      |      |
  | TAB  |   _  |   -  |  +   |  =   |                |   0  |   4  |   5  |   6  |  ↵   |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |  ⌥   |   ⌘  |                |  ⌘   |   ⌥  |      |      |  ?   |
  |   ~  |   €  |  `   |  '   |   "  |                |  .   |   1  |   2  |   3  |  /   |
  `-------------+------+------+------+------.  ,------+------+------+------+------+------'
                              |      |      |  |      |      |
                              |  L3  |   ⎈  |  |  ⇧   |  L0  |
                              `-------------'  `-------------'
*/

  [2] = LAYOUT(
        XXXXXXX, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,
        KC_CIRC, KC_7, KC_8, KC_9, KC_BSPC, XXXXXXX,
        XXXXXXX, KC_TAB, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,
        KC_0, KC_4, KC_5, KC_6, KC_ENT, XXXXXXX,
        XXXXXXX, KC_TILDE, LSA(KC_2), KC_GRV, MT(MOD_LALT, KC_QUOT), MT(MOD_LGUI, KC_DQT),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        MT(MOD_RGUI, KC_PDOT), MT(MOD_RALT, KC_1), KC_2, KC_3, KC_SLSH, XXXXXXX,
        XXXXXXX, XXXXXXX, TO(3), _______, XXXXXXX,
        XXXXXXX, _______, TO(0), XXXXXXX, XXXXXXX
  ),

/* Layer 3

  ,----------------------------------.                ,----------------------------------.
  |      |      |      |      |      |                |      |      |      |      |      |
  |   ⏏  | ⏪   |  ⏯   |  ⏩  |  👢  |                |      |      |      |      |  ⌫   |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |      |      |                |      |      |      |      |      |
  |      |  ←M  |  M↑  |   M↓ |  M→  |                |  ←   |  ↓   |   ↑  |   →  |  ↵   |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |      |      |                |      |      |      |      |      |
  |  ⌥⇧⏏ |      |      |      |      |                |      | acl0 | acl1 | acl2 |      |
  `-------------+------+------+------+------.  ,------+------+------+------+------+------'
                              |      |      |  |      |      |
                              |      | LCLK |  | RCLK |  L0  |
                              `-------------'  `-------------'
*/

  [3] = LAYOUT(
        XXXXXXX, KC_EJCT ,KC_MPRV, KC_MPLY, KC_MNXT, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R,
        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT, XXXXXXX,
        XXXXXXX, LALT(LGUI(KC_EJCT)), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, XXXXXXX,
        XXXXXXX, KC_BTN2, TO(0), XXXXXXX, XXXXXXX
  ),

};
