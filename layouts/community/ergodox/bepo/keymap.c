#include QMK_KEYBOARD_H
#include "keymap_bepo.h"
#include "keymap_french.h"
#include "print.h"

// keymaps
#define BEPO 0	// default layer, for bepo compatible systems
#define QW_B 1	// bepo to qwerty base compat layer, for qwerty systems
#define QW_A 2	// bepo with altgr key to qwerty compat layer
#define QW_S 3	// bepo with shift key to qwerty compat layer
#define AZ_B 4	// bepo to azerty base compat layer, for azerty systems
#define AZ_A 5	// bepo with altgr key to azerty compat layer
#define AZ_S 6	// bepo with shift key to azerty compat layer
#define FNAV 7	// function / navigation / mouse layer
#define NUMK 8	// numeric keypad layer

enum custom_keycodes {
  EPRM,
  KP_00 = SAFE_RANGE,
  KC_TNUMLOCK,
};

bool base_layer_is_bepo = true;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: default layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   $    |   "  |   <  |   >  |   (  |   )  | BEPO |                                  |ScroLo|   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   %    |   B  |E_ACUT|   P  |   O  |E_GRAV|QWERTY|                                  |CapsLo|   ^  |   V  |   D  |   L  |   J  |   Z    |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |   W    |   A  |   U  |   I  |   E  |   ,  |------|                                  |------|   C  |   T  |   S  |   R  |   N  |   M    |
 * |--------+------+------+------+------+------|AZERTY|                                  |TNumLo|------+------+------+------+------+--------|
 * | E_CIRC |A_GRAV|   Y  |   X  |   .  |   K  |      |                                  |      |   '  |   Q  |   G  |   H  |   F  | C_CEDIL|
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |Escape|Insert|LSuper|T_FNav|L_NumK|             | Tab  |LCtrl |      |RCtrl |Delete|             |Hyper | Meh  |RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | LAlt |      |AltGr |      |      |
 *                                             | Space|Backsp|------|      |------|RShift|Enter |
 *                                             |      |  ace |L_FNav|      |L_FNav|      |      |
 *                                             `--------------------'      `--------------------'
 */
[BEPO] = LAYOUT_ergodox(
// Left hand
BP_DOLLAR,	BP_DQOT,	BP_LGIL,	BP_RGIL,	BP_LPRN,	BP_RPRN,	DF(BEPO),
BP_PERCENT,	BP_B,		BP_E_ACUTE,	BP_P,		BP_O,		BP_E_GRAVE,	DF(QW_B),
BP_W,		BP_A,		BP_U,		BP_I,		BP_E,		BP_COMMA,
BP_ECRC,	BP_A_GRAVE,	BP_Y,		BP_X,		BP_DOT,		BP_K,		DF(AZ_B),
KC_ESC,		KC_INS,		KC_LGUI,	TG(FNAV),	MO(NUMK),
														KC_TAB,		KC_LCTL,
																KC_LALT,
												KC_SPC,		KC_BSPC,	MO(FNAV),
// Right hand
				KC_SLCK,	BP_AT,		BP_PLUS,	BP_MINUS,	BP_SLASH,	BP_ASTR,	BP_EQUAL,
				KC_CAPSLOCK,	BP_DCRC,	BP_V,		BP_D,		BP_L,		BP_J,		BP_Z,
						BP_C,		BP_T,		BP_S,		BP_R,		BP_N,		BP_M,
				KC_TNUMLOCK,	BP_APOS,	BP_Q,		BP_G,		BP_H,		BP_F,		BP_CCED,
								KC_HYPR,	KC_MEH,		KC_RGUI,	KC_PSCREEN,	KC_PAUSE,
KC_RCTL,	KC_DEL,
KC_ALGR,
MO(FNAV),	KC_RSHIFT,	KC_ENTER),
/* Keymap 1: bepo to qwerty base compat layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   $    |   "  |   <  |   >  |   (  |   )  | BEPO |                                  |ScroLo|   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   %    |   b  |   e  |   p  |   o  |   e  |QWERTY|                                  |CapsLo|   ^  |   v  |   d  |   l  |   j  |   z    |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |   w    |   a  |   u  |   i  |   e  |   ,  |------|                                  |------|   c  |   t  |   s  |   r  |   n  |   m    |
 * |--------+------+------+------+------+------|AZERTY|                                  | NumLo|------+------+------+------+------+--------|
 * |   e    |   a  |   y  |   x  |   .  |   k  |      |                                  |      |   '  |   q  |   g  |   h  |   f  |   c    |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |Escape|Insert|LSuper|T_FNav|L_NumK|             | Tab  |LCtrl |      |RCtrl |Delete|             |Hyper | Meh  |RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | LAlt |      |AltGr |      |      |
 *                                             | Space|Backsp|------|      |------|RShift|Enter |
 *                                             |      |  ace |L_FNav|      |L_FNav|      |      |
 *                                             `--------------------'      `--------------------'
 */
