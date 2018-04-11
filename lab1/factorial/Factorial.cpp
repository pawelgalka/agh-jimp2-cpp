//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

bool IsOutOfRange(int value);

int Factorial(int value) {
  if (IsOutOfRange(value)) return 0;
  if (value == 0) return 1;
  else {
    if (value < 0) return value * Factorial(value + 1);
    else return value * Factorial(value - 1);
  }

}

bool IsOutOfRange(int value) { return value >= 13 || value <= -13; }
