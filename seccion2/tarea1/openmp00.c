/*openmp00.c
Primer programa con OpemMP
Miguel Angel Mendoza Guadarrama
7 - mayo - 18
*/

#include<stdio.h>

int main (int argc, char *argv[]){
	#pragma omp parallel
		{
		printf("Hola mundo con OpenMP\n");
		}

	return 0;
}
