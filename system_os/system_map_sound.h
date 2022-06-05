/*
 *  system sound map
 */

#pragma once
#include <Arduino.h>

#define IN_BUZZER 9
int beat = 120;

const int noteCount = 16;
int melodyNes  [noteCount] = {196, 587, 262, 784, 330, 988, 392, 1175, 330, 988, 262, 784, 294, 880, 262, 784,};
int durationNes[noteCount] = {198, 186, 198, 186, 209, 174, 198, 174, 209, 174, 209, 186, 198, 186, 198, 186,};

void soundNes()
{
  for (int i = 0; i < noteCount; i++)
  {
    tone(IN_BUZZER, melodyNes[i], durationNes[i]);
    delay(beat);
    noTone(IN_BUZZER);
  }
}

class Sound
{
  private:
  public:

    void player(void (*draw_fn))
    {
      draw_fn;
    }
} sound;
