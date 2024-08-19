#include <iostream>
#include <cstdlib>

int main(int argc, char** argv){
    char a[] = {"hola"};
    char c[6];
    char b[] = {'m', 'u', 'n', 'd','o', '\0'};
    int i = 0;
    while(a[i] != '\0'){
        char temp;
        temp = a[i]+3;
        std::cout << temp;
        i++;
    }
    std::cout << ' ' <<b<<std::endl;
    return EXIT_SUCCESS;
}