[QW_B] = LAYOUT_ergodox(
// Left hand
KC_DOLLAR,	S(KC_QUOT),	S(KC_COMM),	S(KC_DOT),	KC_LPRN,	KC_RPRN,	KC_TRNS,
KC_PERCENT,	KC_B,		KC_E,		KC_P,		KC_O,		KC_E,		KC_TRNS,
KC_W,		KC_A,		KC_U,		KC_I,		KC_E,		KC_COMMA,
KC_E,		KC_A,		KC_Y,		KC_X,		KC_DOT,		KC_K,		KC_TRNS,
KC_ESC,		KC_INS,		KC_LGUI,	KC_TRNS,	KC_TRNS,
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												KC_TRNS,	KC_TRNS,	KC_TRNS,
// Right hand
				KC_TRNS,	KC_AT,		KC_PLUS,	KC_MINUS,	KC_SLASH,	KC_ASTR,	KC_EQUAL,
				KC_TRNS,    	KC_CIRC,	KC_V,		KC_D,		KC_L,		KC_J,		KC_Z,
						KC_C,		KC_T,		KC_S,		KC_R,		KC_N,		KC_M,
				KC_TRNS,   	KC_QUOT,	KC_Q,		KC_G,		KC_H,		KC_F,		KC_C,
								KC_TRNS,	KC_TRNS,	KC_RGUI,	KC_PSCREEN,	KC_PAUSE,
KC_TRNS,	KC_TRNS,
MO(QW_A),
KC_TRNS,	MO(QW_S),	KC_ENTER),
/* Keymap 2: bepo with altgr key to qwerty compat layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   $    |   "  |   <  |   >  |   [  |   ]  | BEPO |                                  |ScroLo|   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   %    |   |  |   e  |   &  |   o  |   e  |QWERTY|                                  |CapsLo|   ^  |   v  |   d  |   l  |   j  |   z    |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |   w    |   a  |   u  |   i  |   €  |   ,  |------|                                  |------|   c  |   t  |   s  |   r  |   n  |   m    |
 * |--------+------+------+------+------+------|AZERTY|                                  | NumLo|------+------+------+------+------+--------|
 * |   e    |   \  |   {  |   }  |   .  |   ~  |      |                                  |      |   '  |   q  |   g  |   h  |   f  |   c    |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |Escape|Insert|LSuper|T_FNav|L_NumK|             | Tab  |LCtrl |      |RCtrl |Delete|             |Hyper | Meh  |RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | LAlt |      |AltGr |      |      |
 *                                             |   _  |Backsp|------|      |------|RShift|Enter |
 *                                             |      |  ace |L_FNav|      |L_FNav|      |      |
 *                                             `--------------------'      `--------------------'
 */
[QW_A] = LAYOUT_ergodox(
// Left hand
KC_DOLLAR,	S(KC_QUOT),	S(KC_COMM),	S(KC_DOT),	KC_LBRC,	KC_RBRC,	KC_TRNS,
KC_PERCENT,	KC_PIPE,	KC_E,		KC_AMPR,	KC_O,		KC_E,		KC_TRNS,
KC_W,		KC_A,		KC_U,		KC_I,		RALT(KC_5),	KC_COMMA,
KC_E,		KC_BSLASH,	KC_LCBR,	KC_RCBR,	KC_DOT,		KC_TILDE,	KC_TRNS,
KC_ESC,		KC_INS,		KC_LGUI,	KC_TRNS,	KC_TRNS,
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												KC_UNDS,	KC_TRNS, 	KC_TRNS,
// Right hand
				KC_TRNS,	KC_AT,		KC_PLUS,	KC_MINUS,	KC_SLASH,	KC_ASTR,	KC_EQUAL,
				KC_TRNS,    	KC_CIRC,	KC_V,		KC_D,		KC_L,		KC_J,		KC_Z,
						KC_C,		KC_T,		KC_S,		KC_R,		KC_N,		KC_M,
				KC_TRNS,   	KC_QUOT,	KC_Q,		KC_G,		KC_H,		KC_F,		KC_C,
								KC_TRNS,	KC_TRNS,	KC_RGUI,	KC_PSCREEN,	KC_PAUSE,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_ENTER),
