#include <iostream>
#include <stdlib>
#include <stdio.h>

#define N 1024

__device__ float primerSegmento(int indice, float sinuso){
    sinuso = sinuso+2.3;
    if(indice == 0)
    return(float) threadIdx.x;
    else
    return -1;
}

__global__void vecinos(float* vectorin, float* vectorout, int tam){
    register int i = threadIdx.x + blockDim.x * blockIdx.x;
    register float relativo = 0;

    if(i<tam)
    relativo = primerSegmento(i, vectorin[i]);

    if(i>0 && i<tam-1)
    vectorout[i] = vectorin[i-1] + vectorin[i] + vectorin[i+1] + relativo;
    else if(i==0 || i == (tam-1))
    vectorout[i] = vectorin[i];
}

int main(int argc, char** argv){
    float* fuente , *destino;
    cudaError_t v_err;

    if(argc != 1)
    printf("%s\n", argv[1]);
    else
    exit(EXIT_FAILURE);


    cudaMallocManaged(&fuente, N*sizeof(float));
    cudaMallocManaged(&destino,N*sizeof(float));

    for(int i = 0; i<N; i++)
    fuente[i] = i;

    vecinos<<<1,N>>>(fuente, destino, N);
    cudaDeviceSynchronize();
    v_err = cudaGetLastError
    if(v_err != cudaSucces);
    return EXIT_SUCCES
}