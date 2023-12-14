#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <check.h>

#define PI 3.141592653589793238462643383279 

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

long double s21_cos(double x){
    if(x < 0)
        x = -x;
    while(x >= 2*PI)
        x -= (double)2*PI;
    if (x >= PI)
        x = (double)(PI - (x-PI));
    double res = 0.0;
    for(int i = 0; i < 11; i++){
        res += pow(-1.0,i) * pow(x,2.0*i)/phactorial(2*i);
    }
    return res;
}

long double s21_sin(double x){
    int minus = 1;
    if(x < 0){
        minus = -minus;
        x = fabs(x);
    }
    while(x >= 2*PI)
        x -= 2*PI;
    if (x >= PI/2)
        x = PI/2 - (x-PI/2);
    long double res = 0.0;
    for(int i = 0; i < 250000; i++){
        res += pow(-1.0,i) * pow(x,2.0*i + 1)/(long double)phactorial(2*i + 1);
    }
    return minus*res;
}

// Функция тестирования какой-либо задачи.
START_TEST(test_name)
{
    for(double i = 0.0; i < 1.0; i+=0.10){
        long double temp = 0.0;
        double temp_m = 0.0;
        temp = s21_cos(i);
        temp_m = cos(i);
        //printf("s21 == %.20LF |||  math == %.20lf\n",temp, temp_m);
        ck_assert_ldouble_eq_tol(temp,temp_m,0.000000000000001);
    }
}
END_TEST

// Функция создания набора тестов.
Suite *example_suite_create(void)
{
    Suite *suite = suite_create("Example");
    // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
    TCase *tcase_core = tcase_create("Core of example");
    
    // Добавление теста в группу тестов.
    tcase_add_test(tcase_core, test_name);
    
    // Добавление теста в тестовый набор.
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