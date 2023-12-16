#include <stdio.h>
#include <math.h>

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

long double s21_exp(double x){
	long double res = 0.0;
	double es = 2.71828182846;
	double ksi = (x - 0) / 6.678;
	long int fac = 1;
	for(int i = 0 ; i < 20; i++){
		if(i > 0)
			fac *=i;
		res+= help_pow(x,i)/fac;
	}
	//res += pow(es,ksi) * help_pow(x,21) / phactorial(21);
	return res;
}
int main(){
	for (int i = 0; i < 11; i++)
		printf("%.15Lf  ||||    %.15lf\n",s21_exp(i), exp(i));
}
