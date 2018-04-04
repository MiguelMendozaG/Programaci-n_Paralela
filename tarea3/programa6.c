/*17mutex.c
Usando mutex
*/
//Miguel Angel Mendoza Guadarrama
//02 - abril - 2018


#include <stdio.h>
#include <pthread.h>
#define NUM_HILOS 2
#define CICLO 100

double b;
void* hiloDeposito(void *i){
	double m = *(double *) (i);
	int j;
	printf("Entrando a hiloDeposito \n");
	for(j = 0; j < CICLO + 1; j++){
		b += m;
		//sleep(1);
	}
}

void* hiloRetiro(void *i){
	double m = *(double *) (i);
	int j;
	printf("Entrando a hiloRetiro \n");
	for(j = 0; j < CICLO; j++){
		b -= m;
		//sleep(1);
	}
}

int main(){
	int i;
	double bi;
	double q = 10.0;
	printf("Antes de crear tipo de hilos \n");
	pthread_t tid[NUM_HILOS];
	b = 100000.0;
	bi = b;
	printf("Antes de crear los hilos \n");
	pthread_create(&tid[0], NULL, hiloDeposito, (void *) (&q));
	pthread_create(&tid[1], NULL, hiloRetiro, (void *) (&q));

	for(i = 0; i < NUM_HILOS; i++){
		pthread_join(tid[i], NULL);
	}
	printf("El balance inicial es: %.2lf \nEl balance final es: %.2lf \n", bi, b);
	return 0;
}