/* Keymap 3: bepo with shift key to qwerty compat layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   #    |   1  |   2  |   3  |   4  |   5  | BEPO |                                  |ScroLo|   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   `    |   B  |   E  |   P  |   O  |   E  |QWERTY|                                  |CapsLo|   !  |   V  |   D  |   L  |   J  |   Z    |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |   W    |   A  |   U  |   I  |   E  |   ;  |------|                                  |------|   C  |   T  |   S  |   R  |   N  |   M    |
 * |--------+------+------+------+------+------|AZERTY|                                  | NumLo|------+------+------+------+------+--------|
 * |   E    |   A  |   Y  |   X  |   :  |   K  |      |                                  |      |   ?  |   Q  |   G  |   H  |   F  |   C    |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |Escape|Insert|LSuper|T_FNav|L_NumK|             | Tab  |LCtrl |      |RCtrl |Delete|             |Hyper | Meh  |RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | LAlt |      |AltGr |      |      |
 *                                             | Space|Backsp|------|      |------|RShift|Enter |
 *                                             |      |  ace |L_FNav|      |L_FNav|      |      |
 *                                             `--------------------'      `--------------------'
 */
[QW_S] = LAYOUT_ergodox(
// Left hand
KC_HASH,	KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_TRNS,
KC_GRV,		S(KC_B),	S(KC_E),	S(KC_P),	S(KC_O),	S(KC_E),	KC_TRNS,
S(KC_W),	S(KC_A),	S(KC_U),	S(KC_I),	S(KC_E),	KC_SCOLON,
S(KC_E),	S(KC_A),	S(KC_Y),	S(KC_X),	KC_COLON,	S(KC_K),	KC_TRNS,
S(KC_ESC),	S(KC_INS),	S(KC_LGUI),	KC_TRNS,	KC_TRNS,
														S(KC_TAB),	S(KC_LCTL),
																S(KC_LALT),
												KC_TRNS,	KC_TRNS,	KC_TRNS,
// Right hand
				KC_TRNS,	KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_TRNS,
				KC_TRNS,	KC_EXLM,	S(KC_V),	S(KC_D),	S(KC_L),	S(KC_J),	S(KC_Z),
						S(KC_C),	S(KC_T),	S(KC_S),	S(KC_R),	S(KC_N),	S(KC_M),
				KC_TRNS,	S(KC_SLASH),	S(KC_Q),	S(KC_G),	S(KC_H),	S(KC_F),	S(KC_C),
								KC_TRNS,	KC_TRNS,	S(KC_RGUI),	KC_TRNS,	KC_TRNS,
S(KC_RCTL),	KC_TRNS,
S(KC_RALT),
KC_TRNS,	KC_TRNS,	KC_TRNS),
/* Keymap 4: bepo to azerty base compat layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   $    |   "  |   <  |   >  |   (  |   )  | BEPO |                                  |ScroLo|   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   %    |   b  |e_acut|   p  |   o  |e_grav|QWERTY|                                  |CapsLo|   ^  |   v  |   d  |   l  |   j  |   z    |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |   w    |   a  |   u  |   i  |   e  |   ,  |------|                                  |------|   c  |   t  |   s  |   r  |   n  |   m    |
 * |--------+------+------+------+------+------|AZERTY|                                  | NumLo|------+------+------+------+------+--------|
 * |   e    |a_grav|   y  |   x  |   .  |   k  |      |                                  |      |   '  |   q  |   g  |   h  |   f  | c_cedil|
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |Escape|Insert|LSuper|T_FNav|L_NumK|             | Tab  |LCtrl |      |RCtrl |Delete|             |Hyper | Meh  |RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | LAlt |      |AltGr |      |      |
 *                                             | Space|Backsp|------|      |------|RShift|Enter |
 *                                             |      |  ace |L_FNav|      |L_FNav|      |      |
 *                                             `--------------------'      `--------------------'
 */
