/*
    game MENU page
*/

#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system_gfx_st7565.h"
#include "system_list.h"
#include "sys_image48.h"
#include "game_map_xbmp.h"

void drawPgs3();
void randomPcCat();

int8_t item{};

int8_t randX[20];
int8_t randY[20];

void renderPgs3()
{
  uint32_t time;
  time = millis() + 10;

  do {
    u8g2.clearBuffer();
    drawPgs3();
    u8g2.sendBuffer();
  } while ( millis() < time );
}

void drawPgs3()
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
  /*
  for (int a = 0; a < 128; a += 8)
  {
    for (int b = 0; b < 56; b += 8)
    {
      u8g2.drawPixel(a, b);
    }
  }
  */
  for (int a = 0; a < 128; a += 8)
  {
    u8g2.drawXBMP(a, 53, wall2_w, wall2_h, wall2_bits);    //8x11
  }
  
  u8g2.drawHLine(0, 0, 128);   //top

  u8g2.setBitmapMode(1);
  u8g2.drawRFrame(5, 7, 50, 50, 1);
  u8g2.drawRBox(6, 8, 50, 50, 1);

  u8g2.setBitmapMode(0);
  u8g2.drawXBMP(59, 3, messageMenu_w, messageMenu_h, messageMenu_bits);    //64x39
  u8g2.drawXBMP(62, 39, nes_cat_w, nes_cat_h, nes_cat);     //16x14
  u8g2.drawXBMP(94, 40, pcCat_w, pcCat_h, pcCat_bits);

  randomPcCat();

  messagePgs2(obj[item].title1, obj[item].title2, "");

  messageTwo(63, 12, (String) + (item + 1), (String)"/" + OBJ_MAX_SIZE); //105

  //drawCursor(false);
  u8g2.drawXBMP(6, 8, 48, 48, obj[item].icon);
}

void randomPcCat()
{
  for (int a = 0; a < 20; a++)
  {
    randX[a] = random(98, 106);
    randY[a] = random(42, 46);
  }

  for (int a = 0; a < 20; a++)
  {
    u8g2.drawPixel(randX[a], randY[a]);
  }
}
