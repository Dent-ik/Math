#include "../math.h"

long double MathCeil(double x) {
  double res;
  if (x != x) {
    res = x;
  } else if (x == POS_INF) {
    res = POS_INF;
  } else if (x == NEG_INF) {
    res = NEG_INF;
  } else {
    res = (x - (long long int)x != 0 && x > 0) ? (long long int)x + 1
                                               : (long long int)x;
  }
  return res;
}