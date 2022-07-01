/*
    game SAPPER
*/

#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system.h"
#include "sys_list.h"
#include "sys_gfx_st7565.h"

#define patt1_sapper_w 8
#define patt1_sapper_h 8
const uint8_t patt1_sapper_bits[] = {
  0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7E, 0x00,
};

#define patt2_sapper_w 8
#define patt2_sapper_h 8
const uint8_t patt2_sapper_bits[] = {
  0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81,
};

uint8_t boxSapper[5][9] =
{ {0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void renderPgsSapper()
{
  u8g2.clearBuffer();
  u8g2.sendBuffer();
}


void calcSapper()
{
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 9; j++) {

      boxSapper[i][j] = 0;
    }
  }
}

void drawSapper()
{
  
}
