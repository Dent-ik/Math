#include "../math.h"

long double MathFloor(double x) {
  if (IS_NAN(x) || IS_INF(x)) {
    return x;
  }
  int res = (int)x;
  res -= (x < 0 && (x - res));
  return (long double)res;
}