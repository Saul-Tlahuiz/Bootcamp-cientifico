#include <iostream>
#include <cstdlib>
#include <cmath>

//para la funcion seno vamos a necesitar evaluar si el numero que se pasa esta dentro del intervalo [-pi,pi]

// Definir la constante PI
const double PI = 3.14159265358979323846;

// Función para verificar si un número está dentro del intervalo [-π, π]
bool estaDentroDelIntervalo(double numero) {
    return (numero >= -PI && numero <= PI);
}


int main() {
    double numero;

    std::cout << "Introduce un numero para verificar si está dentro del intervalo [-π, π]: ";
    std::cin >> numero;

    if (estaDentroDelIntervalo(numero)) {
        std::cout << "El numero " << numero << " está dentro del intervalo [-π, π]." << std::endl;
    } else {
        std::cout << "El numero " << numero << " no está dentro del intervalo." << std::endl;
    }
    return EXIT_SUCCESS;
}


/*
ya que tenemos la funcion que nos dice si el numero dado pertenece al intervalo [-pi,pi] vamos a escribir la funcion para el signo, misma que
usaremos despues para la funcion del calculo del seno, para la codificacion de esta funcion nos vamos a apoyar en el codigo escrito en julia
function signo(x)
    if x > 0
        return 1
    else 
        return -1
    end
end
*/ 

int signo(double numero) {
    if (numero > 0) {
        return 1;   // Retorna 1 si el número es mayor que 0
    } else {
        return -1;  // Retorna -1 si el número es menor o igual a 0
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

/*
ya que se tienen las 2 funciones anteriores vamos a escribir la funcion del seno y la juntaremos con las funciones anteriores
*/
double seno(double x) {
    double x_0 = x / 1024;
    double y = x_0 * x_0;
    for (int i = 0; i < 10; ++i) {
        y = 4 * y * (1 - y);
    }
    return y;
}

int main() {
    std::cout << "Introduce un numero entre el intervalo [-π, π] para calcular el seno" << std::endl;
    double numero;
    std::cin >> numero;

    estaDentroDelIntervalo(numero);
    double seno_calculado = std::sqrt(seno(numero)) * signo(numero);
    std::cout << "El seno del numero " << numero << " es: " << seno_calculado << std::endl;

    return 0;
}


