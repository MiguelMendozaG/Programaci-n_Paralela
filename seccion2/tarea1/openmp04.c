/*openmp04.c
Programa con OpenMP indica la cantidad de hilos
Miguel Angel Mendoza Guadarrama
7 - mayo - 18
*/

#include<stdio.h>
#include<omp.h>
#define NUM_HILOS 8
int main (){
	int pid;
	omp_set_num_threads(NUM_HILOS);
	#pragma omp parallel private(pid)
	{
	pid = omp_get_thread_num(); //regresa num de hilo
	printf("Hola ,soy el hilo: %d\n", pid);
	}
	
	return 0;
}
