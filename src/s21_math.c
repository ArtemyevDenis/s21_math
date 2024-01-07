#include "s21_math.h"

int IsInt(double x) { return x == (int64_t)x; }

long double HelpPow(double x, int count) {
  long double res = 1.0;
  for (int i = 0; i < count; i++) res *= x;
  return res;
}

long double s21_fabs(double x) {
  long double res = 0.0;
  if (x == INF)
    res = INF;
  else if (x != x)
    res = S21_NAN;
  else
    res = x < 0 ? -x : x;
  return res;
}

double Phactorial(int n) {
  long double rez = 1.0;
  if (n == 0 || n == 1)
    rez = 1;
  else
    for (int i = 1; i <= n; i++) rez *= i;
  return rez;
}

long double s21_exp(double x) {
  long double res = 1.0;
  if (x != x)
    res = S21_NAN;
  else if (x >= 709.8)
    res = INF;
  else if (x <= -708.4)
    res = 0;
  else {
    long double power = 1, phac = 1, change = s21_fabs(x);
    for (int i = 1; i < 400; i++) {
      power *= change;
      phac *= i;
      res += power / phac;
    }
    if (x < 0) res = 1 / res;
  }
  return res;
}

long double s21_log(double x) {
  long double res = 0.0;
  if (x == 0) {
    res = -INF;
  } else if (x == INF)
    res = INF;
  else if (x > 0) {
    long double oldSum = 0.0;
    long double chisl = (x - 1) / (x + 1);
    long double chisl2 = chisl * chisl;
    long double znam = 1.0;
    long double tempChisl = chisl;
    res = chisl;
    while (res != oldSum) {
      oldSum = res;
      znam += 2.0;
      tempChisl *= chisl2;
      res += tempChisl / znam;
    }
    res *= 2.0;
  } else {
    res = S21_NAN;
  }
  return res;
}

long double s21_pow(double base, double exp_) {
  long double res = 0;
  int isInteger = IsInt(exp_);
  if (base == +0 && s21_fabs(s21_fmod(exp_, 2)) == 1 && isInteger == 1 &&
      exp_ < 0)
    res = 1 / 0.0;
  else if (base == -0 && s21_fabs(s21_fmod(exp_, 2)) == 1 && isInteger == 1 &&
           exp_ < 0)
    res = S21_NAN;
  else if (s21_fabs(base) == 0 && exp_ < 0 && exp_ > -INF &&
           ((s21_fabs(s21_fmod(exp_, 2)) == 0 && isInteger == 1) ||
            isInteger == 0))
    res = INF;
  else if (s21_fabs(base) == 0 && exp_ == -INF)
    res = INF;
  else if (base == +0 && exp_ > 0 && s21_fmod(exp_, 2) == 1 && isInteger == 1)
    res = +0;
  else if (base == -0 && exp_ > 0 && s21_fmod(exp_, 2) == 1 && isInteger == 1)
    res = -0;
  else if (s21_fabs(base) == 0 &&
           ((exp_ > 0 && s21_fmod(exp_, 2) == 0 && isInteger == 1) ||
            (exp_ > 0 && isInteger == 0)))
    res = +0;
  else if (base == -1 && (exp_ == -INF || exp_ == INF))
    res = 1;
  else if (base > -INF && base < 0 && exp_ > -INF && exp_ < INF &&
           isInteger == 0)
    res = S21_NAN;
  else if ((exp_ == -INF && s21_fabs(base) < 1) ||
           (exp_ == INF && s21_fabs(base) > 1))
    res = INF;
  else if ((exp_ == -INF && s21_fabs(base) > 1) ||
           (exp_ == INF && s21_fabs(base) < 1))
    res = +0;
  else if (base == -INF && exp_ < 0 && s21_fabs(s21_fmod(exp_, 2)) == 1 &&
           isInteger == 1)
    res = -0;
  else if (base == -INF && exp_ < 0 &&
           (isInteger == 0 || (s21_fmod(exp_, 2) == 0 && isInteger == 1)))
    res = +0;
  else if (base == -INF && exp_ > 0 && s21_fmod(exp_, 2) == 1 && isInteger == 1)
    res = -INF;
  else if (base == -INF && exp_ > 0 &&
           (isInteger == 0 || (s21_fmod(exp_, 2) == 0 && isInteger == 1)))
    res = INF;
  else if (base == INF && exp_ < 0)
    res = +0;
  else if (base == INF && exp_ > 0)
    res = INF;
  else if (base == 1)
    res = 1;
  else if (s21_fabs(exp_) == 0)
    res = 1;
  else if (base != base || exp_ != exp_)
    res = S21_NAN;
  else if (s21_fmod(exp_, 2) == 0 && base < 0)
    res = s21_exp(s21_log(-base) * exp_);
  else if ((s21_fmod(exp_, 2) != 0 && base < 0))
    res = -s21_exp(s21_log(-base) * exp_);
  else
    res = s21_exp(s21_log(base) * exp_);
  return res;
}

