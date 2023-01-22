#include QMK_KEYBOARD_H
//#include "keymap_czech.h"

// NOTE: Using timers here: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_macros.md at the end.


enum layers {
    _BASE = 0,
    _NAV,
    _NUM,
    _FNC,
    _SYM,
    _APP,
    _RGB
};

// Combo Layers
// enum combos {
//   ACC,
//   SET,
// };
// const uint16_t PROGMEM accent_combo[] = {KC_SPC, MO(_SYM1), COMBO_END};
// const uint16_t PROGMEM settings_combo[] = {MO(_EXT), SFT_T(KC_SPC), COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   [ACC] = COMBO(accent_combo, MO(_ACC)),
//   [SET] = COMBO(settings_combo, MO(_SET)),
// };

// // Layer Aliases
// #define NAV MO(_NAV)
// #define NUM MO(_NUM)
// #define FNC MO(_FNC)
// #define SYM MO(_SYM)
// #define APP MO(_APP)
// #define RGB MO(_RGB)

// Oneshot Aliases
#define OS_CTL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_SFT OSM(MOD_LSFT)
#define OS_GUI OSM(MOD_LGUI)
#define OS_RALT OSM(MOD_RALT)

// Other Aliases
#define _______________ KC_TRNS
#define xxxxxxxxxxxxxxx XXXXXXX
#define DEL_WORD LCTL(KC_BSPC)
#define UNDO KC_UNDO
#define REDO KC_AGAIN
#define CUT KC_CUT
#define COPY KC_COPY
#define PASTE KC_PSTE
#define BACKTICK RALT(KC_MINS)
#define TILDE RALT(KC_EQL)
#define CEGR RSA(KC_E)

enum custom_keycodes {
    MY_PDOT = SAFE_RANGE,
    MY_COMM,
    MY_AMPR,
    MY_PIPE,
    MY_EXLM
    // ,
    // CZ_A,
    // CZ_C,
    // CZ_D,
    // CZ_E,
    // CZ_EH,
    // CZ_I,
    // CZ_N,
    // CZ_O,
    // CZ_R,
    // CZ_S,
    // CZ_T,
    // CZ_U,
    // CZ_UK,
    // CZ_Y,
    // CZ_Z,
    // CZ_HAC,
    // CZ_CAR,
    // CZ_PGF,
    // CZ_EUR,
    // CZ_PND,
    // GR_OMEG,
    // GR_MJU,
    // GR_BETA,
};

// NOTE: Unicode worked, but is sending the actual codes instead of the characters they represent. For that a registry entry " reg add "HKCU\Control Panel\Input Method" -v EnableHexNumpad -t REG_SZ -d 1 " must be added and the machine restarted and is still not the recommended or reliable option as per https://qmk.github.io/qmk_mkdocs/master/en/feature_unicode/.
// The other option is to install WinCompose (https://github.com/samhocevar/wincompose) 

// Unicode map >>>>>
// DOC: https://qmk.github.io/qmk_mkdocs/master/en/feature_unicode/
enum unicode_names {
    CZ_A, // 0 - á
    CZ_C,       // 1 - č
    CZ_D,       // 2 - ď
    CZ_E,       // 3 - é
    CZ_EH,      // 4 - ě
    CZ_I,       // 5 - í
    CZ_N,       // 6 - ň
    CZ_O,       // 7 - ó
    CZ_R,       // 8 - ř
    CZ_S,       // 9 - š
    CZ_T,       // 10 - ť
    CZ_U,       // 11 - ú
    CZ_UK,      // 12 - ů
    CZ_Y,       // 13 - ý
    CZ_Z,       // 14 - ž

    CZ_AU,      // 15 - Á
    CZ_CU,      // 16 - Č
    CZ_DU,      // 17 - Ď
    CZ_EU,      // 18 - É
    CZ_EHU,     // 19 - Ě
    CZ_IU,      // 20 - Í
    CZ_NU,      // 21 - Ň
    CZ_OU,      // 22 - Ó
    CZ_RU,      // 23 - Ř
    CZ_SU,      // 24 - Š
    CZ_TU,      // 25 - Ť
    CZ_UU,      // 26 - Ú
    CZ_UKU,     // 27 - Ů
    CZ_YU,      // 28 - Ý
    CZ_ZU,      // 29 - Ž

    CZ_HAC,     // 30 - ˇ
    CZ_CAR,     // 31 - ´
    CZ_PGF,     // 32 - §
    CZ_EUR,     // 33 - €
    CZ_PND,     // 34 - Ł
    GR_OMEG,    // 35 - Ω
    GR_MJU,     // 36 - µ
    GR_BETA // 37 - ß
};

