/* 08aEnvioRecep.c envío y recepción de datos
Miguel Ángel Mendoza Guadarrama
31 - mayo - 18
*/

#include<stdio.h>
#include<mpi.h>
int main(int argc, char **argv){
	int np, rank, i, arr[10], arr2[10];
	MPI_Status estado;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == 0){
		for(i=0; i<10; i++)
			arr[i] = i;
		MPI_Send(&arr, 10, MPI_INT ,3,0,MPI_COMM_WORLD);
	}

	if (rank == 3){
		MPI_Recv(&arr2, 10, MPI_INT,0, 0, MPI_COMM_WORLD, &estado);
		for(i=0; i<10; i++)
			printf("Valor recibido en procesador [%d]: %d \n", rank, arr2[i]);
	}
	MPI_Finalize();
	return 0;

}
