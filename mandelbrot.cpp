
/*
Para generar el conjunto de Mandelbrot vamos a utilizar la funcion para multiplicar numeros complejos y la de modulo


std::vector<double> multComplejos(const std::vector<double>& operando1, const std::vector<double>& operando2) {
    double prodReal = operando1[0] * operando2[0] - operando1[1] * operando2[1];
    double prodImg = operando1[0] * operando2[1] + operando1[1] * operando2[0];
    return {prodReal, prodImg};
}

std::vector<double> moduloComplejo(const std::vector<double>& complejo){
    double r_2 = complejo[0]*complejo[0];
    double i_2 = complejo[1]*complejo[1];
    double resultado = std::sqrt(r_2 + i_2);
    return {resultado};
}

*/

#include <iostream>
#include <vector>
#include <cmath>

// Función para multiplicar dos números complejos
std::vector<double> multComplejos(const std::vector<double>& operando1, const std::vector<double>& operando2) {
    double prodReal = operando1[0] * operando2[0] - operando1[1] * operando2[1];
    double prodImg = operando1[0] * operando2[1] + operando1[1] * operando2[0];
    return {prodReal, prodImg}; //aqui se hizo un ajuste para reducir el codigo anterior pero funciona igual
}

// Función para calcular el módulo de un número complejo
double modulo(const std::vector<double>& complejo) {
    double r_2 = complejo[0] * complejo[0];
    double i_2 = complejo[1] * complejo[1];
    return std::sqrt(r_2 + i_2); //tambien se redujo esta parte 
}

// Función para verificar si un número complejo diverge
bool divergeQ(const std::vector<double>& z) {
    return modulo(z) > 2;
}

int main() {
    const int SIZE = 1000;
    std::vector<std::vector<int>> fractal(SIZE, std::vector<int>(SIZE, 127));
    
    std::vector<double> x(SIZE);
    std::vector<double> y(SIZE);

    // Inicializar los rangos x e y
    for (int i = 0; i < SIZE; ++i) {
        x[i] = -2.0 + 1.5 * i / (SIZE - 1);
        y[i] = -1.5 + 1.5 * i / (SIZE - 1);
    }

    // Generar el fractal
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            double a = x[i];
            double b = y[j];
            std::vector<double> dato = {a, b};
            std::vector<double> z = {0.0, 0.0};

            int k;
            for (k = 1; k <= 256; ++k) {
                z = multComplejos(z, z);
                z[0] += dato[0];
                z[1] += dato[1];

                if (divergeQ(z)) {
                    fractal[i][j] = k;
                    break;
                }
            }
        }
    }

    // Imprimir el fractal
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << fractal[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
