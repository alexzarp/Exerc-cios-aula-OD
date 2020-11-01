//Não sei porque só funciona se declarar swap aqui
#include "swap.c"

int particiona (int *vet, int inicio, int fim) {
    int pivo = vet[inicio];
    int aux, esq, dir;
    esq = inicio;
    dir = fim;
    while(esq<dir){
        while(vet[esq]<=pivo){
            esq++;
        }
        while (vet[dir] > pivo){
            dir--;
        }
        if(esq < dir){
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
            //swap (&vet[esq], &vet[dir]);
        }
        
        
    }
    vet[inicio] = vet[dir];
    vet[dir] = pivo;
    return dir;
}

void quicksort (int *vet, int inicio, int fim) {
    int pivo;
    if (inicio < fim) {
        pivo = particiona (vet, inicio, fim);
        quicksort(vet, inicio, pivo-1);
        quicksort(vet, pivo+1, fim);
    }
}