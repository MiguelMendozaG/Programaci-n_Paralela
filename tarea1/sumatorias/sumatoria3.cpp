//sumatoria3.cpp
//Programa que calcula la suma del 1 al 4000000000 y devuelve el tiempo que le toma realizar esa operación
//Autor: Miguel Angel Mendoza Guadarrama
//5 de marzo de 2018
#include <iostream>
#include <time.h>

int main(int argc, char **argv) {
  
    int inicio = 1;
    //long int fin = 4000000000;
    long int fin = 2147483646;
    long long int resultado = 0;
    clock_t t_ini, t_fin;
    double secs;
    std::cout << "Suma 3: de 1 a " << fin <<std::endl;
    
    t_ini = clock();
    for (inicio; inicio <= fin; inicio++){
      resultado += inicio;
      //std::cout << "res: "<< resultado << "i: "<< inicio << std::endl;
      
    }

    t_fin = clock();
    
    secs = (double) (t_fin - t_ini) / CLOCKS_PER_SEC;
    std::cout << "Suma = " << resultado << std::endl;
    std::cout << secs * 1000.0 << " milisegundos\n" << std::endl;
    
    return 0;
}
