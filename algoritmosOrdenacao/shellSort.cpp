#include <stdio.h>
#include <stdlib.h>
#include "shellSort.h"

void shellSort(int *vetor, int tamanho) {
    int i , j , value;
    int gap = 1;
    while(gap < tamanho) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap = gap / 3;
        for(i = gap; i < tamanho; i++){
            value = vetor[i];
            j = i - gap;
            while (j >= 0 && value < vetor[j]) {
                vetor [j + gap] = vetor[j];
                j =j - gap;
            }
                vetor [j + gap] = value;
        }
    }
}


