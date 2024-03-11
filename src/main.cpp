#include <Arduino.h>

#include <esp32_smartdisplay.h>
#include <ui/ui.h>
#include <Audio.h>
//#include "lv_examples.h"

#define WIFI_SSID "InsotechPB"
#define WIFI_PASSWORD "Hola1234"

Audio *audio;

/**
 * Create a QR Code
 */
void lv_example_qrcode_1(void)
{
    lv_color_t bg_color = lv_palette_lighten(LV_PALETTE_LIGHT_BLUE, 5);
    lv_color_t fg_color = lv_palette_darken(LV_PALETTE_BLUE, 4);

    // lv_obj_t * qr = lv_qrcode_create(lv_screen_active());
    // lv_qrcode_set_size(qr, 150);
    // lv_qrcode_set_dark_color(qr, fg_color);
    // lv_qrcode_set_light_color(qr, bg_color);
    lv_obj_t * qr = lv_qrcode_create(ui_Screen1,150,fg_color,bg_color);
    // lv_qrcode_set_size(qr, 150);
    // lv_qrcode_set_dark_color(qr, fg_color);
    // lv_qrcode_set_light_color(qr, bg_color);

    /*Set data*/
    const char * data = "https://lvgl.io";
    lv_qrcode_update(qr, data, strlen(data));
    lv_obj_center(qr);

    /*Add a border with bg_color*/
    lv_obj_set_style_border_color(qr, bg_color, 0);
    lv_obj_set_style_border_width(qr, 5, 0);
}




void setup()
{

    Serial.begin(115200);
    Serial.setDebugOutput(true);

    smartdisplay_init();

    lv_disp_get_default();

    ui_init();
    lv_example_qrcode_1();
}

ulong next_millis;

ulong Mtimer=0;
int Sec=0;
void loop()
{
if(millis()>Mtimer+10000)
    {
        Mtimer=millis();
        lv_label_set_text_fmt(ui_Producto, "Coca Cola");
        lv_label_set_text_fmt(ui_Precio, "$ %d", Sec++);
        switch(Sec)
        {
        case 0:
            _ui_screen_change(&ui_Pantalla, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Pantalla_screen_init);
            break;
        case 1:
            _ui_screen_change(&ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen2_screen_init);
            break;
        case 2:
            _ui_screen_change(&ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen3_screen_init);
            break;
        case 3:
            _ui_screen_change(&ui_Screen4, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen4_screen_init);
            break;
        case 4:
            _ui_screen_change(&ui_Screen5, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen5_screen_init);            
            break;
        case 5:
            _ui_screen_change(&ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Screen1_screen_init);            
            break;
        default:
            _ui_screen_change(&ui_Pantalla, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_Pantalla_screen_init);
            
            Sec=0;
            break;        
        }
    }
    lv_timer_handler();
}