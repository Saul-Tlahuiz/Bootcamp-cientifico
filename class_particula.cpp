#include <iostream>
#include <cstdlib>

class Particula{ //clase base o superclase
    public:
    float a,b;

    void imprime(void){
        std::cout <<a<<',' <<b<< std::endl;
    }
};

class Planeta:public Particula{ //clase que hereda
    public: 
    float masa;
};

class Otra:public Planeta{
    public:
    float temporal;

    void imprime(void){
        std::cout <<a<<','<<b<<','<<masa<<','<<temporal<<std::endl;
    }
};

int main(int argc, char** argv){
    Particula p1;
    Planeta p2;
    Otra prueba;

    std::cout <<sizeof(p1)<<std::endl;
    std::cout <<sizeof(p2)<<std::endl;
    std::cout <<sizeof(prueba)<<std::endl;

    Otra* aptObj = nullptr;

    p1.a = 0;
    p1.b = 0;
    prueba.imprime();

    p2.a = 0;
    p2.b = 0;
    p2.masa = 8734;

    aptObj = &prueba;
    std::cout<<p2.masa<<std::endl;

    return EXIT_SUCCESS;
}