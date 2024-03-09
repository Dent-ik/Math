#include "../math.h"

long double MathAcos(double x) {
  long double res = NAN;
  if (x == 0) {
    return PI_2;
  }
  if (x < 1 && x >= 0) res = MathAtan(MathSqrt(1 - x * x) / x);
  if (x < 0 && x > -1) res = PI + MathAtan(MathSqrt(1 - x * x) / x);
  if (x == 1) res = 0;
  if (x == -1) res = PI;
  return res;
}