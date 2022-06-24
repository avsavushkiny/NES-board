/*
 *  system sound map
 */

#pragma once
#include <Arduino.h>

#define IN_BUZZER 9
int beat = 120;
/*
const int noteCount = 16;
int melodyNes  [noteCount] = {196, 587, 262, 784, 330, 988, 392, 1175, 330, 988, 262, 784, 294, 880, 262, 784,};
int durationNes[noteCount] = {198, 186, 198, 186, 209, 174, 198, 174, 209, 174, 209, 186, 198, 186, 198, 186,};
*/
const int noteCount = 7;
int melodyNes  [noteCount] = {330, 2637, 415, 523, 494, 1865, 2489};
int durationNes[noteCount] = {767, 256, 791, 23, 860, 105, 128};

void soundNes()
{
  for (int i = 0; i < noteCount; i++)
  {
    tone(IN_BUZZER, melodyNes[i], durationNes[i]);
    delay(beat);
    noTone(IN_BUZZER);
  }
}
