#include <stdlib>
#include <iostream>
#define N 256

__global__void matrizE(float A[N][N], float esc){
    int i = threadIdx.x;
    int j = threadIdx.y;
    A[i][j] = esc * A[i][j];
}

int main(void){

    float *matrizt;

    dim3 hilosBloque(N,N);

    matrizE<<<1,hilosBloque>>>(matrizt,4.5);

    return EXIT_SUCCESS;
}
