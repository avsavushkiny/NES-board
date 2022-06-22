/*
 *  game MENU page
 */
 
#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system_gfx_st7565.h"
#include "system_list.h"
#include "sys_image48.h"
#include "game_map_xbmp.h"

void drawPgs2();

int8_t item{};

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

  for (int a = 0; a < 128; a++)
  {
  u8g2.drawXBMP(a, 53, wall_w, wall_h, wall_bits);
  }
  
  
  messagePgs2(obj[item].title1, obj[item].title2, "play");
  //messageTwo(58, 20, (String) + (item + 1), (String)"/" + OBJ_MAX_SIZE); //105
  //drawCursor(false);
  u8g2.drawXBMP(5, 8, 48, 48, obj[item].icon);
}
