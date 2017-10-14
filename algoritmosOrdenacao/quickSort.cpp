#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"

void quickSort(int *a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quickSort(a, left, j);
    }
    if(i < right) {
        quickSort(a, i, right);
    }
}
