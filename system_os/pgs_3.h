/*
    screensaver page
*/

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system_gfx_st7565.h"
#include "pgs_1.h"

void drawPgs3();
void calcPgs3();

int8_t x{};
int8_t y{};

int period = 3000;
unsigned long time_now = 3000;
int8_t timeBacklight{};

void renderPgs3()
{
  //sys.backlight(true);

  if (millis() >= time_now + period) {
    time_now += period;
    calcPgs3();
    timeBacklight++;
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
    timeBacklight = 0;
  }


  uint32_t time;
  time = millis() + 10;

  do {
    u8g2.clearBuffer();
    drawPgs3();
    u8g2.sendBuffer();
  } while ( millis() < time );
}

void calcPgs3()
{
  x = random(0, 54);
  y = random(0, 46);
}

void drawPgs3()
{
  u8g2.drawXBMP(x, y, nes_logo_w, nes_logo_h, nes_logo);
}
