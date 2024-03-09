#include "../math.h"

long double MathSin(double x) {
  long double res = 0.0;
  if (ISNAN(x)) {
    res = NAN;
  } else if (x == POS_INF) {
    return POS_INF;
  } else {
    x = MathFmod(x, 2 * PI);
    for (int i = 0; i < 15; i++) {
      res += MathPowInt(-1, i) * MathPowInt(x, 2 * i + 1) /
             MathFactorial(2 * i + 1);
    }
  }
  return res;
}
