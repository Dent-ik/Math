#include "../math.h"

long double MathAtan(double x) {
  long double res = 0;
  if (x == POS_INF) {
    res = POS_INF;
  }
  if (x == NEG_INF) {
    res = NEG_INF;
  }
  if (x == 1) {
    res = PI / 4;
  }
  if (x == -1) {
    res = -PI / 4;
  }
  if (x != x) {
    res = x;
  }
  if (res == 0) {
    int is_a_range = (x > -1 && x < 1);
    res = is_a_range ? x : 1.0 / x;
    for (int i = 1; i < 7000; i++) {
      double a = MathPowInt(-1, i);
      double b = MathPowInt(x, (1 + 2 * i) * (is_a_range ? 1 : -1));
      double c = 1 + 2 * i;
      res += a * b / c;
    }
    if (!is_a_range) res = (PI * MathFabs(x) / (2 * x)) - res;
  }
  return res;
}
