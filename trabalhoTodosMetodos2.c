#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mergesort.c"
#include "quicksort.c"
//#include "heapsort.c"

void geraVetorCrescente (int *vet , int n) {
    for (int i = 0; i < n; i++) {
        vet[i] = i+1;
    }
}
void geraVetorDecrescente (int *vet , int n) {
    int j = n;
    for (int i = 0; i < n; i++) {
        vet[i] = j;
        j--;
    }
}

void geraVetorAleatorio (int *vet, int n, int num) {
    int i;
    for (i = 0; i < n; i++){
        vet[i] = rand() % num;
        
    }
}

void escolheTipoVet (int tipovet, int *vet, int n, int num) {
    if (tipovet == 1) {
            geraVetorCrescente(vet, n);
        }
        else if (tipovet == 2) {
            geraVetorDecrescente(vet, n);
        }
        else if (tipovet == 3){
            geraVetorAleatorio(vet, n, num);
        }
}

void main(){
    int n;
    int num = 1000000;
    clock_t start,end;
    double difTempo;
    int metodo;
    int tipovet;

    printf("Qual método de ordenção usar?\n1 - Mergesort\n2 - Quicksort\n3 - Heapsort\n");
    scanf("%d", &metodo);
    printf("\n");
    printf("Ok, agora escolha o tamanho do vetor a ser usado?\n");
    scanf("%d", &n);
    printf("\n");
    int vet[n];
    printf("Escolha agora o tipo de vetor.\n1 - Crescente\n2 - Decrescente\n3 - Aleatorio");
    printf("\n");
    scanf("%d", &tipovet);
    printf("\n");
    escolheTipoVet (tipovet, vet, n, num);

    if (metodo == 1) {
        start = clock();
        mergesort(vet, 0, n);  
    }
    else if (metodo == 2) {
        start = clock();
        quicksort(vet, 0, n);
    }
    else if (metodo == 3) {
        start = clock();
        //heapsort (vet, n);
    }
    
    end = clock();

    printf("\nValore ordenados ");
    for(int q=0;q<n;q++){
        printf("%d ",vet[q]);
        }
    printf("\n");

    difTempo = ((double)end - start)/CLOCKS_PER_SEC;
    
    printf("\nTempo(s): %lf\n",difTempo);
    printf("Tempo(ms) %lf\n",difTempo*1000);
}