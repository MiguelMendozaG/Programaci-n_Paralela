/*openmp09a.c
Suma en hilos obteniendo el total
Miguel Angel Mendoza Guadarrama
8 - mayo - 18
*/

#include<stdio.h>
#include<omp.h>
#define DATOS 10000
#define NHILOS 4

int main (){
	int parte, suma=0;
	omp_set_num_threads(4);
	parte=DATOS/NHILOS;
	#pragma omp parallel reduction(+:suma)
	{
	int i=0, Li, Lf, rank;
	rank=omp_get_thread_num();
	
	printf("rank vale:%d y parte vale: %d\n", rank,parte);
	Li=(rank*parte)+1;
	Lf=(Li+parte-1);	
	printf("Li vale: %d, Lf vale: %d\n",Li,Lf);	
	for (i=Li; i<=Lf; i++)
		suma+=i;

	printf("\n subtotal: %d \n", suma);
	}
	printf("\n total: %d\n",suma);
	return 0;
}
