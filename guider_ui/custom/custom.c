/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "widgets_init.h"

void custom_set_background(lv_ui *ui, const lv_img_dsc_t *img)
{
    if(img == NULL || ui == NULL || ui->screen == NULL) return;

    lv_obj_set_style_bg_img_src(ui->screen, img, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->screen, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_tiled(ui->screen, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->screen, LV_OPA_TRANSP, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void custom_apply_mode(lv_ui *ui, int mode)
{
    /* mode: 0 none, 1 setting(menu_bar), 2 music(music_play), 3 sound_ai(cont_1) */
    bool show_menu = mode == 1;
    bool show_music = mode == 2;
    bool show_sound = mode == 3;

    if(ui->screen_menu_bar) {
        if(show_menu) lv_obj_clear_flag(ui->screen_menu_bar, LV_OBJ_FLAG_HIDDEN);
        else lv_obj_add_flag(ui->screen_menu_bar, LV_OBJ_FLAG_HIDDEN);
    }
    if(ui->screen_music_play) {
        if(show_music) lv_obj_clear_flag(ui->screen_music_play, LV_OBJ_FLAG_HIDDEN);
        else lv_obj_add_flag(ui->screen_music_play, LV_OBJ_FLAG_HIDDEN);
    }
    if(ui->screen_cont_1) {
        if(show_sound) lv_obj_clear_flag(ui->screen_cont_1, LV_OBJ_FLAG_HIDDEN);
        else lv_obj_add_flag(ui->screen_cont_1, LV_OBJ_FLAG_HIDDEN);
    }

    if(ui->screen_setting) {
        if(show_menu) lv_obj_add_state(ui->screen_setting, LV_STATE_CHECKED);
        else lv_obj_clear_state(ui->screen_setting, LV_STATE_CHECKED);
    }
    if(ui->screen_music) {
        if(show_music) lv_obj_add_state(ui->screen_music, LV_STATE_CHECKED);
        else lv_obj_clear_state(ui->screen_music, LV_STATE_CHECKED);
    }
    if(ui->screen_sounds_ai) {
        if(show_sound) lv_obj_add_state(ui->screen_sounds_ai, LV_STATE_CHECKED);
        else lv_obj_clear_state(ui->screen_sounds_ai, LV_STATE_CHECKED);
    }
}

void custom_toggle_music(lv_ui *ui)
{
    if(ui == NULL) return;
    bool is_checked = ui->screen_music && lv_obj_has_state(ui->screen_music, LV_STATE_CHECKED);
    custom_apply_mode(ui, is_checked ? 0 : 2);
}

void custom_toggle_setting(lv_ui *ui)
{
    if(ui == NULL) return;
    bool is_checked = ui->screen_setting && lv_obj_has_state(ui->screen_setting, LV_STATE_CHECKED);
    custom_apply_mode(ui, is_checked ? 0 : 1);
}

void custom_toggle_sound_ai(lv_ui *ui)
{
    if(ui == NULL) return;
    bool is_checked = ui->screen_sounds_ai && lv_obj_has_state(ui->screen_sounds_ai, LV_STATE_CHECKED);
    custom_apply_mode(ui, is_checked ? 0 : 3);
}

void custom_update_play_state(lv_ui *ui, bool playing)
{
    if(ui == NULL || ui->screen_gif == NULL) return;
    if(playing) {
        lv_animimg_start(ui->screen_gif);
    } else {
        lv_anim_del(ui->screen_gif, NULL);
        if(screen_gif_imgs[0]) lv_img_set_src(ui->screen_gif, screen_gif_imgs[0]);
    }
}

void custom_update_listening_state(lv_ui *ui, bool listening)
{
    if(ui == NULL || ui->screen_listening_gif == NULL) return;
    if(listening) {
        lv_animimg_start(ui->screen_listening_gif);
        if(ui->screen_listening_txt) lv_obj_clear_flag(ui->screen_listening_txt, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_anim_del(ui->screen_listening_gif, NULL);
        if(screen_listening_gif_imgs[0]) lv_img_set_src(ui->screen_listening_gif, screen_listening_gif_imgs[0]);
        if(ui->screen_listening_txt) lv_obj_add_flag(ui->screen_listening_txt, LV_OBJ_FLAG_HIDDEN);
    }
}

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    if(ui == NULL) return;
    /* Start with all panels hidden and buttons unchecked. */
    custom_apply_mode(ui, 0);
}

