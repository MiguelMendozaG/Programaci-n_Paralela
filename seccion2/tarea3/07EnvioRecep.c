/* 07EnvioRecep.c envío y recepción de datos char
Miguel Ángel Mendoza Guadarrama
31 - mayo - 18
*/

#include<stdio.h>
#include<mpi.h>
int main(int argc, char **argv){
	int np, pa, i;
	char *cad={"HOLA MUNDITO"};
	MPI_Status estado;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &pa);
	if (pa == 0){
		MPI_Send(&cad, 14, MPI_CHAR ,1,0,MPI_COMM_WORLD);
	}

	if (pa == 1){
		MPI_Recv(&cad, 14, MPI_CHAR,0, 0, MPI_COMM_WORLD, &estado);
		printf("Recibí de %d el valor: %s \n", estado.MPI_SOURCE, cad);
	}
	MPI_Finalize();
	return 0;

}
