/*openmp03b.c
Programa con OpenMP
Miguel Angel Mendoza Guadarrama
7 - mayo - 18
*/

#include<stdio.h>
#include<omp.h>
int main (){
	int p, numHilo;
	p = omp_get_num_procs();
	omp_set_num_threads(p);
	#pragma omp parallel private(numHilo)
	{
	numHilo = omp_get_thread_num();
	printf("Hola Mundo, desde el hilo: %d\n", numHilo);
	}
	
	return 0;
}