const uint32_t PROGMEM unicode_map[] = {
    [CZ_A] = 0xE1,       // 0 - á
    [CZ_C] = 0x10D,       // 1 - č
    [CZ_D] = 0x10F,       // 2 - ď
    [CZ_E] = 0xE9,       // 3 - é
    [CZ_EH] = 0x11B,      // 4 - ě
    [CZ_I] = 0xED,       // 5 - í
    [CZ_N] = 0x148,       // 6 - ň
    [CZ_O] = 0xF3,       // 7 - ó
    [CZ_R] = 0x159,       // 8 - ř
    [CZ_S] = 0x161,       // 9 - š
    [CZ_T] = 0x165,       // 10 - ť
    [CZ_U] = 0xFA,       // 11 - ú
    [CZ_UK] = 0x16F,      // 12 - ů
    [CZ_Y] = 0xFD,       // 13 - ý
    [CZ_Z] = 0x17E,       // 14 - ž

    [CZ_AU] = 0xC1,      // 15 - Á
    [CZ_CU] = 0x10C,      // 16 - Č
    [CZ_DU] = 0x10E,      // 17 - Ď
    [CZ_EU] = 0xC9,      // 18 - É
    [CZ_EHU] = 0x11A,     // 19 - Ě
    [CZ_IU] = 0xCD,      // 20 - Í
    [CZ_NU] = 0x147,      // 21 - Ň
    [CZ_OU] = 0xD3,      // 22 - Ó
    [CZ_RU] = 0x158,      // 23 - Ř
    [CZ_SU] = 0x160,      // 24 - Š
    [CZ_TU] = 0x164,      // 25 - Ť
    [CZ_UU] = 0xDA,      // 26 - Ú
    [CZ_UKU] = 0x16E,     // 27 - Ů
    [CZ_YU] = 0xDD,      // 28 - Ý
    [CZ_ZU] = 0x17D,      // 29 - Ž

    [CZ_HAC] = 0x2C7,     // 30 - ˇ
    [CZ_CAR] = 0xB4,     // 31 - ´
    [CZ_PGF] = 0xA7,     // 32 - §
    [CZ_EUR] = 0x20AC,     // 33 - €
    [CZ_PND] = 0x141,     // 34 - Ł
    [GR_OMEG] = 0x2126,    // 35 - Ω
    [GR_MJU] = 0xB5,     // 36 - µ
    [GR_BETA] = 0xDF     // 37 - ß
};
// Unicode map <<<<<<

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {                                                                                       
  /*
    * LAYER 0: RSTHD
    *              _____                                                   _____
    *       .-----|  Y  |-----._____                           _____.-----| . > |-----.
    * .-----|  C  |_____|  F  |  K  |                         |  Z  |  L  |_____|  U  |-----.
    * |  J  |-----|  T  |-----|_____|                         |_____|-----|  A  |-----|  Q  |
    * |-----|  S  |_____|  H  |  D  |                         |  M  |  N  |_____|  I  |-----|
    * |  R  |-----|  G  |-----|_____|                         |_____|-----| , < |-----|  O  |
    * |-----|  V  |_____|  P  |  B  |                         |  X  |  W  |_____| ; : |-----|
    * |  -_ |-----'     '-----|_____|                         |_____|-----'     '-----| / ? |
    * '-----'          .-----. _____   .-.._           _..-.   _____ .-----.          '-----'
    *                  | TAB ||BCKSP| /     /         \     \ | END || PLAY|           
    *                  '-----':_____|/  E  /           \ SPC \|_____:'-----'
    *                               '--.._/             \_..--'
    */
[_BASE] = LAYOUT_split_3x5_3(
           KC_J,            KC_C,            KC_Y,            KC_F,            KC_K,                 KC_Z,            KC_L,          KC_COMM,            KC_U,            KC_Q, 
   LALT_T(KC_R),    LGUI_T(KC_S),    LCTL_T(KC_T),    LSFT_T(KC_H),            KC_D,                 KC_M,    RSFT_T(KC_N),     RCTL_T(KC_A),    RGUI_T(KC_I),    RALT_T(KC_O), 
        KC_MINS,            KC_V,            KC_G,            KC_P,            KC_B,                 KC_X,            KC_W,           KC_DOT,         KC_SCLN,         KC_SLSH, 
                                     LT(3,KC_TAB),   LT(2,KC_BSPC),      LT(1,KC_E),         LT(4,KC_SPC),    LT(5,KC_ENT),          KC_MPLY
),
  /*
    * LAYER 1: Navigation
    *              _____                                                   _____
    *       .-----|  Y  |-----._____                           _____.-----| . > |-----.
    * .-----|  C  |_____|  F  |  K  |                         |  Z  |  L  |_____|  U  |-----.
    * |  J  |-----|  T  |-----|_____|                         |_____|-----|  A  |-----|  Q  |
    * |-----|  S  |_____|  H  |  D  |                         |  M  |  N  |_____|  I  |-----|
    * |  R  |-----|  G  |-----|_____|                         |_____|-----| , < |-----|  O  |
    * |-----|  V  |_____|  P  |  B  |                         |  X  |  W  |_____| ; : |-----|
    * |  -_ |-----'     '-----|_____|                         |_____|-----'     '-----| / ? |
    * '-----'          .-----. _____   .-.._           _..-.   _____ .-----.          '-----'
    *                  | TAB ||BCKSP| /     /         \     \ | END || PLAY|           
    *                  '-----':_____|/  E  /           \ SPC \|_____:'-----'
    *                               '--.._/             \_..--'
    */
[_NAV] = LAYOUT_split_3x5_3(
         KC_DEL,         KC_HOME,           KC_UP,          KC_END,         KC_PGUP,               KC_DEL,         KC_HOME,            KC_UP,          KC_END,         KC_PGUP, 
  LALT(KC_BSPC), LGUI_T(KC_LEFT), LCTL_T(KC_DOWN), LSFT_T(KC_RGHT),         KC_PGDN,              KC_BSPC,         KC_LEFT,          KC_DOWN,         KC_RGHT,         KC_PGDN, 
         KC_CUT,         KC_COPY,         KC_PSTE,         KC_UNDO,        KC_AGAIN,               KC_CUT,         KC_COPY,          KC_PSTE,         KC_UNDO,        KC_AGAIN, 
                                          KC_PSCR,         KC_PAUS, _______________,               KC_ESC, _______________,          KC_SCRL
),                                                                           
[_NUM] = LAYOUT_split_3x5_3(
        KC_ASTR,         KC_SLSH,         KC_LCBR,         KC_RCBR,           KC_GT,              MY_AMPR,           KC_P3,            KC_P4,           KC_P5,           KC_P6, 
LALT_T(KC_PPLS), LGUI_T(KC_MINS), LCTL_T(KC_LBRC), LSFT_T(KC_RBRC),           KC_LT,              MY_PIPE,           KC_P0,            KC_P1,           KC_P2,         MY_PDOT, 
        KC_CIRC,         KC_BSLS,         KC_LPRN,         KC_RPRN,         KC_PERC,              MY_EXLM,           KC_P7,            KC_P8,           KC_P9,         MY_COMM, 
                                         TG(_NUM), _______________,        TG(_NAV),       _______________,          KC_EQL, _______________
),                          
/* DM_REC1 & 2 start recording of one of two available dynamic macros.
 * DM_RSTP stops recording of the macro(s).
 * DM_PLY1 & 2 replay the dynamic macros.
 */
[_FNC] = LAYOUT_split_3x5_3(
          KC_F6,           KC_F5,           KC_F4,           KC_F3,         DM_REC1,                KC_INS,           KC_F3,           KC_F4,           KC_F5,           KC_F6, 
  LALT_T(KC_F2),  LGUI_T(KC_F12),  LCTL_T(KC_F11),  LSFT_T(KC_F10),         DM_REC2,               KC_CAPS,          KC_F10,          KC_F11,          KC_F12,           KC_F2, 
          KC_F1,           KC_F9,           KC_F8,           KC_F7,         DM_RSTP,               CW_TOGG,           KC_F7,           KC_F8,           KC_F9,           KC_F1, 
                                        TO(_BASE),        TG(_FNC),         QK_LEAD,               DM_PLY1,         DM_PLY2, _______________
),      
  /*
    * LAYER 4: Symbols
    *              _____                                                   _____
    *       .-----|  #  |-----._____                           _____.-----|  *  |-----.
    * .-----|  @  |_____|  $  |  %  |                         |  ^  |  &  |_____|  (  |-----.
    * |  !  |-----|     |-----|_____|                         |_____|-----| [ { |-----|  )  |
    * |-----|     |_____|     |     |                         |  {  |  }  |_____| ] } |-----|
    * | ` ~ |-----|     |-----|_____|                         |_____|-----|     |-----| ' " |
    * |-----|     |_____|     |     |                         | - _ | = + |_____|  |  |-----|
    * |  ~  |-----'     '-----|_____|                         |_____|-----'     '-----| \ | |
    * '-----'          .-----. _____   .-.._           _..-.   _____ .-----.          '-----'
    *                  |     ||CTRL | /     /         \     \ | BSp ||     |             
    *                  '-----':_____|/ ENT /           \ SPC \|_____:'-----'
    *                               '--.._/             \_..--'
    */         
// UNICODE VERSION:                                                                                                  
[_SYM] = LAYOUT_split_3x5_3(
      X(CZ_PGF),       X(CZ_EUR),       X(CZ_CAR),       X(CZ_HAC),         KC_TILD,       XP(CZ_N, CZ_NU), XP(CZ_C, CZ_CU),XP(CZ_EH, CZ_EHU),XP(CZ_S, CZ_SU), XP(CZ_D, CZ_DU), 
        KC_UNDS,          KC_DLR,         KC_HASH,         KC_LSFT,           KC_AT,     XP(CZ_UK, CZ_UKU), XP(CZ_A, CZ_AU), XP(CZ_E, CZ_EU), XP(CZ_I, CZ_IU), XP(CZ_O, CZ_OU), 
     X(GR_BETA),       X(CZ_PND),      X(GR_OMEG),       X(GR_MJU),          KC_GRV,       XP(CZ_U, CZ_UU), XP(CZ_R, CZ_RU), XP(CZ_Y, CZ_YU), XP(CZ_Z, CZ_ZU), XP(CZ_T, CZ_TU), 
                                        TG(_BASE),         KC_DQUO,         KC_QUOT,       _______________,        TG(_RGB), _______________
),   

// // Manual version:
// [_SYM] = LAYOUT_split_3x5_3(
//          CZ_PGF,          CZ_EUR,          CZ_CAR,          CZ_HAC,         KC_TILD,                    CZ_N,            CZ_C,           CZ_EH,             CZ_S,        CZ_D, 
//         KC_UNDS,          KC_DLR,         KC_HASH,         KC_LSFT,           KC_AT,                   CZ_UK,            CZ_A,            CZ_E,             CZ_I,        CZ_O, 
//         GR_BETA,          CZ_PND,         GR_OMEG,          GR_MJU, xxxxxxxxxxxxxxx,                    CZ_U,            CZ_R,            CZ_Y,             CZ_Z,        CZ_T, 
//                                            KC_GRV,         KC_DQUO,         KC_QUOT,         xxxxxxxxxxxxxxx,           TG(6), xxxxxxxxxxxxxxx
// ),       
// [_SYM] = LAYOUT_split_3x5_3(
// xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx,         KC_TILD,       xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx,xxxxxxxxxxxxxxx,xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, 
//         KC_UNDS,          KC_DLR,         KC_HASH,         KC_LSFT,           KC_AT,       xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, 
// xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx,xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx,        xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, 
//                                            KC_GRV,         KC_DQUO,         KC_QUOT,       xxxxxxxxxxxxxxx,           TG(6), xxxxxxxxxxxxxxx
// ),                              

[_APP] = LAYOUT_split_3x5_3(
        KC_ACL1,         KC_WH_L,         KC_MS_U,         KC_WH_R,         KC_WH_U,               KC_MYCM,         KC_EXEC,         KC_CALC,         KC_MAIL,          KC_PWR, 
        KC_ACL0,         KC_MS_L,         KC_MS_D,         KC_MS_R,         KC_WH_D,               KC_LSFT,         KC_WBAK,         KC_WFWD,         KC_WREF,         KC_SLEP, 
        KC_ACL2,          KC_CUT,         KC_COPY,         KC_PSTE, xxxxxxxxxxxxxxx,               KC_MUTE,         KC_MPRV,         KC_MNXT,         KC_WFAV, xxxxxxxxxxxxxxx, 
                                          KC_BTN3,         KC_BTN2,         KC_BTN1,             TG(_BASE), xxxxxxxxxxxxxxx, _______________
),
/* PB_X are programmable buttons. These are programmable within the host operating system: https://docs.qmk.fm/#/feature_programmable_button
 *
 */
[_RGB] = LAYOUT_split_3x5_3(
        RGB_M_P,         RGB_M_B,         RGB_M_R,        RGB_M_SW,        RGB_M_SN,              RGB_RMOD,         RGB_SAI,         RGB_SAD, xxxxxxxxxxxxxxx,          KC_PWR, 
        RGB_M_T,         RGB_M_G,         RGB_M_X,         RGB_M_K, xxxxxxxxxxxxxxx,               RGB_MOD,         RGB_HUI,         RGB_HUD,         RGB_SPI,         RGB_SPD, 
xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx, xxxxxxxxxxxxxxx,               RGB_TOG,         RGB_VAI,         RGB_VAD, xxxxxxxxxxxxxxx,         KC_SLEP, 
                                  xxxxxxxxxxxxxxx,        TG(_APP),        TG(_SYM),             TO(_BASE),        TG(_RGB), _______________
)                                                                                                  
};   

