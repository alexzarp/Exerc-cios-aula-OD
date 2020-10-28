#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int particiona (int *vet, int inicio, int fim);
void quicksort (int *vet, int inicio, int fim);


int particiona (int *vet, int inicio, int fim) {
    int pivo = fim;
    int cont = inicio;
    for (int i = inicio; i < fim; i++){
        if(vet[i] <= vet[pivo]) {
            cont++;
            /*pivo = vet[i];
            vet[i] = vet[inicio];
            vet[inicio] = pivo;*/
            swap(&vet[cont], &vet[i]);
        }
    }

    if (vet[cont] > vet[pivo]){
        /*pivo = vet[inicio];
        vet[inicio] = vet[cont];
        vet[cont] = pivo;
        cont++;*/
        swap(&vet[cont], &vet[pivo]);
    }
    
    return pivo;
}

void quicksort (int *vet, int inicio, int fim) {
    int pivo;
    if (inicio < fim) {
        pivo = particiona (vet, inicio, fim);
        quicksort(vet, inicio, pivo-1);
        quicksort(vet, pivo+1, fim);
    }
}

//Quando for usar esse código para testes, descomente o main.
//caso contrário comente ele.
/*void main(){
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
}*/