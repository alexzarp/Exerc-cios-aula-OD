//FINALIZADO
int particiona (int *vet, int inicio, int fim) {
    int pivo = vet[inicio];
    int aux, esq, dir;
    esq = inicio + 1;
    dir = fim;
    while(esq <= dir){
        if(vet[esq] <= pivo){
            esq++;
        }
        else if (vet[dir] > pivo){
            dir--;
        }
        else if(esq <= dir){
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
            esq++;
            dir--;
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