[AZ_B] = LAYOUT_ergodox(
// Left hand
FR_DLR,		FR_QUOT,	FR_LESS,	FR_GRTR,	FR_LPRN,	FR_RPRN,	KC_TRNS,
FR_PERC,	KC_B,		FR_EACU,	KC_P,		KC_O,		FR_EGRV,	KC_TRNS,
FR_W,		FR_A,		KC_U,		KC_I,		KC_E,		FR_COMM,
KC_E,		FR_AGRV,	KC_Y,		KC_X,		FR_DOT,		KC_K,		KC_TRNS,
KC_ESC,		KC_INS,		KC_LGUI,	KC_TRNS,	KC_TRNS,
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												KC_TRNS,	KC_TRNS,	KC_TRNS,
// Right hand
				KC_TRNS,	FR_AT,		FR_PLUS,	FR_MINS,	FR_SLSH,	FR_ASTR,	FR_EQL,
				KC_TRNS,	KC_LBRC,	KC_V,		KC_D,		KC_L,		KC_J,		FR_Z,
						KC_C,		KC_T,		KC_S,		KC_R,		KC_N,		FR_M,
				KC_TRNS,	FR_APOS,	FR_Q,		KC_G,		KC_H,		KC_F,		FR_CCED,
								KC_TRNS,	KC_TRNS,	KC_RGUI,	KC_PSCREEN,	KC_PAUSE,
KC_TRNS,	KC_TRNS,
MO(AZ_A),
KC_TRNS,	MO(AZ_S),	KC_ENTER),
/* Keymap 5: bepo with altgr key to azerty compat layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   $    |   "  |   <  |   >  |   [  |   ]  | BEPO |                                  |ScroLo|   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   %    |   |  |   e  |   &  |   o  |   e  |QWERTY|                                  |CapsLo|   ^  |   v  |   d  |   l  |   j  |   z    |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |   w    |   a  |u_grav| trem |   €  |   ,  |------|                                  |------|   c  |   t  |   s  |   r  |   n  |   m    |
 * |--------+------+------+------+------+------|AZERTY|                                  | NumLo|------+------+------+------+------+--------|
 * |   /    |   \  |   {  |   }  |   .  |   ~  |      |                                  |      |   '  |   q  |   g  |   h  |   f  |   c    |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |Escape|Insert|LSuper|T_FNav|L_NumK|             | Tab  |LCtrl |      |RCtrl |Delete|             |Hyper | Meh  |RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | LAlt |      |AltGr |      |      |
 *                                             |   _  |Backsp|------|      |------|RShift|Enter |
 *                                             |      |  ace |L_FNav|      |L_FNav|      |      |
 *                                             `--------------------'      `--------------------'
 */
[AZ_A] = LAYOUT_ergodox(
// Left hand
FR_DLR,		FR_QUOT,	FR_LESS,	FR_GRTR,	FR_LBRC,	FR_RBRC,	KC_TRNS,
FR_PERC,	FR_PIPE,	FR_EACU,	FR_AMP,		KC_O,		FR_EGRV,	KC_TRNS,
FR_W,		FR_A,		FR_UGRV,	S(KC_LBRC),	FR_EURO,	FR_COMM,
FR_SLSH,	FR_BSLS,	FR_LCBR,	FR_RCBR,	FR_DOT,		FR_TILD,	KC_TRNS,
KC_ESC,		KC_INS,		KC_LGUI,	KC_TRNS,	KC_TRNS,
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												FR_UNDS,	KC_TRNS,	KC_TRNS,
// Right hand
				KC_TRNS,	FR_AT,		FR_PLUS,	FR_MINS,	FR_SLSH,	FR_ASTR,	FR_EQL,
				KC_TRNS,	KC_LBRC,	KC_V,		KC_D,		KC_L,		KC_J,		FR_Z,
						KC_C,		KC_T,		KC_S,		KC_R,		KC_N,		FR_M,
				KC_TRNS,	FR_APOS,	FR_Q,		KC_G,		KC_H,		KC_F,		FR_CCED,
								KC_TRNS,	KC_TRNS,	KC_RGUI,	KC_PSCREEN,	KC_PAUSE,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_ENTER),
