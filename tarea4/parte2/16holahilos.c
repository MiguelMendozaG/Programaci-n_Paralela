/*16holahilos.c
Programa que implementa hilos múltiples pasando
referencia a la función hilo implementando tanto valores
pasados por referencia, como idetnficador de hilo
Realiza sumas parciales y la suma total se agrega en una variable global*/
//Miguel Angel Mendoza Guadarrama
//10 - 04 - 18
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define NUM_HILOS 4
#define DATOS 100
int suma = 0;
void *hilo(void *pArg){
	int li,i,subtotal=0;
	int myNum = *((int*)pArg);
	li=DATOS/NUM_HILOS*myNum+1;
	for(i=li; i<li+DATOS/NUM_HILOS; i++)
		subtotal=subtotal+i;
	printf("soy el hilo numero: %d y produje la siguiente cuenta: %d \n",myNum,subtotal);
	suma=suma+subtotal;
	pthread_exit(NULL);
}

int main()
{
int i,tnum[NUM_HILOS];
pthread_t tid[NUM_HILOS];
for(i=0; i<NUM_HILOS; i++){
	tnum[i]=i;
	if(pthread_create(&tid[i], NULL, hilo, &tnum[i])){
		printf("Error al crear el hilo \n");
		exit(0);
	}
}
for(i=0; i<NUM_HILOS; i++)
pthread_join(tid[i],NULL);

printf("La suma total es: %d \n",suma);

return 0;
}
