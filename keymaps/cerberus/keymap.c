#include QMK_KEYBOARD_H
#include "eeprom.h"
#include "keymap_swiss_de.h"

#ifdef AUDIO_ENABLE
#include "muse.h"
#endif

enum planck_keycodes {
    RGB_SLD = EZ_SAFE_RANGE,
    CH_LSPO,
    CH_RSPC,
};

enum planck_layers {
    _QWERTZ,
    _LOWER,
    _BASE,
    _RAISE,
    _ADJUST,
    _RESET,
    _NAVIGATE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTZ] = LAYOUT_planck_grid(
        KC_ESCAPE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           CH_Z,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,
        KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           CH_QUOT,        KC_ENTER,
        KC_LSFT,        CH_Y,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         CH_MINS,        CH_DLR,
        KC_LCTL,        KC_LGUI,        KC_LALT,        MO(6),          LOWER,          KC_SPACE,       KC_NO,          RAISE,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT
    ),

    [_LOWER] = LAYOUT_planck_grid(
        CH_SECT,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
        KC_DELETE,      CH_PLUS,        CH_AT,          CH_ASTR,        CH_CCED,        CH_PERC,        CH_AMPR,        CH_PIPE,        CH_HASH,        CH_EQL,         CH_SLSH,        KC_TRANSPARENT,
        KC_TRANSPARENT, CH_LPRN,        CH_RPRN,        CH_LBRC,        CH_RBRC,        CH_LCBR,        CH_RCBR,        CH_BSLS,        CH_LABK,        CH_RABK,        CH_EXLM,        CH_DQUO,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_RALT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    [_BASE] = LAYOUT_planck_grid(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    [_RAISE] = LAYOUT_planck_grid(
        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,
        KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
        KC_TRANSPARENT, KC_PSCR,        KC_HOME,        KC_END,         KC_INSERT,      KC_PGDN,        KC_PGUP,        CH_DIAE,        CH_ACUT,        CH_GRV,         CH_CIRC,        CH_TILD,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    [_ADJUST] = LAYOUT_planck_grid(
        KC_NO,          KC_NO,          KC_NO,          AU_OFF,         AU_ON,          KC_NO,          KC_NO,          RGB_TOG,        RGB_VAD,        RGB_VAI,        KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          MU_MOD,         MU_TOG,         KC_NO,          KC_NO,          RGB_MOD,        RGB_HUD,        RGB_HUI,        LED_LEVEL,      KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_AUDIO_MUTE,  KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,KC_NO,      KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK
    ),

    [_RESET] = LAYOUT_planck_grid(
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO
    ),

    [_NAVIGATE] = LAYOUT_planck_grid(
        TO(0),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(5),
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_CAPS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO
    ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    // No QWERTZ

    // LOWER
    [1] = {
        {0,255,255},   {0,255,255},   {0,255,255},   {0,255,255},   {0,255,255},   {0,255,255},   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,255,255},   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,255,255},   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,255,255},                  {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    },

    // No BASE

    // RAISE
    [3] = {
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,255,255},   {0,255,255},   {0,255,255},   {0,255,255},   {0,255,255},   {0,255,255},
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,255,255},   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,255,255},   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,255,255},                  {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    },

    // ADJUST
    [4] = {
        {0,0,0},       {0,0,0},       {0,0,0},       {105,255,255}, {105,255,255}, {0,0,0},       {0,0,0},       {146,224,255}, {146,224,255}, {146,224,255}, {0,0,0},       {0,0,0},
        {0,0,0},       {0,0,0},       {0,0,0},       {105,255,255}, {105,255,255}, {0,0,0},       {0,0,0},       {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {0,0,0},
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
        {31,255,255},  {0,0,0},       {0,0,0},       {0,0,0},       {0,255,255},   {0,0,0},                      {0,255,255},   {31,255,255},  {31,255,255},  {31,255,255},  {31,255,255},
    },

    // RESET
    [5] = {
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,255,255},                  {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    },

    // NAVIGATE
    [6] = {
        {0,255,255},   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,255,255},
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
        {0,255,255},   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},                      {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    },
};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color( i, 0, 0, 0 );
        } else {
            RGB rgb = hsv_to_rgb( hsv );
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
        }
    }
}

bool caps_lock_on(void) {
    return host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK);
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }

    int layer = biton32(layer_state);

    switch (layer) {
        case 1:
            set_layer_color(1);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        case 5:
            set_layer_color(5);
            break;
        case 6:
            set_layer_color(6);
            break;
        default:
            if (caps_lock_on()) {
                rgb_matrix_set_color_all(0, 0, 0);
                rgb_matrix_set_color(24, 255, 0, 0 );
            }
            else if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
                rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CH_LSPO:
            perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
            return false;
        case CH_RSPC:
            perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
            return false;
        case RGB_SLD:
            if (record->event.pressed) rgblight_mode(1);
            return false;
    }
    return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
            #ifdef MOUSEKEY_ENABLE
                register_code(KC_MS_WH_DOWN);
                unregister_code(KC_MS_WH_DOWN);
            #else
                register_code(KC_PGDN);
                unregister_code(KC_PGDN);
            #endif
        } else {
            #ifdef MOUSEKEY_ENABLE
                register_code(KC_MS_WH_UP);
                unregister_code(KC_MS_WH_UP);
            #else
                register_code(KC_PGUP);
                unregister_code(KC_PGUP);
            #endif
        }
    }
}

void matrix_scan_user(void) {
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
