/*
    game START page
*/

#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "sys_gfx_st7565.h"
#include "sys_list.h"

void drawPgs0();

int8_t iitem{};

void renderPgs0()
{
  uint32_t time;
  time = millis() + 10;

  do {
    u8g2.clearBuffer();
    drawPgs0();
    u8g2.sendBuffer();
  } while ( millis() < time );
}

void drawPgs0()
{
  if (sys.obj0y() > 0)
  {
    iitem++;
    delay(250);
  }
  else if (sys.obj0y() < 0)
  {
    iitem--;
    delay(250);
  }
  else iitem = iitem;

  if (iitem >= OBJCM_MAX_SIZE)
  {
    iitem = 0;
  }

  if (iitem < 0)
  {
    iitem = OBJCM_MAX_SIZE - 1;
  }

  gfx.renderCatMessage(catMessage,
                       objCatMessage[iitem].text1,
                       objCatMessage[iitem].text2,
                       objCatMessage[iitem].text3,
                       objCatMessage[iitem].text4);
                       
  //messageTwo(105, 12, (String) + (iitem + 1), (String)"/" + OBJ_MAX_SIZE);
  drawCursor(false);
}
