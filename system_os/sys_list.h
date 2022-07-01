/*
    game list
*/

#pragma once
#include <Arduino.h>
#include "sys_image48.h"

#define OBJ_MAX_SIZE 10
#define OBJCM_MAX_SIZE 5

#define NES_OS_VER 1
#define NES_OS_UPDATE 250622
#define GAME_PACK  1

enum StateConsole
{
  CONSOLE_SCREEN_SAVER, //0
  CONSOLE_PGS_HELLO,    //1
  CONSOLE_PGS_MENU,     //2
} stateConsole;

enum StateGame
{
  GAME_PLAY,    //0
  GAME_PAUSED,  //1
  GAME_OVER,    //2  
} stateGame;

struct Object
{
  String title1;
  String title2;
  String info;
  int numObj;
  const uint8_t* icon;
} obj[]
{
  {"Acey", "Ducey", "", 101, acdu_bits},
  {"Aliens", "Invaders", "", 102, ai_bits},
  {"Dice", "Original", "", 103, dice_bits},
  {"Jocker", "& Dice", "", 104, jdice_bits},
  {"Pong", "(NES ver)", "", 105, pong_bits},
  {"Snake", "Original", "", 106, snake_bits},
  {"Tetris", "Original", "", 107, tetris_bits},
  {"Sapper", "(NES ver)", "", 108, sapper_bits},
  {"Test FPS", "Systems", "", 200, testFps_bits},
  {"Test ADC", "Systems", "", 201, testAdc_bits},
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
