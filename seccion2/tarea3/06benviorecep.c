/* 06benviorecep.c envío y recepción de datos enteros 
Miguel Ángel Mendoza Guadarrama
31 - mayo - 18
*/

#include<stdio.h>
#include<mpi.h>
int main(int argc, char **argv){
	int np, rank, dato=10, dato0, dato1, dato2, dato3;
	MPI_Request envio;
	MPI_Status estado;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == 0){
		dato = dato+10;
		MPI_Send(&dato, 1, MPI_INT,1,0,MPI_COMM_WORLD);
		MPI_Recv(&dato0, 1, MPI_INT,3,0,MPI_COMM_WORLD,&estado);
		printf("Proceso %d recibido el dato %d desde el procesador %d \n", rank,dato0,estado.MPI_SOURCE);
	}

	if (rank == 1){
		MPI_Recv(&dato1, 1, MPI_INT,0,0,MPI_COMM_WORLD,&estado);
		dato1=dato1*10;
		MPI_Send(&dato1, 1, MPI_INT,2,0,MPI_COMM_WORLD);
		printf("Proceso %d recibido el dato %d desde el procesador %d \n", rank,dato1,estado.MPI_SOURCE);
	}

	if (rank == 2){
		MPI_Recv(&dato2, 1, MPI_INT,1,0,MPI_COMM_WORLD,&estado);
		dato2=dato2-10;
		MPI_Send(&dato2, 1, MPI_INT,3,0,MPI_COMM_WORLD);
		printf("Proceso %d recibido el dato %d desde el procesador %d \n", rank,dato2,estado.MPI_SOURCE);
	}

	if (rank == 3){
		MPI_Recv(&dato3, 1, MPI_INT,2,0,MPI_COMM_WORLD,&estado);
		dato3=dato3/10;
		MPI_Send(&dato3, 1, MPI_INT,0,0,MPI_COMM_WORLD);
		printf("Proceso %d recibido el dato %d desde el procesador %d \n", rank,dato3,estado.MPI_SOURCE);
	}

	MPI_Finalize();
	return 0;

}
