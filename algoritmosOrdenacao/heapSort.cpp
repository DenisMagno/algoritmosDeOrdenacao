#include "heapSort.h"

void heapSort(int v[], int n){
    int i, aux;

    for(i=(n-1)/2; i >= 0; i--){
        criaHeap(i, n-1, v);
    }

    for(i = n-1; i >= 1; i--){
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        criaHeap(0, i - 1, v);
    }
}

void criaHeap(int i, int f, int v[]){
    int aux = v[i];
    int j = i * 2 + 1;

    while(j <= f){
        if(j < f){
            if(v[j] < v[j + 1]){
                j = j + 1;
            }
        }

        if(aux < v[j]){
            v[i] = v[j];
            i = j;
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }

    v[i] = aux;
}
