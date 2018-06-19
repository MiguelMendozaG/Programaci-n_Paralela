/* 26Scatter2.c ilustra el comando MPI_Scatter
Miguel Angel Mendoza Guadarrama
13 - junio - 2018
*/
#include<stdio.h>
#include<mpi.h>
#define tam 4

int Gather(int mi_rank, int mi_np){
	int arreglo[8] = {3,5,7,9,11,13,15,17}, recepcion=0;
	int arreglo1[sizeof(arreglo)/sizeof(int)];
	int raiz = 0, i;
	//Se distribuye un elemento del arreglo a un procesador, hasta 	completar el numero de elementos en el arreglo
	MPI_Scatter(&arreglo, sizeof(arreglo1[0])/sizeof(int), MPI_INT,	&recepcion, 1, MPI_INT, raiz, MPI_COMM_WORLD);
	//Lee cada uno de los elementos que contiene cada proceso del comunicador y los envia al proceso raiz
	for(i=0; i<mi_np; i++)
		MPI_Gather(&recepcion, 1, MPI_INT, &arreglo1, 1, MPI_INT, i, MPI_COMM_WORLD);
	if(mi_rank==0){
		printf("rango: %d\n", mi_rank);
		for(i=0; i<sizeof(arreglo1)/sizeof(int); i++)
			printf("%d \n",arreglo1[i]);
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int np, rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	Gather(rank, np);
	MPI_Finalize();
	return 0;
}
