/*
 *  game MENU page
 */
 
#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system_gfx_st7565.h"
#include "system_list.h"
#include "game_map_xbmp.h"

void drawPgs1();

int8_t item{};

void renderPgs1()
{
  uint32_t time;
  time = millis() + 10;

  do {
    u8g2.clearBuffer();
    drawPgs1();
    u8g2.sendBuffer();
  } while ( millis() < time );
}

void drawPgs1()
{
  if (sys.obj0y() > 0)
  {
    item++;
    delay(250);
  }
  else if (sys.obj0y() < 0)
  {
    item--;
    delay(250);
  }
  else item = item;

  if (item >= OBJ_MAX_SIZE)
  {
    item = 0;
  }

  if (item < 0)
  {
    item = OBJ_MAX_SIZE - 1;
  }
  
  messageDiaFrameBottom(obj[item].title, obj[item].info, "play");
  messageTwo(105, 12, (String) + (item + 1), (String)"/" + OBJ_MAX_SIZE);
  drawCursor(false);

  u8g2.drawXBMP(0, 10, 90, 24, obj[item].icon);
}
