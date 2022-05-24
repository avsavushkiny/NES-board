#pragma once
#include <Arduino.h>

#define DEF_RES_Y0 2100
#define DEF_RES_Y1 2100
#define DEF_RES_X0 2100
#define DEF_RES_X1 2100

#define CORR_y0 100

#define JOI_0Y 27
#define JOI_1Y 28
#define JOI_X0 26
#define JOI_X1 26

#define H_RES 64
#define W_RES 128

int yJoi0 = H_RES / 2;
int yJoi1 = H_RES / 2;
int xJoi0 = W_RES / 2;
int xJoi1 = W_RES / 2;

int dataJoiY0{};
int dataJoiY1{};
int dataJoiX0{};
int dataJoiX1{};

class Systems
{
  private:

  public:
    //systems sw
    bool sw0()
    {
      if (digitalRead(6) == false)
      {
        return true;
      }
      else return false;
    }

    bool sw1()
    {
      if (digitalRead(7) == false)
      {
        return true;
      }
      else return false;
    }

    //system dADC
    int joi0y()
    {
      dataJoiY0 = analogRead(JOI_0Y);

      if ((dataJoiY0 < (DEF_RES_Y0 - 200)) && (dataJoiY0 > (DEF_RES_Y0 - 1100)))
      {
        return yJoi0 = yJoi0 - 1;
      }
      else if (dataJoiY0 < (DEF_RES_Y0 - 1100))
      {
        return yJoi0 = yJoi0 - 2;
      }
      else if ((dataJoiY0 > (DEF_RES_Y0 + 200)) && (dataJoiY0 < (DEF_RES_Y0 + 1100)))
      {
        return yJoi0 = yJoi0 + 1;
      }
      else if (dataJoiY0 > (DEF_RES_Y0 + 1100))
      {
        return yJoi0 = yJoi0 + 2;
      }
      else return yJoi0;
    }

    int joi1y()
    {
      dataJoiY1 = analogRead(JOI_1Y);

      if ((dataJoiY1 < (DEF_RES_Y1 - 200)) && (dataJoiY1 > (DEF_RES_Y1 - 1100)))
      {
        return yJoi1 = yJoi1 - 1;
      }
      else if (dataJoiY1 < (DEF_RES_Y1 - 1100))
      {
        return yJoi1 = yJoi1 - 2;
      }
      else if ((dataJoiY1 > (DEF_RES_Y1 + 200)) && (dataJoiY1 < (DEF_RES_Y1 + 1100)))
      {
        return yJoi1 = yJoi1 + 1;
      }
      else if (dataJoiY1 > (DEF_RES_Y1 + 1100))
      {
        return yJoi1 = yJoi1 + 2;
      }
      else return yJoi1;
    }

    int joi0x()
    {
      dataJoiX0 = analogRead(JOI_X0);

      if ((dataJoiX0 < (DEF_RES_X0 - 200)) && (dataJoiX0 > (DEF_RES_X0 - 1100)))
      {
        return xJoi0 = xJoi0 + 1;
      }
      else if (dataJoiX0 < (DEF_RES_X0 - 1100))
      {
        return xJoi0 = xJoi0 + 2;
      }
      else if ((dataJoiX0 > (DEF_RES_X0 + 200)) && (dataJoiX0 < (DEF_RES_X0 + 1100)))
      {
        return xJoi0 = xJoi0 - 1;
      }
      else if (dataJoiX0 > (DEF_RES_X0 + 1100))
      {
        return xJoi0 = xJoi0 - 2;
      }
      else return xJoi0;
    }


    //system backlight
    void backlight(bool state)
    {
      pinMode(8, OUTPUT);

      if (state == true)
      {
        digitalWrite(8, 1);
      }
      else
      {
        digitalWrite(8, 0);
      }
    }
};

Systems sys;
