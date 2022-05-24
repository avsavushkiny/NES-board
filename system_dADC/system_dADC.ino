/*
    test NES game board
*/

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>

U8G2_ST7565_ERC12864_1_4W_SW_SPI u8g2(U8G2_R0, 18, 19, 17, 16, 20);

//def
#define JOI0Y 27
#define JOI1Y 28
#define JOIXX 26

#define JOI0SW 6
#define JOI1SW 7

#define HRES 64
#define WRES 128

#define PIN_LED 8
#define IN_BUZZER 9

#define DEF_RES_Y0 2100
#define DEF_RES_Y1 2100
#define DEF_RES_XX 2100

const int noteCount = 16;
int melody[noteCount] = {196, 587, 262, 784, 330, 988, 392, 1175, 330, 988, 262, 784, 294, 880, 262, 784,};
int duration[noteCount] = {198, 186, 198, 186, 209, 174, 198, 174, 209, 174, 209, 186, 198, 186, 198, 186,};
short beat = 120;

int yJoi0 = HRES / 2;
int yJoi1 = HRES / 2;
int xJoi  = WRES / 2;

int dataJOI0Y;
int dataJOI1Y;
int dataJOIXX;

void setup() {
  u8g2.begin();
  u8g2.setContrast(0);

  //multicore_launch_core1(setup1);

  analogReadResolution(12);   //4095

  pinMode(JOI0Y, INPUT);
  pinMode(JOI1Y, INPUT);
  pinMode(JOIXX, INPUT);

  pinMode(JOI0SW, INPUT);
  pinMode(JOI1SW, INPUT);

  pinMode(PIN_LED, OUTPUT);   //LED
  digitalWrite(PIN_LED, 1);   //LED ON
}

void setup1()
{
  testMelody();
}

void loop() {
  calcDadc();
  renders();
  delay(50);
}

void calcDadc()
{
  dataJOI0Y = analogRead(JOI0Y);
  dataJOI1Y = analogRead(JOI1Y);
  dataJOIXX = analogRead(JOIXX);

  //y0
  if ((dataJOI0Y < (DEF_RES_Y0 - 200)) && (dataJOI0Y > (DEF_RES_Y0 - 1100)))
  {
    yJoi0 = yJoi0 - 1;
  }
  else if (dataJOI0Y < (DEF_RES_Y0 - 1100))
  {
    yJoi0 = yJoi0 - 2;
  }

  if ((dataJOI0Y > (DEF_RES_Y0 + 200)) && (dataJOI0Y < (DEF_RES_Y0 + 1100)))
  {
    yJoi0 = yJoi0 + 1;
  }
  else if (dataJOI0Y > (DEF_RES_Y0 + 1100))
  {
    yJoi0 = yJoi0 + 2;
  }

  //y1
  if ((dataJOI1Y < (DEF_RES_Y1 - 200)) && (dataJOI1Y > (DEF_RES_Y1 - 1100)))
  {
    yJoi1 = yJoi1 - 1;
  }
  else if (dataJOI1Y < (DEF_RES_Y1 - 1100))
  {
    yJoi1 = yJoi1 - 2;
  }

  if ((dataJOI1Y > (DEF_RES_Y1 + 200)) && (dataJOI1Y < (DEF_RES_Y1 + 1100)))
  {
    yJoi1 = yJoi1 + 1;
  }
  else if (dataJOI1Y > (DEF_RES_Y1 + 1100))
  {
    yJoi1 = yJoi1 + 2;
  }
  
  //xx
  if ((dataJOIXX < (DEF_RES_XX - 200)) && (dataJOIXX > (DEF_RES_XX - 1100)))
  {
    xJoi = xJoi + 1;
  }
  else if (dataJOIXX < (DEF_RES_XX - 1100))
  {
    xJoi = xJoi + 2;
  }

  if ((dataJOIXX > (DEF_RES_XX + 200)) && (dataJOIXX < (DEF_RES_XX + 1100)))
  {
    xJoi = xJoi - 1;
  }
  else if (dataJOIXX > (DEF_RES_XX + 1100))
  {
    xJoi = xJoi - 2;
  }
}

void drawText()
{
  u8g2.setFont(u8g2_font_6x13_tf);

  u8g2.setCursor(5, 10);
  u8g2.print((String) "test NES system");
  
  u8g2.setCursor(5, 20);
  u8g2.print((String) dataJOI0Y);
  u8g2.setCursor(5, 30);
  u8g2.print((String) dataJOI1Y);
  u8g2.setCursor(5, 40);
  u8g2.print((String) dataJOIXX);
}

void drawFrames()
{
  u8g2.drawFrame(xJoi, yJoi0, 10, 10);   //joi 0
  u8g2.drawFrame(xJoi, yJoi1, 5, 5);     //joi 1
}

void renders()
{
  u8g2.firstPage();
  do {
    drawText();
    drawFrames();
    drawButton();
  } while (u8g2.nextPage());
  delay(50);
}

void testMelody()
{
  for (int i = 0; i < noteCount; i++)
  {
    tone(IN_BUZZER, melody[i], duration[i]);
    delay(beat);
    noTone(IN_BUZZER);
  }
}

void drawButton()
{
  if (digitalRead(JOI0SW) == false)
  {
    u8g2.setFont(u8g2_font_6x13_tf);
    u8g2.setCursor(70, 30); //x, y
    u8g2.print((String) "clk Joi0");
    Serial.println("clk Joi0");
  }
  else
  {
    u8g2.setFont(u8g2_font_6x13_tf);
    u8g2.setCursor(70, 30); //x, y
    u8g2.print((String) "no Joi0");
    Serial.println("no Joi0");
  }

  if (digitalRead(JOI1SW) == false)
  {
    u8g2.setFont(u8g2_font_6x13_tf);
    u8g2.setCursor(70, 40); //x, y
    u8g2.print((String) "clk Joi1");
    Serial.println("clk Joi1");
  }
  else
  {
    u8g2.setFont(u8g2_font_6x13_tf);
    u8g2.setCursor(70, 40); //x, y
    u8g2.print((String) "no Joi1");
    Serial.println("no Joi1");
  }
}
