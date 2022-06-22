/*
    game list
*/

#pragma once
#include <Arduino.h>
#include "game_map_xbmp.h"
#include "sys_image48.h"

#define OBJ_MAX_SIZE 7
#define OBJCM_MAX_SIZE 5

/*
struct Object
{
  String title;
  String info;
  const uint8_t* icon;
} obj[]
{
  {"Pong",            "Atari, 1972",      pong1972},
  {"Aliens Invaders", "Atari, 1978",      aliens1978},
  {"Dice",            "Harrison, 1974",   dice1974},
  {"Snake",           "Nokia, 1997",      snake2},
  {"Tetris",          "Pajitnov, 1984",   tetris1984},
  {"Acey Ducey",      "B.Palmby, 1973",   aceyDucey1973},
};
*/

struct Object
{
  String title1;
  String title2;
  String info;
  const uint8_t* icon;
} obj[]
{
  {"Acey Ducey", "Original", "Palmby'73", acdu_bits},
  {"Aliens", "Invaders", "Atari'78", ai_bits},
  {"Dice", "Original", "Harrison'74", dice_bits},
  {"Jocker &", "Dice", "Basic'73", jdice_bits},
  {"Pong", "(NES ver)", "Atari'72", pong_bits},
  {"Snake", "Original", "Nokia'97", snake_bits},
  {"Tetris", "Original", "Pajitnov'84", tetris_bits},
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
  {"I work on NES OS,", "ver 1 200622 beta", "game pack 1 22",    "press start"},
  {"Designer", "and programmer", "avsavushkiny GHub",        "press start"},
};
