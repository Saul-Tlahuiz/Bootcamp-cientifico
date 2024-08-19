#include <iostream>
#include <cstdlib>

int signo(double numero) {
    if(numero > 0){
    return 1;
    }else{
    return -1;
    }
}

int main() {
    double numero;

    std::cout << "Introduce un numero para determinar su signo: ";
    std::cin >> numero;

    int resultado = signo(numero);

    std::cout << "El signo del numero " << numero << " es: " << resultado << std::endl;

    return 0;
}