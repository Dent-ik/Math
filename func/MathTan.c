#include "../math.h"

long double MathTan(double x) {
  x = MathFmod(x, PI);
  long double res = MathCos(x);
  return !res ? NAN : MathSin(x) / res;
}
