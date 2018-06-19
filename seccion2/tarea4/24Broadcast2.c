/* 24Broadcast2.c ilustra el comando MPI_Broadcast
Miguel Angel Mendoza Guadarrama
13 - junio - 2018
*/
#include<stdio.h>
#include<mpi.h>
#define tam 8
#define mitad tam/2

int main(int argc, char *argv[]) {
	int np, rank, i;
	int cuentaEnvio, cuentaRecep, fuente;
	float bufEnvio[tam] = {1.0, 2.0, 3.0, 4.0};
	float bufRecep[tam] = {0.0, 0.0, 0.0, 0.0};
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(np == tam){
		fuente = 1;
		cuentaEnvio = tam;
		cuentaRecep = tam;
		if(rank == 0)
			{
			MPI_Bcast((void *)bufEnvio, cuentaEnvio, MPI_FLOAT, rank,
			MPI_COMM_WORLD);
			}
		for(i=0; i<tam; i++) bufRecep[i] = bufEnvio[i];
		printf("Rank = %d Resultados: %2.3f %2.3f %2.3f %2.3f \n",rank,bufEnvio[0],bufEnvio[1],bufRecep[2],bufRecep[3]);
		}
	else
		printf("Se debe de especificar el numero correcto de procesos (%d) \n",tam);
	MPI_Finalize();
	return 0;
}
