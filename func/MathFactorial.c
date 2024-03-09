#include "../math.h"

long double MathFactorial(long long int x) {
  if (x == 1 || x == 0) return 1;
  if (x < 0) return POS_INF;

  long double res = x * MathFactorial(x - 1);

  return res;
}