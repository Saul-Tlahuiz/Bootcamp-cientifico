#include <iostream>

float raiz(float x);

int main (void){
    std::cout << "Este programa calcula las raices de un polinomio" << std::endl;
    std::cout << "de segundo grado" << std::endl;
    std::cout << "usando la formula general\n\n" << std::endl;

    std::cout << "Ingresa un numero positivo:";
    float dato;
    std::cin >> dato;

    float resultado;
    resultado = raiz(dato);

    if (resultado < 0){
      std::cout<< "Su raiz es imaginaria\n";
    exit(1);
    }else
      std::cout << raiz(dato) << std::endl;
    return 0;
}

float raiz(float x){
    float tol = 0.0000001;
    float a = x;
    float b = 1;

    if(x>0){
        while ((a-b)*(a-b) > tol)
        {
        a = (a+b)/2;
        b = x/a;
        }
        return a;
    }
    return -1.0;
}