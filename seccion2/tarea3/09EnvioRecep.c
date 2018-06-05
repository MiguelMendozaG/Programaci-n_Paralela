/* 09EnvioRecep.c envío y recepción de datos en comunicaciones colectivas
Miguel Ángel Mendoza Guadarrama
31 - mayo - 18
*/

#include<stdio.h>
#include<mpi.h>
int main(int argc, char **argv){
	int np, pa, dato1, dato2;
	MPI_Status estado;
	MPI_Request envio;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pa);
	if (pa == 0){
		dato1=20;
		MPI_Isend(&dato1, 1, MPI_INT ,1,0,MPI_COMM_WORLD, &envio);
		MPI_Barrier(MPI_COMM_WORLD);
	}

	if (pa == 1){
		MPI_Irecv(&dato2, 1, MPI_INT,0, 0, MPI_COMM_WORLD, &envio);
		MPI_Barrier(MPI_COMM_WORLD);
		printf("Valor recibido: %d \n", dato2);
	}
	MPI_Finalize();
	return 0;

}
