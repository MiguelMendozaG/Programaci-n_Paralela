/* ppm800x600.c Genera una imagen de tipo ppm 
Para generar la imagen se debe ejecutar:
./ppm800x600 >> imagen.ppm
Miguel Angel Mendoza Guadarrama
22 - mayo - 18
*/

#include<stdio.h>
#include<stdlib.h>
int main(){
	srand(time(NULL));
	int i,j,v;
	printf("P3\n800 600 \n 255");
	for (i=0; i<600; i++){
		printf("\n");
		for(j=0; j<800; j++){
			printf("%d %d %d ", rand()%255, rand()%255, rand()%255);		
		}		
	}
return 0;
}
