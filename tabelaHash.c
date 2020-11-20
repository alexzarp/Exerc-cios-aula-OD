#include <stdio.h>
#include <stdlib.h>

struct bloco {
    int valor;
    struct bloco *proximo;
};
typedef struct Bloco bloco;

void printaBloco (bloco *rec) {
    rec = rec -> proximo;
    printf("Esta é a lista");

    if (rec) {
        do {
            printf("%d",rec -> valor);
        } while (rec);
        printf("\n");
    }
    else {
        printf("Esta lista está vazia no momento.\n");
    }
}
// Essa insere pelo início
void insereFim (bloco *raiz, int elementoASerInserido) {
    bloco *novo = NULL;
    
}



int main () {
    
    
    return 0;
}