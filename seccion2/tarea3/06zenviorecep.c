/* 06zenviorecep.c envío y recepción de datos enteros 
Miguel Ángel Mendoza Guadarrama
31 - mayo - 18
*/

#include<stdio.h>
#include<mpi.h>
int main(int argc, char **argv){
	int np, rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("Hola mundo, este es el rango %d de %d \n", rank, np);
	if (rank == 1){
		double data = 3.14;
		MPI_Send(&data, 1, MPI_DOUBLE,0,27,MPI_COMM_WORLD);
	}

	if (rank == 0){
		double data;
		MPI_Recv(&data,1,MPI_DOUBLE,1,MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("El rango 0 dice: %g \n", data);
	}
	MPI_Finalize();
	return 0;

}
