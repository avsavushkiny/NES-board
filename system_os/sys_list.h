/*
    game list
*/

#pragma once
#include <Arduino.h>
#include "sys_image48.h"

#define OBJ_MAX_SIZE 7
#define OBJCM_MAX_SIZE 5

#define NES_OS_VER 1
#define NES_OS_UPDATE 240622
#define GAME_PACK  1

struct Object
{
  String title1;
  String title2;
  String info;
  const uint8_t* icon;
} obj[]
{
  {"Acey", "Ducey", "", acdu_bits},
  {"Aliens", "Invaders", "", ai_bits},
  {"Dice", "Original", "", dice_bits},
  {"Jocker", "& Dice", "", jdice_bits},
  {"Pong", "(NES ver)", "", pong_bits},
  {"Snake", "Original", "", snake_bits},
  {"Tetris", "Original", "", tetris_bits},
};

struct ObjectCatMessage
{
  String text1;
  String text2;
  String text3;
  String text4;
} objCatMessage[]
{
  {"Hello!", "I am NES console", "how are you?",             "press start"},
  {"To start the game", "click on the ", "button Joystick!", "press start"},
  {"Faster click", "and play!", "Go! Go! Go!",               "press start"},
  {"I work on NES OS,", "version " + (String)NES_OS_VER + "/" + (String)NES_OS_UPDATE, "game pack " + (String)GAME_PACK, "press start"},
  {"Designer", "and programmer", "avsavushkiny,GHub",        "press start"},
};
