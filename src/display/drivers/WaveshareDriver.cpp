#include "WaveshareDriver.h"
#include <display/drivers/common/LV_Helper.h>

WaveshareDriver *WaveshareDriver::instance = nullptr;

void WaveshareDriver::init() {
    printf("WaveshareDriver initializing\n");
    if (!panel.begin()) {
        for (uint8_t i = 0; i < 20; i++) {
            Serial.println("Error, failed to initialize Waveshare ESP32-S3 Touch LCD");
            delay(1000);
        }
        ESP.restart();
    }
    beginLvglHelper(panel);
    panel.setBrightness(16);
}
