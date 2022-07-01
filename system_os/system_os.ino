/*
    NES OS / beta 1
             pack 1

    fonts https://github.com/olikraus/u8g2/wiki/fntlistall
*/
#include <Arduino.h>
#include "system.h"
#include "sys_gfx_st7565.h"
#include "pgs_hello.h"
#include "pgs_screensaver.h"
#include "pgs_game_menu.h"
#include "pgs_nes.h"
#include "sys_map_sound.h"
#include "sys_list.h"

int periodTimerScreen = 1000;
unsigned long timeTimerNow = 0;

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
    timeTimer = 0;
    delay(500);
  }
  else pgs = pgs;

  if (pgs == 0)
  {
    stateConsole = CONSOLE_PGS_HELLO; timeNow = millis();
    renderPgsHello();
  }

  else if (pgs == 1)
  {
    stateConsole = CONSOLE_PGS_MENU; timeNow = millis();
    renderPgsGameMenu();
  }


  else if (pgs == 2)
  {
    stateConsole = CONSOLE_SCREEN_SAVER;
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
    sys.backlight(true);
    gfx.renderMessageBottom(messageBottom, "! Return to menu", "", 10);
    delay(1500);
    pgs = 0;
  }


  if (millis() >= timeTimerNow + periodTimerScreen)
  {
    timeTimerNow += periodScreen;
    timeTimer++;

    if (timeTimer >= 60)
    {
      timeTimer = 0;
      stateConsole = CONSOLE_SCREEN_SAVER;

      for (;;)
      {
        renderPgsScreenSaver();

        if (sys.obj0y() > 0)
        {
          sys.backlight(true);
          delay(250);
          break;
        }
      }
    }
    else
    {
      timeTimerNow = millis();
    }
  }
}
