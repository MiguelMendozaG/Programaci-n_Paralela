/*openmp05a.c
Programa con OpenMP utilizando funciones OMPs
Miguel Angel Mendoza Guadarrama
7 - mayo - 18
*/

#include<stdio.h>
#include<omp.h>

int main (){
	int hiloID, numHilos, procs, maxH, inpar, dinamic, nido;
	#pragma omp parallel private(numHilos, hiloID)
	{
	hiloID = omp_get_thread_num(); //regresa num de hilo
	//operaciones exclusivas del hilo maestro
	if (hiloID == 0)
	{
		printf("Hilo %d Obtiene informacion del entorno \n", hiloID);
		//resultados de informacion del entorno
		procs = omp_get_num_procs();
		numHilos = omp_get_num_threads();
		maxH = omp_get_max_threads();
		inpar = omp_in_parallel();
		dinamic = omp_get_dynamic();
		nido = omp_get_nested();
		//impresion de la informacion del entorno
		printf("Numero de procesadores: %d \n", procs);
		printf("Numero de hilos: %d\n", numHilos);
		printf("Maximo de hilos: %d\n", maxH);
		printf("Esta en paralelo?: %d\n", inpar);
		printf("hilos dinamicos habilitados: %d\n", dinamic);
		printf("Soporte de anidacion en paralelo?: %d\n", nido);
	}

	}
	
	return 0;
}
