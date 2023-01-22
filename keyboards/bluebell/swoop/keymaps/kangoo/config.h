/* Copyright 2022 Marek Vsechovsky <marek@vsechovsky.com>
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
 
// From kyek config.h
#pragma once
#define ONESHOT_TIMEOUT 1000
//#define COMBO_COUNT 2


// DOC: https://thomasbaart.nl/2018/12/20/qmk-basics-leader-key/
#define LEADER_NO_TIMEOUT // Sets infinite timeout JUST FOR THE LEADER KEY itself.
#define LEADER_TIMEOUT 250 // Sets up the leader key timeout.
#define LEADER_PER_KEY_TIMING // Defines this timeout is per key, not the whole sequencer 
// #define LEADER_KEY_STRICT_KEY_PROCESSING // By default this feature filters the keycodes out of Mod-tap and Layer Tap functions so that LT(3, KC_A) becomes KC_A etc. This stops this behaviour.

// DOC: https://thomasbaart.nl/2018/12/13/qmk-basics-tap-dance/
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// DOC: https://docs.qmk.fm/#/tap_hold 
#define PERMISSIVE_HOLD 
#define IGNORE_MOD_TAP_INTERRUPT 
//#define PERMISSIVE_HOLD_PER_KEY

// MOUSE key movement
// DOC: https://docs.qmk.fm/#/feature_mouse_keys
#define MK_COMBINED
#define MOUSEKEY_INITIAL_SPEED 50

// DOC: https://docs.qmk.fm/#/feature_rgblight
#define RGBLIGHT_HUE_STEP 5
//#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_DEFAULT_HUE 50
// To save some memory you can undefine some of the lighting effects.
// For example the following undefines 2 of them and saves 4KiB:
//  #undef RGBLED_NUM
// +#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
// +#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
//  #define RGBLED_NUM 12
//  #define RGBLIGHT_HUE_STEP 8
//  #define RGBLIGHT_SAT_STEP 8
//
// You can also modify the speeds of the animations
// const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 20, 10, 5};
// const uint8_t RGBLED_RAINBOW_MOOD_INTERVALS[] PROGMEM = {120, 60, 30};
// const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 20};
// const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {100, 50, 20};
// const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {127, 63, 31};
// const uint8_t RGBLED_TWINKLE_INTERVALS[] PROGMEM = {50, 25, 10};
// const uint8_t RGBLED_GRADIENT_RANGES[] PROGMEM = {255, 170, 127, 85, 64};

// #ifdef RGB_DI_PIN
//     #define RGBLIGHT_LED_MAP { 17, 12, 11, 5, 4, 16, 13, 10, 6, 3, 15, 14, 9, 7, 2, 18, 8, 1 }
// #endif

// Lighting layers enable:
#define RGBLIGHT_LAYERS


// ENCODERS
// DOC: docs.qmk.fm/#/feature_encoders
// #define ENCODERS_PAD_A { }
// #define ENCODERS_PAD_B { }
//#define ENCODER_RESOLUTIONS { }
// Those below are already defined in the default inherited config.h for the SWOOP keyboard.
// #define ENCODERS_PAD_A_RIGHT { B5 }
// #define ENCODERS_PAD_B_RIGHT { B4 }
// Optionally define the number of pulses per notch for each encoder.
#define ENCODER_RESOLUTIONS_RIGHT { 8 }
//#define ENCODER_DIRECTION_FLIP

// #define ENCODER_MAP_KEY_DELAY 10

// Enable Unicode input using the UC_WINC method, for which the WinCompose program (https://github.com/samhocevar/wincompose) must be installed.
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE



// COLORS
#define HSV_POWR HSV_RED // Punctuation

#define HSV_PUNCT 222, 255, 70 // Punctuation
#define HSV_PUNCT2 HSV_TEAL // Punctuation

#define HSV_NAV_ARR HSV_SPRINGGREEN // Arrows
#define HSV_NAV_HE  HSV_CHARTREUSE // Home & End
#define HSV_NAV_PG  HSV_GREEN // PgUp & PgDn

#define HSV_ACT_CUT HSV_MAGENTA // Cut
#define HSV_ACT_COP HSV_MAGENTA // Copy
#define HSV_ACT_PST HSV_MAGENTA // Paste

#define HSV_ACT_UR  HSV_CORAL // Undo & Redo 
#define HSV_ACT_ESC  HSV_RED // ESC

#define HSV_ACT_DEL HSV_ORANGE // Delete & Backspace

#define HSV_ACT_INS HSV_CHARTREUSE // Insert

#define HSV_ACT_MBT HSV_GREEN // Mouse buttons

#define HSV_ACT_OPR HSV_BLUE// Operations

#define HSV_ACT_LCK 222, 255, 255 // Lock buttons (srrl, caps)
#define HSV_LCK_CAPS HSV_RED // CapsLock indicator
#define HSV_LCK_SCRL HSV_GREEN // ScrlLock indicator

#define HSV_OPTS HSV_CORAL // Options

#define HSV_ACT_CMD HSV_TEAL // Pause, PrintScreen

#define HSV_APP_FND HSV_SPRINGGREEN // Find, explorers etc.

#define HSV_MATH_OP HSV_PINK // Math operators
#define HSV_MATH_EQ HSV_PURPLE // Math equal sign

// #define HSV_NUM_0        80, 255, 255
// #define HSV_NUM_1        90, 255, 255
// #define HSV_NUM_2        100, 255, 255
// #define HSV_NUM_3        110, 255, 255
// #define HSV_NUM_4        120, 255, 255
// #define HSV_NUM_5        130, 255, 255
// #define HSV_NUM_6        140, 255, 255
// #define HSV_NUM_7        150, 255, 255
// #define HSV_NUM_8        160, 255, 255
// #define HSV_NUM_9        170, 255, 255

#define HSV_NUM_0        100, 255, 255
#define HSV_NUM_1        100, 255, 255
#define HSV_NUM_2        100, 255, 255
#define HSV_NUM_3        140, 255, 255
#define HSV_NUM_4        140, 255, 255
#define HSV_NUM_5        140, 255, 255
#define HSV_NUM_6        140, 255, 255
#define HSV_NUM_7        170, 255, 255
#define HSV_NUM_8        170, 255, 255
#define HSV_NUM_9        170, 255, 255

#define HSV_FN_1        43, 255, 255 // FN range 1 (1-4) | Yellow
#define HSV_FN_2        21, 255, 255 // FN range 2 (5-8) | Orange
#define HSV_FN_3        0, 255, 255 // FN range 3 (9-12) | Red

#define HSV_RGB_LYR HSV_CORAL // RGB Layer Indicator
#define HSV_RGB_R HSV_RED // RGB Layer Indicator
#define HSV_RGB_G HSV_GREEN // RGB Layer Indicator
#define HSV_RGB_B HSV_BLUE // RGB Layer Indicator
