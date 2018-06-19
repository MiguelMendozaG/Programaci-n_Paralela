/* 22EjemDatatypeRombo.c Ejemplo tipos de datos Datatype con vectores
Miguel Angel Mendoza Guadarrama
13 - junio - 2018
*/
#include<stdio.h>
#include<mpi.h>
#define tam 8
#define mitad tam/2

int main(int argc, char *argv[]) {
	int np, rank;
	int sizeofint, a[tam][tam], b[mitad], disp[tam], blocklen[tam];
	int i, j, datos=0;
	MPI_Datatype superior;
	MPI_Status estado;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	//calcula el inicio y tamaÃ±o de cada fila:
	for(i=0; i<mitad; i++)
		{
		disp[i]= ((mitad - 1) - i)+(i * tam);
		disp[i + mitad] = (i) + ((i + mitad) * tam);
		blocklen[i] = blocklen[(tam-1) - i] = ( i + 1 ) * 2;
		datos += 2*blocklen[i];
		}
	int *medio;
	medio = (int*)malloc(datos * sizeof(int));
	//crea tipo
	MPI_Type_indexed(tam, blocklen, disp, MPI_INT, &superior);
	MPI_Type_commit(&superior);
	if(rank==0)
		{
		for(i=0; i<tam; i++)
			for(j=0; j<tam; j++)
				a[i][j] = i*10+j;
		for(i=1; i<np; i++)
		MPI_Send(a, 1, superior, i, 99, MPI_COMM_WORLD);
		}
	else
		{
		MPI_Recv(medio, datos, MPI_INT, 0, 99, MPI_COMM_WORLD,
		&estado);
		printf("Soy el proceso no. %d \n",rank);
		for(i=0; i<datos; i++)
			printf("%3d ",medio[i]);
		printf("\n\n");
		}
	free(medio);
	MPI_Finalize();
	return 0;
}
