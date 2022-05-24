#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>

#define PIN_LED 8
#define SECONDS 1

U8G2_ST7565_ERC12864_F_4W_SW_SPI u8g2(U8G2_R0, 18, 19, 17, 16, 20);


uint16_t execute_with_fps(void (*draw_fn)(void)) {
  uint16_t FPS10 = 0;
  uint32_t time;

  time = millis() + SECONDS * 1000;

  // picture loop
  do {
    u8g2.clearBuffer();
    draw_fn();
    u8g2.sendBuffer();
    FPS10++;
  } while ( millis() < time );
  return FPS10;
}

void setup() {
  u8g2.begin();
  u8g2.setContrast(0);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, 1);
}

void loop() {
  execute_with_fps(draw_text);
}


void draw_text()
{
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setCursor(10, 8); //x, y
  u8g2.print("Menu");

  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setCursor(30, 20); //x, y
  u8g2.print("Pong");
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setCursor(30, 30); //x, y
  u8g2.print("Atari. 1972");
}
