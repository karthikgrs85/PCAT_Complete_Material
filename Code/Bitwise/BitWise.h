#pragma once
#include <stdbool.h>

void setNthBit(unsigned char *a, int n);
void setNBits(unsigned char *a, int x, int y);

void resetNthBit(unsigned char *a, int n);
void resetNBits(unsigned char *a, int x, int y);

void flipNthBit(unsigned char *a, int n);
void flipNBits(unsigned char *a, int x, int y);

bool testNthBit(unsigned char a, int n);


unsigned char getValueForRange(unsigned char a, int x, int y);
