/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <linux/input.h>

#include "recovery_ui.h"
#include "common.h"

#define KEY_HOME			102
#define KEY_VOLUMEDOWN		114
#define KEY_VOLUMEUP		115
#define KEY_ENTER			28


char* MENU_HEADERS[] = { "8宝系统恢复工具(EVB-V13: 上下键选择，回车键确定)",
                         "",
                         NULL };

char* MENU_ITEMS[] = { "立即重启系统",
                       "升级外部存储设备中的更新包",
                       "清空数据/恢复出厂",
                       "清除缓存分区",
                       "升级缓存中的更新包",
                       NULL };

void device_ui_init(UIParameters* ui_parameters) {
}

int device_recovery_start() {
    return 0;
}

int device_toggle_display(volatile char* key_pressed, int key_code) {
    return key_code == KEY_HOME;
}

int device_reboot_now(volatile char* key_pressed, int key_code) {
    return 0;
}

int device_handle_key(int key_code, int visible) {
    if (visible) {
        switch (key_code) {
            case KEY_DOWN:
            case KEY_VOLUMEDOWN:
                return HIGHLIGHT_DOWN;

            case KEY_UP:
            case KEY_VOLUMEUP:
                return HIGHLIGHT_UP;

            case KEY_ENTER:
                return SELECT_ITEM;
        }
    }

    return NO_ACTION;
}

int device_perform_action(int which) {
    return which;
}

int device_wipe_data() {
    return 0;
}
