#include <iostream>
#include <stdlib.h>

void vecinos(float* vector, int tam){
    int i = _threadidx.x + blockDim.x * blockDim.x;
    if(i > 0 && i < tam-1)
    vectorout[i] = vectorin[i-1] + vectorin[i] + vectorin[i+1];
}

int main(void){
    float *fuente, *destino;
    cudaError_t v_err;

    cudaMallocManaged(&fuente, N*sizeof(float));
    cudaMallocManaged(&destino, N*sizeof(float));

    for(int i = 0; i<N; i++)
    fuente[i] = i;

    vecinos<<<1,N>>>(fuente, destino, N);
    cudaDeviceSynchronize();
    v_err = cudaGetLastError();
    if(v_err != cudaSucces)
    exit(EXIT_FAILURE);

    for(int i = 0; i<N;i++)
    fuente[i] = i;
    std::cout<<destino[i]>>' ';
    std::cout<<std::endl;
    cudaFree(fuente),cudaFree(destino);
    return EXIT_SUCCESS;
}