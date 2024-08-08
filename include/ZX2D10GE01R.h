
#define LGFX_USE_V1
#include <LovyanGFX.hpp>

#include <lgfx/v1/platforms/esp32s3/Panel_RGB.hpp>
#include <lgfx/v1/platforms/esp32s3/Bus_RGB.hpp>
#include <driver/i2c.h>

class LGFX : public lgfx::LGFX_Device
{
public:
    lgfx::Bus_RGB _bus_instance;
    lgfx::Panel_ST7701S _panel_instance;
    lgfx::Light_PWM _light_instance;

    LGFX(void)
    {
        {
            auto cfg = _panel_instance.config();
            cfg.pin_rst = -1;
            cfg.memory_width = 480;
            cfg.memory_height = 480;
            cfg.panel_width = 480;
            cfg.panel_height = 480;

            cfg.offset_x = 0;
            cfg.offset_y = 0;
            _panel_instance.config(cfg);
        }

        {
            auto cfg = _panel_instance.config_detail();

            cfg.pin_cs = 21;
            cfg.pin_sclk = 47;
            cfg.pin_mosi = 41;

            _panel_instance.config_detail(cfg);
        }

        {
            auto cfg = _bus_instance.config();
            cfg.panel = &_panel_instance;
            cfg.pin_d0 = 47;  // B0
            cfg.pin_d1 = 41;  // B1
            cfg.pin_d2 = 0;   // B2
            cfg.pin_d3 = 42;  // B3
            cfg.pin_d4 = 14;  // B4
            cfg.pin_d5 = 8;   // G0
            cfg.pin_d6 = 13;  // G1
            cfg.pin_d7 = 18;  // G2
            cfg.pin_d8 = 12;  // G3
            cfg.pin_d9 = 11;  // G4
            cfg.pin_d10 = 17; // G5
            cfg.pin_d11 = 10; // R0
            cfg.pin_d12 = 16; // R1
            cfg.pin_d13 = 9;  // R2
            cfg.pin_d14 = 15; // R3
            cfg.pin_d15 = 46; // R4

            cfg.pin_henable = 39;
            cfg.pin_vsync = 48;
            cfg.pin_hsync = 40;
            cfg.pin_pclk = 45;
            cfg.freq_write = 15000000;

            cfg.hsync_polarity = 1;
            cfg.hsync_front_porch = 10;
            cfg.hsync_pulse_width = 10;
            cfg.hsync_back_porch = 10;
            cfg.vsync_polarity = 1;
            cfg.vsync_front_porch = 14;
            cfg.vsync_pulse_width = 2;
            cfg.vsync_back_porch = 12;
            cfg.pclk_idle_high = 0;
            cfg.de_idle_high = 0;
            _bus_instance.config(cfg);
        }
        _panel_instance.setBus(&_bus_instance);

        {
            auto cfg = _light_instance.config();
            cfg.pin_bl = GPIO_NUM_38;
            _light_instance.config(cfg);
        }
        _panel_instance.light(&_light_instance);

        setPanel(&_panel_instance);
    }
};