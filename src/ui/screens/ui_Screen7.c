// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_VM_Ver2.0

#include "../ui.h"

void ui_Screen7_screen_init(void)
{
    ui_Screen7 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel8 = lv_obj_create(ui_Screen7);
    lv_obj_set_width(ui_Panel8, 222);
    lv_obj_set_height(ui_Panel8, 71);
    lv_obj_set_x(ui_Panel8, -4);
    lv_obj_set_y(ui_Panel8, -108);
    lv_obj_set_align(ui_Panel8, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel8, lv_color_hex(0x416BFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Panel8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Panel8, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel8, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel8, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel8, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Panel8, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Panel8, 4, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label12 = lv_label_create(ui_Panel8);
    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label12, "     Gracias\nPor su compra!");
    lv_obj_set_style_text_font(ui_Label12, &ui_font_Exo32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image5 = lv_img_create(ui_Screen7);
    lv_img_set_src(ui_Image5, &ui_img_f600_png);
    lv_obj_set_width(ui_Image5, LV_SIZE_CONTENT);   /// 72
    lv_obj_set_height(ui_Image5, LV_SIZE_CONTENT);    /// 72
    lv_obj_set_x(ui_Image5, 3);
    lv_obj_set_y(ui_Image5, 35);
    lv_obj_set_align(ui_Image5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}
