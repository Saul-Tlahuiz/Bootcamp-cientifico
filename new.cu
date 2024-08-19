#include <stdio.h>
#include <stdlib.h>

__global__ void muln(float *a, float *b, float *c){
    *c = (*a) * (*b);
}

int main(void){
    float a,b,c; //host

    float *d_a, *d_b, *d_c; //device

    int size = sizeof(float);
    //reservamos memoria
    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);
    cudaMalloc((void**)&d_c, size);
    a = 2.0;
    b = 5.2;

    //copiamos al device
    cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);
    //lanzamos el kernel
    muln<<<1,1>>>(d_a,d_b,d_c);
    //recuperamos del device
    cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);
    //limpiamos la memoria en el device una por una
    cudaFree(d_a);cudaFree(d_b);cudaFree(d_c);

    printf("%f\n",c);

    return 0;
}