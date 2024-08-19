#include <iostream>
#include <cstdlib>

int main(int argc, char** argv){
    std::cout << argc<<std::endl;
    std::cout << **argv <<std::endl;

    return EXIT_SUCCESS;
}