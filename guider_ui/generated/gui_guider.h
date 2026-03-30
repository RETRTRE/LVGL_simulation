/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_back_ground;
	lv_obj_t *screen_menu_bar;
	lv_obj_t *screen_menu_bar_sidebar_page;
	lv_obj_t *screen_menu_bar_subpage_1;
	lv_obj_t *screen_menu_bar_cont_1;
	lv_obj_t *screen_menu_bar_label_1;
	lv_obj_t *screen_menu_bar_subpage_2;
	lv_obj_t *screen_menu_bar_cont_2;
	lv_obj_t *screen_menu_bar_label_2;
	lv_obj_t *screen_menu_bar_subpage_3;
	lv_obj_t *screen_menu_bar_cont_3;
	lv_obj_t *screen_menu_bar_label_3;
	lv_obj_t *screen_setting;
	lv_obj_t *screen_setting_label;
	lv_obj_t *screen_music;
	lv_obj_t *screen_music_label;
	lv_obj_t *screen_sounds_ai;
	lv_obj_t *screen_sounds_ai_label;
	lv_obj_t *screen_music_play;
	lv_obj_t *screen_last;
	lv_obj_t *screen_last_label;
	lv_obj_t *screen_play;
	lv_obj_t *screen_play_label;
	lv_obj_t *screen_next;
	lv_obj_t *screen_next_label;
	lv_obj_t *screen_music_name;
	lv_span_t *screen_music_name_span;
	lv_obj_t *screen_bar_1;
	lv_obj_t *screen_gif;
	lv_obj_t *screen_cont_1;
	lv_obj_t *screen_listening_gif;
	lv_obj_t *screen_listening_txt;
	lv_span_t *screen_listening_txt_span;
	lv_obj_t *screen_voice_in_ctr;
	lv_obj_t *screen_voice_in_ctr_label;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen(lv_ui *ui);
LV_IMG_DECLARE(_setting_easy_alpha_28x28);
LV_IMG_DECLARE(_setting_selected_alpha_28x28);
LV_IMG_DECLARE(_music_easy_alpha_28x28);
LV_IMG_DECLARE(_music_selected_alpha_28x28);
LV_IMG_DECLARE(_sound_easy_alpha_28x28);
LV_IMG_DECLARE(_sound_selected_alpha_28x28);
LV_IMG_DECLARE(_last_alpha_20x20);
LV_IMG_DECLARE(_pause_alpha_20x20);
LV_IMG_DECLARE(_play_alpha_20x20);
LV_IMG_DECLARE(_next_alpha_20x20);
#include "extra/widgets/animimg/lv_animimg.h"
LV_IMG_DECLARE(screen_gifplaying_00);
LV_IMG_DECLARE(screen_gifplaying_01);
LV_IMG_DECLARE(screen_gifplaying_02);
LV_IMG_DECLARE(screen_gifplaying_03);
LV_IMG_DECLARE(screen_gifplaying_04);
LV_IMG_DECLARE(screen_gifplaying_05);
LV_IMG_DECLARE(screen_gifplaying_06);
LV_IMG_DECLARE(screen_gifplaying_07);
LV_IMG_DECLARE(screen_gifplaying_08);
LV_IMG_DECLARE(screen_gifplaying_09);
LV_IMG_DECLARE(screen_gifplaying_10);
LV_IMG_DECLARE(screen_gifplaying_11);
LV_IMG_DECLARE(screen_gifplaying_12);
LV_IMG_DECLARE(screen_gifplaying_13);
LV_IMG_DECLARE(screen_gifplaying_14);
LV_IMG_DECLARE(screen_gifplaying_15);
LV_IMG_DECLARE(screen_gifplaying_16);
LV_IMG_DECLARE(screen_gifplaying_17);
LV_IMG_DECLARE(screen_gifplaying_18);
LV_IMG_DECLARE(screen_gifplaying_19);
LV_IMG_DECLARE(screen_gifplaying_20);
LV_IMG_DECLARE(screen_gifplaying_21);
LV_IMG_DECLARE(screen_gifplaying_22);
LV_IMG_DECLARE(screen_gifplaying_23);
LV_IMG_DECLARE(screen_gifplaying_24);
LV_IMG_DECLARE(screen_gifplaying_25);
LV_IMG_DECLARE(screen_gifplaying_26);
LV_IMG_DECLARE(screen_gifplaying_27);
LV_IMG_DECLARE(screen_gifplaying_28);
LV_IMG_DECLARE(screen_gifplaying_29);
LV_IMG_DECLARE(screen_gifplaying_30);
LV_IMG_DECLARE(screen_gifplaying_31);
LV_IMG_DECLARE(screen_gifplaying_32);
LV_IMG_DECLARE(screen_gifplaying_33);
LV_IMG_DECLARE(screen_gifplaying_34);
LV_IMG_DECLARE(screen_gifplaying_35);
LV_IMG_DECLARE(screen_gifplaying_36);
LV_IMG_DECLARE(screen_gifplaying_37);
LV_IMG_DECLARE(screen_gifplaying_38);
LV_IMG_DECLARE(screen_gifplaying_39);
LV_IMG_DECLARE(screen_gifplaying_40);
LV_IMG_DECLARE(screen_gifplaying_41);
#include "extra/widgets/animimg/lv_animimg.h"
LV_IMG_DECLARE(screen_listening_giflistening_00);
LV_IMG_DECLARE(screen_listening_giflistening_01);
LV_IMG_DECLARE(screen_listening_giflistening_02);
LV_IMG_DECLARE(screen_listening_giflistening_03);
LV_IMG_DECLARE(screen_listening_giflistening_04);
LV_IMG_DECLARE(screen_listening_giflistening_05);
LV_IMG_DECLARE(screen_listening_giflistening_06);
LV_IMG_DECLARE(screen_listening_giflistening_07);
LV_IMG_DECLARE(screen_listening_giflistening_08);
LV_IMG_DECLARE(screen_listening_giflistening_09);
LV_IMG_DECLARE(screen_listening_giflistening_10);
LV_IMG_DECLARE(screen_listening_giflistening_11);
LV_IMG_DECLARE(screen_listening_giflistening_12);
LV_IMG_DECLARE(screen_listening_giflistening_13);
LV_IMG_DECLARE(screen_listening_giflistening_14);
LV_IMG_DECLARE(screen_listening_giflistening_15);
LV_IMG_DECLARE(screen_listening_giflistening_16);
LV_IMG_DECLARE(screen_listening_giflistening_17);
LV_IMG_DECLARE(screen_listening_giflistening_18);
LV_IMG_DECLARE(screen_listening_giflistening_19);
LV_IMG_DECLARE(screen_listening_giflistening_20);
LV_IMG_DECLARE(screen_listening_giflistening_21);
LV_IMG_DECLARE(screen_listening_giflistening_22);
LV_IMG_DECLARE(screen_listening_giflistening_23);
LV_IMG_DECLARE(screen_listening_giflistening_24);
LV_IMG_DECLARE(screen_listening_giflistening_25);
LV_IMG_DECLARE(screen_listening_giflistening_26);
LV_IMG_DECLARE(screen_listening_giflistening_27);
LV_IMG_DECLARE(screen_listening_giflistening_28);
LV_IMG_DECLARE(screen_listening_giflistening_29);

LV_FONT_DECLARE(lv_font_Abel_regular_12)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_Amiko_Regular_12)
LV_FONT_DECLARE(lv_font_Abel_regular_15)


#ifdef __cplusplus
}
#endif
#endif
