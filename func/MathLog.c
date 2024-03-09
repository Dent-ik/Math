#include "../math.h"

long double MathLog(double x) {
  if (x == POS_INF) {
    return x;
  }
  if (x == 0) {
    return NEG_INF;
  }
  if (x < 0) {
    return NAN;
  }
  long double res = 0, count = 0;
  int count_e = 0;
  for (; x >= E; count_e++) {
    x /= E;
  }
  for (int i = 0; i < 1000; i++) {
    count = res;
    res = count + 2 * (x - MathExp(count)) / (x + MathExp(count));
  }
  res += count_e;
  return res;
}