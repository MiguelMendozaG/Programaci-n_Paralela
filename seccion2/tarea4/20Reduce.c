/* 20Reduce.c comunicacion con reduce 
Miguel Angel Mendoza Guadarrama
13 - junio - 2018
*/
#include<stdio.h>
#include<mpi.h>


int main(int argc, char *argv[])
	{
	int np, i, j, a[160], suma=0, sumatotal=0;
	int rank;
	
	for(i=0; i<160; i++)
		a[i]=rand()%5;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int x[np];
	MPI_Scatter(a, np, MPI_INT, x, np, MPI_INT, 0, MPI_COMM_WORLD);
	
	for(i=0; i<np; i++){
		suma+=x[i];
		printf("Suma parcial de %2d es: %d\n",rank,suma);
	}

	MPI_Reduce(&suma, &sumatotal, 1, MPI_INT, MPI_SUM, 0,
	MPI_COMM_WORLD);

	if(rank==0){
		printf("La suma total es: %d \n",sumatotal);
	}

	MPI_Finalize();
	return 0;
}
