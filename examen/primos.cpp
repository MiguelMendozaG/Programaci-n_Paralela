/* primos.c
Encuentran numeros primos entre el 400,000 y el 550,000 en 4,8,16 y 32 hilos */
//Miguel Angel Mendoza Guadarrama
//15 - abril - 2018

#include <stdio.h>
#include <pthread.h>
#define NUM_HILOS 1
long int sub[NUM_HILOS];
long int sumatoria= 550000;
long int sum_init = 400000;
long int res;


void *hilo(void *i) {
	 //FILE* fichero;
	 //fichero = fopen("examen_primos.txt", "wt");
    int valor = *((int *)(i));
    long int x,cuenta=0, x_init, x_end,num;
    //printf("\nHola. Soy el hilo: %lu y tengo el valor: %d \n",pthread_self(),valor);
	x_init = ((float)(sumatoria-sum_init)/NUM_HILOS) * valor+sum_init+1;
	x_end = sumatoria  - ((float)(sumatoria-sum_init)/NUM_HILOS) * (NUM_HILOS - (valor +1));
	//printf ("\nx_init: %ld  x_end: %ld   hilo: %d",x_init,x_end,valor);
    for(x=x_init; x<=x_end; x++){
		num =x;
		//printf ("x_init: %ld \t x_end: %ld ",x_init,x_end);	
		for (int i = 2; i < x; i++){
		  if (num%i != 0){
			res = num/i;
			if (res < i){
				//printf("\n Numero primo encontrado: %ld",num);
				//fprintf(fichero,"%ld\n",num);
				cuenta++;
				break;
			}
			  }
			else if (num%i == 0){
				break;
			}
		}
	}
     printf("La cantidad de numeros primos en el hilo %d es: %ld \n",valor,cuenta);
     sub[valor]=cuenta;
	//fclose(fichero);
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
		//printf("\ntid[i]= %d, valor de subtotal: %ld \n",i,sub[i]);
		total=total + sub[i];
	}
	
	printf("***Despues de enlazar o unir total vale: %ld ***\n",total);
	return 0;
}
