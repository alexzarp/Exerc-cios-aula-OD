#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergesort (int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int meio = intercala((inicio + fim)/2);
        mergesort(vet, inicio, meio);
        mergesort(vet, meio+1, fim);
        intercala(vet, inicio, meio, fim);
    }
}

void intercala (int *vet, int inicio, int meio, int fim) {
    int aux = malloc (fim - inicio + 1);
    int i = inicio;
    int j = meio + 1;
    int *k = 0;

    while (i <= meio && j <= fim) {
        if (vet[i] <= vet[j]) {
            aux[k] = vet[i];
            i++;
        } else {
            aux[k] = vet[j];
            j++;
        }
        k++;
    }

    while (i <= meio) {
        aux[k] = vet[i];
        k++;
        i++;
    }

    while (j <= fim) {
        aux[k] = vet[j];
        k++;
        j++;
    }

    for (k = inicio; k <= fim; k++) {
        vet[*k] = aux[k - inicio];
    }
    free(aux);
}

void main(){
    int vet[5] = {3,27,6,4,5};
    int n=5;

    printf("Valore desordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");

    mergesort(vet, 0, n);

    printf("Valore ordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");
}