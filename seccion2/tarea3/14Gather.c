/* 14Gather.c comunicacion con gather
Miguel Ángel Mendoza Guadarrama
31 - mayo - 18
*/

#include<stdio.h>
#include<mpi.h>
#define N 4

int main(int argc, char *argv[]){
	int np, i;
	int rank;
	int EnvioLocal[N];
	int RecepLocal[1000];
	int root=0;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	for(i=0; i<N; i++)
		EnvioLocal[i] = (rank+1)*i;
	MPI_Allgather(EnvioLocal, N, MPI_INT, RecepLocal, N, MPI_INT, MPI_COMM_WORLD);
	printf("Proceso: %d\n", rank);
	for(i=0; i<N; i++)
		printf("DatEnv: %2d, ", EnvioLocal[i]);
	printf("\n");
	for(i=0; i<N*np; i++)
		printf("%d: DatRec: %2d, ",i, RecepLocal[i]);
	printf("\n");
	MPI_Finalize();
	return 0;

}
