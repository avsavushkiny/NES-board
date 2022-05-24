/*
    NES OS v1
    21/05/22

    fonts https://github.com/olikraus/u8g2/wiki/fntlistall
*/
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "system.h"

void drawFrames();

U8G2_ST7565_ERC12864_F_4W_SW_SPI u8g2(U8G2_R0, 18, 19, 17, 16, 20);

int j0_y{};
int j1_y{};
int j0_x{};

void execute_with_fps(void (*draw_fn)(void)) {
  uint16_t FPS10 = 0;
  uint32_t time;

  time = millis() + 10;

  do {
    u8g2.clearBuffer();
    draw_fn();
    u8g2.sendBuffer();
    FPS10++;
  } while ( millis() < time );
  //return FPS10;
}

void setup()
{
  u8g2.begin();
  u8g2.setContrast(0);
  analogReadResolution(12);

  sys.backlight(true);
}

void loop()
{
  j0_y = sys.joi0y();
  j1_y = sys.joi1y();
  j0_x = sys.joi0x();

  execute_with_fps(drawFrames);
}
/*
void drawButton()
{
  if (sys.sw0())
  {
    u8g2.setFont(u8g2_font_6x13B_tr);
    u8g2.setCursor(70, 30); //x, y
    u8g2.print((String) "clk Joi0");
    Serial.println("clk Joi0");
  }
  else
  {
    u8g2.setFont(u8g2_font_6x13B_tr);
    u8g2.setCursor(70, 30); //x, y
    u8g2.print((String) "no Joi0");
    Serial.println("no Joi0");
  }
}
*/
/*
void drawText()
{
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setCursor(10, 10); //x, y
  u8g2.print("main menu");

  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setCursor(10, 30); //x, y
  u8g2.print("Pong");
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setCursor(10, 40); //x, y
  u8g2.print("Atari. 1972");
}
*/
void drawFrames()
{
  u8g2.drawFrame(j0_x, j0_y, 5, 10); //x, y, w, h
  u8g2.drawFrame(120,  j1_y, 5, 10);
}
