/* 19ascatter.c comunicacion con scatter
Miguel Angel Mendoza Guadarrama
13 junio 2018
*/

#include<stdio.h>
#include<mpi.h>
#define tarr 1000
int main(int argc, char *argv[])
	{
	int np, i, a[tarr];
	int rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int x[np];

	for(i=0; i<tarr; i++)
		a[i]=i;
	
	MPI_Scatter(a, np, MPI_INT, x, np, MPI_INT, 0, MPI_COMM_WORLD);
	//if(rank!=0){
	printf("Rank = %d \n",rank);
	
	for(i=0; i<np; i++)
		printf(" %2d ",x[i]);

	printf("\n");
	// }
	MPI_Finalize();
	return 0;
}
