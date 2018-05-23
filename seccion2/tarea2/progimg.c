/* progimg.c Convierte una imagen RGB tipo ppm en tonos de grises 
Miguel Angel Mendoza Guadarrama
22 - mayo - 18*/
#include<stdio.h>

int result [150000], R[150000], G[150000], B[150000];
int i, j,v, filas, columnas;
char valor[2]; //para poder leer el encabezado

void readfile(){
	FILE* x;
	x = fopen("imagen_ascii.ppm","r");
	fscanf(x, "%c", &valor[0]);//primer valor P3
	fscanf(x, "%c", &valor[1]);//segundo valor P3
	fscanf(x, "%d %d %d", &filas, &columnas, &v);//filas, columnas, resolucion

	for (i=0; i < filas*3*columnas; i++){
		fscanf(x, "%d %d %d", &R[i], &G[i], &B[i]);	
	}
}

//Programa principal
int main(){
	int i;
	readfile();
	printf("P3 \n%d %d \n%d\n", filas, columnas,v);
	for(i=0; i <filas*columnas; i++){
		result[i] = (R[i], G[i], B[i])/3;
		//printf("%d %d %d \n", R[i], G[i], B[i]);
		printf("%d %d %d ", result[i], result[i], result[i]);
	}
	return 0;
}
