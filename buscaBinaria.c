#include <stdio.h>

int buscaBinaria (int chave, int *vet, int n) {
    int inicio = 0, fim = n -1, meio;
    

    while (inicio <= meio) {
        meio = (inicio + fim)/2;

        if (chave == vet[meio]) {
            return meio;
        }

        else if (chave < vet[meio]) {
            fim = meio - 1;
        }

        else {
            inicio = meio + 1;
        }
    }
}

int main() {
    int n = 10;
    int vet[10] = {4,5,22,3,45,56,5,534,5346,745};

    int retorno = buscaBinaria(56, vet, n);

    printf("Posição %d\n",retorno+1);
    return 0;
}