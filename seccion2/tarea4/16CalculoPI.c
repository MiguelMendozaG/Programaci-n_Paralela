/* 16CalculoPI.c 
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
	n=100;
	h=1.0/(double)n;
	sum = 0.0;

	//Suma de intervalos
	for(i=rank+1; i<=n; i+=np) {
		x = h*((double)i - 0.5);
		sum = sum + f(x);
	}
	mypi = h*sum;
	printf("\n Proceso: %d, mypi: %.16f \n",rank,mypi);
	if(rank==0) {
		pi = mypi;
		for(i=1; i<np; i++){
			origen=i; //recibe resultados del resto de procesos
			MPI_Recv(&mypi, 1, MPI_DOUBLE, origen, tag, MPI_COMM_WORLD, &status);
			pi += mypi;
		}
		printf("\n PI es aproximadamente: %.16f, el error cometido es %.16f",pi,PI25DT-pi);
		} 
	else {
		destino=0; // Envia calculo local a proceso 0
		MPI_Send(&mypi, 1, MPI_DOUBLE, destino, tag, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}
