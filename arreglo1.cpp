#include <iostream>
#include <cstdlib>

int main(int argc, char** argv){
    int arreglo[10];

    arreglo[0] = 0;

    for(int i = 0;i <10; i++)
    arreglo[i] = 0;
    for(int i = 0;i <10; i++)
    std::cout <<arreglo[i]<<' '<<std::endl;

    return EXIT_SUCCESS;
}