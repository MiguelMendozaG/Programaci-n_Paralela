/*13holahilos.c
Programa que implementa hilos múltiples pasando
referencia a la función hilo implementando valores
pasados por referencia, y regresa la función la
referencia de un valor modificado. Genera una cadena
con mensaje. Cada valor de X será diferente para cada
hilo. Se requiere la función pthread_join() para
recibir el parámetro
*/
//Miguel Angel Mendoza Guadarrama
//10 - 04 - 18
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#define NUM_HILOS 10
//Tabla con los identificadores de los hilos
pthread_t tid[NUM_HILOS];
//Tipo de datos y tabla (estructura) con los parametros
typedef struct{
int id;
char *cadena;
}thr_param_t;
/*se tiene que crear una tabla para los parámetros ya
que se pasan por referencia. Así si solo se tuviera una
variable para los parámetros, al modifcar esta, se
modificarían todas las que se habian pasado
anteriormente porque los hilos no se quedan con el
valor, sino con la dirección */
thr_param_t param[NUM_HILOS];
void *hilo(thr_param_t *p)
//Funcion que ejecutan loshilos
{
printf("%s %d \n", p->cadena, p->id);
pthread_exit(&p->id); //se devuelve el valor (mas bien la direccion)
}
int main(int argc, char *argv[])
{
int i,*res;
printf("Creando hilos...\n");
for(i=0; i<NUM_HILOS; i++){
param[i].cadena=strdup("Hola, soy el hilo ");
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
printf("El hilo: %d devolviÃ3 el valor: %d \n",i,*res);
}
printf("Todos los hilos finalizados... \n");
return 0;
}
