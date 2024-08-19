#include <iostream>
#include <cstdlib>

#define REN 3
#define COL 5

int main(int argc, char** argv){
    int Matriz[REN][COL];

    int* Apt=nullptr;
    Apt = &Matriz[0][0];
    std::cout <<Apt<<std::endl;

    for(int i = 0; i<REN;i++)
    for(int j = 0; j<COL;j++){
    *Apt=0;
    Apt++;
    }

    std::cout<<Apt<<std::endl;

    for(int i = 0; i< REN; i++){
        for(int j = 0; j<COL;j++)
        std::cout<<Matriz[i][j]<<' ';
        std::cout<<std::endl;
    }
    return EXIT_SUCCESS;
}

