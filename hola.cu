#include <stdio.h>

__global__ void mikernel(void){
}

int main(void){
    mikernel<<<1, 1>>();
    printf("Hola Mundo\n");
    return 0;
}
