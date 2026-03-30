/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_back_ground
    ui->screen_back_ground = lv_img_create(ui->screen);
    lv_obj_add_flag(ui->screen_back_ground, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_pivot(ui->screen_back_ground, 50,50);
    lv_img_set_angle(ui->screen_back_ground, 0);
    lv_obj_set_pos(ui->screen_back_ground, 0, 0);
    lv_obj_set_size(ui->screen_back_ground, 320, 240);

    //Write style for screen_back_ground, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_back_ground, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_back_ground, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_back_ground, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_back_ground, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_bar
    ui->screen_menu_bar = lv_menu_create(ui->screen);

    //Create sidebar page for menu screen_menu_bar
    ui->screen_menu_bar_sidebar_page = lv_menu_page_create(ui->screen_menu_bar, "Setting");
    lv_menu_set_sidebar_page(ui->screen_menu_bar, ui->screen_menu_bar_sidebar_page);
    lv_obj_set_scrollbar_mode(ui->screen_menu_bar_sidebar_page, LV_SCROLLBAR_MODE_OFF);

    //Create subpage for screen_menu_bar
    ui->screen_menu_bar_subpage_1 = lv_menu_page_create(ui->screen_menu_bar, NULL);
    ui->screen_menu_bar_cont_1 = lv_menu_cont_create(ui->screen_menu_bar_sidebar_page);
    ui->screen_menu_bar_label_1 = lv_label_create(ui->screen_menu_bar_cont_1);
    lv_label_set_text(ui->screen_menu_bar_label_1, "WiFi");
    lv_obj_set_size(ui->screen_menu_bar_label_1, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_scrollbar_mode(ui->screen_menu_bar_subpage_1, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->screen_menu_bar, ui->screen_menu_bar_cont_1, ui->screen_menu_bar_subpage_1);

    //Create subpage for screen_menu_bar
    ui->screen_menu_bar_subpage_2 = lv_menu_page_create(ui->screen_menu_bar, NULL);
    ui->screen_menu_bar_cont_2 = lv_menu_cont_create(ui->screen_menu_bar_sidebar_page);
    ui->screen_menu_bar_label_2 = lv_label_create(ui->screen_menu_bar_cont_2);
    lv_label_set_text(ui->screen_menu_bar_label_2, "Blue tooth");
    lv_obj_set_size(ui->screen_menu_bar_label_2, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_scrollbar_mode(ui->screen_menu_bar_subpage_2, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->screen_menu_bar, ui->screen_menu_bar_cont_2, ui->screen_menu_bar_subpage_2);

    //Create subpage for screen_menu_bar
    ui->screen_menu_bar_subpage_3 = lv_menu_page_create(ui->screen_menu_bar, NULL);
    ui->screen_menu_bar_cont_3 = lv_menu_cont_create(ui->screen_menu_bar_sidebar_page);
    ui->screen_menu_bar_label_3 = lv_label_create(ui->screen_menu_bar_cont_3);
    lv_label_set_text(ui->screen_menu_bar_label_3, "Background");
    lv_obj_set_size(ui->screen_menu_bar_label_3, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_scrollbar_mode(ui->screen_menu_bar_subpage_3, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->screen_menu_bar, ui->screen_menu_bar_cont_3, ui->screen_menu_bar_subpage_3);
    lv_event_send(ui->screen_menu_bar_cont_1, LV_EVENT_CLICKED, NULL);
    lv_obj_set_pos(ui->screen_menu_bar, 10, 10);
    lv_obj_set_size(ui->screen_menu_bar, 260, 220);
    lv_obj_set_scrollbar_mode(ui->screen_menu_bar, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_menu_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_menu_bar, 153, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_menu_bar, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_menu_bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_menu_bar_extra_sidebar_page_main_default
    static lv_style_t style_screen_menu_bar_extra_sidebar_page_main_default;
    ui_init_style(&style_screen_menu_bar_extra_sidebar_page_main_default);

    lv_style_set_bg_opa(&style_screen_menu_bar_extra_sidebar_page_main_default, 255);
    lv_style_set_bg_color(&style_screen_menu_bar_extra_sidebar_page_main_default, lv_color_hex(0xdaf2f8));
    lv_style_set_bg_grad_dir(&style_screen_menu_bar_extra_sidebar_page_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_radius(&style_screen_menu_bar_extra_sidebar_page_main_default, 0);
    lv_obj_add_style(ui->screen_menu_bar_sidebar_page, &style_screen_menu_bar_extra_sidebar_page_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_menu_bar_extra_option_btns_main_default
    static lv_style_t style_screen_menu_bar_extra_option_btns_main_default;
    ui_init_style(&style_screen_menu_bar_extra_option_btns_main_default);

    lv_style_set_text_color(&style_screen_menu_bar_extra_option_btns_main_default, lv_color_hex(0x151212));
    lv_style_set_text_font(&style_screen_menu_bar_extra_option_btns_main_default, &lv_font_Abel_regular_12);
    lv_style_set_text_opa(&style_screen_menu_bar_extra_option_btns_main_default, 255);
    lv_style_set_text_align(&style_screen_menu_bar_extra_option_btns_main_default, LV_TEXT_ALIGN_CENTER);
    lv_style_set_pad_top(&style_screen_menu_bar_extra_option_btns_main_default, 10);
    lv_style_set_pad_bottom(&style_screen_menu_bar_extra_option_btns_main_default, 10);
    lv_obj_add_style(ui->screen_menu_bar_cont_3, &style_screen_menu_bar_extra_option_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_menu_bar_cont_2, &style_screen_menu_bar_extra_option_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_menu_bar_cont_1, &style_screen_menu_bar_extra_option_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_menu_bar_extra_option_btns_main_checked
    static lv_style_t style_screen_menu_bar_extra_option_btns_main_checked;
    ui_init_style(&style_screen_menu_bar_extra_option_btns_main_checked);

    lv_style_set_text_color(&style_screen_menu_bar_extra_option_btns_main_checked, lv_color_hex(0x9ab700));
    lv_style_set_text_font(&style_screen_menu_bar_extra_option_btns_main_checked, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_menu_bar_extra_option_btns_main_checked, 255);
    lv_style_set_text_align(&style_screen_menu_bar_extra_option_btns_main_checked, LV_TEXT_ALIGN_CENTER);
    lv_style_set_border_width(&style_screen_menu_bar_extra_option_btns_main_checked, 0);
    lv_style_set_radius(&style_screen_menu_bar_extra_option_btns_main_checked, 0);
    lv_style_set_bg_opa(&style_screen_menu_bar_extra_option_btns_main_checked, 60);
    lv_style_set_bg_color(&style_screen_menu_bar_extra_option_btns_main_checked, lv_color_hex(0x00e0b8));
    lv_style_set_bg_grad_dir(&style_screen_menu_bar_extra_option_btns_main_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->screen_menu_bar_cont_3, &style_screen_menu_bar_extra_option_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_add_style(ui->screen_menu_bar_cont_2, &style_screen_menu_bar_extra_option_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_add_style(ui->screen_menu_bar_cont_1, &style_screen_menu_bar_extra_option_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_screen_menu_bar_extra_main_title_main_default
    static lv_style_t style_screen_menu_bar_extra_main_title_main_default;
    ui_init_style(&style_screen_menu_bar_extra_main_title_main_default);

    lv_style_set_text_color(&style_screen_menu_bar_extra_main_title_main_default, lv_color_hex(0x41485a));
    lv_style_set_text_font(&style_screen_menu_bar_extra_main_title_main_default, &lv_font_Amiko_Regular_12);
    lv_style_set_text_opa(&style_screen_menu_bar_extra_main_title_main_default, 255);
    lv_style_set_text_align(&style_screen_menu_bar_extra_main_title_main_default, LV_TEXT_ALIGN_CENTER);
    lv_style_set_bg_opa(&style_screen_menu_bar_extra_main_title_main_default, 255);
    lv_style_set_bg_color(&style_screen_menu_bar_extra_main_title_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_menu_bar_extra_main_title_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_pad_top(&style_screen_menu_bar_extra_main_title_main_default, 0);
    lv_style_set_pad_bottom(&style_screen_menu_bar_extra_main_title_main_default, 0);
    lv_menu_t * screen_menu_bar_menu= (lv_menu_t *)ui->screen_menu_bar;
    lv_obj_t * screen_menu_bar_title = screen_menu_bar_menu->sidebar_header_title;
    lv_obj_set_size(screen_menu_bar_title, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_add_style(lv_menu_get_sidebar_header(ui->screen_menu_bar), &style_screen_menu_bar_extra_main_title_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);







    //Write codes screen_setting
    ui->screen_setting = lv_imgbtn_create(ui->screen);
    lv_obj_add_flag(ui->screen_setting, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_setting, LV_IMGBTN_STATE_RELEASED, NULL, &_setting_easy_alpha_28x28, NULL);
    lv_imgbtn_set_src(ui->screen_setting, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_setting_selected_alpha_28x28, NULL);
    ui->screen_setting_label = lv_label_create(ui->screen_setting);
    lv_label_set_text(ui->screen_setting_label, "");
    lv_label_set_long_mode(ui->screen_setting_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_setting_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_setting, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_setting, 280, 10);
    lv_obj_set_size(ui->screen_setting, 28, 28);

    //Write style for screen_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_setting, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_setting, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_setting, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_setting, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_setting, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_setting, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_setting, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_setting, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_setting, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_setting, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_setting, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_setting, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_setting, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_setting, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_setting, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_setting, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_setting, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_setting, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_setting, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_setting, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_setting, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_music
    ui->screen_music = lv_imgbtn_create(ui->screen);
    lv_obj_add_flag(ui->screen_music, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_music, LV_IMGBTN_STATE_RELEASED, NULL, &_music_easy_alpha_28x28, NULL);
    lv_imgbtn_set_src(ui->screen_music, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_music_selected_alpha_28x28, NULL);
    ui->screen_music_label = lv_label_create(ui->screen_music);
    lv_label_set_text(ui->screen_music_label, "");
    lv_label_set_long_mode(ui->screen_music_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_music_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_music, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_music, 280, 65);
    lv_obj_set_size(ui->screen_music, 28, 28);

    //Write style for screen_music, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_music, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_music, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_music, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_music, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_music, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_music, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_music, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_music, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_music, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_music, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_music, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_music, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_music, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_music, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_music, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_music, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_music, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_music, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_music, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_music, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_music, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_music, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_music, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_music, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_sounds_ai
    ui->screen_sounds_ai = lv_imgbtn_create(ui->screen);
    lv_obj_add_flag(ui->screen_sounds_ai, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_sounds_ai, LV_IMGBTN_STATE_RELEASED, NULL, &_sound_easy_alpha_28x28, NULL);
    lv_imgbtn_set_src(ui->screen_sounds_ai, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_sound_selected_alpha_28x28, NULL);
    ui->screen_sounds_ai_label = lv_label_create(ui->screen_sounds_ai);
    lv_label_set_text(ui->screen_sounds_ai_label, "");
    lv_label_set_long_mode(ui->screen_sounds_ai_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_sounds_ai_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_sounds_ai, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_sounds_ai, 280, 120);
    lv_obj_set_size(ui->screen_sounds_ai, 28, 28);

    //Write style for screen_sounds_ai, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_sounds_ai, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_sounds_ai, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_sounds_ai, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_sounds_ai, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sounds_ai, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_sounds_ai, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_sounds_ai, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_sounds_ai, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_sounds_ai, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_sounds_ai, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_sounds_ai, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_sounds_ai, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_sounds_ai, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_sounds_ai, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_sounds_ai, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_sounds_ai, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_sounds_ai, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_sounds_ai, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_sounds_ai, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_sounds_ai, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_sounds_ai, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_sounds_ai, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_sounds_ai, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_sounds_ai, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_music_play
    ui->screen_music_play = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_music_play, 10, 10);
    lv_obj_set_size(ui->screen_music_play, 260, 220);
    lv_obj_set_scrollbar_mode(ui->screen_music_play, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_music_play, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_music_play, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_music_play, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_music_play, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_music_play, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_music_play, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_music_play, 254, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_music_play, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_music_play, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->screen_music_play, lv_color_hex(0xc18306), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->screen_music_play, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->screen_music_play, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_music_play, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_music_play, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_music_play, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_music_play, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_music_play, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_last
    ui->screen_last = lv_imgbtn_create(ui->screen_music_play);
    lv_obj_add_flag(ui->screen_last, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_last, LV_IMGBTN_STATE_RELEASED, NULL, &_last_alpha_20x20, NULL);
    ui->screen_last_label = lv_label_create(ui->screen_last);
    lv_label_set_text(ui->screen_last_label, "");
    lv_label_set_long_mode(ui->screen_last_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_last_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_last, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_last, 50, 180);
    lv_obj_set_size(ui->screen_last, 20, 20);

    //Write style for screen_last, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_last, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_last, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_last, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_last, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_last, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_last, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_last, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_last, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_last, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_last, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_last, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_last, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_last, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_last, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_last, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_last, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_last, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_last, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_last, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_last, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_last, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_last, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_last, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_last, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_play
    ui->screen_play = lv_imgbtn_create(ui->screen_music_play);
    lv_obj_add_flag(ui->screen_play, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_play, LV_IMGBTN_STATE_RELEASED, NULL, &_pause_alpha_20x20, NULL);
    lv_imgbtn_set_src(ui->screen_play, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_play_alpha_20x20, NULL);
    ui->screen_play_label = lv_label_create(ui->screen_play);
    lv_label_set_text(ui->screen_play_label, "");
    lv_label_set_long_mode(ui->screen_play_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_play_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_play, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_play, 115, 180);
    lv_obj_set_size(ui->screen_play, 20, 20);

    //Write style for screen_play, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_play, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_play, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_play, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_play, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_play, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_play, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_play, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_play, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_play, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_play, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_play, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_play, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_play, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_play, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_play, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_play, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_play, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_play, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_play, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_play, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_play, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_play, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_play, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_play, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_add_state(ui->screen_play, LV_STATE_CHECKED);

    //Write codes screen_next
    ui->screen_next = lv_imgbtn_create(ui->screen_music_play);
    lv_obj_add_flag(ui->screen_next, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_next, LV_IMGBTN_STATE_RELEASED, NULL, &_next_alpha_20x20, NULL);
    ui->screen_next_label = lv_label_create(ui->screen_next);
    lv_label_set_text(ui->screen_next_label, "");
    lv_label_set_long_mode(ui->screen_next_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_next_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_next, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_next, 180, 180);
    lv_obj_set_size(ui->screen_next, 20, 20);

    //Write style for screen_next, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_next, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_next, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_next, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_next, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_next, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_next, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_next, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_next, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_next, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_next, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_next, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_next, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_next, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_next, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_next, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_next, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_next, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_next, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_next, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_next, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_next, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_next, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_next, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_next, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_music_name
    ui->screen_music_name = lv_spangroup_create(ui->screen_music_play);
    lv_spangroup_set_align(ui->screen_music_name, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->screen_music_name, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->screen_music_name, LV_SPAN_MODE_BREAK);
    //create span
    ui->screen_music_name_span = lv_spangroup_new_span(ui->screen_music_name);
    lv_span_set_text(ui->screen_music_name_span, "hello");
    lv_style_set_text_color(&ui->screen_music_name_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&ui->screen_music_name_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->screen_music_name_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->screen_music_name, 56, 114);
    lv_obj_set_size(ui->screen_music_name, 130, 12);

    //Write style state: LV_STATE_DEFAULT for &style_screen_music_name_main_main_default
    static lv_style_t style_screen_music_name_main_main_default;
    ui_init_style(&style_screen_music_name_main_main_default);

    lv_style_set_border_width(&style_screen_music_name_main_main_default, 0);
    lv_style_set_radius(&style_screen_music_name_main_main_default, 0);
    lv_style_set_bg_opa(&style_screen_music_name_main_main_default, 0);
    lv_style_set_pad_top(&style_screen_music_name_main_main_default, 0);
    lv_style_set_pad_right(&style_screen_music_name_main_main_default, 0);
    lv_style_set_pad_bottom(&style_screen_music_name_main_main_default, 0);
    lv_style_set_pad_left(&style_screen_music_name_main_main_default, 0);
    lv_style_set_shadow_width(&style_screen_music_name_main_main_default, 0);
    lv_obj_add_style(ui->screen_music_name, &style_screen_music_name_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->screen_music_name);

    //Write codes screen_bar_1
    ui->screen_bar_1 = lv_bar_create(ui->screen_music_play);
    lv_obj_set_style_anim_time(ui->screen_bar_1, 1000, 0);
    lv_bar_set_mode(ui->screen_bar_1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_bar_1, 0, 100);
    lv_bar_set_value(ui->screen_bar_1, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_bar_1, 8, 160);
    lv_obj_set_size(ui->screen_bar_1, 240, 4);

    //Write style for screen_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_bar_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_bar_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_bar_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_bar_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_bar_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_bar_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_bar_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_bar_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_gif
    ui->screen_gif = lv_animimg_create(ui->screen_music_play);
    lv_animimg_set_src(ui->screen_gif, (const void **) screen_gif_imgs, 42);
    lv_animimg_set_duration(ui->screen_gif, 30*42);
    lv_animimg_set_repeat_count(ui->screen_gif, LV_ANIM_REPEAT_INFINITE);
    lv_img_set_src(ui->screen_gif, screen_gif_imgs[0]);
    lv_obj_set_pos(ui->screen_gif, 49, 9);
    lv_obj_set_size(ui->screen_gif, 154, 100);

    //Write codes screen_cont_1
    ui->screen_cont_1 = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_1, 10, 10);
    lv_obj_set_size(ui->screen_cont_1, 260, 220);
    lv_obj_set_scrollbar_mode(ui->screen_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_1, 153, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_listening_gif
    ui->screen_listening_gif = lv_animimg_create(ui->screen_cont_1);
    lv_animimg_set_src(ui->screen_listening_gif, (const void **) screen_listening_gif_imgs, 30);
    lv_animimg_set_duration(ui->screen_listening_gif, 30*30);
    lv_animimg_set_repeat_count(ui->screen_listening_gif, LV_ANIM_REPEAT_INFINITE);
    lv_img_set_src(ui->screen_listening_gif, screen_listening_gif_imgs[0]);
    lv_obj_set_pos(ui->screen_listening_gif, 48, 2);
    lv_obj_set_size(ui->screen_listening_gif, 160, 169);

    //Write codes screen_listening_txt
    ui->screen_listening_txt = lv_spangroup_create(ui->screen_cont_1);
    lv_spangroup_set_align(ui->screen_listening_txt, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->screen_listening_txt, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->screen_listening_txt, LV_SPAN_MODE_BREAK);
    lv_obj_add_flag(ui->screen_listening_txt, LV_OBJ_FLAG_HIDDEN);
    //create span
    ui->screen_listening_txt_span = lv_spangroup_new_span(ui->screen_listening_txt);
    lv_span_set_text(ui->screen_listening_txt_span, "Identifying~~~");
    lv_style_set_text_color(&ui->screen_listening_txt_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&ui->screen_listening_txt_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->screen_listening_txt_span->style, &lv_font_Abel_regular_12);
    lv_obj_set_pos(ui->screen_listening_txt, 87, 128);
    lv_obj_set_size(ui->screen_listening_txt, 79, 14);

    //Write codes screen_voice_in_ctr
    ui->screen_voice_in_ctr = lv_btn_create(ui->screen_cont_1);
    ui->screen_voice_in_ctr_label = lv_label_create(ui->screen_voice_in_ctr);
    lv_label_set_text(ui->screen_voice_in_ctr_label, "Press to talk");
    lv_label_set_long_mode(ui->screen_voice_in_ctr_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_voice_in_ctr_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_voice_in_ctr, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_voice_in_ctr_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_voice_in_ctr, 57, 163);
    lv_obj_set_size(ui->screen_voice_in_ctr, 141, 30);

    //Write style for screen_voice_in_ctr, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_voice_in_ctr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_voice_in_ctr, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_voice_in_ctr, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_voice_in_ctr, lv_color_hex(0x5482a9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_voice_in_ctr, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_voice_in_ctr, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_voice_in_ctr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_voice_in_ctr, lv_color_hex(0x12548b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_voice_in_ctr, &lv_font_Abel_regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_voice_in_ctr, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_voice_in_ctr, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

}
