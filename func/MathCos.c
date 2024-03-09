#include "../math.h"

long double MathCos(double x) {
  long double res = NAN;
  if (x != POS_INF || x != NEG_INF || !IS_NAN(x)) {
    res = MathSin(PI / 2 - x);
  }
  return res;
}