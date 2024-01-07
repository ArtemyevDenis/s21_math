#ifndef S21_MATH_H
#define S21_MATH_H

#include <check.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592653589793238462643383279
#define INF __builtin_huge_vall()
#define S21_NAN __builtin_nanf("0x7fc00000")

int IsInt(double x);
long double HelpPow(double x, int count);
long double s21_fabs(double x);  //
double Phactorial(int n);
long double s21_exp(double x);                  //
long double s21_log(double x);                  //
long double s21_pow(double base, double exp_);  //
long double s21_sqrt(double x);                 //
long double s21_fmod(double x, double y);       //
long double s21_sin(double x);                  //
long double s21_cos(double x);                  //
long double s21_acos(double x);                 //
long double s21_atan(double x);                 //
long double s21_asin(double x);                 //
int s21_abs(int x);                             //
long double s21_ceil(double x);                 //
long double s21_floor(double x);                //
long double s21_tan(double x);                  //

#endif