#include <iostream>
#include <cstdlib>

void func(double*,double*);

int main(void){
    double par1, par2;

    par1 = -1324.1324;
    par2 = 87945.345;

    std::cout << "Desde la funcion principal"<<std::endl;
    func(&par1,&par2);
    std::cout << "Desde invocar la funcion"<<std::endl;
    std::cout << "Parametros de entrada: "<<par1<< ' ' << par2<<std::endl;

    return EXIT_SUCCESS;
}