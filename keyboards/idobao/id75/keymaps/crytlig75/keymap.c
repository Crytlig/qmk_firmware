#include QMK_KEYBOARD_H

#define S_NO        RSFT(KC_NO)
#define CS_TRNS     LCTL(LSFT(KC_TRNS))

enum unicode_names {
    aa,
    AA,
    ae,
    AE,
    oe,
    OE,
    SNEK
};

// Tap Dance declarations
enum {
    TD_SC_CL,
    TD_PAR_PAR,
    TD_C_SC,
    TD_ESC_CAPS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for colon, twice for semi colon
    [TD_SC_CL] = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_SCLN),
    // Tap once for left parenthesis, twice for right parenthesis
    [TD_PAR_PAR] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
    // Tap once for comma, twice for semi colon
    [TD_C_SC] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_SCLN),
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

// Custom keycodes for custom events
enum custom_keycodes {
    MENVIM = SAFE_RANGE,
    QVIM,
    WQVIM,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MENVIM:
        if (record->event.pressed) {
            // SEND_STRING(SS_LCTL("c"));
            register_code(KC_ESC);
            unregister_code(KC_ESC);
            SEND_STRING(":");
        } else {
            // when keycode MENVIM is released
        }
        break;

    case QVIM:
        if (record->event.pressed) {
            SEND_STRING("q!");
        } else {
            // when keycode QVIM is released
        }
        break;

    case WQVIM:
        if (record->event.pressed) {
            SEND_STRING("wq!");
        } else {
            // when keycode QVIM is released
        }
        break;
    }
    return true;
};

const uint32_t PROGMEM unicode_map[] = {
    [aa]  = 0x00E5,  // å
    [AA]  = 0x00C5,  // Å
    [ae] = 0x00E6,  // æ
    [AE] = 0x00C6,  // Æ
    [oe] = 0x00F8,  // ø
    [OE] = 0x00D8,  // Ø
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_5x15(
        TD(TD_ESC_CAPS),  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,     KC_8,  KC_9,     KC_0,    KC_EQL,  KC_GRV,  KC_DEL,  KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_LBRC, KC_Y,     KC_U,  KC_I,     KC_O,    KC_P,    KC_BSPC, KC_BSPC, KC_INS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_SLSH,  KC_H,  KC_J,     KC_K,    KC_L,    KC_QUOT, KC_ENT,  KC_ENT,  KC_RSFT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_SCLN, KC_N,     KC_M,  KC_COMM,  KC_DOT,  KC_MINS, S_NO,    KC_HOME, KC_END,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, MO(1),    KC_SPC,  KC_SPC,  KC_LALT,  MO(2), KC_RGUI,  KC_RALT, KC_RCTL, MO(1),   TG(1),   KC_PSCR
    ),

    [1] = LAYOUT_ortho_5x15(
        _______, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_PGDN,
        _______, _______, KC_UP,    _______, _______, _______, KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN,  KC_RGHT, _______, _______, KC_BSLS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, CS_TRNS,
        _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [2] = LAYOUT_ortho_5x15(
        _______,        UC_MOD,  _______,   _______, _______, _______, _______, _______, _______, _______,     _______,    _______,    _______, _______, RGB_TOG,
        _______,        QVIM,    WQVIM,     _______, _______, _______, _______, _______, _______, _______,     _______,    XP(aa, AA), _______, _______, RGB_MOD,
        _______,        _______, _______,   _______, _______, _______, _______, _______, _______, _______,     XP(ae, AE), XP(oe, OE), _______, _______, RGB_VAI,
        MENVIM,         _______, _______,   _______, _______, _______, KC_SCLN, _______, _______, TD(TD_C_SC), _______,    _______,    _______, _______, RGB_VAD,
        TD(TD_PAR_PAR), _______, RESET,     _______, _______, _______, _______, _______, _______, _______,     _______,    _______,    _______, _______, _______
    ),
};

