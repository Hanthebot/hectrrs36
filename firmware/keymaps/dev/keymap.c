#include QMK_KEYBOARD_H

enum custom_keycodes {
    M_CSTAB = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_CSTAB:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
                tap_code(KC_TAB);
                unregister_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
            }
            return false;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        LSFT_T(KC_A), KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LSFT_T(KC_SCLN),
        LT(4, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, LT(4, KC_SLSH),
        LSFT_T(KC_SPC), LT(1, KC_TAB), KC_LGUI, LALT_T(KC_ENT), LCTL_T(KC_ENT), LT(2, KC_BSPC)
    ),
    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_MUTE, KC_MPLY, KC_MPRV, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_DEL,
        KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MNXT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_NO, KC_TRNS, KC_RALT, KC_ENT, KC_BSPC
    ),
    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV, KC_LBRC, KC_RBRC, LSFT(KC_MINS), LSFT(KC_7),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, LSFT(KC_9), LSFT(KC_0), KC_EQL, KC_QUOT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_COMM), LSFT(KC_DOT), KC_LSFT,
        KC_0, LSFT_T(KC_0), KC_LCTL, KC_TRNS, KC_LSFT, KC_NO
    ),
    [3] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_LCTL,
        KC_TRNS, KC_TRNS, KC_LSFT, KC_LCTL, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_ACL0,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_BTN1, KC_BTN2, KC_BTN3, KC_ACL1,
        KC_BTN2, KC_BTN1, KC_BTN3, KC_TRNS, KC_LCTL, KC_NO
    ),
    [4] = LAYOUT(
        KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_PAST, KC_7, KC_8, KC_9, LSFT(KC_MINS),
        KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11, KC_PPLS, KC_4, KC_5, KC_6, KC_DOT,
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12, KC_MINS, KC_1, KC_2, KC_3, KC_SLSH,
        KC_LSFT, KC_NO, KC_LSFT, KC_TRNS, LCTL_T(KC_0), LSFT_T(KC_0)
    ),
    [5] = LAYOUT(
        KC_F5, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
        KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS,
        KC_LSFT, KC_SPC, KC_ESCAPE, KC_BSPC, KC_ENT, KC_RSFT
    ),
};


