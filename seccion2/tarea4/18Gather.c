/* 18Gather.c comunicacion con gather
Miguel Angel Mendoza Guadarrama
13 junio 2018
*/

#include<stdio.h>
#include<mpi.h>
#define N 8
int main(int argc, char *argv[])
	{
	int np,i,j,x[N], a[1000], rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	for(i=0; i<N; i++){
		x[i]=rank+i;
		printf("%d ",x[i]); }

	printf("\n");
	MPI_Gather(x, N, MPI_INT, a, N, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank==0){
		printf("Rank 0 gather: \n");
		for(i=0; i<np; i++){
			for(j=0; j<N; j++)
				printf(" %2d ",a[N*i+j]);
			printf("\n");
		}
	printf("\n"); }
	MPI_Finalize();
	return 0;
}
