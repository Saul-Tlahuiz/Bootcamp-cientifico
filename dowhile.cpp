#include <iostream>

int main(void){
    char a = 'z';
    std::cout << "Escribe una letra" <<std::endl;
    std::cin >> a;
    do{
        std::cout << "El valor de la letra es:" << a << std::endl;
        std::cout << "Escribe una letra" <<std::endl;
        std::cin >> a;
    } while (a == 'a');

    return 0;
}