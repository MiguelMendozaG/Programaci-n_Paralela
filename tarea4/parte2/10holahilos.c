/*10holahilos.c
Programa que implementa hilos múltiples pasando
referencia a la función hilo implementando tanto valores
pasados por referencia, como identificador de hilo
Se requiere la función pthread_join()
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
	printf("soy el hilo numero: %d y mi id es: %lu\n",myNum,pthread_self());
	pthread_exit(NULL);
}

int main(){
	int i, tnum[NUM_HILOS];
	pthread_t tid[NUM_HILOS];
	for(i=0; i < NUM_HILOS; i++){
		tnum[i] = i;
		if (pthread_create(&tid[i], NULL, hilo, &tnum[i])){
			printf("Error el crear el hilo \n");
			exit(0);
		}
	}
	for (i=0; i<NUM_HILOS; i++)
		pthread_join(tid[i], NULL);
	return 0;
}

