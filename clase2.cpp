#include<iostream>
#include<cstdlib>

class Persona{
    private:
    char oculto;
    public:
    std::string nombre;
    int edad;
    Persona(std::string nombre = "Pepe", int edad = 0){
    std::cout<<"Se invoca el constructor"<<std::endl;}

    void saludar(void){
        std::cout<<"Hola\n";
    }
};

int main(int argc, char** argv){
    Persona Pancho;
    Pancho.saludar();
    std::cout<<Pancho.nombre<<std::endl;
    std::cout<<Pancho.edad<<std::endl;
    return EXIT_SUCCESS;
}