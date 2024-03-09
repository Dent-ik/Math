#ifndef MATH_H_
#define MATH_H_
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define POS_INF +1.0 / 0.0
#define NEG_INF -1.0 / 0.0
#define NAN 0.0 / 0.0
#define IS_NAN(x) (x != x)
#define LN2 0.69314718055994530941
#define E 2.7182818284590452353602874
#define IS_INF(x) (x == NEG_INF || x == POS_INF)
#define ISNAN(x) (!(x >= 0) && !(x < 0))

#define PI 3.14159265358979323846264338327950288
#define PI_2 PI / 2
#define PI_3 PI / 3
#define PI_4 PI / 4
#define PI_6 PI / 6
#define PI_8 PI / 8
#define PI_X2 PI * 2
#define PI_X4 PI * 4
#define PI_X8 PI * 8
#define EPS10 0.0000000001
#define MAX_LONG_DOUBLE 1.79769313486231571e+308

int MathAbs(int x);
long double MathAcos(double x);
long double MathAsin(double x);
long double MathAtan(double x);
long double MathCeil(double x);
long double MathAcos(double x);
long double MathExp(double x);
long double MathCos(double x);
long double MathFabs(double x);
long double MathFloor(double x);
long double MathFmod(double x, double y);
long double MathLog(double x);
long double MathPow(double base, double exp);
long double MathSin(double x);
long double MathSqrt(double x);
long double MathTan(double x);
long double MathPowInt(double base, double exp);
long double MathFactorial(long long int x);
int is_nan_answer(double x, double y);

#endif