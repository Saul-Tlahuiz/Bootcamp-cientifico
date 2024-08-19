#include <iostream>
#include <cstdlib>

int main(int argc, char** argv){
    int *Ptr = nullptr;

    if(Ptr ==  NULL)
    std::cout<<"Es un apuntador no valido"<<std::endl;
    Ptr = new int;
    *Ptr = 34;
    //por cada new debe haber un delete, si no se usa el delete el programa no sabe cuando dejar de usar esa variable
    std::cout<<*Ptr<<std::endl;
    delete(Ptr);
}