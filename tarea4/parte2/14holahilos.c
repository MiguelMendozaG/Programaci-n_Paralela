/*14holahilos.c
Programa que implementa hilos múltiples pasando
referencia a la función hilo implementando valores
pasados por referencia, y regresa la función la
referencia de un valor modificado
Realiza sumas parciales según el número de datos y el
número de hilos. Al final se realiza la suma total */
//Miguel Angel Mendoza Guadarrama
//10 - 04 - 18
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define NUM_HILOS 4
#define DATOS 100
//Tabla con los identificadores de los hilos
pthread_t tid[NUM_HILOS];
//Tipo de datos y tabla (estructura) con los parametros
typedef struct{
int id;
}thr_param_t;
thr_param_t param[NUM_HILOS];
void *hilo(thr_param_t *p)
//Funcion que ejecutan los hilos
{
int cuenta=0, i, li;
li=DATOS/NUM_HILOS*p->id+1;
for(i=li; i<li+DATOS/NUM_HILOS; i++)
cuenta=cuenta+i;
printf("Soy el hilo numero: %d y produje la siguiente cuenta: %d \n",p->id,cuenta);
p->id=cuenta;
pthread_exit(&p->id); //se devuelve el valor (mas bien la direccion)
}
int main(int argc, char *argv[])
{
int i,*res,total=0;
printf("Creando hilos...\n");
for(i=0; i<NUM_HILOS; i++){
param[i].id= i;
if(pthread_create(&tid[i], NULL, (void *)&hilo,&param[i]))
{
printf("Error al crear el hilo \n");
exit (0);
}
}
printf("Hilos creados.... Esperando a que terminen....\n");
for(i=0; i<NUM_HILOS; i++){
pthread_join(tid[i],(void *)&res);
printf("El hilo: %d devolviÃ3 el valor: %d\n",i,*res);
total=total+*res;
}
printf("Suma final: %d \n",total);
printf("Todos los hilos finalizados... \n");
return 0;
}
