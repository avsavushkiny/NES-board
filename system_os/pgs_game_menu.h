/*
    game MENU page
*/

#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "sys_gfx_st7565.h"
#include "sys_list.h"
#include "sys_image48.h"
#include "pgs_pck1_testFps.h"
#include "pgs_pck1_testAdc.h"
#include "pgs_pck1_sapper.h"
#include "pgs_pck1_ai.h"

void drawPgsGameMenu();
void randomPcCat();
void selectionProgramm();
void interrupt(); void drawPgsGameMenu();

int8_t item{};
int pgs{0};
int timeTimer = 0;

int8_t randX[20];
int8_t randY[20];

void renderPgsGameMenu()
{
  sys.backlight(true);

  uint32_t time;
  time = millis() + 10;

  do {
    u8g2.clearBuffer();
    drawPgsGameMenu();
    u8g2.sendBuffer();
  } while ( millis() < time );
}

void drawPgsGameMenu()
{
  if (sys.obj0y() > 0)
  {
    item++; timeTimer = 0;
    delay(250);
  }
  else if (sys.obj0y() < 0)
  {
    item--; timeTimer = 0;
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

  messagePgsGameMenu (obj[item].title1, obj[item].title2, "");

  messageTwo(63, 12, (String) + (item + 1), (String)"/" + OBJ_MAX_SIZE); //105

  drawCursor(false);
  u8g2.drawXBMP(6, 8, 48, 48, obj[item].icon);

  selectionProgramm();
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

void selectionProgramm()
{
  //102 Aliens Invaders
  if ((obj[item].numObj == 102) && (sys.sw1() == true))
  {
    gfx.renderMessageStartscreen("Game", "Aliens Invaders", 10);

    for (;;)
    {
      //renderPgsAi();

      if (sys.iSw() == true)
      {
        delay(250);
        break;
      }
    }
  }

  //108 Sapper
  if ((obj[item].numObj == 108) && (sys.sw1() == true))
  {
    gfx.renderMessageStartscreen("Game", "Sapper (NES ver)", 10);

    for (;;)
    {
      renderPgsSapper();
      if (sys.iSw() == true)
      {
        delay(250);
        break;
      }
    }
  }

  //200
  if ((obj[item].numObj == 200) && (sys.sw1() == true))
  {
    gfx.renderMessageStartscreen("Systems", "Test FPS", 10);

    for (;;)
    {
      renderPgsTestFPS();  
      if (sys.iSw() == true)
      {
        delay(250);
        break;
      }
      break;
    }
  }

  //201
  if ((obj[item].numObj == 201) && (sys.sw1() == true))
  {
    gfx.renderMessageStartscreen("Systems", "Test ADC", 10);

    for (;;)
    {
      renderPgsTestAdc();
      if (sys.iSw() == true)
      {
        delay(250);
        break;
      }
    }
  }
}

void interrupt()
{
  if (sys.iSw() == true)
  {
    delay(250);
    pgs = 1;
    renderPgsGameMenu();
  }
}
