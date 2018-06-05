/* 10EnvioRecep.c envío y recepción de datos
Miguel Ángel Mendoza Guadarrama
31 - mayo - 18
*/

#include<stdio.h>
#include<mpi.h>
int main(int argc, char **argv){
	int np, pa, i=0, j=0, flag;
	MPI_Status estado;
	MPI_Request envio;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pa);
	if (pa == 0){
		i=100;
		MPI_Isend(&i, 1, MPI_INT ,1,10,MPI_COMM_WORLD, &envio);
	}
	if (pa == 1){
		while(flag!=0){
			MPI_Test(&envio, &flag, &estado);
			MPI_Wait(&envio, &estado);
			printf("\n %d \n", flag);
		}
		MPI_Irecv(&j, 1, MPI_INT, 0, 10, MPI_COMM_WORLD, &envio);
		printf("Valor recibido: %d \n", j);
	}
	MPI_Finalize();
	return 0;

}
