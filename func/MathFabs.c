#include "../math.h"

long double MathFabs(double x) {
  if (x < 0) {
    x = -x;
  }
  return (long double)x;
}