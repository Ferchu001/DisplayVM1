// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_VM_Ver2.0

#include "../ui.h"

void ui_Screen15_screen_init(void)
{
    ui_Screen15 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen15, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel16 = lv_obj_create(ui_Screen15);
    lv_obj_set_width(ui_Panel16, 222);
    lv_obj_set_height(ui_Panel16, 71);
    lv_obj_set_x(ui_Panel16, -4);
    lv_obj_set_y(ui_Panel16, -108);
    lv_obj_set_align(ui_Panel16, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel16, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel16, lv_color_hex(0x416BFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Panel16, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Panel16, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel16, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel16, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel16, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Panel16, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Panel16, 4, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label20 = lv_label_create(ui_Panel16);
    lv_obj_set_width(ui_Label20, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label20, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label20, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label20, "     Gracias\nPor su compra!");
    lv_obj_set_style_text_font(ui_Label20, &ui_font_Exo32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image17 = lv_img_create(ui_Screen15);
    lv_img_set_src(ui_Image17, &ui_img_f600_png);
    lv_obj_set_width(ui_Image17, LV_SIZE_CONTENT);   /// 72
    lv_obj_set_height(ui_Image17, LV_SIZE_CONTENT);    /// 72
    lv_obj_set_x(ui_Image17, 3);
    lv_obj_set_y(ui_Image17, 35);
    lv_obj_set_align(ui_Image17, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image17, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image17, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}
