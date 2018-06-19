/* 17CalculoPIconBcast.c Calculo de PI con funciones colectivas
Miguel Angel Mendoza Guadarrama
13 junio 2018
*/

#include<stdio.h>
#include<mpi.h>

double f(double a){
	return(4.0 / (1.0 + a *a));
}

int main(int argc, char *argv[])
{
	int n, rank, np, i;
	double PI25DT = 3.141592653589793238462643;
	double mypi, pi, h, sum, x;
	int origen, destino, tag=100;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("\n PROCESO %d de %d ",rank, np);
	
	if(rank==0) {
		n=100; 
	} //Inicializa el numero de intervalos

	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD); 
	/*el proceso 0 	envía el número de intervalos al resto de los procesos */
	h = 1.0/(double)n;
	sum = 0.0 ;

	//Suma de intervalos
	for(i = rank+1; i <= n; i+=np){
		x = h * ((double)i - 0.5);
		sum += f(x);
	}

	mypi = h*sum;
	printf("\n Proceso: %d, mypi: %.16f \n",rank, mypi);
	MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0,
	MPI_COMM_WORLD);
	
	/*Reduccion mediante suma del valor computado localmente en el
	proceso 0 */
	if(rank==0)
		printf("\n PI es aproximadamente: %.16f, el error cometido es %.16f",pi,PI25DT-pi);
	MPI_Finalize();
	return 0;
}
