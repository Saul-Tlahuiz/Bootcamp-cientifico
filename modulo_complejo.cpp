#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath> // esta biblioteca la usaremos para poder usar la funcion raiz

/*
Codigo a replicar en Julia
vamos a generar la funcion que calcula el modulo de un numero complejo
Datos de entrada
complejo -> real
datos de salida -> real
procedimiento:
function modulo(complejo)
    r_2 = complejo[1]*complejo[1]
    i_2 = complejo[2]*complejo[2]
    resultado = sqrt(r_2 + i_2)
end
ejemplo:modulo([1,1])
resultado:1.4142135623730951
=#
function modulo(complejo)
    r_2 = complejo[1]*complejo[1]
    i_2 = complejo[2]*complejo[2]
    resultado = sqrt(r_2 + i_2)
end
*/

std::vector<double> moduloComplejo(const std::vector<double>& complejo){
    double r_2 = complejo[0]*complejo[0];
    double i_2 = complejo[1]*complejo[1];
    double resultado = std::sqrt(r_2 + i_2);
    return {resultado};
}

int main(){
    std::vector<double> complejo = {1.0, 1.0};

    std::vector<double> resultado = moduloComplejo(complejo);
    std::cout<<"El modulo del numero complejo dado es: " <<resultado[0]<<std::endl;
    return EXIT_SUCCESS;
}

