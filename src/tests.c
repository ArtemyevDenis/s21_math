#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_asin) {
  ck_assert_ldouble_nan(s21_asin(-1.000001));
  ck_assert_ldouble_nan(s21_asin(1.00000001));
  ck_assert_ldouble_nan(s21_asin(-132.000001));
  ck_assert_ldouble_nan(s21_asin(132.00000001));
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(-0), asin(-0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(-0.123456), asin(-0.123456), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(0.123456), asin(0.123456), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(0.45781), asin(0.45781), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(-0.45781), asin(-0.45781), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(0.999672), asin(0.999672), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(-0.999672), asin(-0.999672), 0.000001);
}
END_TEST

START_TEST(test_s21_atan) {
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(-0), atan(-0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(INF), atan(INF), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(-INF), atan(-INF), 0.000001);
  ;
  ck_assert_ldouble_eq_tol(s21_atan(-1234.123456), atan(-1234.123456),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(-0.123456), atan(-0.123456), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(140.45781), atan(140.45781), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(0.999672), atan(0.999672), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(-0.999672), atan(-0.999672), 0.000001);
}
END_TEST

START_TEST(test_s21_acos) {
  ck_assert_ldouble_nan(s21_acos(-1.000001));
  ck_assert_ldouble_nan(s21_acos(1.00000001));
  ck_assert_ldouble_nan(s21_acos(-132.000001));
  ck_assert_ldouble_nan(s21_acos(132.00000001));
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(-0), acos(-0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(-0.123456), acos(-0.123456), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(0.123456), acos(0.123456), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(0.45781), acos(0.45781), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(-0.45781), acos(-0.45781), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(0.999672), acos(0.999672), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(-0.999672), acos(-0.999672), 0.000001);
}
END_TEST

START_TEST(test_s21_fmod) {
  ck_assert_ldouble_nan(s21_fmod(INF, 10));
  ck_assert_ldouble_nan(s21_fmod(INF, -10));
  ck_assert_ldouble_nan(s21_fmod(-INF, 10.123));
  ck_assert_ldouble_nan(s21_fmod(-INF, -10.123));
  ck_assert_ldouble_nan(s21_fmod(10.123, -0));
  ck_assert_ldouble_nan(s21_fmod(-112.1234, 0));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, 0));
  ck_assert_ldouble_nan(s21_fmod(-112.1234, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, -112.1234));
  ck_assert_ldouble_nan(s21_fmod(112.1234, S21_NAN));
  ck_assert_ldouble_eq_tol(s21_fmod(10.123, INF), fmod(10.123, INF), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(1.123, -INF), fmod(1.123, -INF), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(-23.456, INF), fmod(-23.456, INF),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(-10.15678, -INF), fmod(-10.15678, -INF),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(0, 14), fmod(0, 14), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(-0, -14), fmod(-0, -14), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(-0, 0.124), fmod(-0, 0.124), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(0, -0.124), fmod(0, -0.124), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(10, 2), fmod(10, 2), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(-123, 0.124), fmod(-123, 0.124), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(56890.012344, 0.145678),
                           fmod(56890.012344, 0.145678), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(56890.012344, -0.145678),
                           fmod(56890.012344, -0.145678), 0.000001);
}
END_TEST

