#include <iostream>
#include <cstdlib>
#include <vector>

/*
Codigo de Julia a replicar en C++
Funcion para multiplicar numeros complejos
Datos de entrada
vamos a proponer usar un arreglo para representar los numeros complejos
Datos de salida
reales
Procedimiento:
function multComplejos(operando1,operando2)
    prodReal = operando1[1]*operando2[1] - operando1[2]*operando2[2]
    prodImg = operando1[1]*operando2[2] + operando1[2]*operando2[1]
    return prodReal,prodImg
end
*/

std::vector<double> multComplejos(const std::vector<double>& operando1, const std::vector<double>& operando2) {
    double prodReal = operando1[0] * operando2[0] - operando1[1] * operando2[1];
    double prodImg = operando1[0] * operando2[1] + operando1[1] * operando2[0];
    return {prodReal, prodImg};
}

int main() {
    // Definir dos números complejos
    std::vector<double> operando1 = {3.0, 2.0}; // Representa 3 + 2i
    std::vector<double> operando2 = {1.0, 4.0}; // Representa 1 + 4i

    // Multiplicar los números complejos
    std::vector<double> resultado = multComplejos(operando1, operando2);
    
    // Imprimir el resultado
    std::cout << "El resultado de la multiplicación es: " 
              << resultado[0] << " + " << resultado[1] << "i" << std::endl;

    return 0;
}
