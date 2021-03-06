/*11holahilos.c
Programa que implementa hilos múltiples pasando
referencia a la función hilo implementando tanto valores
pasados por referencia, como identificador de hilo y regresa la función la referencia de un valor modificado.
Se requiere la función pthread_join() para recibir el dato
*/
//Miguel Angel Mendoza Guadarrama
//10 - 04 - 18
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define NUM_HILOS 4
void *hilo(void *pArg)
{
	int myNum = *((int*)pArg);
	int a;
	printf("soy el hilo numero: %d \n",myNum);
	a = myNum*10;
	printf("el valor modificado vale %d \n",a);
	pthread_exit(&a);
}

int main(){
	int i, b=0, tnum[NUM_HILOS], *res;
	res = &b;
	pthread_t tid[NUM_HILOS];
	for(i=0; i < NUM_HILOS; i++){
		tnum[i] = i;
		if (pthread_create(&tid[i], NULL, hilo, &tnum[i])){
			printf("Error el crear el hilo \n");
			exit(0);
		}
	}
	for (i=0; i<NUM_HILOS; i++){
		printf("El valor devuelto por el hilo: %d es: %d \n",i,*res);
		pthread_join(tid[i],(void *)&res);
	}
	return 0;
}