// Belongs to Leader Key at https://docs.qmk.fm/#/feature_leader_key
LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        // START: Example of leader key combinations from https://docs.qmk.fm/#/feature_leader_key
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_F) {
            // Anything you can do in a macro.
            SEND_STRING("QMK is awesome.");
        }
        SEQ_TWO_KEYS(KC_D, KC_D) {
            SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
        }
        SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
            SEND_STRING("https://start.duckduckgo.com\n");
        }
        SEQ_TWO_KEYS(KC_A, KC_S) {
            register_code(KC_LGUI);
            register_code(KC_S);
            unregister_code(KC_S);
            unregister_code(KC_LGUI);
        }
        // END: Example of leader key combinations
    }
}

// // START: Leader key custom processing hooks: (https://docs.qmk.fm/#/feature_leader_key)
// void leader_start(void) {
//   // sequence started
// }

// void leader_end(void) {
//   // sequence ended (no success/failure detection)
// }
// // END: Leader key custom processing hooks

// LIGHTING:
// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM BASE_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {17, 1, HSV_GREEN} // Indicator
    // {87, 1, HSV_GREEN} // Full stop 
    // {10, 1, HSV_PUNCT}, // Comma
    // {13, 2, HSV_PUNCT2} // Semicolon and slash
);

// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM NAV_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_ACT_ESC}, // Escape
    {5, 1, HSV_NAV_ARR}, // Left arrow
    {9, 2, HSV_NAV_ARR}, // Down & UP arrows
    {12, 1, HSV_NAV_ARR}, // Right arrow
    {4, 1, HSV_NAV_HE}, // Home
    {11, 1, HSV_NAV_HE}, // End
    {15, 2, HSV_NAV_PG}, // PgUp & PgDn
    {13, 2, HSV_ACT_UR}, // Undo & Redo
    {1, 1, HSV_ACT_CUT}, // Cut
    {6, 1, HSV_ACT_COP}, // Copy
    {8, 1, HSV_ACT_PST}, // Paste
    {2, 2, HSV_ACT_DEL}, // Delete & Backspace
    {17, 1, HSV_ACT_LCK} // ScrlLock (and PrintScreen on the ohter side)
    // 7 is Pause on the other side.
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM NUM_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {17, 1, HSV_GREEN}, // Indicator
    {4, 1, HSV_NUM_3},
    {5, 1, HSV_NUM_0},
    {6, 1, HSV_NUM_7},
    {8, 1, HSV_NUM_8},
    {9, 1, HSV_NUM_1},
    {10, 1, HSV_NUM_4},
    {11, 1, HSV_NUM_5},
    {12, 1, HSV_NUM_2},
    {13, 1, HSV_NUM_9},
    {14, 2, HSV_PUNCT},
    {16, 1, HSV_NUM_6},
    {1, 3, HSV_MATH_OP},
    {7, 1, HSV_MATH_EQ}

);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM FNC_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {17, 1, HSV_GREEN}, // Indicator
    {1, 2, HSV_ACT_LCK},
    {3, 1, HSV_ACT_INS},
    {4, 1, HSV_FN_1},
    {5, 1, HSV_FN_3},
    {6, 1, HSV_FN_2},
    {8, 1, HSV_FN_2},
    {9, 1, HSV_FN_3},
    {10, 1, HSV_FN_1},
    {11, 1, HSV_FN_2},
    {12, 2, HSV_FN_3},
    {14, 2, HSV_FN_1},
    {16, 2, HSV_FN_2}
);
const rgblight_segment_t PROGMEM SYM_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_AZURE},
    {2, 1, HSV_TURQUOISE},
    {3, 1, HSV_CYAN},
    {4, 1, HSV_TEAL},
    {5, 1, HSV_BLUE},
    {6, 1, HSV_GOLDENROD},
    {8, 1, HSV_GOLD},
    {7, 1, HSV_YELLOW},
    {9, 1, HSV_ORANGE},
    {10, 1, HSV_CORAL},
    {11, 1, HSV_PINK},
    {12, 1, HSV_PURPLE},
    {13, 1, HSV_MAGENTA},
    {14, 1, HSV_GREEN},
    {15, 1, HSV_CHARTREUSE},
    {16, 1, HSV_SPRINGGREEN},
    {17, 1, HSV_RED},
    {0, 1, HSV_OFF}
);
const rgblight_segment_t PROGMEM APP_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_ACT_MBT},
    {1, 1, HSV_APP_FND},
    {2, 2, HSV_NAV_PG},
    {4, 1, HSV_NAV_HE},
    {5, 1, HSV_NAV_ARR},
    {6, 1, HSV_ACT_PST},
    {7, 1, HSV_ACT_MBT},
    {8, 1, HSV_ACT_COP},
    {9, 2, HSV_NAV_ARR},
    {11, 1, HSV_NAV_HE},
    {12, 1, HSV_NAV_ARR},
    {13, 1, HSV_ACT_CUT},
    {14, 1, HSV_OPTS},
    {15, 2, HSV_POWR},
    {17, 2, HSV_ACT_MBT}
);
const rgblight_segment_t PROGMEM RGB_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RGB_R},
    {7, 1, HSV_RGB_G},
    {17, 1, HSV_RGB_B}
);
const rgblight_segment_t PROGMEM CAPSLOCK_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_LCK_CAPS},
    {7, 1, HSV_LCK_CAPS},
    {17, 1, HSV_LCK_CAPS} 
);
const rgblight_segment_t PROGMEM SCROLLLOCK_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_LCK_SCRL},
    {7, 1, HSV_LCK_SCRL},
    {17, 1, HSV_LCK_SCRL} 
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM kangoo_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    BASE_layer,
    NAV_layer, // Overrides caps lock layer
    NUM_layer, // Overrides other layers
    FNC_layer,  // Overrides other layers
    SYM_layer,
    APP_layer,
    RGB_layer,
    CAPSLOCK_layer,
    SCROLLLOCK_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = kangoo_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(7, led_state.caps_lock);
    rgblight_set_layer_state(8, led_state.scroll_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_BASE, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_NAV, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(_NUM, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(_FNC, layer_state_cmp(state, _FNC));
    rgblight_set_layer_state(_SYM, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(_APP, layer_state_cmp(state, _APP));
    rgblight_set_layer_state(_RGB, layer_state_cmp(state, _RGB));
    return state;
}

// ENCODERS:
// DOC: https://docs.qmk.fm/#/feature_encoders
// NOTE: I did not manage to make the map work. Was getting bunch of "conflictiong types for 'encoder_map'" errors upon compilation.
// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][1][2] = { // const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//     [_BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [_NAV] =  { ENCODER_CCW_CW(KC_RGHT, KC_LEFT) },
//     [_NUM] =  { ENCODER_CCW_CW(KC_UP, KC_DOWN) },
//     [_FNC] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [_SYM] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [_APP] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [_RGB] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
// };
// #endif

// When NOT using ENCODER_MAP_ENABLE = yes, the callback functions can be used
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods;
    mods = get_mods();
    // We need to know the modifier state here. This can be done in several ways apparently:
    // bool shift = keyboard_report->mods & (MOD_BIT(KC_LSFT)); // or
    // bool shift = get_mods() & MOD_BIT(KC_LSFT); // or
    bool shift = (mods & MOD_MASK_SHIFT) > 0; // .. if the difference between left and right modifiers is not important.
    bool ctrl  = (mods & MOD_MASK_CTRL) > 0;
    bool alt   = (mods & MOD_MASK_ALT) > 0;

    // Apparently, according to https://www.youtube.com/watch?v=GLqSPa_Zc2Q we could also use
    if (IS_LAYER_ON(0)) {  // to see if a layer is ON.
        if (clockwise) {
            if (shift) {
                tap_code(KC_MFFD);
            } else if (ctrl) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_VOLU);
                tap_code(KC_VOLU);
            }
        } else {
            if (shift) {
                tap_code(KC_MRWD);
            } else if (ctrl) {
                tap_code(KC_MPRV);
            } else {
                tap_code(KC_VOLD);
                tap_code(KC_VOLD);
            }
        }
    } else if (IS_LAYER_ON(1)) {
        if (clockwise) {
            if (alt) {
                tap_code(KC_UP);
            } else {
                tap_code(KC_RGHT);
            }
        } else {
            if (alt) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_LEFT);
            }
        }
    } else if (IS_LAYER_ON(2)) { // Zoom
        if (clockwise) {
            tap_code16(C(KC_PPLS));
        } else {
            tap_code16(C(KC_PMNS));
        }
    } else if (IS_LAYER_ON(6)) {
        if (clockwise) {
            if (shift) {
                tap_code16(RGB_SAI);
            } else if (ctrl) {
                tap_code16(RGB_HUI);
            } else if (alt) {
                tap_code16(RGB_VAI);
            } else {
                tap_code16(RGB_MOD);
            }
        } else {
            if (shift) {
                tap_code16(RGB_SAD);
            } else if (ctrl) {
                tap_code16(RGB_HUD);
            } else if (alt) {
                tap_code16(RGB_VAD);
            } else {
                tap_code16(RGB_RMOD);
            }
        }
    }
    // switch (get_highest_layer(layer_state | default_layer_state)) {
    //     case 0:               // _BASE
    //         if (index == 0) { // First encoder
    //             if (clockwise) {
    //                 // if (shift) {
    //                 //     tap_code16(KC_MFFD);
    //                 // } else if (ctrl) {
    //                 //     tap_code16(KC_MNXT);
    //                 // } else {
    //                     tap_code(KC_VOLU);
    //                 // }
    //             } else {
    //                 // if (shift) {
    //                 //     tap_code16(KC_MRWD);
    //                 // } else if (ctrl) {
    //                 //     tap_code16(KC_MPRV);
    //                 // } else {
    //                     tap_code(KC_VOLD);
    //                 // }
    //             }
    //         }
    //         // else if (index == 1) { // Second encoder etc.
    //         //     if (clockwise) {
    //         //         rgb_matrix_increase_speed();
    //         //     } else {
    //         //         rgb_matrix_decrease_speed();
    //         //     }
    //         // }
    //         break;
    //     // case 1: // _NAV
    //     //     if (index == 0) {
    //     //         if (clockwise) {
    //     //             if (alt) {
    //     //                 if (shift && ctrl) {
    //     //                     tap_code16(C(S(KC_UP)));
    //     //                 } else if (shift) {
    //     //                     tap_code16(S(KC_UP));
    //     //                 } else if (ctrl) {
    //     //                     tap_code16(C(KC_UP));
    //     //                 } else {
    //     //                     tap_code16(KC_UP);
    //     //                 }
    //     //             } else {
    //     //                 if (shift && ctrl) {
    //     //                     tap_code16(C(S(KC_RGHT)));
    //     //                 } else if (shift) {
    //     //                     tap_code16(S(KC_RGHT));
    //     //                 } else if (ctrl) {
    //     //                     tap_code16(C(KC_RGHT));
    //     //                 } else {
    //     //                     tap_code16(KC_RGHT);
    //     //                 }
    //     //             }
    //     //         } else {
    //     //             if (alt) {
    //     //                 if (shift && ctrl) {
    //     //                     tap_code16(C(S(KC_DOWN)));
    //     //                 } else if (shift) {
    //     //                     tap_code16(S(KC_DOWN));
    //     //                 } else if (ctrl) {
    //     //                     tap_code16(C(KC_DOWN));
    //     //                 } else {
    //     //                     tap_code16(KC_DOWN);
    //     //                 }
    //     //             } else {
    //     //                 if (shift && ctrl) {
    //     //                     tap_code16(C(S(KC_LEFT)));
    //     //                 } else if (shift) {
    //     //                     tap_code16(S(KC_LEFT));
    //     //                 } else if (ctrl) {
    //     //                     tap_code16(C(KC_LEFT));
    //     //                 } else {
    //     //                     tap_code16(KC_LEFT);
    //     //                 }
    //     //             }
    //     //         }
    //     //     }
    //     //     // else if (index == 1) {
    //     //     //     if (clockwise) {
    //     //     //         tap_code_delay(KC_VOLU, 10);
    //     //     //     } else {
    //     //     //         tap_code_delay(KC_VOLD, 10);
    //     //     //     }
    //     //     // }
    //     //     break;
    //     // case 2: // _NUM
    //     //     // Kangoo Swoop has only one encoder so no need to check the index in fact. The two cases above are just for demonstration.
    //     //     if (clockwise) {
    //     //         tap_code16(C(KC_PPLS));
    //     //     } else {
    //     //         tap_code16(C(KC_PMNS));
    //     //     }
    //     //     break;
    //     // case 6: // _RGB
    //     //     if (clockwise) {
    //     //         if (shift) {
    //     //             tap_code16(RGB_SAI);
    //     //         } else if (ctrl) {
    //     //             tap_code16(RGB_HUI);
    //     //         } else if (alt) {
    //     //             tap_code16(RGB_VAI);
    //     //         } else {
    //     //             tap_code16(RGB_MOD);
    //     //         }
    //     //     } else {
    //     //         if (shift) {
    //     //             tap_code16(RGB_SAD);
    //     //         } else if (ctrl) {
    //     //             tap_code16(RGB_HUD);
    //     //         } else if (alt) {
    //     //             tap_code16(RGB_VAD);
    //     //         } else {
    //     //             tap_code16(RGB_RMOD);
    //     //         }
    //     //     }
    //     //     break;
    // }
    return false;
}

