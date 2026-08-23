// keyboards/ferris/keymaps/maartenq/keymap.c

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _NUM,
    _SYM,
    _NAV,
};

#define QWERTY TO(_QWERTY)
#define SYM OSL(_SYM)
#define NAV TO(_NAV)
#define NUM TO(_NUM)

// i-tec KVM dock hotkeys: dock reads raw HID taps, so mod-tap/one-shot
// keys on this board (Alt, Shift) can't reliably send them -- macros
// with SS_TAP send clean isolated keydown/keyup instead.
enum custom_keycodes {
    KVM_MRVN = SAFE_RANGE, // Output 1 -> PC1 marvin
    KVM_BUP,               // Output 1 -> PC2 bup
    KVM_SLRT,               // Output 1 -> PC3 slarti
    KVM_DFLT,               // kb/mouse mode -> Default (Output 1 only)
    KVM_ROAM,               // kb/mouse mode -> Roaming (fallback)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
        case KVM_MRVN:
            SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(100) SS_TAP(X_SCRL) SS_DELAY(100) SS_TAP(X_1));
            return false;
        case KVM_BUP:
            SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(100) SS_TAP(X_SCRL) SS_DELAY(100) SS_TAP(X_2));
            return false;
        case KVM_SLRT:
            SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(100) SS_TAP(X_SCRL) SS_DELAY(100) SS_TAP(X_3));
            return false;
        case KVM_DFLT:
            SEND_STRING(SS_TAP(X_LSFT) SS_DELAY(100) SS_TAP(X_LSFT) SS_DELAY(100) SS_TAP(X_1));
            return false;
        case KVM_ROAM:
            SEND_STRING(SS_TAP(X_LSFT) SS_DELAY(100) SS_TAP(X_LSFT) SS_DELAY(100) SS_TAP(X_2));
            return false;
    }
    return true;
}


enum combos {
  Q_P,
  W_O,
  E_I,
  R_U,
  T_Y,
  S_L,
  D_K,
  F_J,
  G_H,
};

