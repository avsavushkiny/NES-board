/*
    graphics output library
*/

#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system.h"
#include "sys_map_xbmp.h"

#define WIDTH 128
#define HEIGHT 64
#define CTRL_TO 50

U8G2_ST7565_ERC12864_F_4W_SW_SPI u8g2(U8G2_R0, 18, 19, 17, 16, 20);

unsigned long previousMillis = 0;
const long interval = 300;

class Gfx
{
  private:
  public:
    void screen()
    {
      u8g2.begin();
      u8g2.setContrast(0);
      sys.backlight(true);
    }

    void renderCatMessage( void (*draw_fn)(String, String, String, String),
                           String a, String b, String c, String d )
    {
      uint32_t time;
      time = millis() + 10;

      do {
        u8g2.clearBuffer();
        draw_fn(a, b, c, d);
        u8g2.sendBuffer();
      } while ( millis() < time );
    }

    void renderMessageBottom( void (*draw_fn)(String, String),
                              String a, String b, int timeDelay )
    {
      uint32_t time;
      time = millis() + timeDelay;

      do {
        u8g2.clearBuffer();
        draw_fn(a, b);
        u8g2.sendBuffer();
      } while ( millis() < time );
    }

    void renderPage( void (*draw_fn)(void), int timeDelay )
    {
      uint32_t time;
      time = millis() + timeDelay;

      do {
        u8g2.clearBuffer();
        draw_fn();
        u8g2.sendBuffer();
      } while ( millis() < time );
    }

    void renderMessageStartscreen(String title1, String title2, int timeDelay)
    {
      uint32_t time;
      time = millis() + timeDelay;

      do {
        u8g2.clearBuffer();
        
        u8g2.setFont(u8g2_font_6x10_tr);
        u8g2.clearBuffer();
        u8g2.setCursor(10, 29); u8g2.print(title1);
        u8g2.setCursor(10, 39); u8g2.print(title2);

        u8g2.sendBuffer();
      } while ( millis() < time );

      delay(1500);
    }
};

Gfx gfx;

void catMessage(String text1, String text2, String text3, String text4)
{
  u8g2.drawXBMP(2, 3, diaFrameHello_w, diaFrameHello_h, diaFrameHello);
  u8g2.drawXBMP(105, 45, nes_cat_w, nes_cat_h, nes_cat);
  u8g2.drawHLine(102, 59, 21);

  u8g2.setFont(u8g2_font_6x10_tr); //u8g2_font_6x10_tr
  u8g2.setCursor(9, 14);
  u8g2.print(text1);
  u8g2.setCursor(9, 24);
  u8g2.print(text2);
  u8g2.setCursor(9, 34);
  u8g2.print(text3);

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
  }
  else
  {
    u8g2.setCursor(20, 52);
    u8g2.print(text4);
  }
}

void messageBottom(String text1, String text2)
{
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.setCursor(16, 35);
  u8g2.print(text1);
  u8g2.setCursor(16, 45);
  u8g2.print(text2);
}

bool drawCursor(bool stateCursor)
{
  if (stateCursor == true)
  {
    u8g2.setDrawColor(2);
    u8g2.setBitmapMode(1);
    u8g2.drawXBMP(sys.joi0x(), sys.joi0y(), cursorOne_w, cursorOne_h, cursorOne);
    u8g2.setDrawColor(1);
    u8g2.setBitmapMode(0);
    return true;
  }
  else return false;
}

bool drawCursorTwo(bool stateCursor)
{
  if (stateCursor == true)
  {
    u8g2.setDrawColor(2);
    u8g2.setBitmapMode(1);
    u8g2.drawXBMP(sys.joi0x(), sys.joi0y(), cursorTwo_w, cursorTwo_h, cursorTwo);
    u8g2.setDrawColor(1);
    u8g2.setBitmapMode(0);
    return true;
  }
  else return false;
}

void messageTwo(int8_t x, int8_t y, String text1, String text2)
{
  //u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.setCursor(x, y);
  u8g2.print((String)text1 + (String)text2);
}

void messagePgsGameMenu(String title1, String title2, String title3)
{
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.setCursor(63, 22); //60,24
  u8g2.print(title1);
  u8g2.setCursor(63, 32); //60,34
  u8g2.print(title2);

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval + 200)
  {
    previousMillis = currentMillis;
  }
  else
  {
    u8g2.drawXBMP(100, 55, play_w, play_h, play_bits);    //23x7
  }
}
