/* 14bhilosjoin.c
Metodo correcto para generar hilos y trabajar con la función
pthread_join() además de acumular valores */
//Miguel Angel Mendoza Guadarrama
//4 - abril - 2018

#include <stdio.h>
#include <pthread.h>
#define NUM_HILOS 10
int sub[NUM_HILOS];

void *hilo(void *i) {
    int valor = *((int *)(i));
    int x,cuenta=0;
    printf("Hola. Soy el hilo: %lu y tengo el valor: %d \n",pthread_self(),valor);
    for(x=0; x<10;x++)
        cuenta=cuenta+(valor*10+1)+x;
     printf("El valor de cuenta para el hilo %d es: %d \n",valor,cuenta);
     sub[valor]=cuenta;
     pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	int i,y[NUM_HILOS];
	int total=0, *subtotal;
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
		printf("tid[i]= %d, valor de subtotal: %d \n",i,sub[i]);
		total=total + sub[i];
	}
	
	printf("***Despues de enlazar o unir total vale: %d***\n",total);
	return 0;
}
