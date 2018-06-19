/* 22EjemDatatypeDiagonal.c Ejemplo tipos de datos Datatype con vectores
Miguel Angel Mendoza Guadarrama
13 - junio - 2018
*/
#include<stdio.h>
#include<mpi.h>


int main(int argc, char *argv[]) {
	int np, rank;
	MPI_Status estado;
	MPI_Datatype superior;
	int arreglo[10][10], medio[55], i, j;
	int tam=10, disp[10], bloque[10];
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	//calcula el inicio y tamaÃ±o de cada fila:
	for(i=0; i<10; i++)
		{
		disp[i]=tam*i+i;
		bloque[i] = 10-i;
		}
	//crea tipo para triangular superior
	MPI_Type_indexed(10, bloque, disp, MPI_INT, &superior);
	MPI_Type_commit(&superior);
	if(rank==0)
		{
		for(i=0; i<10; i++)
			for(j=0; j<10; j++)
				arreglo[i][j] = i*10+j;
		for(i=1; i<np; i++)
			MPI_Send(arreglo, 1, superior, i, 99, MPI_COMM_WORLD);
		}
	else
		{
		MPI_Recv(medio, 55, MPI_INT, 0, 99, MPI_COMM_WORLD,
		&estado);
		printf("Soy el proceso no. %d \n",rank);
		for(i=0; i<55; i++)
			printf("%3d ",medio[i]);
		printf("\n\n");
		}
	if(rank==0)
		{
		printf("\t\t\tgracias...\n"); //getchar();
		}
	MPI_Finalize();
	return 0;
}
