#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<omp.h>

int main(){
	unsigned long limit = 4294967294, i;
	long double pi, valor, pow_;
	for (i = 1; i < limit; i++){
		pow_ = i*i;
		valor += 1/(pow_);
	}

	pi = sqrt(valor*6);
	printf("PI en %ld iteraciones vale: %0.30Le ", i, pi);


	return 0;

}
