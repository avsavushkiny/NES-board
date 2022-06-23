/*
 *  game MENU page
 */
/* 
#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system_gfx_st7565.h"
#include "system_list.h"
#include "sys_image48.h"

void drawPgsM();

int8_t item{};

void renderPgsM()
{
  uint32_t time;
  time = millis() + 10;

  do {
    u8g2.clearBuffer();
    drawPgsM();
    u8g2.sendBuffer();
  } while ( millis() < time );
}

void drawPgsM()
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

  messagePgsM(obj[item].title1, obj[item].title2, obj[item].info, "");
  messageTwo(58, 20, (String) + (item + 1), (String)"/" + OBJ_MAX_SIZE); //105
  drawCursor(false);

  u8g2.drawXBMP(5, 8, 48, 48, obj[item].icon);
  u8g2.drawFrame(5, 8, 48, 48);
}*/
