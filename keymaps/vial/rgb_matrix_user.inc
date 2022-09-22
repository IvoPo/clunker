
RGB_MATRIX_EFFECT(startup_animation_dots)
RGB_MATRIX_EFFECT(kitt)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "eeprom.h"
#include "eeconfig.h"

bool BASE_EFFECT_NOT_STARTED_YET = true;
uint8_t base_effect_startup_counter = 255;

uint8_t led_count = 8;
uint8_t led_first = 0;

static uint8_t time_to_led(uint8_t time, uint8_t led_behind) {
    uint16_t led_time = led_count * time;
    uint16_t step = ((2 * led_count + (led_time / 128)) - led_behind) % (2 * led_count);
    uint8_t led;

    if (step < led_count) {
        led = step;
    } else {
        led = led_count - 1 - (step - led_count);
    }

    return led;
}

static void startup_animation_setleds(effect_params_t* params, bool dots) {
    uint8_t factor = 5;
    HSV      hsv  = rgb_matrix_config.hsv;
    RGB rgb       = rgb_matrix_hsv_to_rgb(hsv);
    if (dots) {
        rgb_matrix_set_color_all(0, 0, 0);
    }
    int32_t num = (g_rgb_timer & (0b11111 << factor)) >> factor;

    if (num == 17 || num == 18 || num == 19 ||
        num == 20 || num == 21) {
        if (dots == true) {
            for (int i = 0; i < 28; i++) {
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
        return;
    } else if (num == 0 || num == 1 || num == 2) {
        return;
    } else if (num >= 22) {
        eeprom_read_block(&rgb_matrix_config, EECONFIG_RGB_MATRIX, sizeof(rgb_matrix_config));
        rgb_matrix_mode_noeeprom(rgb_matrix_config.mode);
        return;
    }

    int32_t num2 = (27/2) + num - 2;
    int32_t num1 = 27 - num2;
    rgb_matrix_set_color(num1, rgb.r, rgb.g, rgb.b);
    rgb_matrix_set_color(num2, rgb.r, rgb.g, rgb.b);
}



static HSV KITT_math(HSV hsv, uint8_t i, uint8_t time) {

    // reset base effect startup
    if (i == 0) {
        BASE_EFFECT_NOT_STARTED_YET = true;
    }

    hsv.h = 0;
    hsv.s = 255;

    if (i >= led_first && i < led_first + led_count) {
        uint8_t j = i - led_first;
        if (j == time_to_led(time, 0)) {
            hsv.v = hsv.v;
        } else if (j == time_to_led(time, 1)) {
            hsv.v = hsv.v/2;
        } else if (j == time_to_led(time, 2)) {
            hsv.v = hsv.v/4;
        } else if (j == time_to_led(time, 3)) {
            hsv.v = hsv.v/8;
        } else {
            hsv.v = 0;
        }
    } else {
        hsv.v = 0;
    }

    return hsv;
}

static bool startup_animation_dots(effect_params_t* params) {
    startup_animation_setleds(params, true);
    return false;
}

bool kitt(effect_params_t* params) {
    return effect_runner_i(params, &KITT_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS