#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore {
    int id;
    
    struct Arvore *esquerda, *direita;    
} Node;

int addNode (Node *raiz, Node *novo) {
    if (raiz == NULL) {
        return novo;
    } else {
        if (raiz->id >= novo->id) {
            raiz->esquerda = addNode (raiz->esquerda, novo);
        } else {
            raiz->direita = addNode(raiz->direita, novo); 
        }
    }
    return raiz;
}

Node *buscaChave (Node *raiz, int chave) {
    if (raiz == NULL || raiz->id == chave) {
        return raiz;
    }
    else if (chave > raiz->id) {
        return buscaChave(raiz->direita, chave);
    }
    return buscaChave(raiz->esquerda, chave);
}

/*void printaArvoreOrd (Node *raiz) {
    if (raiz == NULL) {
        printf("Arvore ainda não plantada")
    }
    else if (raiz->id >= ){

    }
}*/

void main () {
    Node *novoGalho = (Node *) malloc(sizeof (Node));
    novoGalho->esquerda = NULL;
    novoGalho->direita = NULL;

    printf("O código 000 fecha o loop\nO código 123 faz a busca de uma chave\n");

    int elemento, chave;
    for (;;) {
        printf("Digite um elemento ");
        scanf("%d",&elemento);

        if (elemento == 000) {
            break;
        }
        else if (elemento != 123){
            addNode (novoGalho, chave);
        } else {
            printf("Qual é a chave a ser buscada?");
            scanf("%d", &chave);
            buscaChave (novoGalho, chave);
        }
        
        //printar
    }
}