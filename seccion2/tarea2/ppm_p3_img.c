/*ppm_p3_img.c Genera una imagen de 800x800 en formato p3 de ppm
Miguel Angel Mendoza Guadarrama
22 - mayo - 18*/

#include<stdio.h>
#include<stdlib.h>

int main(){

	int row = 800, col = 800;
	int i, j;
	int color = 0, color1 = 0, color2 = 255, color3=0;
	char tipo[2] = "P3";
	printf("P3\n%d %d \n255 \n",row, col);
	srand(time(NULL));

	for (i = 0; i < row; i++){
		color1 = rand()%100;
		color2 = 255 - color1;
		color3 = 255 - i;
		if (color3<0) color3 = color1;
		if (i%100 == 0)	{
			if (color == color1){
				color = color2;
			}
			else if (color == color2){
				color = color1;
			}
		}
		for (j = 0; j < col; j++){
			if (j%100 == 0){
				if (color == color1){
					color = color2;
				}
				else if (color = color2){
					color = color1;	
				}
			}
			printf("%d %d %d \n",color,color3,color2);
		}
	}

	return 0;
}

