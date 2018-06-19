/* 21EjemplosDatatype Ejemplo tipos de datos Datatype en matrices
Miguel Angel Mendoza Guadarrama
13 - junio - 2018
*/
#include<stdio.h>
#include<mpi.h>


int main(int argc, char *argv[]) {
	int np, rank;
	MPI_Status estado;
	MPI_Datatype columna;
	MPI_Datatype expandido;
	MPI_Datatype doblearreglo;
	int arregloa[4][5], arreglob[4], i, j, k;
	int arreglo1[3], arreglo2[9];
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	//crea tipo para la diagonal:
	MPI_Type_contiguous(9, MPI_INT, &expandido);
	MPI_Type_commit (&expandido);
	
	if(rank==0)
		{
		for(i=0; i<3; i++)
			arreglo1[i]=i;
		for(i=1; i<np; i++)
			MPI_Send(arreglo1, 1, expandido, i, 55, MPI_COMM_WORLD);
		}
	
	else
		{
		MPI_Recv( arreglo2, 9, MPI_INT, 0, 55, MPI_COMM_WORLD, &estado);
		printf("Soy el proceso no. %d \n",rank);
		printf("\n");
		for(i=0; i<9; i++)
			printf("%d ",arreglo2[i]);
		printf("\n\n");
		}

	if(rank==0)
	{
		printf("\t\t\tgracias...\n");
	}
	MPI_Finalize();
	return 0;
}
