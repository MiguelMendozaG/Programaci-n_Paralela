/*openmp08.c
Rellena arreglos
Miguel Angel Mendoza Guadarrama
8 - mayo - 18
*/

#include<stdio.h>
#include<omp.h>
#define DATOS 100
#define NHILOS 4

int main (){
	int parte, suma=0;
	omp_set_num_threads(NHILOS);
	parte=DATOS/NHILOS;
	#pragma omp parallel
	{
	int i, Li, Lf, rank;
	rank=omp_get_thread_num();
	Li=(rank*parte)+1;
	Lf=(Li+parte-1);	
	for (i=Li; i<=Lf; i++)
		suma+=i;
	printf("\n subtotal: %d Hilo: %d \n", suma, omp_get_thread_num());
	}
	printf("\n valor de suma despues de paralelizacion: %d\n",suma);
	return 0;
}
