// Copyright 2024 qqsplit-78 (@NPC-977)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define EE_HANDS// eeprom区分左右
#define SPLIT_USB_DETECT// 连接usb的部分被委派为主
#define SPLIT_LED_STATE_ENABLE// 同步左右指示灯状态
#define SPLIT_TRANSACTION_IDS_USER USER_DATA// 自定义分体传输
#define LAYER_STATE_2BIT// 2层

// 禁用选项
#define NO_MUSIC_MODE
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_ACTION_TAPPING
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
