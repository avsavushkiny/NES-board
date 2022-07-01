/*
    screensaver page
*/

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system.h"
#include "sys_gfx_st7565.h"
#include "sys_map_xbmp.h"
#include "sys_list.h"

void drawPgsScreenSaver();
void calcPgsScreenSaver();
void messageScreenSaver();
void calcRandomLogo();

int8_t x{};
int8_t y{};
int periodScreen = 3000;
unsigned long timeNow = 0;
int timeBacklight{};

void renderPgsScreenSaver()
{
  calcPgsScreenSaver();

  uint32_t time;
  time = millis() + 10;
  do {
    u8g2.clearBuffer();
    drawPgsScreenSaver();
    u8g2.sendBuffer();
  } while ( millis() < time );
}

void calcPgsScreenSaver()
{
  if (millis() >= timeNow + periodScreen)
  {
    timeNow += periodScreen;

    if (stateConsole == CONSOLE_SCREEN_SAVER)
    {
      calcRandomLogo();
      timeBacklight++;
    }
    else
    {
      timeNow = millis(); timeBacklight = 0;
    }
  }

  if (timeBacklight >= 5)
  {
    sys.backlight(false);

    if (sys.obj0y() > 0)
    {
      sys.backlight(true);
      delay(250);
      timeBacklight = 0;
    }
  }
  else sys.backlight(true);

  if (timeBacklight == 10)
  {
    timeBacklight = 5;
  }
}

void calcRandomLogo()
{
  x = random(0, 54);
  y = random(0, 46);
}

void drawPgsScreenSaver()
{
  u8g2.drawXBMP(x, y, nes_logo_w, nes_logo_h, nes_logo);
}

void messageScreenSaver()
{
  messageTwo(5, 39, "Power save mode", "");
  messageTwo(5, 49, "Press the button to exit", "");
}
