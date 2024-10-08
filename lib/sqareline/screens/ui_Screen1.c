// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 9.1.0
// Project name: AC_V9

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_remove_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Arc1 = lv_arc_create(ui_Screen1);
lv_obj_set_width( ui_Arc1, 150);
lv_obj_set_height( ui_Arc1, 150);
lv_obj_set_align( ui_Arc1, LV_ALIGN_CENTER );
lv_arc_set_value(ui_Arc1, 50);
lv_obj_set_style_bg_image_src( ui_Arc1, &ui_img_flash_png, LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_image_recolor(ui_Arc1, lv_color_hex(0xFFFFFF), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_image_recolor_opa(ui_Arc1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0xFFBDA5), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_Arc1, 50, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_Arc1, 15, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_rounded(ui_Arc1, false, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_pad_left(ui_Arc1, 5, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Arc1, 0, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Arc1, 0, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Arc1, 0, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0xFFA883), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_Arc1, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_Arc1, 5, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_rounded(ui_Arc1, false, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Arc1, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_Label1 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label1, 0 );
lv_obj_set_y( ui_Label1, -126 );
lv_obj_set_align( ui_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label1,"Hello");
lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xCDFF57), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_letter_space(ui_Label1, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Label1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label1, &ui_font_Dameron, LV_PART_MAIN| LV_STATE_DEFAULT);

}
