#include <stdio.h>
#include <cuda_runtime.h>

__globlal__ void escalav(float* esc, float* vect, int tam){
    vect[threadIdx.x] = *esc * vect[threadIdx.x];
}

int main(void){
    float a[10] = {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
    float esc = 4.5;

    int tamv = 10;
    int tamd = size(float);

    float* d_a;
    float* d_esc;
    int* d_tamv;

    cudaMalloc((void **)&d_a, tamv*tamv);
    cudaMalloc((void **)&d_esc, tamd);

    cudaMemcpy(d_a, &a, tamv*tamd, cudaMemcpyHostToDevice);
    cudaMemcpy(d_esc, &esc, tamd, cudaMemcpyHostToDevice);

    escalav<<<1,10>>>(d_esc,d_a);

    cudaMemcpy(a, d_a, tamv*tamd,cudaMemcpyDeviceToHost);

    cudaFree(d_a), cudaFree(d_esc);
    return 0;
}