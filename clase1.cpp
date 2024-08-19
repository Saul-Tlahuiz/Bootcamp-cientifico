#include<iostream>
#include<cstdlib>

//En c++ podemos definir clases que no contengan nada o que contenga todas las cosas

class Persona{
    private:
    char oculto;
    public://con esto decimos si la clase es accesible desde fuera 
    //adentro de la clase definimos atributos y metodos
    std::string nombre;
    int edad = 10;

    void saludar(void){
        std::cout<<"Hola soy "<<nombre<<" y tengo "<<edad<<" años"<<std::endl;
    }
};

int main(int argc, char** argv){
    //tipo de la variable
    Persona Pancho;
    Pancho.saludar();
    return EXIT_SUCCESS;
}