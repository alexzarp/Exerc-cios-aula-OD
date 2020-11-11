#include <stdio.h>
#include <stdlib.h>
#include "getMax.c"

void countSort(int *vet, int i, int n) {
    int *aux;
    aux = (int *) malloc(vet sizeof(int));

    int cont[10];
    int posicao[10];
    for (int zera = 0; zera<10; zera++) {
        cont[zera] = 0;
        posicao[zera] = 0;
    }


}

void radixsort (int *vet, int n) {
    int max = getMax(vet,n);

    for (int i = 1; max/i > 0; i *= 10) {
        countSort(vet, i, n);
    }
}

void main() {
    

}