/* Keymap 6: bepo with shift key to azerty compat layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   #    |   1  |   2  |   3  |   4  |   5  | BEPO |                                  |ScroLo|   6  |   7  |   8  |   9  |   0  |   °    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   `    |   B  |   E  |   P  |   O  |   E  |QWERTY|                                  |CapsLo|   !  |   V  |   D  |   L  |   J  |   Z    |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |   W    |   A  |   U  |   I  |   E  |   ;  |------|                                  |------|   C  |   T  |   S  |   R  |   N  |   M    |
 * |--------+------+------+------+------+------|AZERTY|                                  | NumLo|------+------+------+------+------+--------|
 * |   E    |   A  |   Y  |   X  |   :  |   K  |      |                                  |      |   ?  |   Q  |   G  |   H  |   F  |   C    |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |Escape|Insert|LSuper|T_FNav|L_NumK|             | Tab  |LCtrl |      |RCtrl |Delete|             |Hyper | Meh  |RSuper|PrntSc| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      | LAlt |      |AltGr |      |      |
 *                                             | Space|Backsp|------|      |------|RShift|Enter |
 *                                             |      |  ace |L_FNav|      |L_FNav|      |      |
 *                                             `--------------------'      `--------------------'
 */
[AZ_S] = LAYOUT_ergodox(
// Left hand
FR_HASH,	FR_1,		FR_2,		FR_3,		FR_4,		FR_5,		KC_TRNS,
FR_GRV,		S(KC_B),	S(KC_E),	S(KC_P),	S(KC_O),	S(KC_E),	KC_TRNS,
S(FR_W),	S(FR_A),	S(KC_U),	S(KC_I),	S(KC_E),	FR_SCLN,
S(KC_E),	S(FR_A),	S(KC_Y),	S(KC_X),	FR_COLN,	S(KC_K),	KC_TRNS,
S(KC_ESC),	S(KC_INS),	S(KC_LGUI),	KC_TRNS,	KC_TRNS,
														S(KC_TAB),	S(KC_LCTL),
																S(KC_LALT),
												KC_TRNS,	KC_TRNS,	KC_TRNS,
// Right hand
				KC_TRNS,	FR_6,		FR_7,		FR_8,		FR_9,		FR_0,		FR_OVRR,
				KC_TRNS,	FR_EXLM,	S(KC_V),	S(KC_D),	S(KC_L),	S(KC_J),	S(FR_Z),
						S(KC_C),	S(KC_T),	S(KC_S),	S(KC_R),	S(KC_N),	S(FR_M),
				KC_TRNS,	FR_QUES,	S(FR_Q),	S(KC_G),	S(KC_H),	S(KC_F),	S(KC_C),
								KC_TRNS,	KC_TRNS,	S(KC_RGUI),	KC_TRNS,	KC_TRNS,
S(KC_RCTL),	KC_TRNS,
S(KC_RALT),
KC_TRNS,	KC_TRNS,	KC_TRNS),
/* Keymap 7: function / navigation / mouse layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |VolMut|                                  |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |        | Next |LClick|  Up  |RClick| WhUp |VolDwn|                                  |      | PgUp | Home |  Up  |  End |  F11 |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        | Prev | Left | Down | Right|WhDown|------|                                  |------| PgDn | Left | Down | Right|  F12 |        |
 * |--------+------+------+------+------+------| VolUp|                                  |      |------+------+------+------+------+--------|
 * |        | Undo |  Cut | Copy | Paste|      |      |                                  |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |             |      |      |      |      |      |             |      |      |      |      | RESET |
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |      |      |      |      |      |
 *                                             |      |      |------|      |------|      |      |
 *                                             |      |      |      |      |      |      |      |
 *                                             `--------------------'      `--------------------'
 */
