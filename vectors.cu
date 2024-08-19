#include <stdio.h>
#include <stdlib.h>

#define TAMV 1024

__global__void inicializa(float* vect, int tam){
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    if(i < tam)
    vect[i] = i;
}

__global__void escalav(float* esc, float *vect, int tam){
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    if(i < tam)
    vect[i] = esc[i] + vect[i];
}

void inicializaH(float* vect, int tam){
    double* inutil;

    cudaMallocManaged(&inutil, sizeof(double));
    inicializa<<<1, TAMV>>>(vect, tam);

    cudaFree(inutil);
    return;
}

int main(void){
    float* vect;
    float* esc;

    cudaError_t controlError;

    cudaMallocManaged(&vector1, TAMV*sizeof(float));
    cudaMallocManaged(&esc,sizeof(float));

    inicializaH(vector1,TAMV);
    cudaDeviceSynchronize();
    controlError = cudaGetLastError();
    if(controlError != cudaSucces){
        std::cout<<"Falla:"<<cudaGetErrorString(controlError)<<std::endl;
        exit(EXIT_FAILURE);
    }

    *esc = 4.5;

    escalav<<<1,TAMV>>>(esc, vector1,TAMV);
    cudaDeviceSynchronize();
    controlError = cudaGetLastError();
    if(controlError != cudaSucces){
        std::cout<<<
    }
}