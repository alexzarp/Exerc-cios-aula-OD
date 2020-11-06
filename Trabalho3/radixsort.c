#include <stdio.h>
#include "getMax.c"

void countSort(vet, i, n) {
    
}

void radixsort (int *vet, int n) {
    int max = getMax(vet,n);

    for (int i = 1; max/i > 0; i *= 10) {
        countSort(vet, i, n);
    }
}


void main() {
    

}