#include <iostream>
#include <cstdlib>

int main(void){
    double par1;
    std::cout << &par1 <<std::endl; // con el operador ampersan o & obtenemos el espacio de memoria donde se guarda la variable par1 y nos la devuelve
    return EXIT_SUCCESS;
} 