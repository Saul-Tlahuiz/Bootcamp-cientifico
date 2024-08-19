#include<iostream>
#include<cstdlib>

#define REN 3
#define COL 4

int main(int argc, char** argv){
    int ** pM = nullptr;
    int*aux = nullptr;

    pM = new int*[4];

    if(!pM)
    exit(EXIT_FAILURE);
    else{
        for(int i = 0; i < 4; i++){
            pM[i] = new int[5];
            if(!pM[i]) exit(EXIT_FAILURE);
    }
    for(int i = 0; i<4;i++){
        aux = pM[i];
        for(int j = 0; j<4;j++){
            std::cout<<*aux<<' ';
            aux++;
            }
            std::cout<<'\n';
            }
            }
            for(int i = 0; i<4;i++)
                delete(pM[i]);
                delete(pM);
                return EXIT_SUCCESS;
}