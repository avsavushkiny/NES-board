/*
    info page
*/

#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system.h"
#include "sys_gfx_st7565.h"
#include "sys_map_xbmp.h"

void drawScreenSaver();
void timer();

unsigned long previousMillis2 = 0;
const long interval2 = 3000;

int rndX{};
int rndY{};

void renderPgsScreenSaver()
{
  uint32_t time;
  time = millis() + 10;

  do {
    u8g2.clearBuffer();
    timer();
    u8g2.sendBuffer();
  } while ( millis() < time );
}

void drawScreenSaver()
{
  rndX = random(0, 68);
  rndY = random(10, 64);

  messageTwo(rndX, rndY, "Screen saver", "");
}

void timer()
{
  unsigned long currentMillis2 = millis();
  if (currentMillis2 - previousMillis2 >= interval2)
  {
    previousMillis2 = currentMillis2;
  }
  else
  {
    drawScreenSaver();
  }
}
