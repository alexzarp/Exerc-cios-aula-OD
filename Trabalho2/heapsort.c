//FINALIZADO
# include "swap.c"
void criaheap (int *vet, int n, int i) {
    int aux;
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
        swap (&vet[i], &vet[maior]);
        criaheap(vet, n, maior);
    }
}

void heapsort (int *vet, int n) {
    int k;
    int aux;
    for (k = (n/2 - 1); k >= 0; k--) {
        criaheap (vet, n, k);
    }

    for (k = n-1; k >= 0; k--) {
        swap(&vet[0], &vet[k]);
        criaheap(vet, k, 0);
    }
}