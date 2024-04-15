// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "transactions.h"

typedef struct _config_data_t {
    bool rgb_state;
} config_data_t;

typedef union { // eeprom存储RGB开关状态，指示灯色调
    uint32_t      raw;
    config_data_t config_data;
} user_config_t;
user_config_t user_config;

enum my_keycodes { // 自定义键码，"QK_KB_0"支持vial内的自定义键码
    RGB_STATE = QK_KB_0
};

void eeconfig_init_user(void) { // eeprom初始化
    user_config.raw                    = 0;
    user_config.config_data.rgb_state  = true; // 默认
    eeconfig_update_user(user_config.raw); // 更新eeprom
}

void user_date_slave_handler(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) { // 从机接收到数据处理方法
    const config_data_t *m2s          = (const config_data_t *)in_data;
    user_config.config_data.rgb_state = m2s->rgb_state; // 更新rgb指示灯状态
}

void keyboard_post_init_user(void) {                              // user级初始化自定义
    user_config.raw = eeconfig_read_user();                       // 从eeprom读出
    transaction_register_rpc(USER_DATA, user_date_slave_handler); // 注册自定义分体传输方法
}

void housekeeping_task_user(void) { // user级键盘内务管理自定义
    if (is_keyboard_master()) {     // 主机才进行发消息到从机
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 500) { // 每500ms同步一次
            transaction_rpc_send(USER_DATA, sizeof(user_config.config_data), &user_config.config_data);
            last_sync = timer_read32();
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) { // user级键码处理自定义
    switch (keycode) {
        case RGB_STATE:
            if (record->event.pressed) {
                user_config.config_data.rgb_state = !user_config.config_data.rgb_state;
                eeconfig_update_user(user_config.raw);
            }
            return false; // 跳过该键
        default:return true; // 其他键码正常处理
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) { // 自定义指示灯
    if (!user_config.config_data.rgb_state) {                                // RGB设置为000覆盖动画效果
        rgb_matrix_set_color_all(0, 0, 0);
    }

    if (host_keyboard_led_state().caps_lock) { // 大写指示灯
        rgb_matrix_set_color(19, 255, 0, 0);
    }

    if (get_highest_layer(layer_state) == 1) { // fn层指示灯
        HSV hsv = rgb_matrix_get_hsv();
        hsv.v = !rgb_matrix_get_val() ? 32 : rgb_matrix_get_val();
        hsv.h = (hsv.h+128)%256;
        RGB rgb                            = hsv_to_rgb(hsv);
        for (uint8_t i = led_min; i < led_max; i++) {
            if (HAS_FLAGS(g_led_config.flags[i], 0x08)) {
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
    }
    return false;
}

uint8_t mod_config(uint8_t mod) { // 不使用magic keycodes交换修饰符
    return mod;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // 默认按键布局
    [0] = LAYOUT(
      KC_ESC  ,KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,    KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,KC_EQL  ,KC_BSPC ,KC_DEL   ,
      KC_F1   ,KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,             KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_LBRC ,KC_RBRC ,KC_BSLS ,KC_VOLU  ,
      KC_F5   ,KC_CAPS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,             KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,KC_ENT  ,KC_MUTE  ,
      KC_F9   ,KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,             KC_B    ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,KC_UP   ,KC_VOLD  ,
      KC_F10  ,KC_LCTL ,KC_LWIN ,KC_LALT ,MO(1)   ,KC_SPC  ,KC_SPC  ,             KC_SPC  ,KC_SPC  ,KC_RALT ,MO(1)   ,KC_RCTL ,KC_LEFT ,KC_DOWN ,KC_RGHT
      ),
    [1] = LAYOUT(
      KC_ESC  ,KC_GRV  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6    ,   KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,KC_DEL ,NK_TOGG   ,
      KC_F1   ,KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,             KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_HOME ,KC_END ,RGB_HUI ,RGB_STATE,
      KC_F2   ,KC_CAPS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,             KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_PGUP ,KC_PGDN ,RGB_SAI  ,RGB_RMOD,
      KC_F11  ,KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,             KC_B    ,KC_N    ,KC_M    ,KC_DEL  ,KC_INS  ,KC_SLSH ,KC_RSFT,RGB_VAI ,RGB_MOD,
      KC_F12  ,KC_LCTL ,GU_TOGG ,KC_LALT ,KC_NO   ,KC_SPC  ,KC_SPC  ,             KC_SPC  ,KC_SPC  ,KC_RALT ,KC_NO   ,KC_RCTL ,RGB_SPD ,RGB_VAD ,RGB_SPI 
      )
};