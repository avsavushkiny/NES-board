/*
 *  start screen page
 */

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "sys_gfx_st7565.h"
#include "sys_map_xbmp.h"
#include "sys_map_sound.h"
#include "sys_list.h"

void logoNes();

void drawPgsNes()
{
  gfx.renderPage(logoNes, 1500);
}

void logoNes()
{
  u8g2.drawXBMP(37, 23, nes_logo_w, nes_logo_h, nes_logo);
}
