#include "../math.h"

long double MathAsin(double x) {
  long double res = NAN;
  if (x == 0) {
    return 0;
  }

  if (x > 1 || x < -1) {
    return res;
  }
  if (x == 1 || x == -1) {
    res = PI / (2 * x);
  }
  if (x > -1 && x < 1) {
    res = PI / 2 - MathAcos(x);
  }
  return res;
}
