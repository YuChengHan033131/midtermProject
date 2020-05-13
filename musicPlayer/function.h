#ifndef FUNCTION_H
#define FUNCTION_H
//mbed add https://gitlab.larc-nthu.net/ee2405_2020/DA7212
#include "mbed.h"
#include <cmath>
#include "DA7212.h"
#include "uLCD_4DGL.h"


void playChord(float *notes,int numbers,float time);
void playNote(float freq,float time);


#endif