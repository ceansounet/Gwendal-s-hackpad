// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        TO(1),   KC_F13,   KC_F14,   KC_F15, KC_AUDIO_MUTE,
        KC_F16,   KC_F17,   KC_F18,   KC_F19, KC_F20 ,
        KC_F21,   KC_F22,   KC_F23,   KC_F24,
        KC_CALC, KC_NO, KC_WWW_HOME, QK_RBT
    ),
    [1] = LAYOUT(
        TO(2),   KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [2] = LAYOUT(
        TO(0),   MI_TOGG,   MI_OCTD,   MI_OCTU, KC_TRNS,
        MI_C,   MI_D,   MI_E,   MI_F, KC_TRNS,
        MI_G,   MI_A,   MI_B,   MI_C1,
        MI_SUST,   MI_SOFT,   MI_BNDD,   MI_BNDU
    )
};
bool oled_task_user(void) {
    oled_write_ln_P(PSTR("Hello"), false);
    return false;
}
enum custom_keycodes {
    SS_HELLO = SAFE_RANGE,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SS_HELLO:
            if (record->event.pressed) {
                SEND_STRING("Hello, world!\n");
            }
            return false;
    }

    return true;
}