/* 14bhilosjoin.c
Sumatoria hasta 1000000000 con 8 hilos */
//Miguel Angel Mendoza Guadarrama
//9 - abril - 2018

#include <stdio.h>
#include <pthread.h>
#define NUM_HILOS 8
long int sub[NUM_HILOS];
long int sumatoria= 1000000000;
long int res;


void *hilo(void *i) {
    int valor = *((int *)(i));
    long int x,cuenta=0;
    printf("Hola. Soy el hilo: %lu y tengo el valor: %d \n",pthread_self(),valor);
    for(x=0; x<sumatoria/NUM_HILOS;x++)
        cuenta=cuenta+(valor* sumatoria/NUM_HILOS +1)+x;
     printf("El valor de cuenta para el hilo %d es: %ld \n",valor,cuenta);
     sub[valor]=cuenta;
     pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	int i,y[NUM_HILOS];
	long int total=0, *subtotal;
	pthread_t tid[NUM_HILOS];
	for(i=0; i<NUM_HILOS; i++) {
		y[i]=i;
		if(pthread_create(&tid[i], NULL, hilo, (void *)(&y[i])))
			{ printf("Error al crear el hilo \n");
			break;
			}
	}

	for(i=0; i<NUM_HILOS; i++)
	{
		pthread_join(tid[i],NULL);
		printf("tid[i]= %d, valor de subtotal: %ld \n",i,sub[i]);
		total=total + sub[i];
	}
	
	printf("***Despues de enlazar o unir total vale: %ld***\n",total);
	return 0;
}
