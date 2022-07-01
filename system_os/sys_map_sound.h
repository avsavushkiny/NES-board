/*
 *  system sound map
 */

#pragma once
#include <Arduino.h>

#define IN_BUZZER 9
int beat = 120;

enum SystemsSound
{
  START,  //0
  PAUSED, //1
  MENU,   //2
  CLICK,  //3
} sysSound;

const int noteCountNes = 7;
int melodyNes  [noteCountNes] = {330, 2637, 415, 523, 494, 1865, 2489};
int durationNes[noteCountNes] = {767, 256, 791, 23, 860, 105, 128};

void soundNes()
{
  for (int i = 0; i < noteCountNes; i++)
  {
    tone(IN_BUZZER, melodyNes[i], durationNes[i]);
    delay(beat);
    noTone(IN_BUZZER);
  }
}

void soundPaused()
{
  
}

void soundMenu()
{
  
}

void soundClick()
{
  
}
