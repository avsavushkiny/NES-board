/*
    test ADC page
*/

#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system.h"
#include "sys_list.h"
#include "sys_gfx_st7565.h"
#include "pgs_game_menu.h"

void drawPgsTestAdc();
void drawClickButtonFrames();


void renderPgsTestAdc()
{
  gfx.renderPage(drawClickButtonFrames, 10);
}

void drawClickButtonFrames()
{
    if (sys.sw0() == true)
    {
    u8g2.drawBox(sys.joi0x(), sys.joi0y(), 10, 10);
    }
    else
    {
    u8g2.drawFrame(sys.joi0x(), sys.joi0y(), 10, 10);
    }

    if (sys.sw1() == true)
    {
    u8g2.drawBox(sys.joi0x(), sys.joi1y(), 25, 25);
    }
    else
    {
    u8g2.drawFrame(sys.joi0x(), sys.joi1y(), 25, 25);
    }
}
