/*
 *  start screen
 */

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system_gfx_st7565.h"
#include "system_map_xbmp.h"
#include "system_map_sound.h"

void logoNes();

void drawPgsNes()
{
  gfx.renderPage(logoNes, 2000);
}

void logoNes()
{
  u8g2.drawXBMP(37, 23, nes_logo_w, nes_logo_h, nes_logo);
}
