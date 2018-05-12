/*openmp07.c
Rellena arreglos
Miguel Angel Mendoza Guadarrama
8 - mayo - 18
*/

#include<stdio.h>
#include<omp.h>
#define DATOS 10000000

int main (){
	long i, suma = 0;
	for (i=1; i<=DATOS; i++){
		suma +=i;
	}
	printf("\n Total: %ld \n",suma);
	return 0;
}
