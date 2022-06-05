/*
    NES OS v1 / beta 05/06/22
    21/05/22

    fonts https://github.com/olikraus/u8g2/wiki/fntlistall
*/
#include <Arduino.h>
#include "system.h"
#include "system_gfx_st7565.h"
#include "pgs_1.h"
#include "pgs_nes.h"
#include "system_map_sound.h"
#include "system_list.h"

int pgs{0};

void setup()
{
  gfx.screen();
  analogReadResolution(12);
  drawPgsNes();
}

void setup1()
{
  soundNes();
}

void loop1()
{

}

void loop()
{
  if (sys.sw0() == true)
  {
    pgs++;
    delay(500);
  }
  else pgs = pgs;

  Serial.println(pgs);

  if (pgs == 0)
  {
    gfx.renderCatMessage(messageHelloCat,
                         "Hello!",
                         "I am NES console,",
                         "how are you?",
                         "press start");
  }

  else if (pgs == 1)
  {
    renderPgs1();
  }

  else
  {
    gfx.renderMessage(messageBottom, "!!!", "Page not found");
    delay(3000);
    pgs = 0;
  }

}