[FNAV] = LAYOUT_ergodox(
// Left hand
KC_NO,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_MUTE,
KC_NO,		KC_MS_BTN5,	KC_MS_BTN1,	KC_MS_UP,	KC_MS_BTN2,	KC_MS_WH_UP,	KC_VOLU,
KC_NO,		KC_MS_BTN4,	KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_RIGHT,	KC_MS_WH_DOWN,
KC_NO,		KC_UNDO,	KC_CUT,		KC_COPY,	KC_PASTE,	KC_NO,		KC_VOLD,
KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_NO,  	KC_TRNS,
																KC_TRNS,
												KC_NO,		KC_NO,  	KC_TRNS,
// Right hand
				KC_NO,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_NO,
				KC_NO,		KC_PGUP,	KC_HOME,	KC_UP,		KC_END,		KC_F11,		KC_NO,
						KC_PGDOWN,	KC_LEFT,	KC_DOWN,	KC_RIGHT,	KC_F12,		KC_NO,
				KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
								KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_NO,		RESET,
KC_TRNS,	KC_NO,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_NO),
/* Keymap 8: numeric keypad layer, sends keypad codes
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |                                  |      |      | NumLo|   /  |   *  |   -  |        |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |   7  |   8  |   9  |   +  |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|                                  |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |                                  |TNumLo|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |   1  |   2  |   3  | Enter|        |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |             |      |      |      |      |      |             |   0  |  00  |   .  | Enter|      |
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |      |      |      |      |      |
 *                                             |      |      |------|      |------|      |      |
 *                                             |      |      |      |      |      |      |      |
 *                                             `--------------------'      `--------------------'
 */
[NUMK] = LAYOUT_ergodox(
// Left hand
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												KC_NO,		KC_TRNS,	KC_TRNS,
// Right hand
				KC_NO,		KC_NO,		KC_NUMLOCK,	KC_KP_SLASH,	KC_KP_ASTERISK,	KC_KP_MINUS,	KC_NO,
				KC_NO,		KC_NO,		KC_KP_7,	KC_KP_8,	KC_KP_9,	KC_KP_PLUS,	KC_NO,
						KC_NO,		KC_KP_4,	KC_KP_5,	KC_KP_6,	KC_KP_PLUS,	KC_NO,
				KC_TRNS,	KC_NO,		KC_KP_1,	KC_KP_2,	KC_KP_3,	KC_KP_ENTER,	KC_NO,
								KC_KP_0,	KP_00,		KC_KP_COMMA,	KC_KP_ENTER,	KC_NO,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_NO)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
    // keypad "double 0"
    case KP_00:
      if (record->event.pressed) {
	SEND_STRING(SS_TAP(X_KP_0) SS_DOWN(X_KP_0));
      }
      else {
	SEND_STRING(SS_UP(X_KP_0));
      }
      break;
    case KC_TNUMLOCK:
      if (record->event.pressed) {
	SEND_STRING(SS_TAP(X_NUMLOCK));
	if(IS_LAYER_ON(NUMK)) {
          layer_off(NUMK);
	}
	else {
	  layer_on(NUMK);
	}
      }
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 7:
      ergodox_right_led_3_on();
      uprintf("layer:7\n");
      break;
    case 8:
      ergodox_right_led_2_on();
      uprintf("layer:8\n");
      break;
    default:
      break;
  }
  return state;
};

uint32_t default_layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_right_led_1_off();
  switch (layer) {
    case 0:
      uprintf("default layer:0\n");
      base_layer_is_bepo = true;
      break;
    case 1:
      ergodox_right_led_1_on();
      uprintf("default layer:1\n");
      base_layer_is_bepo = false;
      break;
    case 4:
      ergodox_right_led_1_on();
      uprintf("default layer:4\n");
      base_layer_is_bepo = false;
      break;
    default:
      break;
  }
  return state;
};

// Runs constantly in the background, in a loop.
void led_set_user(uint8_t usb_led) {
    if (! base_layer_is_bepo) {
        ergodox_right_led_1_on();
    }
    else if (usb_led & (1<<USB_LED_NUM_LOCK) && IS_LAYER_ON(NUMK)) {
        ergodox_right_led_1_on();
    }
    else if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_1_on();
    }
    else if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
        ergodox_right_led_1_on();
    }
    else {
        ergodox_right_led_1_off();
    }
};