START_TEST(test_s21_pow) {
  ck_assert_ldouble_infinite(s21_pow(0, -3));
  ck_assert_ldouble_infinite(s21_pow(-0, -3));
  ck_assert_ldouble_infinite(s21_pow(0, -2));
  ck_assert_ldouble_infinite(s21_pow(-0, -0.3));
  ck_assert_ldouble_infinite(s21_pow(0, -0.3));
  ck_assert_ldouble_infinite(s21_pow(0, -INF));
  ck_assert_ldouble_infinite(s21_pow(0.3, -INF));
  ck_assert_ldouble_infinite(s21_pow(2.3, INF));
  ck_assert_ldouble_infinite(s21_pow(-INF, 5));
  ck_assert_ldouble_infinite(s21_pow(-INF, 4.3));
  ck_assert_ldouble_infinite(s21_pow(-INF, 4));
  ck_assert_ldouble_infinite(s21_pow(INF, 4));
  ck_assert_ldouble_nan(s21_pow(-4, 5.3));
  ck_assert_ldouble_nan(s21_pow(4, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, 4));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_eq_tol(s21_pow(0, 3), pow(0, 3), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-0, 3), pow(-0, 3), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(0, 2.3), pow(0, 2.3), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(0, 4), pow(0, 4), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-1, -INF), pow(-1, -INF), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-1, INF), pow(-1, INF), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(1, S21_NAN), pow(1, S21_NAN), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(1, INF), pow(1, INF), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(1, -INF), pow(1, -INF), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(1, 0.1245), pow(1, 0.1245), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(S21_NAN, 0), pow(S21_NAN, 0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(INF, 0), pow(INF, 0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-INF, 0), pow(-INF, 0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(0.123456, 0), pow(0.123456, 0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(2.3, -INF), pow(2.3, -INF), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(0.3, INF), pow(0.3, INF), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-INF, -3), pow(-INF, -3), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-INF, -0.4), pow(-INF, -0.4), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-INF, -4), pow(-INF, -4), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(INF, -3), pow(INF, -3), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(3, -3), pow(3, -3), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(100, -0.1234), pow(100, -0.1234), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-15, 2), pow(-15, 2), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-15, 3), pow(-15, 3), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(100, 0.12367), pow(100, 0.12367), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(15.2786, 6), pow(15.2786, 6), 0.000001);
}
END_TEST

START_TEST(test_s21_exp) {
  ck_assert_ldouble_infinite(s21_exp(INF));
  ck_assert_ldouble_infinite(s21_exp(710));
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_exp(-INF), exp(-INF), 0.000001);
  ck_assert_ldouble_eq_tol(s21_exp(-38), exp(-38), 0.000001);
  ck_assert_ldouble_eq_tol(s21_exp(-2), exp(-2), 0.000001);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_exp(0.127893), exp(0.127893), 0.000001);
  ck_assert_ldouble_eq_tol(s21_exp(10.1263), exp(10.1263), 0.000001);
  ck_assert_ldouble_eq_tol(s21_exp(23), exp(23), 0.000001);
}
END_TEST

START_TEST(test_s21_sqrt) {
  ck_assert_ldouble_infinite(s21_sqrt(INF));
  ck_assert_ldouble_infinite(s21_sqrt(-INF));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(-0.126884));
  ck_assert_ldouble_nan(s21_sqrt(-123));
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.146780), sqrt(0.146780), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sqrt(16.905435), sqrt(16.905435), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sqrt(26), sqrt(26), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sqrt(2048), sqrt(2048), 0.000001);
}
END_TEST

START_TEST(test_s21_log) {
  ck_assert_ldouble_nan(s21_log(-38));
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_infinite(s21_log(INF));
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_log(0.127893), log(0.127893), 0.000001);
  ck_assert_ldouble_eq_tol(s21_log(50.1263), log(50.1263), 0.000001);
  ck_assert_ldouble_eq_tol(s21_log(423), log(423), 0.000001);
}
END_TEST

START_TEST(test_s21_cos) {
  ck_assert_ldouble_nan(s21_cos(-INF));
  ck_assert_ldouble_nan(s21_cos(INF));
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_cos(-100), cos(-100), 0.000001);
  ck_assert_ldouble_eq_tol(s21_cos(-2.45678), cos(-2.45678), 0.000001);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_cos(1.123456), cos(1.123456), 0.000001);
  ck_assert_ldouble_eq_tol(s21_cos(100), cos(100), 0.000001);
}
END_TEST

START_TEST(test_s21_sin) {
  ck_assert_ldouble_nan(s21_sin(-INF));
  ck_assert_ldouble_nan(s21_sin(INF));
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_sin(-100), sin(-100), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sin(-2.45678), sin(-2.45678), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sin(-0), sin(-0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sin(1.123456), sin(1.123456), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sin(100), sin(100), 0.000001);
}
END_TEST

START_TEST(test_s21_abs) {
  ck_assert_int_eq(s21_abs(-100), abs(-100));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(100), abs(100));
}
END_TEST

START_TEST(test_s21_fabs) {
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
  ck_assert_ldouble_infinite(s21_fabs(INF));
  ck_assert_ldouble_eq_tol(s21_fabs(-100.1234536), fabs(-100.1234536),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fabs(945.1238475), fabs(945.1238475), 0.000001);
}
END_TEST

