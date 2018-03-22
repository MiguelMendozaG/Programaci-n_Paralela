//main.cpp
//programa que encuentra los nḿeros primos entre el 2 y el 100
//Miguel Angel Mendoza Guadarrama
//21 - marzo - 2018

#include <iostream>

int main(int argc, char **argv) {
    
  double res; 
  int mod;
  for (int num = 2; num < 100; num++){
    for (int i = 2; i < num; i++){
      if (num%i != 0){
	res = num/i;
	if (res < i){
	  std::cout << "\n Numero primo encontrado: " << num << std::endl;
	  break;
	}
      }
      else if (num%i == 0){
	break;
      }
      
      
    }
  }
  
    return 0;
}
