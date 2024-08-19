#include <iostream>
#include <cstdlib>
#include <cmath> //libreria con funciones matematicas

//descripcion y declaracion de la clase
/*class Cosa{
    public:
    void saludo(void);
};
*/

class Particula{
    public:
    float x,y;
    Particula(float datx, float daty)
    :x{datx}, y{daty}
    {
    }
    Particula(const Particula& org)
    :x{org.x}, y{org.y}
    {
    }
    void saludo(void);
};

//metodo definido fuera de la clase
void Particula::saludo(void){
    std::cout<<"Hola\n";
}

int main(int argc, char** argv){
    char a{'i'};
    Particula tierra(3,0);
    Particula marte = tierra;
    tierra.saludo();
    std::cout<<marte.x<<std::endl;
    marte.x = 9.0;
    std::cout<<tierra.x<<std::endl;
    //Cosa unaCosa;
    //unaCosa.saludo(); //llama al metodo saludo de la clase Cosa
    return EXIT_SUCCESS;
}

 //std::cout <<pow(2.4,8.6)<<std::endl; pow esla funcion para elevar un numero y se puede elevar a cualquier numero real
