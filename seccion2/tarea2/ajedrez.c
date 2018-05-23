/* ajedrez.c crea una imagen de un ajedrez en formato p1 de ppm
Miguel Angel Mendoza Guadarrama
22 - mayo - 18
 */

#include<stdio.h>
#include<stdlib.h>

int main(){
	int row = 800, col = 800;
	long int i, j;
	int color = 0, color1 = 0, color2 = 1;
	char tipo[2] = "p1";
	printf("P1\n%d %d \n",row, col);
	for (i = 0; i < row; i++){
		if (i%100 == 0)	{
			if (color == color1)
				color = color2;
			else if (color == color2)
				color = color1;
		}
		for (j = 0; j < col; j++){
			if (j%100 == 0){
				if (color == color1)
					color = color2;
				else if (color = color2)
					color = color1;	
			}
			printf("%d\n",color);
		}
	}
	return 0;
}
