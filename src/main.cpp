#include <Arduino.h>
#include <ZX2D10GE01R.h>
#include <LovyanGFX.h>
#include <lvgl.h>
#include <ui.h>

static LGFX lcd;
#define screenWidth 480
#define screenHeight 480
// static lv_disp_t *disp;
// static uint8_t *buf;
// static lv_obj_t *label;
#define DRAW_BUF_SIZE (screenHeight * screenWidth)

void disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
  uint32_t w = lv_area_get_width(area);
  uint32_t h = lv_area_get_height(area);

  lcd.startWrite();
  lcd.setAddrWindow(area->x1, area->y1, w, h);

  lcd.writePixels((lgfx::rgb565_t *)px_map, w * h);
  lcd.endWrite();
  /*Call it to tell LVGL you are ready*/
  lv_disp_flush_ready(disp);
}

void setup()
{
  Serial.begin(115200);
  lcd.init();
  lcd.setBrightness(150);
  lcd.setColorDepth(16);
  lcd.fillScreen(TFT_GREEN);

  lv_init();

  static uint8_t *buf1 = (uint8_t *)heap_caps_malloc(DRAW_BUF_SIZE, MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL);
  static lv_disp_t *disp = lv_display_create(screenWidth, screenHeight);
  lv_display_set_flush_cb(disp, disp_flush);
  lv_display_set_buffers(disp, buf1, NULL, DRAW_BUF_SIZE, LV_DISPLAY_RENDER_MODE_PARTIAL);

  ui_init();
}
unsigned long lastTickMillis = 0;
void loop()
{
  unsigned int tickPeriod = millis() - lastTickMillis;
  lv_tick_inc(tickPeriod);
  lastTickMillis = millis();
  // put your main code here, to run repeatedly:
  lv_task_handler();
  delay(5);
}
