/*
 *  clock page
 */

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system_gfx_st7565.h"

void drawPgs2();

void renderPgs2()
{
  uint32_t time;
  time = millis() + 10;

  do {
    u8g2.clearBuffer();
    drawPgs2();
    u8g2.sendBuffer();
  } while ( millis() < time );
}

void drawPgs2()
{
  messageTwo(5, 42, "clock page", "");
}