const uint16_t PROGMEM qp_combo[] = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM wo_combo[] = {KC_W, KC_O, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM ru_combo[] = {KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM ty_combo[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM sl_combo[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM dk_combo[] = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END};

combo_t key_combos[] = {
  [Q_P] = COMBO(qp_combo, KC_LCBR),
  [W_O] = COMBO(wo_combo, KC_LBRC),
  [E_I] = COMBO(ei_combo, KC_RBRC),
  [R_U] = COMBO(ru_combo, KC_RCBR),
  [T_Y] = COMBO(ty_combo, KC_CAPS),
  [S_L] = COMBO(sl_combo, KC_DQT),
  [D_K] = COMBO(dk_combo, KC_LPRN),
  [F_J] = COMBO(fj_combo, KC_RPRN),
  [G_H] = COMBO(gh_combo, KC_QUOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer _QWERTY

  ,----------------------------------.                ,----------------------------------.
  | {    |  [   | ]    |  }   | CAPS |                | CAPS |    } |    ] |    [ |    { |
  |   Q  |   W  |   E  |   R  |   T  |                |  Y   |  U   |  I   |  O   |  P   |
  |------+------+------+------+------|                |------+------+------+------+------|
  | NAV  | "    | (    |  )   | '    |                |    ' |   )  |    ( |    " |  :   |
  |   A  |   S  |   D  |   F  |   G  |                |  H   |  J   |  K   |  L   |  ;   |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      | NUM  |   ⌥  |   ⌘  |                |  ⌘   |  ⌥   |  <   |  >   |  ?   |
  |   Z  |   X  |   C  |   V  |   B  |                |  N   |  M   |  ,   |  .   |  /   |
  `-------------+------+------+------+------.  ,------+------+------+------+------+------'
                              |      |      |  |      |  ⌥⎈⇧ |
                              |  SYM |   ⎈  |  |  ⇧   |   ␣  |
                              `-------------'  `-------------'
*/
   [_QWERTY] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_Y, KC_U, KC_I, KC_O, KC_P,
        LT(_NAV, KC_A), KC_S, KC_D, KC_F, KC_G,
        KC_H, KC_J, KC_K, KC_L, LT(_NAV, KC_SCLN),
        KC_Z, KC_X, LT(_NUM,  KC_C), MT(MOD_LALT, KC_V), MT(MOD_LGUI,KC_B),
        MT(MOD_RGUI, KC_N), MT(MOD_RALT, KC_M), KC_COMM, KC_DOT, KC_SLSH,
        SYM, OSM(MOD_LCTL),
        OSM(MOD_RSFT), MEH_T(KC_SPC)
  ),

/* Layer _SYM

  ,----------------------------------.                ,----------------------------------.
  |      |      |      |      |      |                |      |      |      |      |      |
  |   !  |   @  |   #  |   $  |   %  |                |  ^   |   &  |   *  |  ⎋   |  ⌫   |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |      |      |                |      |      |      |      |      |
  | TAB  |   `  |   ~  |   =  |   +  |                |  \   |  -   |  _   |  |   |  ↵   |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |      |      |                |      |      |      |      |      |
  | NUM  |      |   €  |   ⌥  |   ⌘  |                |  ⌘   |  ⌥   |  <   |  >   |  ?   |
  `-------------+------+------+------+------.  ,------+------+------+------+------+------'
                              |      |      |  |      |      |
                              |      |   ⎈  |  |  ⇧   | QWRT |
                              `-------------'  `-------------'
*/
  [_SYM] = LAYOUT(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,
        KC_CIRC, KC_AMPR, KC_ASTR, KC_ESC, KC_BSPC,
        KC_TAB, KC_GRV, KC_TILDE, KC_EQL, KC_PLUS,
        KC_BSLS, KC_MINS, KC_UNDS, KC_PIPE, KC_ENT,
        NUM, XXXXXXX , LSA(KC_2), OSM(MOD_LALT), OSM(MOD_LGUI),
        OSM(MOD_RGUI), OSM(MOD_RALT), KC_LT, KC_GT, KC_QUES,
        _______, _______,
        _______, QWERTY
  ),


/* Layer _NUM

  ,----------------------------------.                ,----------------------------------.
  |      |      |      |      |      |                |      |      |      |      |      |
  |  F11 |  F7  |  F8  |  F9  |  F12 |                |   .  |   7  |   8  |   9  |      |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |      |      |                |      |      |      |      |      |
  |  F10 |  F4  |  F5  |  F6  |      |                |   0  |   4  |   5  |   6  |      |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |   ⌥  |      |                |      |   ⌥  |      |      |      |
  |      |  F1  |  F2  |  F3  |   ⌘  |                |  ⌘   |   1  |   2  |   3  |  NAV |
  `-------------+------+------+------+------.  ,------+------+------+------+------+------'
                              |      |      |  |      |      |
                              |  SYM |   ⎈  |  |  ⇧   | QWRT |
                              `-------------'  `-------------'
*/

  [_NUM] = LAYOUT(
        KC_F11, KC_F7, KC_F8, KC_F9, KC_F12,
        KC_KP_DOT, KC_7, KC_8, KC_9, XXXXXXX,
        KC_F10, KC_F4, KC_F5, KC_F6, XXXXXXX,
        KC_0, KC_4, KC_5, KC_6, XXXXXXX,
        XXXXXXX, KC_F1, KC_F2, MT(MOD_LALT, KC_F3), OSM(MOD_LGUI),
        OSM(MOD_RGUI), MT(MOD_RALT, KC_1), KC_2, KC_3, NAV,
        SYM, OSM(MOD_LCTL),
        _______, QWERTY
  ),

/* Layer _NAV

  ,----------------------------------.                ,----------------------------------.
  |      |      |      |      |      |                |      |      |      |      |      |
  |   ⏏  | ⏪   |  ⏯   |  ⏩  |   ⏹  |                | HOME | PgDn | PgUp |  END |  DEL |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |      |      |                |      |      |      |      |      |
  |      |  ←M  |  M↑  |   M↓ |  M→  |                |  ←   |  ↓   |   ↑  |   →  |  ↵   |
  |------+------+------+------+------|                |------+------+------+------+------|
  |      |      |      |      |      |                |      |      |      |      |      |
  | MRVN |  BUP | SLRT | DFLT | ROAM |                | MCLK | acl0 | acl1 | acl2 | PrSc |
  `-------------+------+------+------+------.  ,------+------+------+------+------+------'
                              |      |      |  |      |      |
                              | SYM  | LCLK |  | RCLK | QWRT |
                              `-------------'  `-------------'
*/

  [_NAV] = LAYOUT(
        KC_EJCT ,KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP,
        KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_DEL,
        XXXXXXX, MS_LEFT, MS_UP, MS_DOWN, MS_RGHT,
        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT,
        KVM_MRVN, KVM_BUP, KVM_SLRT, KVM_DFLT, KVM_ROAM,
        MS_BTN3, MS_ACL0, MS_ACL1, MS_ACL2, KC_PSCR,
        _______, MS_BTN1,
        MS_BTN2, QWERTY
  ),

};
