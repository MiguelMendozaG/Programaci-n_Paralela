/*openmp00b.c
Programa con OpenMP indicando el numero hilo que se ejecuta
Miguel Angel Mendoza Guadarrama
7 - mayo - 18
*/

#include<stdio.h>

int main (int argc, char *argv[]){
	#pragma omp parallel
		{
		printf("Hola mundo con OpenMP\n");
		printf("Soy el hilo numero: %d\n", omp_get_thread_num());
		}

	return 0;
}
