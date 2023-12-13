#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

long long int phactorial(int n){
    long long int rez = 1;
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
        x -= 2*PI;
    if (x >= PI)
        x = PI - (x-PI);
    long double res = 0.0;
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
    for(int i = 0; i < 11; i++){
        res += pow(-1.0,i) * pow(x,2.0*i + 1)/phactorial(2*i + 1);
    }
    return minus*res;
}

int main(){
    int count_suc = 0, count_fail = 0;
    for(double i = -100.0; i < 100.0; i+=0.10){
        
        long double temp = 0;
        double temp_m = 0;
        temp = s21_cos(i);
        temp_m = cos(i);
        if(fabs(temp - temp_m) <= 0.0000001)
            // printf("SUCCESS ||  s21: %Lf ||  math: %lf || i: %lf\n",temp,temp_m,i);
            count_suc++;
        else{
            printf("FAIL ||  s21: %Lf ||  math: %lf || i: %lf\n",temp,temp_m,i);
            count_fail++;
        }
    }
    printf("SUCCESS: %d\nFAIL: %d\n", count_suc, count_fail);
}