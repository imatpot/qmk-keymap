#include QMK_KEYBOARD_H
#include "keymap_swiss_de.h"

// ┌───────────────────────────────────────────────────────────────────────────┐
// │ Keyboard layout                                                           │
// └───────────────────────────────────────────────────────────────────────────┘

enum planck_layers {
    QWE,
    LOW,
    RSE,
    QMK,
    CMB,
    RST,
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, LOW, RSE, CMB);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base QWERTZ layer
    // ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
    // │ Esc │  Q  │  W  │  E  │  R  │  T  │  Z  │  U  │  I  │  O  │  P  │ Bsp │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │ Tab │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │ ' ? │ Rtn │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │ Sft │  Y  │  X  │  C  │  V  │  B  │  N  │  M  │ , ; │ . : │ - _ │ $ £ │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │ Ctl │ Win │ Alt │ Qmk │ Low │   Space   │ Rse │ Alf │ Adn │ Aup │ Art │
    // └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
    [QWE] = LAYOUT_planck_grid(
        KC_ESC,  CH_Q,    CH_W,    CH_E,    CH_R,    CH_T,    CH_Z,    CH_U,    CH_I,    CH_O,    CH_P,    KC_BSPC,
        KC_TAB,  CH_A,    CH_S,    CH_D,    CH_F,    CH_G,    CH_H,    CH_J,    CH_K,    CH_L,    CH_QUOT, KC_ENT,
        KC_LSFT, CH_Y,    CH_X,    CH_C,    CH_V,    CH_B,    CH_N,    CH_M,    CH_COMM, CH_DOT,  CH_MINS, CH_DLR,
        KC_LCTL, KC_LWIN, KC_LALT, MO(QMK), MO(LOW), KC_SPC,  XXXXXXX, MO(RSE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    // Lower layer
    // ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
    // │  §  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │ Del │  +  │  @  │  *  │  ç  │  %  │  &  │  |  │  #  │  =  │  /  │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │     │  (  │  )  │  [  │  ]  │  {  │  }  │  \  │  <  │  >  │  !  │  "  │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │     │     │     │ --- │ [X] │           │     │     │     │     │     │
    // └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
    [LOW] = LAYOUT_planck_grid(
        CH_SECT, CH_1,    CH_2,    CH_3,    CH_4,    CH_5,    CH_6,    CH_7,    CH_8,    CH_9,    CH_0,    _______,
        KC_DEL,  CH_PLUS, CH_AT,   CH_ASTR, CH_CCED, CH_PERC, CH_AMPR, CH_PIPE, CH_HASH, CH_EQL,  CH_SLSH, _______,
        _______, CH_LPRN, CH_RPRN, CH_LBRC, CH_RBRC, CH_LCBR, CH_RCBR, CH_BSLS, CH_LABK, CH_RABK, CH_EXLM, CH_DQUO,
        _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, _______, _______
    ),

    // Raised layer
    // ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
    // │ F01 │ F02 │ F03 │ F04 │ F05 │ F06 │ F07 │ F08 │ F09 │ F10 │ F11 │ F12 │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │     │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │     │ Ins │ Ins │ --- │ --- │ --- │  ~  │  ¨  │  ´  │  `  │  ^  │  €  │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │     │     │     │ --- │     │           │ [X] │ Hom │ PgD │ PgU │ End │
    // └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
    [RSE] = LAYOUT_planck_grid(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_INS,  KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, CH_TILD, CH_DIAE, CH_ACUT, CH_GRV,  CH_CIRC, CH_EURO,
        _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),

    // QMK-key layer
    // ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
    // │ {Q} │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ {R} │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │ Cps │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │ --- │ --- │ --- │ [X] │ --- │    ---    │ --- │ --- │ --- │ --- │ --- │
    // └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
    // {Q} = Layer QWERTZ
    // {R} = Layer RESET
    [QMK] = LAYOUT_planck_grid(
        TO(QWE), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(RST),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    // Combo layer (lower + raised)
    // ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
    // │ --- │ --- │ --- │ Au- │ Au+ │ --- │ --- │ Bli │ Br- │ Br+ │ --- │ --- │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │ --- │ --- │ --- │ Mu- │ Mu+ │ --- │ --- │ Ani │ Hu- │ Hu+ │ Ind │ --- │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │ Mut │ --- │ --- │ --- │ [X] │ PlayPause │ [X] │ Prv │ VoD │ VoU │ Nxt │
    // └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
    // Ani = Backlight Animation
    // Au- = Chiptune Audio Off
    // Au+ = Chiptune Audio On
    // Bli = Backlight Toggle
    // Br- = Brightness Down
    // Br+ = Brightness Up
    // Hu- = Backlight Hue Previous
    // Hu+ = Backlight Hue Next
    // Ind = Layer Indicator Toggle
    // Mu- = Chiptune Music Off
    // Mu+ = Chiptune Music On
    // Mut = Audio Mute
    // Nxt = Next Track
    // Prv = Previous Track
    // VoD = Volume Down
    // VoU = Volume Up
    [CMB] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_MPLY, XXXXXXX, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
    ),

    // Reset/Bootloader layer
    // ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
    // │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │ --- │
    // ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
    // │ --- │ --- │ --- │     │ --- │   Reset   │ --- │ --- │ --- │ --- │ --- │
    // └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
    [RST] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

// ┌───────────────────────────────────────────────────────────────────────────┐
// │ RGB / LED Configuration                                                   │
// └───────────────────────────────────────────────────────────────────────────┘

#define PLANCK_EZ_LED_LOWER LOW
#define PLANCK_EZ_LED_RAISE RSE
#define PLANCK_EZ_LED_ADJUST CMB

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    // No changes for QWERTZ layer

    // Lower layer
    [LOW] = {
        {255,0,0},   {255,0,0},   {255,0,0},   {255,0,0},   {255,0,0},   {255,0,0},   {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {255,0,0},   {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {255,0,0},   {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {255,0,0},                {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0}
    },

    // Raised layer
    [RSE] = {
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {255,0,0},   {255,0,0},   {255,0,0},   {255,0,0},   {255,0,0},   {255,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {255,0,0},   {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {255,0,0},   {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {255,0,0},                {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0}
    },

    // QMK-key layer
    [QMK] = {
        {255,0,0},   {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {255,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},
        {255,0,0},   {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},                  {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0}
    },

    // Combo layer (lower + raised)
    [CMB] = {
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},                  {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0}
    },

    // Reset/Bootloader layer
    [RST] = {
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},
        {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {255,0,0},                {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0}
    },
};

void set_layer_color(uint8_t layer) {
    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        uint8_t r = ledmap[layer][i][0];
        uint8_t g = ledmap[layer][i][1];
        uint8_t b = ledmap[layer][i][2];
        rgb_matrix_set_color(i, r, g, b);
    }
}

bool is_caps_lock_on(void) {
    return host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK);
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }

    uint8_t layer = biton32(layer_state);

    if (layer == QWE) {
        if (is_caps_lock_on()) {
            rgb_matrix_set_color_all(0, 0, 0);

            uint8_t shift_key_index = 24;
            rgb_matrix_set_color(shift_key_index, 255, 0, 0 );
        }
    } else {
        set_layer_color(layer);
    }

    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
    }

    return true;
}
