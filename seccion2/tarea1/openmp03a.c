/*openmp03a.c
Programa con OpenMP que regresa el numero de hilo
Miguel Angel Mendoza Guadarrama
7 - mayo - 18
*/

#include<stdio.h>
#include<omp.h>
int main (){
	int pid;
	#pragma omp parallel private(pid)
	{
	pid = omp_get_thread_num(); //regresa num de hilo
	printf("Hola, soy el hilo: %d\n", pid);
	}
	

	return 0;
}
