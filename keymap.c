#include QMK_KEYBOARD_H
#include <stdio.h>
char wpm_str[10];
#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_LAYER0] = LAYOUT_ansi(
                             KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                       KC_VOLD, KC_MUTE, KC_VOLU,
                             KC_GRV,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,                        KC_INS,  KC_HOME, KC_PGUP,
                             KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,                       KC_DEL,  KC_END, KC_PGDN,
                             KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
                             KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,                                          KC_UP,
                             KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, TO(1), KC_NO, KC_RALT, KC_RCTL,                                                    KC_LEFT, KC_DOWN, KC_RGHT),
        
    [_LAYER1] = LAYOUT_ansi(
                             TO(0), KC_TRNS, TO(2), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                          KC_VOLD, KC_MUTE, KC_VOLU,
                             KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_NO, KC_BSPC,                             KC_NO,   KC_NO,   KC_NO,
                             KC_NO, KC_NO, KC_NO, LGUI(KC_RGHT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,             KC_NO,   KC_NO,   KC_NO,
                             KC_NO, KC_A, KC_COMM, LGUI(KC_LEFT), KC_DOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT,
                             KC_LSFT, KC_Z, KC_NO, KC_C, KC_V, KC_NO, KC_NO, KC_NO, KC_NO, KC_COMM, KC_DOT, KC_NO,                                          KC_UP,
                             KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_TRNS, KC_NO, KC_NO, KC_NO,                                                      KC_LEFT, KC_DOWN, KC_RGHT),
    
    [_LAYER2] = LAYOUT_ansi(
                             TO(0), TO(1), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                          KC_VOLD, KC_MUTE, KC_VOLU,
                             KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_NO, KC_BSPC,                             KC_NO,   KC_NO,   KC_NO,
                             KC_NO, KC_NO, LGUI(KC_EQL), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO,   KC_NO,   KC_NO,
                             KC_NO, LSFT(KC_LEFT), LGUI(KC_MINS), LSFT(KC_RGHT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_ENT,
                             KC_LSFT, KC_Z, KC_NO, KC_C, KC_V, KC_NO, KC_NO, KC_NO, KC_NO, KC_COMM, KC_DOT, KC_NO,                                          KC_UP,
                             KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_TRNS, KC_NO, KC_NO, KC_NO,                                                      KC_LEFT, KC_DOWN, KC_RGHT)
    
};


#ifdef OLED_DRIVER_ENABLE
#define TAP_FRAMES 2
#define IDLE_FRAMES 4
#define ANIM_FRAME_DURATION 100
#define ANIM_SIZE 584
uint32_t anim_timer = 0;
uint8_t current_tap_frame = 0;
uint8_t current_idle_frame = 0;
static const char PROGMEM idle[IDLE_FRAMES][543] = {
    {
    0,  0,126,126, 24, 60,102, 66,  0, 12, 28,112,112, 28, 12,  0,116,116, 20, 20,124,104,  0,124,124,  0,112,120, 44, 36,124,124,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 16,  8,  8,  4,  4,  4,  8, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
    0,  0,  0,  0,192, 96, 48, 24, 12,132,198, 98, 35, 51, 17,145,113,241,113,145, 17, 51, 35, 98,198,132, 12, 24, 48, 96,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24,100,130,  2,  2,  2,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,192,193,193,194,  4,  8, 16, 32, 64,128,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
    0,  0,252, 15,  1,  0,248, 14, 31,109,140,148,148,164,166,249,224,255,224,249,166,164,148,148,140,109, 31, 14,248,  0,  1, 15,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 56,  4,  3,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 13,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
    0,  0, 31,120,192,  0, 15, 56,124,219,152, 20, 20, 18, 50,207,  3,255,  3,207, 50, 18, 20, 20,152,219,124, 56, 15,  0,192,120, 31, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,135, 31,  7,159,  7, 28,  7,159,  7,159,  7,  2,130,  0,  0,  0,  0,
    32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98,102, 68, 68, 71, 71, 71, 68, 68,102, 98, 35, 49, 16, 24, 12,  6,  3,  1
    },
    {
    0,  0,126,126, 24, 60,102, 66,  0, 12, 28,112,112, 28, 12,  0,116,116, 20, 20,124,104,  0,124,124,  0,112,120, 44, 36,124,124,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 16,  8,  8,  4,  4,  4,  8, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
    0,  0,  0,  0,192, 96, 48, 24, 12,132,198, 98, 35, 51, 17,145,113,241,113,145, 17, 51, 35, 98,198,132, 12, 24, 48, 96,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24,100,130,  2,  2,  2,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,192,193,193,194,  4,  8, 16, 32, 64,128,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
    0,  0,252, 15,  1,  0,248, 14, 31,109,140,148,148,164,166,249,224,255,224,249,166,164,148,148,140,109, 31, 14,248,  0,  1, 15,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 56,  4,  3,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 13,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
    0,  0, 31,120,192,  0, 15, 56,124,219,152, 20, 20, 18, 50,207,  3,255,  3,207, 50, 18, 20, 20,152,219,124, 56, 15,  0,192,120, 31, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,135, 31,  7,159,  7, 28,  7,159,  7,159,  7,  2,130,  0,  0,  0,  0,
    32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98,102, 68, 68, 71, 71, 71, 68, 68,102, 98, 35, 49, 16, 24, 12,  6,  3,  1
    },
    {
    0,  0,126,126, 24, 60,102, 66,  0, 12, 28,112,112, 28, 12,  0,116,116, 20, 20,124,104,  0,124,124,  0,112,120, 44, 36,124,124,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16,  8,  4,  2,  2,  4, 24, 96,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
    0,  0,  0,  0,192, 96, 48, 24, 12,132,198, 98, 35, 51, 17,145,113,241,113,145, 17, 51, 35, 98,198,132, 12, 24, 48, 96,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 60,194,  1,  1,  2,  2,  4,  4,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 96, 96,  0,129,130,130,132,  8, 16, 32, 64,128,  0,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
    0,  0,252, 15,  1,  0,248, 14, 31,109,140,148,148,164,166,249,224,255,224,249,166,164,148,148,140,109, 31, 14,248,  0,  1, 15,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 25,  6,  0,  0,  0,  0,  0,  0,  0, 24, 24, 24, 27,  3,  0, 64,160, 34, 36, 20, 18, 18, 18, 11,  8,  8,  8,  8,  5,  5,  9,  9, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
    0,  0, 31,120,192,  0, 15, 56,124,219,152, 20, 20, 18, 50,207,  3,255,  3,207, 50, 18, 20, 20,152,219,124, 56, 15,  0,192,120, 31, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,135, 31,  7,159,  7, 28,  7,159,  7,159,  7,  2,130,  0,  0,  0,  0,
    32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98,102, 68, 68, 71, 71, 71, 68, 68,102, 98, 35, 49, 16, 24, 12,  6,  3,  1
    },
    {
    0,  0,126,126, 24, 60,102, 66,  0, 12, 28,112,112, 28, 12,  0,116,116, 20, 20,124,104,  0,124,124,  0,112,120, 44, 36,124,124,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
    0,  0,  0,  0,192, 96, 48, 24, 12,132,198, 98, 35, 51, 17,145,113,241,113,145, 17, 51, 35, 98,198,132, 12, 24, 48, 96,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,192,193,193,194,  4,  8, 16, 32, 64,128,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
    0,  0,252, 15,  1,  0,248, 14, 31,109,140,148,148,164,166,249,224,255,224,249,166,164,148,148,140,109, 31, 14,248,  0,  1, 15,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 13,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
    0,  0, 31,120,192,  0, 15, 56,124,219,152, 20, 20, 18, 50,207,  3,255,  3,207, 50, 18, 20, 20,152,219,124, 56, 15,  0,192,120, 31, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,135, 31,  7,159,  7, 28,  7,159,  7,159,  7,  2,130,  0,  0,  0,  0,
    32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98,102, 68, 68, 71, 71, 71, 68, 68,102, 98, 35, 49, 16, 24, 12,  6,  3,  1
    }
};

static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
    {
    0,  0,126,126, 24, 60,102, 66,  0, 12, 28,112,112, 28, 12,  0,116,116, 20, 20,124,104,  0,124,124,  0,112,120, 44, 36,124,124,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,248,248,248,248,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
    0,  0,  0,  0,192, 96, 48, 24, 12,132,198, 98, 35, 51, 17,145,113,241,113,145, 17, 51, 35, 98,198,132, 12, 24, 48, 96,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,129,128,128,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,  0,  1,  1,  2,  4,  8, 16, 32, 67,135,  7,  1,  0,184,188,190,159, 95, 95, 79, 76, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
    0,  0,252, 15,  1,  0,248, 14, 31,109,140,148,148,164,166,249,224,255,224,249,166,164,148,148,140,109, 31, 14,248,  0,  1, 15,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0, 24,  6,  5,152,153,132, 67,124, 65, 65, 64, 64, 32, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1, 61,124,252,252,252,252,252, 60, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
    0,  0, 31,120,192,  0, 15, 56,124,219,152, 20, 20, 18, 50,207,  3,255,  3,207, 50, 18, 20, 20,152,219,124, 56, 15,  0,192,120, 63, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,135, 31,  7,159,  7, 28,  7,159,  7,159,  7,  2,130,  0,  0,  0,  0,
    32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98,102, 68, 68, 71, 71, 71, 68, 68,102, 98, 35, 49, 16, 24, 12,  6,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    },
    {
    0,  0,126,126, 24, 60,102, 66,  0, 12, 28,112,112, 28, 12,  0,116,116, 20, 20,124,104,  0,124,124,  0,112,120, 44, 36,124,124,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
    0,  0,  0,  0,192, 96, 48, 24, 12,132,198, 98, 35, 51, 17,145,113,241,113,145, 17, 51, 35, 98,198,132, 12, 24, 48, 96,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,  0,  1,225, 26,  6,  9, 49, 53,  1,138,124,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
    0,  0,252, 15,  1,  0,248, 14, 31,109,140,148,148,164,166,249,224,255,224,249,166,164,148,148,140,109, 31, 14,248,  0,  1, 15,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  4,  4,  4,  4,  2,  2,  2,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
    0,  0, 31,120,192,  0, 15, 56,124,219,152, 20, 20, 18, 50,207,  3,255,  3,207, 50, 18, 20, 20,152,219,124, 56, 15,  0,192,120, 31, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,122,122,121,121,121,121, 57, 49,  2,  2,  4,  4,  8,  8,  8,136,136,135,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,135, 31,  7,159,  7, 28,  7,159,  7,159,  7,  2,130,  0,  0,  0,  0,
    32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98,102, 68, 68, 71, 71, 71, 68, 68,102, 98, 35, 49, 16, 24, 12,  6,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48,120,124,254,255, 63,  7,  0,  0,  0,  0,255,255,127,127, 63, 62, 28, 24
    },
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_status(void) {
    oled_clear();
    current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
    oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], 543);
    oled_set_cursor(0,6);
    oled_write_P(PSTR("    Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _LAYER0:
            oled_write_P(PSTR("QWERTY"), false);
            break;
        case _LAYER1:
            oled_write_P(PSTR("LOGIC"), false);
            break;
        case _LAYER2:
            oled_write_P(PSTR("FINAL CUT"), false);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A ... KC_H:
        case KC_Q ... KC_T:
        case KC_V ... KC_X:
        case KC_Z ... KC_6:
        case KC_GRAVE:
            if (record->event.pressed) {
                oled_write_raw_P(tap[1], ANIM_SIZE);
            } else {
                oled_write_raw_P(idle[1], 543);
                anim_timer = timer_read32();
            }
            break;
        case KC_I ... KC_P:
        case KC_U:
        case KC_Y:
        case KC_7 ... KC_0:
        case KC_MINUS ... KC_BSLASH:
        case KC_SCOLON ... KC_QUOTE:
        case KC_COMMA ... KC_SLASH:
            if (record->event.pressed) {
                oled_write_raw_P(tap[0], ANIM_SIZE);
            } else {
                oled_write_raw_P(idle[2], 543);
                anim_timer = timer_read32();
            }
            break;
    }
    return true;
};
void suspend_wakeup_init_user(void) {
    oled_write_raw_P(idle[0], 543);
    render_status();
}
void oled_task_user(void) {
    if(timer_elapsed32(anim_timer) > 200) {
        anim_timer = timer_read32();
        render_status();
    }
}
#endif

