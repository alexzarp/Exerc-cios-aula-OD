#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "swap.c"

void criaheap (int *vet, int n, int i) {
    int maior = i;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    if (esquerda < n && vet[esquerda] > vet[maior]) {
        maior = esquerda;
    }

    if (direita < n && vet[direita] > vet[maior]) {
        maior = direita;
    }

    if (maior != i) {
        swap (vet[i], vet[maior]);
        criaheap(vet, n, maior);
    }
}

void heapsort (int *vet, int n) {
    int k;

    for (k = (n/2 - 1); k >= 0; k--) {
        criaheap (vet, n, k);
    }

    for (k = n-1; k >= 0; k--) {
        swap(vet[0], vet[k]);
        criaheap(vet, k, 0);
    }
}

//Quando for usar esse código para testes, descomente o main.
//Caso contrário comente ele.
void main(){
    int vet[8] = {-5,1,9,40,-6,29,7,32};
    int n=8;

    printf("Valore desordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");

    heapsort (vet, n);

    printf("Valore ordenados    ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");
}
//---------------------------------------------------

