// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"


// COMPONENT Label5

lv_obj_t * ui_Label5_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Label5;
    cui_Label5 = lv_label_create(comp_parent);
    lv_obj_set_width(cui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Label5, -47);
    lv_obj_set_y(cui_Label5, -101);
    lv_obj_set_align(cui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(cui_Label5, "Usted ha seleccionado");

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_LABEL5_NUM);
    children[UI_COMP_LABEL5_LABEL5] = cui_Label5;
    lv_obj_add_event_cb(cui_Label5, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Label5, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_Label5_create_hook(cui_Label5);
    return cui_Label5;
}

