#include <stdio.h>
#define N 2048

__global__void hola(void){
    register idx = threadIdx.x * blockDim.x * blockIdx.x + threadIdx.y + blockDim.y*blockIdx.y;
    __share__ A[2][2];
    __share__ B[2][2];
    if(blockIdx.x == 0 && blockIdx.y == 0)
    printf("Thread del primer grupo: %d, %d \n", threadIdx.x,threadIdx.y);
}

int main(){
    dim3 hilos(16,16)
    dim3 bloques(N/hilos.x,N/hilos.y);
    printf("%lu\n", sizeof(hilos));
    printf("%lu\n", sizeof(bloques));
    printf("%d, %d\n", hilos.x, hilos.y);
    printf("%d, %d\n", bloques.x, bloques.y);
    hola<<<bloques,hilos>>>();
    return 0;
}
