#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <type_traits>
#include <stdlib.h>

//vamos a copiar el esquema de particion de Lomuto

int particion(int a[], int start, int end){
    int pivot = a[end]; //agarramos el elemento mas a la derecha del array, i.e, el que sera nuestro pivote
    
    int pIndex = start;

    for(int i = start; i < end ; i++){
        if(a[i] <= pivot){
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    swap(a[pIndex],a[end]);

    return pIndex;
}

void quicksort(int a[], int start, int end){
    if(start >= end){
        return;
        }

        int pivot = particion(a, start, end);

        quicksort(a, start, pivot-1);

        quicksort(a, pivot + 1, end);
}

int main(){
    int a[] = {9, -3, 5, 2 , 6, 8, -6, 1, 3};
    int n = sizeof(a)/sizeof(a[0]);
    quicksort(a, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << ' ';
    }

    return EXIT_SUCCESS
    
}