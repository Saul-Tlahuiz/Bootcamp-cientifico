#include <iostream>
#include <cstdlib>

void fun(int,int); // declaracion

int main(void){
    std::cout<< "Desde la funcion principal" <<std::endl;
    fun(-1324,87945); // llamada

    std::cout << "Despues de invocar la función." << std::endl;
    return EXIT_SUCCESS;
}

void fun(int x, int y){
    std::cout << "Desde dentro de una funcion" <<std::endl;
    std::cout << (x+y) <<std::endl;
    return ;
}