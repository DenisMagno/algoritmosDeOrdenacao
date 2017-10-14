#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"

int particiona (int *V, int inicio, int fim){

    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = V[inicio];

    while(esq < dir) {
        while(V[esq]<= pivo){         //enquanto V[inicio] <= pivo ,
          esq ++;                           //   incrementa esq
        }
        while(V[dir] > pivo){
            dir--;
        }
        if(esq < dir){
            aux = V[esq];           // Troca dir e esq
            V[esq] = V[dir];
            V [dir] = aux;

        }

    }

    V[inicio] = V[dir];
    V[dir] = pivo;                  // trocam inicio e dir de lugar
    return dir;


}

void quickSort(int *V, int inicio, int fim){
    int pivo;

        if(fim > inicio){
            pivo = particiona(V, inicio, fim);    // chama a funcao particiona
            quickSort(V, inicio, pivo-1);
            quickSort(V, pivo+1, fim);
        }
}







