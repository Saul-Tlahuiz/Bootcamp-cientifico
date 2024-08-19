#include <stdio.h>
#define N 8

__global__void sumaMat(float A[N][N], float B[N][N], float C[N][N]){
    int i = threadIdx.x;
    int j = threadIdx.y;

    C[i][j] = A[i][j] + B[i][j];
}

int main(void){
    int bloques = 1;
    //dim3 es un dato unico de cuda y nos permite definir una variable ademas los kernel consumen este tipo de dato
    int N = 8;
    dim3 hilosporbloque(bloques, N, N);

    //definimos la matriz
    float Ma[N][N],Mb[N][N],Mc[N][N];
    
    sumaMat<<<1,(8,8)>>>

    return 0;
}