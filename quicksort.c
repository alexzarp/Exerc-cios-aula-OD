#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int particiona (int *vet, int inicio, int fim) {
    int aux;
    int cont = inicio;
    for (int i = inicio+1; i<= fim; i++){
        if(vet[i]<vet[inicio]) {
            cont++;
            aux = vet[i];
            vet[i] = vet [inicio];
            vet[inicio] = aux;  
        }
    }
    aux = vet[inicio];
    vet[inicio] = vet [cont];
    vet[cont] = aux;
    cont++;

    return cont;
}

void quicksort (int *vet, int inicio, int fim) {
    int vet_aux;
    if (inicio < fim) {
        vet_aux = particiona (vet, inicio, fim);
        quicksort(vet, inicio, vet_aux-1);
        quicksort(vet, vet_aux+1, fim);
    }
}


void main(){
    int vet[5] = {3,27,6,4,5};
    int n=5;

    printf("Valore desordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");

    quicksort(vet, 0, n);

    printf("Valore ordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");
}