/*openmp06.c
Rellena arreglos
Miguel Angel Mendoza Guadarrama
8 - mayo - 18
*/

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define HILOS 100

int main (){
	int s[100];
	int P[100];
	int i;

	#pragma omp parallel for
	for (i=0; i<HILOS; i++){
		s[i] = i+1;
		P[i] = s[i];
		printf("P[i] = %d \t s[i] = %d \n ", P[i], s[i])	;
	}
	return 0;
}
