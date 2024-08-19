#include<iostream>
#include <cstdlib>

#define COL 4
#define REN 3

int main(int argc, char** argv){
    int* Ptr = nullptr;
    int* Arreglo = nullptr;

    Ptr = new int[REN*COL];

    if(!Ptr)
    std::cout<<"Es un apuntador no valido"<<std::endl;

    else{
        Arreglo = Ptr;
        for(int i = 0; i<REN;i++){
            for(int j = 0; j<COL;j++){
                std::cout<<*Arreglo<<' ';
                Arreglo++;
        }
        std::cout<< *Arreglo<<'\n';
    }
   }
 delete(Ptr);
    return EXIT_SUCCESS;
}