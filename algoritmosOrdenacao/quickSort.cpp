#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"

int particiona (int *v, int inicio, int fim){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = v[inicio];

    while(esq < dir) {
        while(v[esq]<= pivo){         //enquanto V[inicio] <= pivo ,
          esq ++;                           //   incrementa esq
        }
        while(v[dir] > pivo){
            dir--;
        }
        if(esq < dir){
            aux = v[esq];           // Troca dir e esq
            v[esq] = v[dir];
            v[dir] = aux;

        }

    }

    v[inicio] = v[dir];
    v[dir] = pivo;                  // trocam inicio e dir de lugar
    return dir;


}

void quickSort(int *v, int inicio, int fim){
    int pivo;

        if(fim > inicio){
            pivo = particiona(v, inicio, fim);    // chama a funcao particiona
            quickSort(v, inicio, pivo-1);
            quickSort(v, pivo+1, fim);
        }
}







