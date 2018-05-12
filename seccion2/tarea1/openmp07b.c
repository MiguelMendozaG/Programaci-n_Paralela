/*openmp07b.c
Rellena arreglos
Miguel Angel Mendoza Guadarrama
8 - mayo - 18
*/

#include<stdio.h>
#include<omp.h>
#define DATOS 10000000
#define NUMHILOS 50

int main (){
	long i, suma = 0;
	omp_set_num_threads(NUMHILOS);
	#pragma parallel for reduce(+:suma)
	for (i=1; i<=DATOS; i++){
		suma +=i;
	}
	printf("\n Total: %ld \n",suma);
	return 0;
}
