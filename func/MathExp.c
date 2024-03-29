#include "../math.h"

long double MathExp(double x) {
  long double res = 1;
  if (x == 0) {
    res = 1;
  } else if (x < -20) {
    res = 0;
  } else if (x != x) {
    res = NAN;
  } else if (x > 706) {
    res = POS_INF;
  } else {
    double x0 = x;
    if (x0 < 0) x0 = -x0;
    long double temp = 1;
    long double num = x0;
    long double i = 1;
    while (temp > 1e-17) {
      temp *= num / i;
      res += temp;

      ++i;
    }
    if (x < 0) {
      res = 1 / res;
    }
  }
  return res;
}