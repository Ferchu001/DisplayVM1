#include <Arduino.h>
#include <ArduinoJson.h>
#include <esp32_smartdisplay.h>
#include <ui/ui.h>
#include <Audio.h>
// #include "lv_examples.h"

#define WIFI_SSID "InsotechPB"
#define WIFI_PASSWORD "Hola1234"

Audio *audio;
void check_rx_commands(void);
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
    lv_obj_t *qr = lv_qrcode_create(ui_Screen1, 150, fg_color, bg_color);
    // lv_qrcode_set_size(qr, 150);
    // lv_qrcode_set_dark_color(qr, fg_color);
    // lv_qrcode_set_light_color(qr, bg_color);

    /*Set data*/
    const char *data = "https://lvgl.io";
    lv_qrcode_update(qr, data, strlen(data));
    lv_obj_center(qr);

    /*Add a border with bg_color*/
    lv_obj_set_style_border_color(qr, bg_color, 0);
    lv_obj_set_style_border_width(qr, 5, 0);
}

void setup()
{

    Serial.begin(115200);
    Serial.setDebugOutput(false);

    smartdisplay_init();
    smartdisplay_lcd_set_backlight(1.0f);

    lv_disp_get_default();

    ui_init();
    lv_example_qrcode_1();

    Serial2.begin(115200, SERIAL_8N1, GPIO_NUM_22, GPIO_NUM_27);
}

ulong next_millis;
struct Dis
{
    int Actual = 0;
    bool Change = false;
} Display;

struct Compra
{
    String Producto;
    String Precio;
    String Cliente;
    String Descripcion;
    String NroOperacion;
} DatosCompra;

void Led(void)
{
    auto const now = millis();
    if (now > next_millis)
    {
        next_millis = now + 500;

#ifdef BOARD_HAS_RGB_LED
        auto const rgb = (now / 2000) % 8;
        smartdisplay_led_set_rgb(rgb & 0x01, rgb & 0x02, rgb & 0x04);
#endif
    }
}
void loop()
{
    Led();
    check_rx_commands();
    if (Display.Change == true)
    {

        //
        // lv_label_set_text_fmt(ui_Precio, "$ %d", Sec++);

        switch (Display.Actual)
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
            break;
        }
        Display.Change = false;
        Serial.println("Cambio a Display: " + String(Display.Actual));
    }
    lv_timer_handler();
}

/***************************Comandos*********************/
/*
1) PANTALLA: XX
2) PRODUCTO:XX
3) PRECIO:XX
4) USUARIO:XX
5) LED:XX
6) SONIDO:XX
7) WIFI: XX
8) PASS:XX
9) NRO_MAQUINA:XX
10) QR:XX


* RESET:XX
* UPGRADE:XX

*/
void check_rx_commands(void)
{
    if (Serial2.available())
    {
        String jsonCommand = Serial.readStringUntil('\n'); // Lee el comando JSON hasta encontrar una nueva línea
        StaticJsonDocument<1024> doc;
        DeserializationError error = deserializeJson(doc, jsonCommand);

        if (error)
        {
            Serial.println("Error al analizar el comando JSON");
        }
        else
        {
            String sPantalla = doc["PANTALLA"];
            String sProducto = doc["PRODUCTO"];
            String sPrecio = doc["PRECIO"];
            String sCliente = doc["CLIENTE"];
            String sDescripcion = doc["DESCRPCION"];
            String sOperacion = doc["NRO_OPERACION"];
            String sLed = doc["LED"];
            String sSonido = doc["SONIDO"];
            String sWifi = doc["WIFI"];
            String sPass = doc["PASS"];
            String sNro_maquina = doc["NRO_MAQUINA"];
            String sQR = doc["QR"];
            String sStatus = doc["STATUS"];
            String sVer_Master = doc["VER_MASTER"];
            String sReset = doc["RESET"];
            String sUpgrade = doc["UPGRADE"];

            if (doc.containsKey("PANTALLA"))
            {
                if (Display.Actual != sPantalla.toInt())
                {
                    Display.Actual = sPantalla.toInt();
                    Display.Change = true;
                }
            }
            if (doc.containsKey("PRODUCTO"))
            {
                if (sProducto != "NULL")
                {
                    DatosCompra.Producto = sProducto;
                    lv_label_set_text_fmt(ui_Producto, DatosCompra.Producto.c_str());
                }
            }
            if (doc.containsKey("PRECIO"))
            {
                if (sPrecio != "NULL")
                {
                    DatosCompra.Precio = sPrecio;
                    lv_label_set_text_fmt(ui_Precio, DatosCompra.Precio.c_str());
                }
            }
            if (doc.containsKey("CLIENTE"))
            {
                if (sCliente != "NULL")
                {
                    DatosCompra.Cliente = sCliente;
                    // lv_label_set_text_fmt(ui_Cliente, DatosCompra.Cliente.c_str());
                }
            }
            if (doc.containsKey("DESCRIPCION"))
            {
                if (sDescripcion != "NULL")
                {
                    DatosCompra.Descripcion = sDescripcion;
                    // lv_label_set_text_fmt(ui_Descripcion, DatosCompra.Descripcion.c_str());
                }
            }
            if (doc.containsKey("NRO_OPERACION"))
            {
                if (sOperacion != "NULL")
                {
                    DatosCompra.NroOperacion = sOperacion;
                    // lv_label_set_text_fmt(ui_Operacion, DatosCompra.Operacion.c_str());
                }
            }
        }
    }
}

void tx_commands()
{
    /*
    STATUS
    VERSION_DISPLAY
    SERIAL_NUMBER

    */
}