// General code processing
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    //static uint16_t layer_exit_timer;
    static bool bExitLayer;

    // rgblight_sethsv_at(HSV_BLUE, 0);
    // rgblight_sethsv_at(HSV_BLUE, 19);
    // rgblight_sethsv_range(HSV_TEAL, 14, 18);
    //bool pressed = record->event.pressed;
    if (IS_LAYER_ON(_NAV) || IS_LAYER_ON(_FNC)) {
        switch (keycode) {
            case KC_AGAIN: case KC_F1:
                if (record->event.pressed) {
                    if (record->tap.count) {
                        bExitLayer = true;
                    }
                } else {
                    if (bExitLayer) {
                        bExitLayer = false;
                        layer_on(_BASE);                            
                    } else {
                        tap_code(keycode);
                    }
                    return false;
                }
        }
    } else if (IS_LAYER_ON(_NUM)) {
        // Shifted numeric layer.
        if (get_mods() & MOD_MASK_SHIFT) {
            switch (keycode) {
                case KC_P0:
                    if (record->event.pressed) {
                        SEND_STRING("{");
                        return false;
                    }
                case KC_P1:
                    if (record->event.pressed) {
                        SEND_STRING("}");
                        return false;
                    }
                case KC_P2:
                    if (record->event.pressed) {
                        SEND_STRING("+");
                        return false;
                    }
                case KC_P3:
                    if (record->event.pressed) {
                        SEND_STRING("(");
                        return false;
                    }
                case KC_P4:
                    if (record->event.pressed) {
                        SEND_STRING(")");
                        return false;
                    }
                case KC_P5:
                    if (record->event.pressed) {
                        SEND_STRING("*");
                        return false;
                    }
                case KC_P6:
                    if (record->event.pressed) {
                        SEND_STRING("/");
                        return false;
                    }
                case KC_P7:
                    if (record->event.pressed) {
                        SEND_STRING("[");
                        return false;
                    }
                case KC_P8:
                    if (record->event.pressed) {
                        SEND_STRING("]");
                        return false;
                    }
                case KC_P9:
                    if (record->event.pressed) {
                        SEND_STRING("%");
                        return false;
                    }
                case MY_PDOT:
                    if (record->event.pressed) {
                        SEND_STRING("-");
                        return false;
                    }
                case MY_COMM:
                    if (record->event.pressed) {
                        SEND_STRING("\\");
                        return false;
                    }
                case MY_AMPR:
                    if (record->event.pressed) {
                        SEND_STRING(">");
                        return false;
                    }
                case MY_PIPE:
                    if (record->event.pressed) {
                        SEND_STRING("<");
                        return false;
                    }
                case MY_EXLM:
                    if (record->event.pressed) {
                        SEND_STRING("^");
                        return false;
                    }
            }
        } else {
            switch (keycode) {
                // case KC_P0: case KC_P1: case KC_P2: case KC_P3: case KC_P4: case KC_P5: case KC_P6: case KC_P7: case KC_P8: case KC_P9:
                //     if (!record->event.pressed) {
                //         return false;
                //     }
                case MY_PDOT:
                    if (record->event.pressed) {
                        SEND_STRING(".");
                        return false;
                    }
                case MY_COMM:
                    if (record->event.pressed) {
                        if (record->tap.count) {
                            bExitLayer = true;
                        }
                    } else {
                        if (bExitLayer) {
                            bExitLayer = false;
                            layer_on(_BASE);                            
                        } else {
                            SEND_STRING(",");
                        }
                        return false;
                    }
                case MY_AMPR:
                    if (record->event.pressed) {
                        SEND_STRING("&");
                        return false;
                    }
                case MY_PIPE:
                    if (record->event.pressed) {
                        SEND_STRING("|");
                        return false;
                    }
                case MY_EXLM:
                    if (record->event.pressed) {
                        SEND_STRING("!");
                        return false;
                    }
            }
        }
    } 
    // else if (IS_LAYER_ON(4)) {
        // bool shift = (get_mods() & MOD_MASK_SHIFT) ? true : false;
        // SEND_STRING("L4. Řád"SS_DELAY(300));
        // if (shift) {
        //         SEND_STRING(" SHIFT "SS_DELAY(300));
        // } else {
        //         SEND_STRING(" NOSHIFT "SS_DELAY(300));
        // }

    //     if (get_mods() & MOD_MASK_SHIFT) {
    //         switch (keycode) {
    //             case CZ_A:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Á");
    //                     return false;
    //                 }
    //             case CZ_C:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Č");
    //                     return false;
    //                 }
    //             case CZ_D:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Ď");
    //                     return false;
    //                 }
    //             case CZ_E:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("É");
    //                     return false;
    //                 }
    //             case CZ_EH:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Ě");
    //                     return false;
    //                 }
    //             case CZ_I:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Í");
    //                     return false;
    //                 }
    //             case CZ_N:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Ň");
    //                     return false;
    //                 }
    //             case CZ_O:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Ó");
    //                     return false;
    //                 }
    //             case CZ_R:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Ř");
    //                     return false;
    //                 }
    //             case CZ_S:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Š");
    //                     return false;
    //                 }
    //             case CZ_T:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Ť");
    //                     return false;
    //                 }
    //             case CZ_U:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Ú");
    //                     return false;
    //                 }
    //             case CZ_UK:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Ů");
    //                     return false;
    //                 }
    //             case CZ_Y:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Ý");
    //                     return false;
    //                 }
    //             case CZ_Z:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Ž");
    //                     return false;
    //                 }

    //                 // if (record->tap.count && record->event.record->event.pressed) {
    //                 //     tap_code16(KC_DQUO); // Send KC_DQUO on tap
    //                 //     return false;        // Return false to ignore further processing of key
    //                 // }
    //                 // break;
    //         }
    //     } else {
    //         switch (keycode) {
    //             case CZ_A:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("á");
    //                     return false;
    //                 }
    //             case CZ_C:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("č");
    //                     return false;
    //                 }
    //             case CZ_D:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("ď");
    //                     return false;
    //                 }
    //             case CZ_E:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("é");
    //                     return false;
    //                 }
    //             case CZ_EH:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("ě");
    //                     return false;
    //                 }
    //             case CZ_I:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("í");
    //                     return false;
    //                 }
    //             case CZ_N:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("ň");
    //                     return false;
    //                 }
    //             case CZ_O:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("ó");
    //                     return false;
    //                 }
    //             case CZ_R:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("ř");
    //                     return false;
    //                 }
    //             case CZ_S:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("š");
    //                     return false;
    //                 }
    //             case CZ_T:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("ť");
    //                     return false;
    //                 }
    //             case CZ_U:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("ú");
    //                     return false;
    //                 }
    //             case CZ_UK:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("ů");
    //                     return false;
    //                 }
    //             case CZ_Y:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("ý");
    //                     return false;
    //                 }
    //             case CZ_Z:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("ž");
    //                     return false;
    //                 }
    //             case CZ_CAR:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("´");
    //                     return false;
    //                 }
    //             case CZ_HAC:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("ˇ");
    //                     return false;
    //                 }
    //             case CZ_PGF:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("§");
    //                     return false;
    //                 }
    //             case CZ_EUR:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("€");
    //                     return false;
    //                 }
    //             case CZ_PND:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Ł");
    //                     return false;
    //                 }
    //             case GR_OMEG:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("Ω");
    //                     return false;
    //                 }
    //             case GR_MJU:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("µ");
    //                     return false;
    //                 }
    //             case GR_BETA:
    //                 if (record->event.pressed) {
    //                     SEND_STRING("ß");
    //                     return false;
    //                 }
    //                 // if (record->tap.count && record->event.record->event.pressed) {
    //                 //     tap_code16(KC_DQUO); // Send KC_DQUO on tap
    //                 //     return false;        // Return false to ignore further processing of key
    //                 // }
    //                 // break;
    //         }
    //     }
    // }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_AGAIN: case MY_COMM: case KC_F1: // Extend the hold term on lower pinky key in the _NAV, _NUM and _FNC layers. (These switch back to the _BASE layer.)
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

// // DOC: https://docs.qmk.fm/#/tap_hold 
// // Applies when PERMISSIVE_HOLD_PER_KEY is enabled.
// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LT(1, KC_BSPC):
//             // Immediately select the hold action when another key is tapped.
//             return true;
//         default:
//             // Do not select the hold action when another key is tapped.
//             return false;
//     }
// }