/* 14c-hilosjoin.c
Metodo correcto para generar hilos y trabajar con la función
pthread_join() además de acumular valores */
//Miguel Angel Mendoza Guadarrama
//02 - abril - 2018

#include <stdio.h>
#include <pthread.h>
#define NUM_HILOS 10
#define VALORES 100

void *hilo(void *i) {
	int valor = *((int *)(i));
	int x,cuenta=0;
	printf("Hola. Soy el hilo: %lu y tengo el valor: %d \n",pthread_self(),valor);
	
	for(x=0; x<VALORES/NUM_HILOS; x++)
		cuenta=cuenta+(valor*10+1)+x;
	printf("El valor de cuenta para el hilo %d es: %d \n",valor,cuenta);
	pthread_exit((void *) &cuenta);
	}

int main(int argc, char *argv[]) {
	int i,y[NUM_HILOS];
	int total=0;
	int *subtotal;
	pthread_t tid[NUM_HILOS];
	
	for(i=0; i<NUM_HILOS; i++) {
		y[i]=i;
		if(pthread_create(&tid[i], NULL, hilo, (void *)(&y[i]))){
			printf("Error al crear el hilo \n");
			break;
		}
	}

	for(i=0; i<NUM_HILOS; i++)
	{
		pthread_join(tid[i], (void **)&subtotal);
		printf("tid[i]= %d, valor de subtotal: %d \n",i,*subtotal);
		total=total + *subtotal;
	}

	printf("---Despues de enlazar o unir total vale: %d---\n",total);
	return 0;
}
