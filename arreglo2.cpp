#include <iostream>
#include <cstdlib>

int main(int argc, char** argv){
    int arreglo[10];
    int* apArr;

    apArr = arreglo;

    for(int i = 0;i <10; i++)
    arreglo[i] = 0;
    for(int i = 0;i <10; i++){
        *apArr = 0;
        apArr++;
    }

    for(int i = 0; i<10; i++)
    std::cout << arreglo[i] << std::endl;
    std::cout<<std::endl;

    return EXIT_SUCCESS;
}

//las funciones en C deben consumir todos los inputs o hay algunos que se pueden omitir?