START_TEST(test_s21_ceil) {
  ck_assert_ldouble_infinite(s21_ceil(INF));
  ck_assert_ldouble_infinite(s21_ceil(-INF));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  ck_assert_ldouble_nan(s21_ceil(-S21_NAN));
  for (double i = -10; i < 10; i += 0.001) {
    ck_assert_double_eq_tol(s21_ceil(i), ceil(i), 0.000001);
  }
  ck_assert_double_eq_tol(s21_ceil(-12.0000000001), ceil(-12.0000000001),
                          0.000001);
  ck_assert_double_eq_tol(s21_ceil(-12.5000000001), ceil(-12.5000000001),
                          0.000001);
  ck_assert_double_eq_tol(s21_ceil(12.0000000001), ceil(12.0000000001),
                          0.000001);
  ck_assert_double_eq_tol(s21_ceil(12.0006000001), ceil(12.0006000001),
                          0.000001);
}
END_TEST

START_TEST(test_s21_floor) {
  for (double i = -10.1; i < 10; i += 0.001) {
    ck_assert_double_eq_tol(s21_floor(i), floor(i), 0.000001);
  }
  ck_assert_ldouble_infinite(s21_floor(INF));
  ck_assert_ldouble_infinite(s21_floor(-INF));
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
  ck_assert_ldouble_nan(s21_floor(-S21_NAN));
  ck_assert_double_eq_tol(s21_floor(-12.0000000001), floor(-12.0000000001),
                          0.000001);
  ck_assert_double_eq_tol(s21_floor(-12.5000000001), floor(-12.5000000001),
                          0.000001);
  ck_assert_double_eq_tol(s21_floor(12.0000000001), floor(12.0000000001),
                          0.000001);
  ck_assert_double_eq_tol(s21_floor(12.0006000001), floor(12.0006000001),
                          0.000001);
}
END_TEST

START_TEST(test_s21_tan) {
  ck_assert_ldouble_nan(s21_tan(INF));
  ck_assert_ldouble_nan(s21_tan(-INF));
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_nan(s21_tan(-S21_NAN));
  ck_assert_double_eq_tol(s21_tan(0), tan(0), 0.000001);
  ck_assert_double_eq_tol(s21_tan(-0), tan(-0), 0.000001);
  for (double i = -10; i < 10; i += 0.001) {
    ck_assert_double_eq_tol(s21_tan(i), tan(i), 0.000001);
  }
  ck_assert_double_eq_tol(s21_tan(-0.12345), tan(-0.12345), 0.000001);
  ck_assert_double_eq_tol(s21_tan(-256.16785), tan(-256.16785), 0.000001);
  ck_assert_double_eq_tol(s21_tan(0.6784), tan(0.6784), 0.000001);
  ck_assert_double_eq_tol(s21_tan(189.054731), tan(189.054731), 0.000001);
}
END_TEST

Suite *s21_math_suite_create(void) {
  Suite *suite = suite_create("math lib tests");
  TCase *tcase_core = tcase_create("Core of example");
  tcase_add_test(tcase_core, test_s21_cos);
  tcase_add_test(tcase_core, test_s21_abs);
  tcase_add_test(tcase_core, test_s21_sin);
  tcase_add_test(tcase_core, test_s21_fabs);
  tcase_add_test(tcase_core, test_s21_ceil);
  tcase_add_test(tcase_core, test_s21_floor);
  tcase_add_test(tcase_core, test_s21_tan);
  tcase_add_test(tcase_core, test_s21_exp);
  tcase_add_test(tcase_core, test_s21_log);
  tcase_add_test(tcase_core, test_s21_pow);
  tcase_add_test(tcase_core, test_s21_sqrt);
  tcase_add_test(tcase_core, test_s21_fmod);
  tcase_add_test(tcase_core, test_s21_acos);
  tcase_add_test(tcase_core, test_s21_atan);
  tcase_add_test(tcase_core, test_s21_asin);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_math_suite_create();
  SRunner *suiteRunner = srunner_create(suite);
  int failedCount = 0;

  srunner_run_all(suiteRunner, CK_NORMAL);
  failedCount = srunner_ntests_failed(suiteRunner);
  srunner_free(suiteRunner);

  if (failedCount != 0) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}