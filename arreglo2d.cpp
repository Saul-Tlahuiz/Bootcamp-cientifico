#include <iostream>
#include <cstdlib>

#define P 2
#define REN 3
#define COL 5

int main(int argc, char** argv){
    int Matriz[P][REN][COL];

    for(int i = 0;i < P; i++)
    for(int j = 0; j < REN; j++)
    for(int k = 0; k < COL; k++)
    Matriz[i][j][k] = 0;

    for(int i = 0;i < P; i++){
    for(int j = 0; j < REN; j++){
    for(int k = 0; k < COL; k++)

    std::cout << Matriz[i][j][k]<< ' ';

    std::cout<<std::endl;
    }
    std::cout<<std::endl;
    }
    return EXIT_SUCCESS;
}