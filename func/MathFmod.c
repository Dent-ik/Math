#include "../math.h"

int is_nan_answer(double x, double y) {
  int A = (y == 0);
  int B = IS_INF(x);
  int C = IS_INF(y);
  int D = (B && C && x != y);
  return (A || B || D);
}

long double MathFmod(double x, double y) {
  if (is_nan_answer(x, y)) {
    return NAN;
  }
  if (IS_INF(y)) {
    return (long double)x;
  }
  int n = x / y;
  long double res = (long double)x - n * (long double)y;
  return res;
}