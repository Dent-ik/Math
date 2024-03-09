#include "../math.h"

long double MathPowInt(double base, double exp) {
  long double res = 1;
  int sign = (exp > 0);
  exp *= sign ? 1 : -1;
  for (long long int i = 0; i < exp; i++) {
    res = sign ? res * base : res / base;
  }
  return res;
}