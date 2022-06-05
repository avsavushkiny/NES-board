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

#define T_GPIO 29

#define nes_logo_w 54
#define nes_logo_h 18

const uint8_t nes_logo[] PROGMEM = {
  0xF0, 0x83, 0x0F, 0xFF, 0x7F, 0xF0, 0x07, 0xF0, 0x83, 0x8F, 0xFF, 0x3F,
  0xFC, 0x1F, 0xF8, 0xC3, 0x8F, 0xFF, 0x3F, 0xFE, 0x3F, 0xF8, 0xC7, 0x87,
  0xFF, 0x3F, 0xFF, 0x3F, 0xF8, 0xC7, 0x87, 0x1F, 0x00, 0x1F, 0x3E, 0xF8,
  0xC7, 0x87, 0x0F, 0x00, 0x1F, 0x00, 0xF8, 0xCF, 0xC7, 0x0F, 0x00, 0x7F,
  0x00, 0xFC, 0xEF, 0xC7, 0xFF, 0x0F, 0xFF, 0x03, 0xFC, 0xEF, 0xC3, 0xFF,
  0x0F, 0xFE, 0x0F, 0x7C, 0xFF, 0xC3, 0xFF, 0x0F, 0xFC, 0x1F, 0x7C, 0xFF,
  0xE3, 0xFF, 0x0F, 0xF0, 0x1F, 0x7E, 0xFE, 0xE3, 0x07, 0x00, 0x80, 0x3F,
  0x7E, 0xFE, 0xE3, 0x03, 0xC0, 0x07, 0x3F, 0x3E, 0xFE, 0xE1, 0x07, 0xC0,
  0x0F, 0x3F, 0x3E, 0xFC, 0xE1, 0xFF, 0xCF, 0xDF, 0x1F, 0x3E, 0xFC, 0xF1,
  0xFF, 0x8F, 0xFF, 0x1F, 0x3F, 0xFC, 0xF1, 0xFF, 0x87, 0xFF, 0x0F, 0x1F,
  0xF8, 0xF0, 0xFF, 0x07, 0xFE, 0x03,
};

/*const int noteCount = 3;
  int melody[noteCount] = {523, 523, 587};
  int duration[noteCount] = {375, 375, 123};
  short beat = 200;*/

const int noteCount = 16;
int melody[noteCount] = {196, 587, 262, 784, 330, 988, 392, 1175, 330, 988, 262, 784, 294, 880, 262, 784,};
int duration[noteCount] = {198, 186, 198, 186, 209, 174, 198, 174, 209, 174, 209, 186, 198, 186, 198, 186,};
short beat = 120;

int j0y;
int j1y;
int jxx;

float vGpio29;
float tC;
int dataGpio29;

int dataJ0y;
int dataJ1y;
int dataJxx;

int corrJ0y = 0;
int corrJ1y = 100;

bool stateLed = true;
bool playLed = false;

void setup1() // core 1
{
  testMelody();
}

void loop1()
{

}

void setup() // core 0
{
  u8g2.begin();
  u8g2.setContrast(0);

  analogReadResolution(12);

  pinMode(JOI0Y, INPUT);
  pinMode(JOI1Y, INPUT);
  pinMode(JOIXX, INPUT);

  pinMode(JOI0SW, INPUT);
  pinMode(JOI1SW, INPUT);

  pinMode(PIN_LED, OUTPUT);   //LED
}

void loop()
{
  calcADC();
  renders();
  led();
}

void renders()
{
  u8g2.firstPage();
  do {
    drawText();
    drawButton();
    drawTwoFrames();
  } while (u8g2.nextPage());
  delay(50);
}

void drawText()
{
  u8g2.drawXBMP(70, 0, nes_logo_w, nes_logo_h, nes_logo); //x, y, w, h, xbmp

  u8g2.setFont(u8g2_font_6x13_tf);
  u8g2.setCursor(5, 10); //x, y
  u8g2.print((String) "test NES");

  u8g2.setCursor(5, 20); //x, y
  u8g2.print((String) "ADC");

  u8g2.setCursor(5, 30); //x, y
  u8g2.print((String) "0y = " + j0y);

  u8g2.setCursor(5, 40); //x, y
  u8g2.print((String) "1y = " + j1y);

  u8g2.setCursor(5, 50); //x, y
  u8g2.print((String) "xx = " + jxx);

  /*u8g2.setCursor(70, 50); //x, y
  u8g2.print((String) "t:" + tC);*/

}

void calcADC()
{
  j0y = analogRead(JOI0Y);
  Serial.println(j0y);

  j1y = analogRead(JOI1Y);
  Serial.println(j1y);

  jxx = analogRead(JOIXX);
  Serial.println(jxx);

  /*dataGpio29 = analogRead(T_GPIO);
  vGpio29 = dataGpio29 * 3.0 / 4095.0;
  tC = 27 - (vGpio29 - 0.706) / 0.001721;*/
  
  Serial.println(tC);

  dataJ0y = (j0y + corrJ0y) * (HRES / 4095.0);
  dataJ1y = (j1y + corrJ1y) * (HRES / 4095.0);

  //dataJxx = jxx * (WRES / 4095.0);

  //map(val, fromMin, fromMax, toMin, toMax)
  dataJxx = map(jxx, 0, 4095, 128, 0);
}

void drawButton()
{
  if (digitalRead(JOI0SW) == false)
  {
    u8g2.setFont(u8g2_font_6x13_tf);
    u8g2.setCursor(70, 30); //x, y
    u8g2.print((String) "click J0");
    Serial.println("click J0");
  }
  else
  {
    u8g2.setFont(u8g2_font_6x13_tf);
    u8g2.setCursor(70, 30); //x, y
    u8g2.print((String) "no J0");
    Serial.println("no J0");
  }

  if (digitalRead(JOI1SW) == false)
  {
    u8g2.setFont(u8g2_font_6x13_tf);
    u8g2.setCursor(70, 40); //x, y
    u8g2.print((String) "click J1");
    Serial.println("click J1");
  }
  else
  {
    u8g2.setFont(u8g2_font_6x13_tf);
    u8g2.setCursor(70, 40); //x, y
    u8g2.print((String) "no J1");
    Serial.println("no J1");
  }
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

void led()
{
  if ((digitalRead(JOI0SW) == false) && (digitalRead(JOI1SW) == false) && (stateLed == true))
  {
    stateLed = false;

    if (stateLed == false)
    {
      digitalWrite(PIN_LED, 0);
    }
  }

  else if ((digitalRead(JOI0SW) == false) && (digitalRead(JOI1SW) == false) && (stateLed == false))
  {
    stateLed = true;

    if (stateLed == true)
    {
      digitalWrite(PIN_LED, 1);
    }
  }

  else
  {
    if (stateLed == true)
    {
      digitalWrite(PIN_LED, 1);
    }

    else if (stateLed == false)
    {
      digitalWrite(PIN_LED, 0);
    }
  }
  Serial.println(stateLed);
}

void drawTwoFrames()
{
  u8g2.drawFrame(dataJxx, dataJ0y, 3, 3);
  u8g2.drawFrame(dataJxx, dataJ1y, 5, 5);
}

void drawField()
{
  uint8_t dist = 2;
  //y
  for (uint8_t a = 0; a < 8; a++)
  {
    u8g2.drawFrame(63, dist, 1, 4);
    dist = dist + 8;
  }
  //x
  for (uint8_t b = 0; b < 16; b++)
  {
    u8g2.drawFrame(dist, 32, 1, 4);
    dist = dist + 8;
  }
}

void calcADCtoD()
{
}
