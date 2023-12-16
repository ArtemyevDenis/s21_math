#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <check.h>

#define PI 3.141592653589793238462643383279 

long double help_pow(double x, int count){
    long double res = 1.0;
    for (int i = 0 ; i < count; i++)
        res*= x;
    return res;
}

double phactorial(int n){
    double rez = 1.0;
    if(n == 0 || n == 1)
        rez = 1;
    else
        for(int i = 1; i <= n; i++)
            rez*=i;
    return rez;
}

int s21_abs(int x){
    return x < 0 ? -x : x;
}

long double s21_fabs(double x){
    return x < 0 ? -x : x;
}

long double s21_ceil(double x){
    double rez = 0.0;
    if(x >= 0)
        rez = (x/1000000000 == 0) ? x : (int)x + 1;
    else
        rez = (int)x;
    return rez; 
}

long double s21_floor(double x){
    double rez = 0.0;
    if(x >= 0)
        rez = (int)x;
    else
        rez = (x/1000000000 == 0) ? x : (int)x - 1;
    return rez; 
}

long double s21_cos(double x){
    int znak = 1;
    if(x < 0)
        x = -x;
    while(x >= 2*PI)
        x -= (double)2*PI;
    if (x >= PI)
        x = (double)(PI - (x-PI));
    double res = 0.0;
    for(int i = 10; i >= 0; i--){
        znak = (i%2 == 0) ? 1 : -1;
        res +=  znak* help_pow(x*x,i)/phactorial(2*i);
    }
    return res;
}

long double s21_sin(double x){
    int minus = 1, znak = 1;
    if(x < 0){
        minus = -minus;
        x = s21_fabs(x);
    }
    while(x >= 2*PI)
        x -= 2*PI;
    if (x >= PI/2)
        x = PI/2 - (x-PI/2);
    long double res = 0.0;
    for(int i = 10; i >= 0; i--){
        znak = (i%2 == 0) ? 1 : -1;
        res += znak * (help_pow(x*x,i) * x)/(long double)phactorial(2*i + 1);
    }
    return minus*res;
}

long double s21_tan(double x){
    while(x >= 2* PI)
        x -= 2* PI;
    return s21_sin(x)/s21_cos(x);
}

// Функция тестирования какой-либо задачи.
START_TEST(test_s21_cos)
{
    ck_assert_ldouble_eq_tol(s21_cos(-100), cos(-100),0.0000000000001);
    ck_assert_ldouble_eq_tol(s21_cos(-2.45678), cos(-2.45678),0.0000000001);
    ck_assert_ldouble_eq_tol(s21_cos(0), cos(0),0.0000000001);
    ck_assert_ldouble_eq_tol(s21_cos(1.123456), cos(1.123456),0.0000000001);
    ck_assert_ldouble_eq_tol(s21_cos(100), cos(100),0.0000000001);
}
END_TEST

START_TEST(test_s21_sin)
{
    ck_assert_ldouble_eq_tol(s21_sin(-100), sin(-100),0.0000000001);
    ck_assert_ldouble_eq_tol(s21_sin(-2.45678), sin(-2.45678),0.0000000001);
    ck_assert_ldouble_eq_tol(s21_sin(0), sin(0),0.0000000001);
    ck_assert_ldouble_eq_tol(s21_sin(1.123456), sin(1.123456),0.0000000001);
    ck_assert_ldouble_eq_tol(s21_sin(100), sin(100),0.0000000001);

}
END_TEST

START_TEST(test_s21_abs)
{
    ck_assert_int_eq(s21_abs(-100), abs(-100));
    ck_assert_int_eq(s21_abs(0), abs(0));
    ck_assert_int_eq(s21_abs(100), abs(100));
}
END_TEST

START_TEST(test_s21_fabs)
{
    ck_assert_ldouble_eq_tol(s21_fabs(-100.1234536), fabs(-100.1234536), 0.00000000001);
    ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 0.00000000001);
    ck_assert_ldouble_eq_tol(s21_fabs(945.1238475), fabs(945.1238475), 0.00000000001);
}
END_TEST

START_TEST(test_s21_ceil)
{
    for(double i = -10; i < 10; i += 0.001){
        //printf("i == %.16f  |||  s21 == %Lf  |||   math == %lf\n", i, s21_ceil(i), ceil(i));
        ck_assert_double_eq_tol(s21_ceil(i),ceil(i),0.00000000001);
    }

}
END_TEST

START_TEST(test_s21_floor)
{
    for(double i = -10.1; i < 10; i += 0.001){
        //printf("i == %.16f  |||  s21 == %Lf  |||   math == %lf\n", i, s21_floor(i), floor(i));
        ck_assert_double_eq_tol(s21_floor(i),floor(i),0.00000001);
    }

}
END_TEST

START_TEST(test_s21_tan)
{
    for(double i = -10; i < 10; i += 0.001){
        //printf("i == %.16f  |||  s21 == %Lf  |||   math == %lf\n", i, s21_ceil(i), ceil(i));
        ck_assert_double_eq_tol(s21_tan(i),tan(i),0.000001);
    }

}
END_TEST


Suite *example_suite_create(void)
{
    Suite *suite = suite_create("tests");
    TCase *tcase_core = tcase_create("Core of example");
    tcase_add_test(tcase_core, test_s21_cos);
    tcase_add_test(tcase_core, test_s21_abs);    
    tcase_add_test(tcase_core, test_s21_sin);
    tcase_add_test(tcase_core, test_s21_fabs);
    tcase_add_test(tcase_core, test_s21_ceil);
    tcase_add_test(tcase_core, test_s21_floor);
    tcase_add_test(tcase_core, test_s21_tan);
    
    suite_add_tcase(suite, tcase_core);
    
    return suite;
}

int main(void)
{
    Suite *suite = example_suite_create();
    SRunner *suite_runner = srunner_create(suite);
    int failed_count = 0;
    
    srunner_run_all(suite_runner, CK_NORMAL);
    // Получаем количество проваленных тестов.
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    
    if (failed_count != 0) {
        // Сигнализируем о том, что тестирование прошло неудачно.
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}