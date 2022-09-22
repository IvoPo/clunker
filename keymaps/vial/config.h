/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x3A, 0x0C, 0x4E, 0x18, 0xA5, 0x27, 0xC2, 0x53}

#define VIAL_UNLOCK_COMBO_ROWS { 2, 5 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 3 }

#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define VIAL_TAP_DANCE_ENTRIES 64
#define VIAL_COMBO_ENTRIES 64

/* RGB Definitions */
#ifdef RGB_MATRIX_ENABLE
    #define RGB_DI_PIN GP1
    #define RGBLED_NUM 8                                // Number of LEDs
    #define DRIVER_LED_TOTAL RGBLED_NUM
    #define RGBLIGHT_LIMIT_VAL 255
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
    #define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CUSTOM_kitt

    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_HUE_PENDULUM
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_HUE_WAVE
    #define ENABLE_RGB_MATRIX_PIXEL_RAIN
    #define ENABLE_RGB_MATRIX_CUSTOM_kitt
#endif

#define E1M1_DOOM2  \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_D4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_C4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_BF3), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_B3 ), \
    Q__NOTE(_C4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_D4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_C4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    H__NOTE(_BF3),

#ifdef AUDIO_ENABLE
    #define AUDIO_PIN GP0
    #define AUDIO_STATE_TIMER GPTD4
    #define AUDIO_INIT_DELAY 1000
    #define STARTUP_SONG SONG(E1M1_DOOM2)
    #define MUSIC_ON_SONG SONG(ODE_TO_JOY)
    #define AUDIO_CLICKY
#endif