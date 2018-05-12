/*openmp10.c
Transformación de los hilos
Miguel Angel Mendoza Guadarrama
8 - mayo - 18
*/

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define HILOS 100


int main (){
	int S[HILOS];
	int P[HILOS];
	int Q[HILOS];
	int i,tid,acumula;

	#pragma omp parallel for
	for (i=0; i<HILOS; i++){
		S[i]=i+1;
		P[i]=S[i];
		printf("P[i] = %d \t S[i] = %d \n", P[i],S[i]);
	}

	#pragma omp parallel reduction(+ : acumula)
	{
	tid = omp_get_thread_num();

	/*Operation*/
	Q[tid] = S[tid]*P[tid]+1;
	//subtotales
	acumula=Q[tid];
	printf("Q[tid]= %d \n", acumula);
	}
	return 0;
}
