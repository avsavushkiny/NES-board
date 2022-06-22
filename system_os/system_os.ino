/*
    NES OS / beta 1 200622
             pack 1 0622

    fonts https://github.com/olikraus/u8g2/wiki/fntlistall
*/
#include <Arduino.h>
#include "system.h"
#include "system_gfx_st7565.h"
#include "pgs_0.h"
#include "pgs_1.h"
#include "pgs_4.h"
#include "pgs_m.h"
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

  if (pgs == 0)
  {
    renderPgs0();
  }

  else if (pgs == 1)
  {
    renderPgsM();
  }

  /*
  else if (pgs == 2)
  {
    renderPgs4();
    delay(3000);
    pgs = 0;
  }

  else if (pgs == 3)
  {
    renderPgs3();
  }

  else if (pgs == 4)
  {
    renderPgs4();
  }
  */
  else
  {
    gfx.renderMessageBottom(messageBottom, "! Return to menu", "", 10);
    delay(2000);
    pgs = 0;
  }

}