long double s21_sqrt(double x) {
  long double res = 0;
  if (x != x)
    res = S21_NAN;
  else if (x == -INF)
    res = -INF;
  else if (x == INF)
    res = INF;
  else if (x > 0) {
    res = s21_pow(x, 0.5);
  } else if (x == 0)
    res = 0;
  else {
    res = S21_NAN;
  }
  return res;
}

long double s21_fmod(double x, double y) {
  long double res = 0;
  if ((x == -INF || x == INF) && y == y)
    res = S21_NAN;
  else if (s21_fabs(y) == 0 && x == x)
    res = S21_NAN;
  else if ((y == -INF || y == INF) && (x > -INF || x < INF))
    res = x;
  else if (x != x || y != y)
    res = S21_NAN;
  else
    res = x - ((int)(x / y) * y);
  return res;
}

long double s21_cos(double x) {
  long double res = 0.0;
  if (x == -INF || x == INF || x != x)
    res = S21_NAN;
  else {
    if (x < 0) x = -x;
    while (x >= 2 * PI) x -= (double)2 * PI;
    if (x >= PI) x = (double)(PI - (x - PI));
    for (int i = 10; i >= 0; i--) {
      int znak = (i % 2 == 0) ? 1 : -1;
      res += znak * HelpPow(x * x, i) / Phactorial(2 * i);
    }
  }
  return res;
}

long double s21_sin(double x) {
  int minus = 1;
  long double res = 0.0;
  if (x == -INF || x == INF || x != x)
    res = S21_NAN;
  else {
    if (x < 0) {
      minus = -minus;
      x = s21_fabs(x);
    }
    while (x >= 2 * PI) x -= 2 * PI;
    if (x >= PI / 2) x = PI / 2 - (x - PI / 2);
    for (int i = 10; i >= 0; i--) {
      int znak = (i % 2 == 0) ? 1 : -1;
      res +=
          znak * (HelpPow(x * x, i) * x) / (long double)Phactorial(2 * i + 1);
    }
  }
  return minus * res;
}

long double s21_acos(double x) {
  long double res = 0;
  if (s21_fabs(x) > 1) {
    res = S21_NAN;
  } else if (x == 1)
    res = 0;
  else if (x == 0)
    res = PI / 2;
  else if (x == -1)
    res = PI;
  else if (x > -1 && x < 1) {
    long double accuracy = 0.0000000001, left = 0, right = PI;
    while (1) {
      long double mid = (left + right) / 2, cosMid = s21_cos(mid);
      if (s21_fabs(cosMid - x) < accuracy) {
        res = mid;
        break;
      }
      if (cosMid > x)
        left = mid;
      else
        right = mid;
    }
  } else
    res = S21_NAN;
  return res;
}

long double s21_atan(double x) {
  long double res = 0;
  if (x == INF)
    res = PI / 2;
  else if (x == -INF)
    res = -PI / 2;
  else if (x > -INF && x < INF) {
    long double arg = 1.0 / s21_sqrt(1 + x * x);
    if (x >= 0)
      res = s21_acos(arg);
    else
      res = s21_acos(arg) * -1;
  } else
    res = S21_NAN;
  return res;
}

long double s21_asin(double x) {
  long double res = 0;
  if (s21_fabs(x) > 1)
    res = S21_NAN;
  else if (s21_fabs(x) <= 1) {
    long double arg = s21_sqrt(1 - x * x);
    if (x >= 0)
      res = s21_acos(arg);
    else
      res = s21_acos(arg) * -1;
  } else
    res = S21_NAN;
  return res;
}
int s21_abs(int x) { return x < 0 ? -x : x; }
long double s21_ceil(double x) {
  long double res = 0.0;
  if (x == -INF)
    res = -INF;
  else if (x == INF)
    res = INF;
  else if (x > -INF && x < INF) {
    if (x >= 0)
      res = (s21_fmod(x, 10) == 0) ? x : (int)x + 1;
    else
      res = (int)x;
  } else
    res = S21_NAN;
  return res;
}

long double s21_floor(double x) {
  long double res = 0.0;
  if (x == -INF)
    res = -INF;
  else if (x == INF)
    res = INF;
  else if (x > -INF && x < INF) {
    if (x >= 0)
      res = (int)x;
    else
      res = (s21_fmod(x, 10) == 0) ? x : (int)x - 1;
  } else
    res = S21_NAN;
  return res;
}

long double s21_tan(double x) {
  long double res = 0;
  if (x == -INF || x == INF)
    res = S21_NAN;
  else if (x > -INF && x < INF) {
    while (x >= 2 * PI) x -= 2 * PI;
    res = s21_sin(x) / s21_cos(x);
  } else
    res = S21_NAN;
  return res;
}