/* 15cuenta.c
*Programa que cuenta las lineas de los archivos de texto que se
la pasen como parametros. Ademas de las lineas de cada archivo,
el programa imprime el numero de lineas totales (contando las
de todos los archivos juntos). Por ejemplo: ./cuenta arch1
arch2 arch3 debera generar una salida como la siguiente (donde
se asume que arch1 tiene 100 lineas, arch2 200 y arch3 300):
./cuenta arch1 arch 2 arch 3
arch1: 100 lineas
arch2: 200 lineas
arch3: 300 lineas
Total: 600 lineas
El programa crea un hilo por cada archivo para permitir que las
lineas de todos los archivos se cuenten concurrentemente. Un
detalle importante es asegurarse de que al final de los archivos
aparacen listados en el mismo orden en el que fueron
especificados. */
//Miguel Angel Mendoza Guadarrama
//02 - abril - 2018

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

/*Estructura que contiene el archivo usar por el hilo
contador y donde el hilo anota el nÃomero de
las lineas de dicho archivo.*/

typedef struct{
	FILE *archivo;
	int lineas;
} dato_t;

/*Cuenta el numero de líneas de un archivo de texto y
cierra su descriptor entrada: flujo del archivo a
procesar. Salida: num. de líneas (-1 si no se puede leer
del archivo)*/

int contar_lineas(FILE *f){
	#define TAMBUF 8129
	char buf[TAMBUF + 1];
	int n, nlineas = 0;
	char *c;
	buf[TAMBUF] = '\0';
	while ((n = fread(buf, sizeof(char), TAMBUF, f)) > 0){
		buf[n] = '\0';
		c = buf;

		while ((c = strchr(c, '\n')) != NULL && c < (buf + TAMBUF)){
			c++;
			nlineas++;
		}
	}

	if(n < 0){
	perror("contar_lineas: read");
	}
	fclose(f);
	return nlineas;
}
/*Función base para los hilos contador*/

void* hilo_contador(void* arg){
	dato_t* d = arg;
	d->lineas = contar_lineas(d->archivo);
	return NULL;
}

/*Mostrar como utilizar el programa * entrada: nombre del
programa*/
void uso(const char* prog){
	fprintf(stderr, "%s arch1 [ ... [archN]]\n", prog);
}
/*Programa principal*/

int main(int argc, char* argv[]){
	int i, total = 0;

	int nh = argc - 1;
	pthread_t idh[nh];
	int creado[nh];
	dato_t datos[nh];
	if (argc <= 1){
		fprintf(stderr, "Error: no hay archivos que procesar \n");
	uso(argv[0]);
	exit(1);	
	}	
	for (i = 0; i < argc - 1; i++){
		creado[i] = 0;
		datos[i].archivo = fopen(argv[i + 1], "r");
		if(datos[i].archivo == NULL){
			fprintf(stderr, "No de puede abrir el archivo '%s' \n", argv[i + 1]);
			perror("Fopen");
				continue;
			}
		if(pthread_create(&idh[i], NULL, hilo_contador, &datos[i]) != 0){
			fprintf(stderr, "No se ha podido crear el hilo contador \n");
			continue;
		}
		creado[i] = 1;
	}
	for(i = 0; i < argc - 1; i++){
		if(!creado[i]){
			printf("No creado\n");
			continue;
		}
		if(pthread_join(idh[i], NULL) != 0){
			fprintf(stderr, "No se ha podido esperar al hilo %lu \n", idh[i]);
			continue;
		}
		printf("%s: %d lineas \n", argv[i + 1], datos[i].lineas);
		total += datos[i].lineas;
	}
	printf("Total: %d \n", total);

return 0;
}
