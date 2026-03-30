/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

void custom_init(lv_ui *ui);
void custom_set_background(lv_ui *ui, const lv_img_dsc_t *img);
/* mode: 0 none, 1 setting(menu_bar), 2 music(music_play), 3 sound_ai(cont_1) */
void custom_apply_mode(lv_ui *ui, int mode);
void custom_toggle_music(lv_ui *ui);
void custom_toggle_setting(lv_ui *ui);
void custom_toggle_sound_ai(lv_ui *ui);
void custom_update_play_state(lv_ui *ui, bool playing);
void custom_update_listening_state(lv_ui *ui, bool listening);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
