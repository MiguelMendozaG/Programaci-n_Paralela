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
	for(i = 0; i < 5; i++){
		printf(".");
		fflush(stdout);
		sleep(1);
	}
	return NULL;
}
void* hilo02(void* arg){
	int i;
	for(i = 0; i < 5; i++){
	printf("o");
	fflush(stdout);
	sleep(1);
	}
	return NULL;
}
void* hilo03(void* arg){
	int i;
	for(i = 0; i < 5; i++){
		printf("+");
		fflush(stdout);
		sleep(1);
	}
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
		printf("Error al crear el hilo 2 \n");
		abort();
	}
	if(pthread_create(&h2, NULL, hilo03, NULL)){
		printf("Error al crear el hilo \n");
		abort();
	}
	for(i = 0; i < 5; i++){
		printf("x");
		fflush(stdout);
		sleep(1);
	}
	printf ("\n");
	//Eliminando mutex
	pthread_mutex_destroy(&m);
	printf("\n Fin del programa principal \n");
	return 0;
}
