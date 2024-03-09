#include "math.h"

#include <check.h>
#include <math.h>
#include <stdlib.h>

START_TEST(abs_tests) {
  int inf_pos = 1.0 / 0.0;
  int inf_neg = -1.0 / 0.0;
  int nan = 0.0 / 0.0;

  ck_assert_int_eq(abs(-10), MathAbs(-10));
  ck_assert_int_eq(abs(-0), MathAbs(-0));
  ck_assert_int_eq(abs(-13), MathAbs(-13));
  ck_assert_int_eq(abs(13), MathAbs(13));
  ck_assert_int_eq(abs(-1000), MathAbs(-1000));
  ck_assert_int_eq(abs(32346234), MathAbs(32346234));
  ck_assert_int_eq(abs(0), MathAbs(0));
  ck_assert_int_eq(abs(inf_pos), MathAbs(inf_pos));
  ck_assert_int_eq(abs(inf_neg), MathAbs(inf_neg));
  ck_assert_int_eq(abs(inf_pos), MathAbs(inf_neg));
  ck_assert_int_eq(abs(nan), MathAbs(nan));
}
END_TEST

START_TEST(fabs_tests) {
  ck_assert_double_eq_tol(fabs(-13.21313), MathFabs(-13.21313), 1e-6);
  ck_assert_double_eq_tol(fabs(13.21313), MathFabs(13.21313), 1e-6);
  ck_assert_double_eq_tol(fabs(-1000.21313), MathFabs(-1000.21313), 1e-6);
  ck_assert_double_eq_tol(fabs(32346234.21313), MathFabs(32346234.21313), 1e-6);
  ck_assert_double_eq_tol(fabs(3.0), MathFabs(3.0), 1e-6);
  ck_assert_double_eq_tol(fabs(-3.0), MathFabs(-3.0), 1e-6);
  ck_assert_double_eq_tol(fabs(-0.0), MathFabs(-0.0), 1e-6);
  ck_assert_double_eq_tol(fabs(0.0), MathFabs(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(fabs(PI), MathFabs(PI), 1e-6);
  ck_assert_ldouble_eq_tol(fabs(PI_2), MathFabs(PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(fabs(PI_3), MathFabs(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(fabs(PI_6), MathFabs(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(fabs(PI_8), MathFabs(PI_8), 1e-6);
  ck_assert_double_infinite(MathFabs(NEG_INF));
  ck_assert_double_infinite(MathFabs(POS_INF));
  ck_assert_double_nan(MathFabs(NAN));
}
END_TEST

START_TEST(fmod_tests) {
  ck_assert_double_eq_tol(fmod(-13.21313, 2.5), MathFmod(-13.21313, 2.5), 1e-6);
  ck_assert_double_eq_tol(fmod(13.21313, 2.5), MathFmod(13.21313, 2.5), 1e-6);
  ck_assert_double_eq_tol(fmod(-1000.21313, 2.5), MathFmod(-1000.21313, 2.5),
                          1e-6);
  ck_assert_double_eq_tol(fmod(32346234.21313, 2.5),
                          fmod(32346234.21313, 2.5), 1e-6);
  ck_assert_double_eq_tol(fmod(0, 2.5), MathFmod(0, 2.5), 1e-6);
  ck_assert_double_eq_tol(fmod(2.5, 2.5), MathFmod(2.5, 2.5), 1e-6);
  ck_assert_double_eq_tol(fmod(+5.1, +3.0), MathFmod(+5.1, +3.0), 1e-6);

  ck_assert_double_eq_tol(fmod(-5.1, +3.0), MathFmod(-5.1, +3.0), 1e-6);
  ck_assert_double_eq_tol(fmod(+5.1, -3.0), MathFmod(+5.1, -3.0), 1e-6);
  ck_assert_double_eq_tol(fmod(-5.1, -3.0), MathFmod(-5.1, -3.0), 1e-6);
  ck_assert_double_eq_tol(fmod(+0.0, 1.0), MathFmod(+0.0, 1.0), 1e-6);
  ck_assert_double_eq_tol(fmod(-0.0, 1.0), MathFmod(-0.0, 1.0), 1e-6);
  ck_assert_double_eq_tol(fmod(5.1, NEG_INF), MathFmod(5.1, NEG_INF),
                          1e-6);
  ck_assert_ldouble_nan(fmod(+5.1, 0));
  ck_assert_ldouble_eq_tol(fmod(PI, 3.222), MathFmod(PI, 3.222), 1e-6);
  ck_assert_ldouble_eq_tol(fmod(PI_2, 3.222), MathFmod(PI_2, 3.222),
                           1e-6);
  ck_assert_ldouble_eq_tol(fmod(PI_6, 3.222), MathFmod(PI_6, 3.222),
                           1e-6);
  ck_assert_ldouble_eq_tol(fmod(PI_8, 3.222), MathFmod(PI_8, 3.222),
                           1e-6);
  ck_assert_double_nan(MathFmod(NEG_INF, NEG_INF));
  ck_assert_double_nan(MathFmod(POS_INF, POS_INF));
  ck_assert_double_nan(MathFmod(POS_INF, NEG_INF));
  ck_assert_double_nan(MathFmod(NAN, POS_INF));
  ck_assert_ldouble_nan(MathFmod(POS_INF, NEG_INF));
  ck_assert_ldouble_nan(MathFmod(NEG_INF, NAN));
}
END_TEST

START_TEST(pow_tests) {
  ck_assert_double_eq_tol(pow(3404.21313, 2.5), MathPow(3404.21313, 2.5), 1e-6);
  ck_assert_double_eq_tol(pow(0, 2.5), MathPow(0, 2.5), 1e-6);
  ck_assert_double_eq_tol(pow(123, -2), MathPow(123, -2), 1e-6);
  ck_assert_ldouble_eq_tol(pow(PI, 3), MathPow(PI, 3), 1e-6);
  ck_assert_ldouble_eq_tol(pow(PI_2, 3), MathPow(PI_2, 3), 1e-6);
  ck_assert_ldouble_eq_tol(pow(PI_3, 3), MathPow(PI_3, 3), 1e-6);
  ck_assert_ldouble_eq_tol(pow(PI_6, 3), MathPow(PI_6, 3), 1e-6);
  ck_assert_ldouble_eq_tol(pow(PI_8, 3), MathPow(PI_8, 3), 1e-6);
  ck_assert_ldouble_eq_tol(pow(NEG_INF, 0.0), MathPow(NEG_INF, 0.0),
                           1e-6);
  ck_assert_double_infinite(MathPow(-0.0, -1.0));
  ck_assert_ldouble_eq_tol(pow(-1, POS_INF), MathPow(-1, POS_INF),
                           1e-6);
  ck_assert_double_infinite(MathPow(-0.0, NEG_INF));
  ck_assert_double_infinite(MathPow(NEG_INF, 5));
  ck_assert_double_infinite(MathPow(NEG_INF, 1));
  ck_assert_double_nan(MathPow(NEG_INF, NAN));
  ck_assert_double_eq(MathPow(NEG_INF, -1), 0);
  ck_assert_double_infinite(MathPow(POS_INF, 2));
  ck_assert_ldouble_eq(MathPow(POS_INF, NEG_INF), 0);
  ck_assert_double_eq(MathPow(-3.3, NEG_INF), 1); 
  ck_assert_double_eq(MathPow(NEG_INF, NEG_INF), 0);
  ck_assert_double_nan(MathPow(NAN, POS_INF));
  ck_assert_double_nan(MathPow(-13.21313, 2.5));
  ck_assert_double_eq(MathPow(POS_INF, NEG_INF), 0);
  ck_assert_double_eq_tol(pow(2, 10), MathPow(2, 10), 1e-6);
  ck_assert_double_eq_tol(pow(2, 0.5), MathPow(2, 0.5), 1e-6);
  ck_assert_double_eq_tol(pow(-2, -3), MathPow(-2, -3), 1e-6);
  ck_assert_double_nan(MathPow(-1, NAN));
  ck_assert_double_eq_tol(pow(+1, NAN), MathPow(+1, NAN), 1e-6);
  ck_assert_double_infinite(MathPow(NEG_INF, 2));
  ck_assert_double_eq_tol(pow(NEG_INF, -1), MathPow(NEG_INF, -1), 1e-6);
  ck_assert_double_eq_tol(pow(-1, 1 / 3), MathPow(-1, 1 / 3), 1e-6);
  ck_assert_double_infinite(MathPow(-0, -3));
}
END_TEST

START_TEST(ceil_tests) {
  ck_assert_double_eq_tol(ceil(-13.54), MathCeil(-13.54), 1e-6);
  ck_assert_double_eq_tol(ceil(13.54), MathCeil(13.54), 1e-6);
  ck_assert_double_eq_tol(ceil(1000), MathCeil(1000), 1e-6);
  ck_assert_double_eq_tol(ceil(102.0000002), MathCeil(102.0000002), 1e-6);
  ck_assert_ldouble_eq_tol(ceil(PI), MathCeil(PI), 1e-6);
  ck_assert_ldouble_eq_tol(ceil(PI_2), MathCeil(PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(ceil(PI_3), MathCeil(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(ceil(PI_6), MathCeil(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(ceil(PI_8), MathCeil(PI_8), 1e-6);
  ck_assert_ldouble_eq_tol(ceil(-0.0), MathCeil(-0.0), 1e-6);
  ck_assert_double_nan(MathCeil(NAN));
  ck_assert_double_infinite(MathCeil(NEG_INF));
  ck_assert_double_infinite(MathCeil(POS_INF));
}
END_TEST

START_TEST(floor_tests) {
  ck_assert_double_eq_tol(floor(-13.54), MathFloor(-13.54), 1e-6);
  ck_assert_double_eq_tol(floor(13.54), MathFloor(13.54), 1e-6);
  ck_assert_double_eq_tol(floor(1000), MathFloor(1000), 1e-6);
  ck_assert_double_eq_tol(floor(102.0000002), MathFloor(102.0000002), 1e-6);
  ck_assert_ldouble_eq_tol(floor(PI), MathFloor(PI), 1e-6);
  ck_assert_ldouble_eq_tol(floor(PI_2), MathFloor(PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(floor(PI_3), MathFloor(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(floor(PI_6), MathFloor(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(floor(PI_8), MathFloor(PI_8), 1e-6);
  ck_assert_ldouble_eq_tol(floor(-0.0), floor(-0.0), 1e-6);
  ck_assert_double_nan(floor(NAN));
  ck_assert_double_infinite(MathFloor(NEG_INF));
  ck_assert_double_infinite(MathFloor(POS_INF));
}
END_TEST

START_TEST(exp_tests) {
  ck_assert_double_eq_tol(exp(-13.54), MathExp(-13.54), 1e-6);
  ck_assert_double_eq_tol(exp(13.54), MathExp(13.54), 1e-6);
  ck_assert_double_eq_tol(exp(-0.54), MathExp(-0.54), 1e-6);
  ck_assert_double_eq_tol(exp(705), MathExp(705), 1e-6);
  ck_assert_double_eq_tol(exp(1), MathExp(1), 1e-6);
  ck_assert_double_eq_tol(exp(2), MathExp(2), 1e-6);
  ck_assert_double_eq_tol(exp(-1), MathExp(-1), 1e-6);
  ck_assert_double_eq_tol(exp(0), MathExp(0), 1e-6);
  ck_assert_double_eq_tol(exp(700), MathExp(700), 1e-6);
  ck_assert_double_eq_tol(exp(1.2345), MathExp(1.2345), 1e-6);
  ck_assert_double_eq_tol(exp(1.23454656768), MathExp(1.23454656768), 1e-6);
  ck_assert_ldouble_eq_tol(exp(PI), MathExp(PI), 1e-6);
  ck_assert_ldouble_eq_tol(exp(PI_2), MathExp(PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(exp(PI_3), MathExp(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(exp(PI_6), MathExp(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(exp(PI_8), MathExp(PI_8), 1e-6);
  ck_assert_double_infinite(MathExp(MAX_LONG_DOUBLE));
  ck_assert_float_eq(exp(MAX_LONG_DOUBLE), MathExp(MAX_LONG_DOUBLE));
  ck_assert_double_nan(MathExp(NAN));
  ck_assert_ldouble_eq_tol(exp(NEG_INF), MathExp(NEG_INF), 1e-6);
  ck_assert_ldouble_eq_tol(exp(E), MathExp(E), 1e-6);
  ck_assert_ldouble_eq(exp(-0), MathExp(-0));
  ck_assert_double_infinite(MathExp(POS_INF));
  ck_assert_double_infinite(MathExp(710));
}
END_TEST

START_TEST(sin_tests) {
  ck_assert_double_eq_tol(sin(-13.54), MathSin(-13.54), 1e-6);
  ck_assert_double_eq_tol(sin(13.54), MathSin(13.54), 1e-6);
  ck_assert_double_eq_tol(sin(0.0), MathSin(0.0), 1e-6);
  ck_assert_double_eq_tol(sin(-0.0), MathSin(-0.0), 1e-6);
  ck_assert_double_eq_tol(sin(+0.0), MathSin(+0.0), 1e-6);
  ck_assert_double_eq_tol(sin(1.0), MathSin(1.0), 1e-6);
  ck_assert_double_eq_tol(sin(2.5), MathSin(2.5), 1e-6);
  ck_assert_double_eq_tol(sin(6.28), MathSin(6.28), 1e-6);
  ck_assert_double_eq_tol(sin(2.2343), MathSin(2.2343), 1e-6);
  ck_assert_double_eq_tol(sin(0.1234), MathSin(0.1234), 1e-6);
  ck_assert_double_eq_tol(sin(PI), MathSin(PI), 1e-6);
  ck_assert_double_eq_tol(sin(PI_2), MathSin(PI_2), 1e-6);
  ck_assert_double_eq_tol(sin(PI_3), MathSin(PI_3), 1e-6);
  ck_assert_double_eq_tol(sin(PI_4), MathSin(PI_4), 1e-6);
  ck_assert_double_eq_tol(sin(-3 * PI_4), MathSin(-3 * PI_4), 1e-6);
  ck_assert_double_eq_tol(sin(PI_6), MathSin(PI_6), 1e-6);
  ck_assert_double_eq_tol(sin(PI_8), MathSin(PI_8), 1e-6);
  ck_assert_double_nan(MathSin(NAN));
  ck_assert_double_nan(MathSin(NEG_INF));
  ck_assert_double_infinite(MathSin(POS_INF));
}
END_TEST

START_TEST(cos_tests) {
  ck_assert_double_eq_tol(cos(-13.54), MathCos(-13.54), 1e-6);
  ck_assert_double_eq_tol(cos(13.54), MathCos(13.54), 1e-6);
  ck_assert_double_eq_tol(cos(0.0), MathCos(0.0), 1e-6);
  ck_assert_double_eq_tol(cos(+0.0), MathCos(+0.0), 1e-6);
  ck_assert_double_eq_tol(cos(-0.0), MathCos(-0.0), 1e-6);
  ck_assert_double_eq_tol(cos(1.0), MathCos(1.0), 1e-6);
  ck_assert_double_eq_tol(cos(2.5), MathCos(2.5), 1e-6);
  ck_assert_double_eq_tol(cos(6.28), MathCos(6.28), 1e-6);
  ck_assert_double_eq_tol(cos(2.2343), MathCos(2.2343), 1e-6);
  ck_assert_double_eq_tol(cos(0.1234), MathCos(0.1234), 1e-6);
  ck_assert_ldouble_eq_tol(cos(PI), MathCos(PI), 1e-6);
  ck_assert_ldouble_eq_tol(
      cos(PI_2), MathCos(PI_2),
      1e-6);    
  ck_assert_ldouble_eq_tol(cos(PI_3), MathCos(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(cos(-3 * PI_4), MathCos(-3 * PI_4), 1e-6);
  ck_assert_ldouble_eq_tol(cos(PI_4), MathCos(PI_4), 1e-6);
  ck_assert_ldouble_eq_tol(cos(PI_6), MathCos(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(cos(PI_8), MathCos(PI_8), 1e-6);
  ck_assert_double_nan(MathCos(NAN));
  ck_assert_double_infinite(MathCos(NEG_INF));
  ck_assert_double_nan(MathCos(POS_INF));
}
END_TEST

START_TEST(tan_tests) {
  ck_assert_double_eq_tol(tan(-13.54), MathTan(-13.54), 1e-6);
  ck_assert_double_eq_tol(tan(13.54), MathTan(13.54), 1e-6);
  ck_assert_double_eq_tol(tan(-0.0), MathTan(-0.0), 1e-6);
  ck_assert_double_eq_tol(tan(0.0), MathTan(0.0), 1e-6);
  ck_assert_double_eq_tol(tan(+0.0), MathTan(+0.0), 1e-6);
  ck_assert_double_eq_tol(tan(1.0), MathTan(1.0), 1e-6);
  ck_assert_double_eq_tol(tan(2.5), MathTan(2.5), 1e-6);
  ck_assert_double_eq_tol(tan(6.28), MathTan(6.28), 1e-6);
  ck_assert_double_eq_tol(tan(2.2343), MathTan(2.2343), 1e-6);
  ck_assert_double_eq_tol(tan(0.1234), MathTan(0.1234), 1e-6);
  ck_assert_ldouble_eq_tol(tan(1 * PI_4), MathTan(1 * PI_4), 1e-6);
  ck_assert_ldouble_eq_tol(tan(3 * PI_4), MathTan(3 * PI_4), 1e-6);
  ck_assert_ldouble_eq_tol(tan(5 * PI_4), MathTan(5 * PI_4), 1e-6);
  ck_assert_ldouble_eq_tol(tan(7 * PI_4), MathTan(7 * PI_4), 1e-6);
  ck_assert_double_eq_tol(tan(PI), MathTan(PI), 1e-06);
  ck_assert_ldouble_eq_tol(tan(PI_3), MathTan(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(tan(PI_6), MathTan(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(tan(PI_8), MathTan(PI_8), 1e-6);
  ck_assert_double_nan(MathTan(NAN));
  ck_assert_double_nan(MathTan(POS_INF));
  ck_assert_double_nan(MathTan(NEG_INF));
}
END_TEST

START_TEST(sqrt_tests) {
  ck_assert_double_eq_tol(sqrt(0.0), MathSqrt(0.0), 1e-6);
  ck_assert_double_eq_tol(sqrt(-0.0), MathSqrt(-0.0), 1e-6);
  ck_assert_double_eq_tol(sqrt(1.0), MathSqrt(1.0), 1e-6);
  ck_assert_double_eq_tol(sqrt(2), MathSqrt(2), 1e-6);
  ck_assert_double_eq_tol(sqrt(3.14), MathSqrt(3.14), 1e-6);
  ck_assert_double_eq_tol(sqrt(6.28), MathSqrt(6.28), 1e-6);
  ck_assert_double_eq_tol(sqrt(2.2343), MathSqrt(2.2343), 1e-6);
  ck_assert_double_eq_tol(sqrt(PI), MathSqrt(PI), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(PI_2), MathSqrt(PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(PI_3), MathSqrt(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(PI_6), MathSqrt(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(sqrt(PI_8), MathSqrt(PI_8), 1e-6);
  ck_assert_double_nan(MathSqrt(-1));
  ck_assert_double_nan(MathSqrt(NEG_INF));
  ck_assert_double_infinite(MathSqrt(POS_INF));
  ck_assert_double_nan(MathSqrt(NAN));
}

START_TEST(log_tests) {
  ck_assert_double_eq_tol(log(13.54), MathLog(13.54), 1e-6);
  ck_assert_float_eq(log(0.0), MathLog(0.0));
  ck_assert_double_eq_tol(log(1.0), MathLog(1.0), 1e-6);
  ck_assert_double_eq_tol(log(3.14), MathLog(3.14), 1e-6);
  ck_assert_double_eq_tol(log(6.28), MathLog(6.28), 1e-6);
  ck_assert_double_eq_tol(log(2.2343), MathLog(2.2343), 1e-6);
  ck_assert_double_eq_tol(log(0.1234), MathLog(0.1234), 1e-6);
  ck_assert_ldouble_eq_tol(log(PI), MathLog(PI), 1e-6);
  ck_assert_ldouble_eq_tol(log(PI_2), MathLog(PI_2), 1e-6);
  ck_assert_ldouble_eq_tol(log(PI_3), MathLog(PI_3), 1e-6);
  ck_assert_ldouble_eq_tol(log(PI_6), MathLog(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(log(PI_8), MathLog(PI_8), 1e-6);
  ck_assert_double_nan(MathLog(NAN));
  ck_assert_ldouble_eq_tol(log(1), MathLog(1), 1e-6);
  ck_assert_double_nan(MathLog(-1));
  ck_assert_double_infinite(MathLog(POS_INF));
  ck_assert_double_infinite(MathLog(0));
}
END_TEST

START_TEST(asin_tests) {
  ck_assert_double_eq_tol(asin(EPS10), MathAsin(EPS10), 1e-6);
  ck_assert_double_eq_tol(asin(0.1234), MathAsin(0.1234), 1e-6);
  ck_assert_double_eq_tol(asin(0.0), MathAsin(0.0), 1e-6);
  ck_assert_double_nan(MathAsin(1.1));
  ck_assert_double_eq_tol(asin(1), MathAsin(1), 1e-6);
  ck_assert_double_eq_tol(asin(-1), MathAsin(-1), 1e-6);
  ck_assert_double_eq_tol(asin(0.5), MathAsin(0.5), 1e-6);
  ck_assert_double_eq_tol(asin(-0.5), MathAsin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(asin(PI_6), MathAsin(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(asin(PI_8), MathAsin(PI_8), 1e-6);
  ck_assert_double_nan(MathAsin(NAN));
  ck_assert_double_nan(MathAsin(-13.54));
  ck_assert_double_nan(MathAsin(PI));
  ck_assert_double_nan(MathAsin(PI_2));
  ck_assert_double_nan(MathAsin(PI_3));
  ck_assert_double_nan(MathAsin(NEG_INF));
  ck_assert_double_nan(MathAsin(POS_INF));
}
END_TEST

START_TEST(acos_tests) {
  ck_assert_double_eq_tol(acos(EPS10), MathAcos(EPS10), 1e-6);
  ck_assert_double_eq_tol(acos(0.1234), MathAcos(0.1234), 1e-6);
  ck_assert_double_eq_tol(acos(0), MathAcos(0), 1e-6);
  ck_assert_double_eq_tol(acos(1), MathAcos(1), 1e-6);
  ck_assert_double_eq_tol(acos(-1), MathAcos(-1), 1e-6);
  ck_assert_double_eq_tol(acos(0.5), MathAcos(0.5), 1e-6);
  ck_assert_double_eq_tol(acos(-0.5), MathAcos(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(acos(PI_4), MathAcos(PI_4), 1e-6);
  ck_assert_ldouble_eq_tol(acos(PI_6), MathAcos(PI_6), 1e-6);
  ck_assert_ldouble_eq_tol(acos(PI_8), MathAcos(PI_8), 1e-6);
  ck_assert_double_nan(MathAcos(13.54));
  ck_assert_double_nan(MathAcos(NAN));
  ck_assert_double_nan(MathAcos(PI));
  ck_assert_double_nan(MathAcos(PI_2));
  ck_assert_double_nan(MathAcos(NEG_INF));
  ck_assert_double_nan(MathAcos(POS_INF));
}
END_TEST

START_TEST(atan_tests) {
  ck_assert_double_eq_tol(atan(-13.54), MathAtan(-13.54), 1e-6);
  ck_assert_double_eq_tol(atan(13.54), MathAtan(13.54), 1e-6);
  ck_assert_double_eq_tol(atan(3.14), MathAtan(3.14), 1e-6);
  ck_assert_double_eq_tol(atan(6.28), MathAtan(6.28), 1e-6);
  ck_assert_double_eq_tol(atan(2.234), MathAtan(2.234), 1e-6);
  ck_assert_double_eq_tol(atan(0.1234), MathAtan(0.1234), 1e-6);
  ck_assert_double_eq_tol(atan(0.0), MathAtan(0.0), 1e-6);
  ck_assert_double_eq_tol(atan(1), MathAtan(1), 1e-6);
  ck_assert_double_eq_tol(atan(-1), MathAtan(-1), 1e-6);
  ck_assert_double_eq_tol(atan(3.5), MathAtan(3.5), 1e-6);
  ck_assert_double_eq_tol(atan(0.5), MathAtan(0.5), 1e-6);
  ck_assert_double_eq_tol(atan(-3.5), MathAtan(-3.5), 1e-6);
  ck_assert_ldouble_eq_tol(atan(PI), MathAtan(PI), 1e-6);
  ck_assert_ldouble_eq_tol(atan(PI_8), MathAtan(PI_8), 1e-6);
  ck_assert_double_nan(MathAtan(NAN));
  ck_assert_double_infinite(MathAtan(NEG_INF));
  ck_assert_double_infinite(MathAtan(POS_INF));
}
END_TEST

Suite *math_tests_create() {
  Suite *math = suite_create("math");
  TCase *math_tests = tcase_create("MATH");
  tcase_add_test(math_tests, ceil_tests);
  tcase_add_test(math_tests, floor_tests);
  tcase_add_test(math_tests, exp_tests);
  tcase_add_test(math_tests, sin_tests);
  tcase_add_test(math_tests, cos_tests);
  tcase_add_test(math_tests, tan_tests);
  tcase_add_test(math_tests, abs_tests);
  tcase_add_test(math_tests, fabs_tests);
  tcase_add_test(math_tests, fmod_tests);
  tcase_add_test(math_tests, pow_tests);
  tcase_add_test(math_tests, sqrt_tests);
  tcase_add_test(math_tests, log_tests);
  tcase_add_test(math_tests, asin_tests);
  tcase_add_test(math_tests, acos_tests);
  tcase_add_test(math_tests, atan_tests);
  suite_add_tcase(math, math_tests);
  return math;
}

int main() {
  Suite *math = math_tests_create();
  SRunner *math_runner = srunner_create(math);
  float number_failed;
  srunner_run_all(math_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(math_runner);
  srunner_free(math_runner);

  return number_failed == 0 ? 0 : 1;
}