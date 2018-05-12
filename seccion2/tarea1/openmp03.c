/*openmp03.c
Programa sin OpenMP
Miguel Angel Mendoza Guadarrama
7 - mayo - 18
*/

#include<stdio.h>
#include<omp.h>
int main (){
	#pragma omp parallel  
	{
	int pid;
	pid = omp_get_thread_num(); //regresa num de hilo
	printf("Hola, mundo desde hilo: %d\n", pid);
	}
	

	return 0;
}
