/* 25Scatter2.c ilustra el comando MPI_Scatter
Miguel Angel Mendoza Guadarrama
13 - junio - 2018
*/
#include<stdio.h>
#include<mpi.h>
#define tam 4

int main(int argc, char *argv[]){
	int np, rank, i;
	int cuentaEnvio, cuentaRecep, fuente;
	float bufEnvio[tam][tam] = {{1.0, 2.0, 3.0, 4.0},{6.0, 7.0, 8.0},{10.0, 11.0, 12.0},{14.0, 15.0, 16.0} };
	float bufRecep[tam];
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(np == tam){
		fuente = 1;
		cuentaEnvio = tam;
		cuentaRecep = tam;
		MPI_Scatter(bufEnvio, cuentaEnvio, MPI_FLOAT, bufRecep, cuentaRecep, MPI_FLOAT, fuente, MPI_COMM_WORLD);
		printf("Rank = %d Resultados: %5.2f %5.2f %5.2f %5.2f \n",rank,bufRecep[0], bufRecep[1],bufRecep[2],bufRecep[3]);
		}
	else
		printf("Se debe de especificar el numero correcto de procesos (%d) \n",tam);
	MPI_Finalize();
	return 0;
}
