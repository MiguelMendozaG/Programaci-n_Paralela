#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<omp.h>

#define NHILOS 2
#define DATOS 4294967294
//4294967294

int main(){
	long double PI25DT = 3.141592653589793238462643;
	unsigned long parte;
	long double pi, valor, pow_;

	omp_set_num_threads(NHILOS);
	parte=DATOS/NHILOS;
	#pragma omp parallel reduction(+:valor)
	{
		int rank;
		unsigned long i=0, Li, Lf;
		rank=omp_get_thread_num();
	
		//printf("\n rank vale:%d y parte vale: %d \n", rank);
		Li=((unsigned long)rank*parte)+1;
		Lf=(unsigned long)(Li+parte-1);	
		printf("Li vale: %ld Lf vale: %ld\n",Li,Lf);	
		for (i=Li; i<=Lf; i++){
			pow_ = 1/(long double)(i*i);
			valor+= pow_;}
		//printf("\n pow: %0.10Le", pow_);
		printf("\n subtotal: %0.20Le \n", valor);
	}
	printf("\n total: %0.20Le\n",valor);
	pi = sqrt(valor*6);
	printf("\n PI = %0.30Le", pi);
	printf("\n El error cometido es %0.20Le",pi-PI25DT);

	return 0 ;

}
