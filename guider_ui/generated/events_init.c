/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

static void custom_music_btn_event_cb(lv_event_t * e);
static void custom_setting_btn_event_cb(lv_event_t * e);
static void custom_sound_ai_btn_event_cb(lv_event_t * e);
static void custom_play_btn_event_cb(lv_event_t * e);
static void custom_voice_btn_event_cb(lv_event_t * e);

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif



void events_init(lv_ui *ui)
{
	if(ui == NULL) return;

	/* Bind to VALUE_CHANGED so we read the post-toggle checked state */
	if(ui->screen_music) {
		lv_obj_add_event_cb(ui->screen_music, custom_music_btn_event_cb, LV_EVENT_VALUE_CHANGED, ui);
	}

	if(ui->screen_setting) {
		lv_obj_add_event_cb(ui->screen_setting, custom_setting_btn_event_cb, LV_EVENT_VALUE_CHANGED, ui);
	}

	if(ui->screen_sounds_ai) {
		lv_obj_add_event_cb(ui->screen_sounds_ai, custom_sound_ai_btn_event_cb, LV_EVENT_VALUE_CHANGED, ui);
	}

	/* Play button controls gif start/stop */
	if(ui->screen_play) {
		lv_obj_add_event_cb(ui->screen_play, custom_play_btn_event_cb, LV_EVENT_VALUE_CHANGED, ui);
	}

	/* Voice press to play listening gif */
	if(ui->screen_voice_in_ctr) {
		lv_obj_add_event_cb(ui->screen_voice_in_ctr, custom_voice_btn_event_cb, LV_EVENT_PRESSED, ui);
		lv_obj_add_event_cb(ui->screen_voice_in_ctr, custom_voice_btn_event_cb, LV_EVENT_RELEASED, ui);
		lv_obj_add_event_cb(ui->screen_voice_in_ctr, custom_voice_btn_event_cb, LV_EVENT_PRESS_LOST, ui);
	}

}

static void custom_music_btn_event_cb(lv_event_t * e)
{
	lv_ui *u = (lv_ui *)lv_event_get_user_data(e);
	bool checked = lv_obj_has_state(lv_event_get_target(e), LV_STATE_CHECKED);
	custom_apply_mode(u, checked ? 2 : 0);
}

static void custom_setting_btn_event_cb(lv_event_t * e)
{
	lv_ui *u = (lv_ui *)lv_event_get_user_data(e);
	bool checked = lv_obj_has_state(lv_event_get_target(e), LV_STATE_CHECKED);
	custom_apply_mode(u, checked ? 1 : 0);
}

static void custom_sound_ai_btn_event_cb(lv_event_t * e)
{
	lv_ui *u = (lv_ui *)lv_event_get_user_data(e);
	bool checked = lv_obj_has_state(lv_event_get_target(e), LV_STATE_CHECKED);
	custom_apply_mode(u, checked ? 3 : 0);
}

static void custom_play_btn_event_cb(lv_event_t * e)
{
	lv_ui *u = (lv_ui *)lv_event_get_user_data(e);
	bool checked = lv_obj_has_state(lv_event_get_target(e), LV_STATE_CHECKED);
	custom_update_play_state(u, checked == false); /* when released (not checked) => play gif */
}

static void custom_voice_btn_event_cb(lv_event_t * e)
{
	lv_ui *u = (lv_ui *)lv_event_get_user_data(e);
	lv_event_code_t code = lv_event_get_code(e);
	if(code == LV_EVENT_PRESSED) {
		custom_update_listening_state(u, true);
	} else if(code == LV_EVENT_RELEASED || code == LV_EVENT_PRESS_LOST) {
		custom_update_listening_state(u, false);
	}
}
