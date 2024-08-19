#include<iostream>
#include<cstdlib>

int main(int argc, char** argv){
    int *Ptr = nullptr;

    Ptr = new int[3];
    if(!Ptr)
    std::cout<<"Es un apuntador no valido"<<std::endl;
    else{
        Ptr[0] = 34;
        std::cout<<Ptr[0]<<std::endl;
    }
    delete(Ptr);
    return EXIT_SUCCESS;
}