/*grises3_4hilos.c Convierte una imagen RGB tipo ppm en tonos de grises. Se usa openmp con 4 hilos 
Miguel Angel Mendoza Guadarrama
22 - mayo - 18*/

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int i,j,fil,col,res;
int *R, *G, *B, *result;
char valor[2];
void readfile(){
	FILE *x;
	x = fopen("2000x1000.ppm","r");
	fscanf(x, "%c", &valor[0]);//primer valor P3
	fscanf(x, "%c", &valor[1]);//segundo valor P3
	fscanf(x, "%d %d %d", &fil, &col, &res);//filas, columnas, resolucion
	R = (int *)malloc(fil*col*3*sizeof(int));
	G = (int *)malloc(fil*col*3*sizeof(int));
	B = (int *)malloc(fil*col*3*sizeof(int));
	for (i = 0; i <fil*col*3; i++)
		fscanf(x, "%d %d %d", &R[i], &G[i], &B[i]);
	}

int main(){
	readfile();
	int rank;
	result = (int *) malloc(fil*col*sizeof(int));
	omp_set_num_threads(4);

	#pragma omp parallel for
	for(i=0; i<fil*col;i++){
		result[i] = (R[i] + G[i] + B[i])/3;
		//printf("num hilos: %d \n", omp_get_thread_num());
	}

	printf("%s\n%d %d\n%d\n", valor,fil,col,res);
	for (i=0; i<fil*col; i++)
		printf("%d %d %d ", result[i], result[i], result[i]);
	
	free(R);
	free(G);
	free(B);
	free(result);
return 0;
}
