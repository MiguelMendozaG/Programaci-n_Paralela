/* 13acast.c comunicacion con broadcast
Miguel Ángel Mendoza Guadarrama
31 - mayo - 18
*/

#include<stdio.h>
#include<mpi.h>
#define N 5
int main(int argc, char *argv){
	int np;
	int rank;
	int a[N], i;
	int root=2;
	for (i=0; i<N ; i++)
		a[i] = 100 +i+root;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Bcast((void *)a, N, MPI_INT, root, MPI_COMM_WORLD);
	printf("rank = %d \n", rank);
	for(i=0; i<N; i++)
		printf("%d ", a[i]);
	printf("\n");

	MPI_Finalize();
	return 0;

}
