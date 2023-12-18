#include <stdio.h>
#include <math.h>

long double s21_exp(double x){
	long double res = 1.0;
	double temp = 1.0;
	double helper = fabs(x);
	for(int i = 1 ; i <= 50; i++){
		temp = (temp*helper)/i;
		res = res + temp;
	}
	if(x<0)
		res = 1.0/res;
	return res;
}

long double s21_log(double x){
	double yn1 = 0.0;
	if (x != 0){
		double yn = x - 1.0; // using the first term of the taylor series as initial-value
		 yn1= yn;
		do
		{
			yn = yn1;
			yn1 = yn + 2 * (x - s21_exp(yn)) / (x + s21_exp(yn));
		} while (fabs(yn - yn1) > 0.000000000001);
	}
	else 
		yn1 = 1;
    return yn1;
}

long double s21_pow(double base, double exp){
	return s21_exp(s21_log(base) * exp);
}

int main(){
	int suc = 0, fail = 0;
	for (double i = -1; i < 1; i+=0.0001)
		if(s21_pow(i,i) - pow(i,i) < 0.00000000001)
			suc++;
		else
			fail++;
	printf("suc == %d\nfail == %d\n", suc, fail);
	// while(s21_exp(10,count) - exp(10) > 0.0000000001){
	// 	count+= 0.0001;
	// }
	// printf("%lf", count);
}
