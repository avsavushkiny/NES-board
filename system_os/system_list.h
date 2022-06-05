/*
 *  game list
 */

#pragma once
#include <Arduino.h>
#include "game_map_xbmp.h"

#define OBJ_MAX_SIZE 6

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
