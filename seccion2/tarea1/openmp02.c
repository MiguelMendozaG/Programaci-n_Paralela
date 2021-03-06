/*openmp02.c
Programa en OpenMP 02 rellenado de arreglos
Miguel Angel Mendoza Guadarrama
7 - mayo - 18
*/

#include<stdio.h>
#include<omp.h>
int main (int argc, char *argv[]){
	double a[1000], b[1000], c[1000];
	int i;
	#pragma omp parallel for
	for (i=0; i<1000; i++){
		a[i] = b[i] + c[i];
		printf("i=%d: a[%4.01f] = b[%4.01f] + c[%4.01f]\n", i, a[i], b[i], c[i]);
	}

	return 0;
}
