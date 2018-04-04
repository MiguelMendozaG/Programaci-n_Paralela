/*16mutex2.c
*Programa que hace que tres hilos
impriman cada uno una serie de 5 caracteres (cada hilo un
carácter diferente) en pantalla incluyendo la función
principal, la cual se considera como un hilo, variación
quitando las líneas de bloqueo y desbloqueo mutex
*/
//Miguel Angel Mendoza Guadarrama
//02 - abril - 2018

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//Variable mutex
pthread_mutex_t m;
void* hilo01(void* arg){
	int i;
	//Bloqueando:
	pthread_mutex_lock(&m);
	for(i = 0; i < 5; i++){
		printf(".\n");
		fflush(stdout);
		sleep(1);
	}
	printf("\n");
	//Desbloqueo
	pthread_mutex_unlock(&m);
	return NULL;
}
void* hilo02(void* arg){
		int i;
		//Bloqueando:
		pthread_mutex_lock(&m);
	for(i = 0; i < 5; i++){
		printf("o\n");
		fflush(stdout);
		sleep(1);
	}
	printf("\n");
	//Desbloqueo
	pthread_mutex_unlock(&m);
	return NULL;
}

void* hilo03(void* arg){
	int i;
	//Bloqueando:
	pthread_mutex_lock(&m);
	for(i = 0; i < 5; i++){
		printf("+\n");
		fflush(stdout);
		sleep(1);
	}
	printf("\n");
	//Desbloqueo
	pthread_mutex_unlock(&m);
	return NULL;
}
//Programa principal
int main(){
	int i;
	pthread_t h1, h2, h3;
	//Iniciando mutex
	pthread_mutex_init(&m, NULL);
	if(pthread_create(&h1, NULL, hilo01, NULL)){
		printf("Error al crear el hilo 1 \n");
		abort();
	}
	if(pthread_create(&h2, NULL, hilo02, NULL)){
		printf("Error al crear el hilo 2\n");
		abort();
	}
	if(pthread_create(&h3, NULL, hilo03, NULL)){
		printf("Error al crear el hilo 3\n");
		abort();
	}
	pthread_join(h1,NULL);
	pthread_join(h2,NULL);
	pthread_join(h3,NULL);
	pthread_mutex_lock(&m);
	for(i = 0; i < 5; i++){
		printf("x\n");
		fflush(stdout);
		sleep(1);
	}
	pthread_mutex_unlock(&m);
	//Eliminando mutex
	pthread_mutex_destroy(&m);
	printf("\n Fin del programa principal \n");
	return 0;
}
