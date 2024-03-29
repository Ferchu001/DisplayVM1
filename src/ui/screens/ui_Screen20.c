// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_VM_Ver2.0

#include "../ui.h"

void ui_Screen20_screen_init(void)
{
    ui_Screen20 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen20, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel21 = lv_obj_create(ui_Screen20);
    lv_obj_set_width(ui_Panel21, 222);
    lv_obj_set_height(ui_Panel21, 71);
    lv_obj_set_x(ui_Panel21, -4);
    lv_obj_set_y(ui_Panel21, -108);
    lv_obj_set_align(ui_Panel21, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel21, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel21, lv_color_hex(0x416BFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel21, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Panel21, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Panel21, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel21, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel21, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel21, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel21, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Panel21, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Panel21, 4, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label25 = lv_label_create(ui_Panel21);
    lv_obj_set_width(ui_Label25, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label25, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label25, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label25, "     Gracias\nPor su compra!");
    lv_obj_set_style_text_font(ui_Label25, &ui_font_Exo32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image22 = lv_img_create(ui_Screen20);
    lv_img_set_src(ui_Image22, &ui_img_f600_png);
    lv_obj_set_width(ui_Image22, LV_SIZE_CONTENT);   /// 72
    lv_obj_set_height(ui_Image22, LV_SIZE_CONTENT);    /// 72
    lv_obj_set_x(ui_Image22, 3);
    lv_obj_set_y(ui_Image22, 35);
    lv_obj_set_align(ui_Image22, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image22, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image22, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}
