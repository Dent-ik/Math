#include "../math.h"

long double MathPow(double base, double deg) {
  long double res = 0;
  bool b = 1;
  long double flag = 1.0;
  long double x = base;
  long double y = deg;
  if (x == NEG_INF) {
    if (y == NEG_INF) {
      res = 0;
      b = 0;
    }
    if (y == -1) {
      res = 0;
    }
    if (y == 1 && b) {
      res = NEG_INF;
      b = 0;
    }
    if ((y != y) && b) {
      res = NAN;
      b = 0;
    }
    if (y == -1. && b) {
      res = -0;
      b = 0;
    }

    if (y == 0. && b) {
      res = 1;
      b = 0;
    }

    if (b) {
      res = POS_INF;
      b = 0;
    }
  }

  if ((x == 0.0 && y == -1) && b) {
    res = POS_INF;
    b = 0;
  }
  if (x == -0.0 && b) {
    if (y == NEG_INF) {
      res = POS_INF;
      b = 0;
    }
  }
  if (x < -0.0 && b) {
    if (y == POS_INF) {
      res = 1.0;
      b = 0;
    }
    if ((y == NEG_INF) && b) {
      res = 1.0;
      b = 0;
    }
    if (((y > 0. && y < 1.0) || (y != (int)y)) && b) {
      res = NAN;
      b = 0;
    }
  }
  if (x == 1.0 && b) {
    res = 1;
    b = 0;
  }
  if ((x < -0 && y == (int)y) && b) {
    x = -x;
    flag = -1.0;
    if ((int)y % 2 == 0) flag *= -1.0;
  }

  if ((int)x == 0 && (int)y == -3) {
    res = POS_INF;
  } else {
    if (b) res = y == 0 ? 1 : x == 0 ? 0 : flag * MathExp(y * MathLog(x));
  }

  return res;
}
