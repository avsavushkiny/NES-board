/*
    game ALIENS INVADERS
*/

#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system.h"
#include "sys_list.h"
#include "sys_gfx_st7565.h"

void calcAliens();
void calcMoveAliens();
void drawAliens();
void drawSpacePlayer();

#define al1_w 6
#define al1_h 6
const uint8_t al1_bits[] = {
  0x22, 0x3E, 0x2A, 0x1C, 0x1B, 0x0C,
};

#define al2_w 6
#define al2_h 6
const uint8_t al2_bits[] = {
  0x21, 0x12, 0x12, 0x1E, 0x1A, 0x0C,
};

#define al3_w 6
#define al3_h 6
const uint8_t al3_bits[] = {
  0x12, 0x0C, 0x33, 0x3F, 0x0C, 0x12,
};

#define al4_w 6
#define al4_h 6
const uint8_t al4_bits[] = {
  0x33, 0x1E, 0x2D, 0x3F, 0x1E, 0x2D,
};

#define sP_w 5
#define sP_h 6
const uint8_t sP_bits[] = {
  0x04, 0x04, 0x0E, 0x1F, 0x1F, 0x15,
};

uint8_t boxAliens[5][9] =
{ {0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

bool boxAliensState = false;
int speedAliensX = 1;
int speedAliensY = 1;
int boxAliensX = 16;
int boxAliensY = 1;

#define ENEMY_TO 4000
#define CTRL_TO 250
#define ROCKET_FLY_TO 50
#define ROCKET_START_TO 1000

int blaster_coords[2];

unsigned long t, ctrl_next, enemy_next, rocket_fire_next, rocket_fly_next;
bool isBlasterFlying = false;

void renderPgsAi()
{
  //timer 1
  unsigned long t = millis();
  if ( t > ctrl_next )
  {
    ctrl_next = t + CTRL_TO;
    calcMoveAliens();
  }
  //timer 2
  if ( t > enemy_next )
  {
    enemy_next = t + ENEMY_TO;
    boxAliensY += speedAliensY;
  }
  //timer 3
  if (t > rocket_fire_next && !isBlasterFlying)
  {
    rocket_fire_next = t + ROCKET_START_TO;
    fireBlaster();
  }
  //timer 4
  if (t > rocket_fly_next)
  {
    rocket_fly_next = t + ROCKET_FLY_TO;
    rocketMove();
  }

  calcAliens();

  u8g2.clearBuffer();
  drawAliens();
  drawSpacePlayer();
  u8g2.sendBuffer();
}


void calcAliens()
{
  while (boxAliensState == false)
  {
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        int rndAliens = random(0, 4);
        boxAliens[i][j] = rndAliens;
      }
    }
    boxAliensState = true;
  }
}

void calcMoveAliens()
{
  boxAliensX += speedAliensX;

  if (boxAliensX >= 42) //90+6-10
  {
    speedAliensX *= -1;
  }
  if (boxAliensX <= 0)  //0
  {
    speedAliensX *= -1;
  }
}

void drawAliens()
{
  for (int i = 0; i < 3; i++)   //y
  {
    for (int j = 0; j < 9; j++) //x
    {
      if (boxAliens[i][j] == 0) u8g2.drawXBMP((j * 10) + boxAliensX, (i * 8) + boxAliensY, al1_w, al1_h, al1_bits);
      if (boxAliens[i][j] == 1) u8g2.drawXBMP((j * 10) + boxAliensX, (i * 8) + boxAliensY, al1_w, al1_h, al2_bits);
      if (boxAliens[i][j] == 2) u8g2.drawXBMP((j * 10) + boxAliensX, (i * 8) + boxAliensY, al1_w, al1_h, al3_bits);
      if (boxAliens[i][j] == 3) u8g2.drawXBMP((j * 10) + boxAliensX, (i * 8) + boxAliensY, al1_w, al1_h, al4_bits);
    }
  }
}

void drawSpacePlayer()
{
  u8g2.drawXBMP(sys.joi0x(), 57, sP_w, sP_h, sP_bits);
}












/*
void drawBlaster()
{
  if (isBlasterFlying)
  {
    u8g2.drawPixel(blaster_coords[X], blaster_coords[Y]);
  }
}

void fireBlaster()
{
  isBlasterFlying = true;
  blaster_coords[X] = sys.joi0x() + sP_w / 2;
  blaster_coords[Y] = 57 - 1;
}

void moveBlaster()
{
  if (blaster_coords[Y] == 0)
  {
    isBlasterFlying = false;
  }
  blaster_coords[Y] -= 1;
}

*/
