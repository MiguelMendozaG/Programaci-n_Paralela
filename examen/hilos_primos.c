/* sumatoria500_hilo1.c
Sumatoria hasta 500,000 con un hilo */
//Miguel Angel Mendoza Guadarrama
//9 - abril - 2018

#include <stdio.h>
#include <pthread.h>
#define NUM_HILOS 2
int sub[NUM_HILOS];
long int sumatoria= 100;
long int res;
long int x_start=0;
//long int num = 550000;

void *hilo(void *i) {
    int valor = *((int *)(i));
	int ii =0;
    long int x,cuenta=0, intervalos = sumatoria/NUM_HILOS;;
    printf("\n Hola. Soy el hilo: %lu y tengo el valor: %d \n",pthread_self(),valor);
    //for(x=1; x<sumatoria/NUM_HILOS ;x++){
		for (ii = (valor * intervalos)+1; ii < ((valor * intervalos) + intervalos)+1; ii++){
			printf ("\n i: %d, limite superior: %ld",ii, ((valor * intervalos) + intervalos)+1);
			if (x%ii != 0){
				res = x/ii;
				if (res < ii){
					printf ("\n Numero primo encontrado: %ld",x);
					cuenta+=1;
					//break;
				}
		  	}
		  	else if (x%ii == 0){
				//break;
		  	}
		}		
	//}
     printf("\n La cantidad de números primos para el hilo %d es: %ld \n",valor,cuenta);
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
