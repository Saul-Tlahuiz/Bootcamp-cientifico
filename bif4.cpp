#include <iostream>
int main (void){
    std::cout << "Escribe una letra";
    char opcion;
    std:: cin >> opcion;

    switch(opcion){
        case 'a' :std::cout << "Escogiste la opcion a/n";
        break;
        case 'b' :std::cout << "Escogiste la opcion b/n";
        break;
        case 'c' :std::cout << "Escogiste la opcion c/n";
        break;
        default: std::cout<< "No escogiste una opcion valida/n";
    }
    return 0;
}