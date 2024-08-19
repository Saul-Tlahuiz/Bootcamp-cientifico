#include <iostream>
#include <stdlib>

#define N 2048

__global__void iniv(float *vector, int tam){
    int i = threadIdx.x + blockIdx.x * blockDim.x
    int brinco = blockDim.x*gridDim.x; //nos dice cuantos threads por bloque hay y cuantos bloques

    int y;
    if( i < tam){
        for(y = i; i < tam; y = y + brinco)
        vector[y] = 1.0;//podemos meter un for dentro de un kernel 
    }
}

__global__void sumaVect(float* vectA,float* vectB,float* vectC,int tam){
    int indice = threadIdx.x + blockId.x * blockDim.x;
    int brinco = blockDim.x*gridDim.x;
    int i;
    if(indice < tam){
        for(i = indice; i < tam; i = i*brinco)
        vectC[i] = vectA[i] + vectB[i];
    }
}

int main(void){
    float *vecta, *vectb, *salida;

    //int gpu = -1;
    //cudaGetDeviceCount(&gpu); // esto se usa para acelerar las lecturas en la gpu
    int numthreads = 256;
    int numBloques = (N+ numthreads-1)/numthreads;
    std::cout<<numBloques<<' \n';

    cudaMallocManaged(&vecta, N*sizeof(float));
    cudaMallocManaged(&vectb, N*sizeof(float));
    cudaMallocManaged(&salida, N*sizeof(float));
    
    iniv<<<2,256>>>(vecta,N);
    iniv<<<4,256>>>(vectb,N);
    iniv<<<numBloques, numthreads>>>(vecta, N);
    iniv<<<numBloques, numthreads>>>(vectb, N);
    cudaDeviceSynchronize(); //lo necesitamos por que despues vamos a llamar un kernel

    sumaVect<<<4,256>>>(vecta,vectb,salida,N);

    for (int i = 0; i<N; i++)
    std::cout<<salida[i]<<' ';
    //std::cout<<vecta[i]<<std::' ';
    //std::cout<<vecta[512]<<std::endl;

    cudaFree(vecta), cudaFree(vectb), cudaFree(salida);
    return EXIT_SUCCESS;
}