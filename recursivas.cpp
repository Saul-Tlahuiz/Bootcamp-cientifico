#include <iostream>
#include <cstdlib>

unsigned long int factorial(int);

int main(int argc, char** argv){
    unsigned long int test = 0;
    std::cout <<sizeof(test)<<std::endl;
    std::cout << factorial(25);
    return EXIT_SUCCESS;
}

unsigned long int factorial(int n){ //unsigned indica que son valores sin signo es decir que solo toma valores positivos
    if(n < 0) exit(EXIT_FAILURE);
    else if(n == 0 || n == 1) return 1;
    else return n*factorial(n-1);
}

//buscar la implementacion del algoritmo quicksort en C++ y explicar lo que entiendo de como funciona