#include <iostream>
#include  <cstdlib>
// vamos a definir una clase generica

class Generica{
    private:
    int x,y;
    public:
    Generica(int atr1, int atr2)
    :x{atr1},y{atr2}
    {}
    Generica& operator ++(void){ //SOBRECARGAMOS EL OPERADOR INCREMENTO
        x++; //el atributo x se incrementa en 1
        --y; //el atributo se decrementa en 1
        //std::cout<<x<<", " <<y<<std::endl;
        return *this;
    }
    Generica& operator +=(const Generica& operando2){
        x+=operando2.x;
        y+=operando2.y;
        return *this;
    }

    void imprime(){
        std::cout<<"Atributo x:"<<x<<", "<<"Atributo y:"<<y<<std::endl;
    }
};

int main(int argc, char** argv){
    Generica operador1{10,10};
    Generica operador2{-2,-3};
    operador1.imprime();
    ++operador1;

    operador2 += operador1;
    operador2.imprime();
    return EXIT_SUCCESS;
}