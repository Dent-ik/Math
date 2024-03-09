#include "../math.h"

long double MathSqrt(double x) {
  long double res = MathPow(x, 0.5);
  if (IS_NAN(x) || x == NEG_INF || x < 0) {
    res = NAN;
  }
  if (x == POS_INF || x == 0) {
    res = (long double)x;
  }
  return res;
}