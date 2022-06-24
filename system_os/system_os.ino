/*
    NES OS / beta 1
             pack 1

    fonts https://github.com/olikraus/u8g2/wiki/fntlistall
*/
#include <Arduino.h>
#include "system.h"
#include "sys_gfx_st7565.h"
#include "pgs_0.h"
#include "pgs_screensaver.h"
#include "pgs_game_menu.h"
#include "pgs_nes.h"
#include "sys_map_sound.h"
#include "sys_list.h"

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
    renderPgsGameMenu();
  }

  
  else if (pgs == 2)
  {
    renderPgsScreenSaver();
  }
  /*
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
    delay(1500);
    pgs = 0;
  }

}
